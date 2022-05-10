/**
 * @file EcuAbstraction.c
 * @author Mina-Ryad (mina.hany.kameel.ryad@gmail.com)
 * @brief 
 * @version 1.0
 * @date 2022-05-10
 * 
 * @copyright Mina-Ryad (c) 2022
 * 
 */

/* Include RTE Application Header */
#include "Rte_TempHBridgeSWC.h"

/*
<RUNNABLE-ENTITY>
    <SHORT-NAME>ReadTemperature</SHORT-NAME>
    <MINIMUM-START-INTERVAL>0</MINIMUM-START-INTERVAL>
    <CAN-BE-INVOKED-CONCURRENTLY>false</CAN-BE-INVOKED-CONCURRENTLY>
    <DATA-SEND-POINTS>
        <VARIABLE-ACCESS>
            <SHORT-NAME>VA_Temp</SHORT-NAME>
            <ACCESSED-VARIABLE>
                <AUTOSAR-VARIABLE-IREF>
                    <PORT-PROTOTYPE-REF DEST="P-PORT-PROTOTYPE">/SWComponent/TempHBridgeSWC/PP_Temperature</PORT-PROTOTYPE-REF>
                    <TARGET-DATA-PROTOTYPE-REF DEST="VARIABLE-DATA-PROTOTYPE">/Interfaces/I_Temperature/Temperature</TARGET-DATA-PROTOTYPE-REF>
                </AUTOSAR-VARIABLE-IREF>
            </ACCESSED-VARIABLE>
        </VARIABLE-ACCESS>
    </DATA-SEND-POINTS>
    <SYMBOL>ReadTemperature_Function</SYMBOL>
</RUNNABLE-ENTITY>
*/
/*
<SENDER-RECEIVER-INTERFACE>
    <SHORT-NAME>I_Temperature</SHORT-NAME>
    <DATA-ELEMENTS>
    <VARIABLE-DATA-PROTOTYPE>
    <SHORT-NAME>Temperature</SHORT-NAME>
    <SW-DATA-DEF-PROPS>
    <SW-DATA-DEF-PROPS-VARIANTS>
        <SW-DATA-DEF-PROPS-CONDITIONAL>
        <IMPLEMENTATION-DATA-TYPE-REF DEST="IMPLEMENTATION-DATA-TYPE">AUTOSAR_PlatformTypes/ImplementationDataTypes/float32</IMPLEMENTATION-DATA-TYPE-REF>
        </SW-DATA-DEF-PROPS-CONDITIONAL>
    </SW-DATA-DEF-PROPS-VARIANTS>
    </SW-DATA-DEF-PROPS>
    </VARIABLE-DATA-PROTOTYPE>
    </DATA-ELEMENTS>
</SENDER-RECEIVER-INTERFACE>
*/
/*
<P-PORT-PROTOTYPE>
    <SHORT-NAME>PP_Temperature</SHORT-NAME>
    <PROVIDED-INTERFACE-TREF DEST="SENDER-RECEIVER-INTERFACE">/Interfaces/I_Temperature</PROVIDED-INTERFACE-TREF>
</P-PORT-PROTOTYPE>
*/
/* Code for Runnable - Read Temperature */
void ReadTemperature_Function()
{
    uint16 ADCResult;
    float PinVoltage, Temperature;

    /* Trigger ADC Conversion and read results */
    Adc_StartGroupConversion(1);

    //Adc_ReadGroup( Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr )
    Adc_ReadGroup( 1, &ADCResult );

    /* Convert ADC raw value to voltage */
    /* 10bit ADC with voltage ref-2.5v */
    PinVoltage = (2.5/1024)*ADCResult;

    /* convert voltage to temperature */
    /* Resp. Sensor Actuator SWC on Application Layer */
    /* Sensor -> for 35degree output is 0.35v */
    Temperature = PinVoltage * 100;

    /* Write Temperature results to RTE */
    Rte_Write_PP_Temperature_Temperature(Temperature);

}

/*
<RUNNABLE-ENTITY>
    <SHORT-NAME>StartMotor</SHORT-NAME>
    <MINIMUM-START-INTERVAL>0</MINIMUM-START-INTERVAL>
    <CAN-BE-INVOKED-CONCURRENTLY>false</CAN-BE-INVOKED-CONCURRENTLY>
    <SYMBOL>StartMotor_Function</SYMBOL>
</RUNNABLE-ENTITY>
*/
/*
    <CLIENT-SERVER-INTERFACE>
     <SHORT-NAME>I_StartMotor</SHORT-NAME>
     <OPERATIONS>
      <CLIENT-SERVER-OPERATION>
       <SHORT-NAME>StartMotor</SHORT-NAME>
       <ARGUMENTS>
        <ARGUMENT-DATA-PROTOTYPE>
         <SHORT-NAME>FanSpeed</SHORT-NAME>
         <TYPE-TREF DEST="IMPLEMENTATION-DATA-TYPE">AUTOSAR_PlatformTypes/ImplementationDataTypes/uint8</TYPE-TREF>
         <DIRECTION>IN</DIRECTION>
        </ARGUMENT-DATA-PROTOTYPE>
       </ARGUMENTS>
       <POSSIBLE-ERROR-REFS>
        <POSSIBLE-ERROR-REF DEST="APPLICATION-ERROR">/Interfaces/I_StartMotor/StartMotor/E_OK</POSSIBLE-ERROR-REF>
        <POSSIBLE-ERROR-REF DEST="APPLICATION-ERROR">/Interfaces/I_StartMotor/StartMotor/E_NOT_OK</POSSIBLE-ERROR-REF>
       </POSSIBLE-ERROR-REFS>
      </CLIENT-SERVER-OPERATION>
     </OPERATIONS>
     <POSSIBLE-ERRORS>
      <APPLICATION-ERROR>
       <SHORT-NAME>E_OK</SHORT-NAME>
       <ERROR-CODE>0</ERROR-CODE>
      </APPLICATION-ERROR>
      <APPLICATION-ERROR>
       <SHORT-NAME>E_NOT_OK</SHORT-NAME>
       <ERROR-CODE>1</ERROR-CODE>
      </APPLICATION-ERROR>
     </POSSIBLE-ERRORS>
    </CLIENT-SERVER-INTERFACE>
*/
/* code for runnable - StartMotor (Server) */
void StartMotor_Function(uint8 Fanspeed)
{

    if(Fanspeed < 50)
    {
        /* Trigger Cooling Fan with half speed*/
        /* H-Bridge settings logic to (1,0) */
        // void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level )
        Dio_WriteChannel(10, STD_HIGH);
        Dio_WriteChannel(11, STD_LOW);
    }
    else
    {
        /* Run Fan at full speed */
        /* H-Bridge settings logic to (1,1) */
        Dio_WriteChannel(10, STD_HIGH);
        Dio_WriteChannel(11, STD_HIGH);
    }

}

/*
<RUNNABLE-ENTITY>
    <SHORT-NAME>StopMotor</SHORT-NAME>
    <MINIMUM-START-INTERVAL>0</MINIMUM-START-INTERVAL>
    <CAN-BE-INVOKED-CONCURRENTLY>false</CAN-BE-INVOKED-CONCURRENTLY>
    <SYMBOL>StopMotor_Function</SYMBOL>
</RUNNABLE-ENTITY>
*/
/* code for runnable - StopMotor (Server) */
void StopMotor_Function()
{
        /* H-Bridge settings logic to (0,0) */
        Dio_WriteChannel(10, STD_LOW);
        Dio_WriteChannel(11, STD_LOW);
}