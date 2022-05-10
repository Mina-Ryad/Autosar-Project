/**
 * @file ApplicationSWC.c
 * @author Mina-Ryad (mina.hany.kameel.ryad@gmail.com)
 * @brief 
 * @version 1.0
 * @date 2022-05-10
 * 
 * @copyright Mina-Ryad (c) 2022
 * 
 */

/* Add RTE Application header file */
#include "Rte_TempControlSWC.h"

/*<SYMBOL>TemperatureControl_Function</SYMBOL>*/
/*
<DATA-RECEIVE-POINT-BY-ARGUMENTS>
    <VARIABLE-ACCESS>
        <SHORT-NAME>VA_Temp</SHORT-NAME>
        <ACCESSED-VARIABLE>
            <AUTOSAR-VARIABLE-IREF>
                <PORT-PROTOTYPE-REF DEST="R-PORT-PROTOTYPE">/SWComponent/TempControlSWC/RP_Temperature</PORT-PROTOTYPE-REF>
                <TARGET-DATA-PROTOTYPE-REF DEST="VARIABLE-DATA-PROTOTYPE">/Interfaces/I_Temperature/Temperature</TARGET-DATA-PROTOTYPE-REF>
            </AUTOSAR-VARIABLE-IREF>
        </ACCESSED-VARIABLE>
    </VARIABLE-ACCESS>
</DATA-RECEIVE-POINT-BY-ARGUMENTS>
*/

/*
<R-PORT-PROTOTYPE>
    <SHORT-NAME>RP_Temperature</SHORT-NAME>
    <REQUIRED-INTERFACE-TREF DEST="SENDER-RECEIVER-INTERFACE">/Interfaces/I_Temperature</REQUIRED-INTERFACE-TREF>
</R-PORT-PROTOTYPE>
*/

/*
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
*/
void TemperatureControl_Function()
{
    float Temperature;
    /* Read data from Ecu Abstraction through RTE */
    Rte_Read_RP_Temperature_Temperature( &Temperature );

    /* Control Logic */
    if(Temperature > 50 && Temperature < 75)
    {
        /* Start Cooling fan at low speed */
        Rte_Call_RP_StartMotor_StartMotor(25);
    }
    else if( Temperature > 75 )
    {
        /* Run fan at high speed */
        Rte_Call_RP_StartMotor_StartMotor(100);
    }
    else if(Temperature < 50)
    {
        /* Stop the cooling fan */
        Rte_Call_RP_StopMotor_StopMotor();
    }
}