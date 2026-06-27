#include <stddef.h>
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "tyre_model_v3_capi_host.h"
#define sizeof(...) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 17
#endif
#ifndef SS_INT64
#define SS_INT64 18
#endif
#else
#include "builtin_typeid_types.h"
#include "tyre_model_v3.h"
#include "tyre_model_v3_capi.h"
#include "tyre_model_v3_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static rtwCAPI_States rtBlockStates [ ] = { { 0 , 1 ,
TARGET_STRING ( "tyre_model_v3/Combined Slip Wheel 2DOF/Magic Tire Const Input/Fx Relaxation/Integrator" ) , TARGET_STRING ( "" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 , 1 , - 1 , 0 } , { 1 , 4 , TARGET_STRING ( "tyre_model_v3/Combined Slip Wheel 2DOF/Magic Tire Const Input/Fy Relaxation/Integrator" ) , TARGET_STRING ( "" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 , 1 , - 1 , 0 } , { 2 , 0 , TARGET_STRING ( "tyre_model_v3/Combined Slip Wheel 2DOF/Magic Tire Const Input/My Relaxation/Integrator" ) , TARGET_STRING ( "" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 , 1 , - 1 , 0 } , { 3 , 5 , TARGET_STRING ( "tyre_model_v3/Combined Slip Wheel 2DOF/Magic Tire Const Input/WhlTrq Relaxation/Integrator" ) , TARGET_STRING ( "" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 , 1 , - 1 , 0 } , { 4 , 2 , TARGET_STRING ( "tyre_model_v3/Combined Slip Wheel 2DOF/Vertical DOF/Vertical Wheel and Unsprung Mass Response/Integrator,\nSecond-Order" ) , TARGET_STRING ( "" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 , 1 , - 1 , 0 } , { 0 , - 1 , ( NULL ) , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } } ; static int_T rt_LoggedStateIdxList [ ] = { 1 , 3 , 0 , 4 , 2 } ;
#ifndef HOST_CAPI_BUILD
static void tyre_model_v3_InitializeDataAddr ( void * dataAddr [ ] ,
cpepv4pomu * localDW , e3e2pluf2v * localX ) { dataAddr [ 0 ] = ( void * ) ( &
localX -> hefyhheelt ) ; dataAddr [ 1 ] = ( void * ) ( & localX -> kbmxmkxuee
) ; dataAddr [ 2 ] = ( void * ) ( & localX -> pqho1itqp2 ) ; dataAddr [ 3 ] =
( void * ) ( & localX -> a1ntnbdeq2 ) ; dataAddr [ 4 ] = ( void * ) ( &
localX -> fzqtz4mp3r [ 0 ] ) ; }
#endif
#ifndef HOST_CAPI_BUILD
static void tyre_model_v3_InitializeVarDimsAddr ( int32_T * vardimsAddr [ ] )
{ vardimsAddr [ 0 ] = ( NULL ) ; }
#endif
#ifndef HOST_CAPI_BUILD
static void tyre_model_v3_InitializeLoggingFunctions ( RTWLoggingFcnPtr
loggingPtrs [ ] ) { loggingPtrs [ 0 ] = ( NULL ) ; loggingPtrs [ 1 ] = ( NULL
) ; loggingPtrs [ 2 ] = ( NULL ) ; loggingPtrs [ 3 ] = ( NULL ) ; loggingPtrs
[ 4 ] = ( NULL ) ; }
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } }
;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } } ; static
uint_T rtDimensionArray [ ] = { 1 , 1 , 2 , 1 } ; static const real_T
rtcapiStoredFloats [ ] = { 0.0 } ; static rtwCAPI_FixPtMap rtFixPtMap [ ] = {
{ ( NULL ) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , }
; static rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , ( int8_T ) 0 , ( uint8_T ) 0 } } ; static int_T rtContextSystems [ 10 ] ; static rtwCAPI_LoggingMetaInfo loggingMetaInfo [ ] = { { 0 , 0 , "" , 0 } } ; static rtwCAPI_ModelMapLoggingStaticInfo mmiStaticInfoLogging = { 10 , rtContextSystems , loggingMetaInfo , 0 , ( NULL ) , { 0 , ( NULL ) , ( NULL ) } , 0 , ( NULL ) } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 0 , ( NULL ) , 0 , ( NULL ) , 0 } , { ( NULL ) , 0 , ( NULL ) , 0 } , { rtBlockStates , 5 } , { rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float" , { 1661874346U , 4182922585U , 1766885739U , 4023193570U } , & mmiStaticInfoLogging , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ; const rtwCAPI_ModelMappingStaticInfo * tyre_model_v3_GetCAPIStaticMap ( void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
static void tyre_model_v3_InitializeSystemRan ( ilpumsz4jk * const mge4gz3cxc
, sysRanDType * systemRan [ ] , cpepv4pomu * localDW , int_T systemTid [ ] ,
void * rootSysRanPtr , int rootTid ) { UNUSED_PARAMETER ( mge4gz3cxc ) ;
UNUSED_PARAMETER ( localDW ) ; systemRan [ 0 ] = ( sysRanDType * )
rootSysRanPtr ; systemRan [ 1 ] = ( NULL ) ; systemRan [ 2 ] = ( sysRanDType
* ) & localDW -> jmjnhe2dwp [ 0 ] . h0jsss4leb . kfhlanvtu0 ; systemRan [ 3 ]
= ( sysRanDType * ) & localDW -> jmjnhe2dwp [ 0 ] . h0jsss4leb . ns0rq1s4hq ;
systemRan [ 4 ] = ( sysRanDType * ) & localDW -> jmjnhe2dwp [ 0 ] .
h0jsss4leb . mag22junxe ; systemRan [ 5 ] = ( sysRanDType * ) & localDW ->
jmjnhe2dwp [ 0 ] . h0jsss4leb . gvdrtrfikl ; systemRan [ 6 ] = ( NULL ) ;
systemRan [ 7 ] = ( NULL ) ; systemRan [ 8 ] = ( NULL ) ; systemRan [ 9 ] = ( NULL ) ; systemTid [ 1 ] = mge4gz3cxc -> Timing . mdlref_GlobalTID [ 0 ] ; systemTid [ 5 ] = mge4gz3cxc -> Timing . mdlref_GlobalTID [ 1 ] ; systemTid [ 4 ] = mge4gz3cxc -> Timing . mdlref_GlobalTID [ 1 ] ; systemTid [ 2 ] = mge4gz3cxc -> Timing . mdlref_GlobalTID [ 0 ] ; systemTid [ 3 ] = mge4gz3cxc -> Timing . mdlref_GlobalTID [ 0 ] ; systemTid [ 6 ] = mge4gz3cxc -> Timing . mdlref_GlobalTID [ 0 ] ; systemTid [ 7 ] = mge4gz3cxc -> Timing . mdlref_GlobalTID [ 0 ] ; systemTid [ 8 ] = mge4gz3cxc -> Timing . mdlref_GlobalTID [ 0 ] ; systemTid [ 9 ] = mge4gz3cxc -> Timing . mdlref_GlobalTID [ 0 ] ; systemTid [ 0 ] = rootTid ; rtContextSystems [ 0 ] = 0 ; rtContextSystems [ 1 ] = 0 ; rtContextSystems [ 2 ] = 2 ; rtContextSystems [ 3 ] = 3 ; rtContextSystems [ 4 ] = 4 ; rtContextSystems [ 5 ] = 5 ; rtContextSystems [ 6 ] = 0 ; rtContextSystems [ 7 ] = 0 ; rtContextSystems [ 8 ] = 0 ; rtContextSystems [ 9 ] = 0 ; }
#endif
#ifndef HOST_CAPI_BUILD
void tyre_model_v3_InitializeDataMapInfo ( ilpumsz4jk * const mge4gz3cxc ,
cpepv4pomu * localDW , e3e2pluf2v * localX , void * sysRanPtr , int
contextTid ) { rtwCAPI_SetVersion ( mge4gz3cxc -> DataMapInfo . mmi , 1 ) ;
rtwCAPI_SetStaticMap ( mge4gz3cxc -> DataMapInfo . mmi , & mmiStatic ) ;
rtwCAPI_SetLoggingStaticMap ( mge4gz3cxc -> DataMapInfo . mmi , &
mmiStaticInfoLogging ) ; tyre_model_v3_InitializeDataAddr ( mge4gz3cxc ->
DataMapInfo . dataAddress , localDW , localX ) ; rtwCAPI_SetDataAddressMap ( mge4gz3cxc -> DataMapInfo . mmi , mge4gz3cxc -> DataMapInfo . dataAddress ) ; tyre_model_v3_InitializeVarDimsAddr ( mge4gz3cxc -> DataMapInfo . vardimsAddress ) ; rtwCAPI_SetVarDimsAddressMap ( mge4gz3cxc -> DataMapInfo . mmi , mge4gz3cxc -> DataMapInfo . vardimsAddress ) ; rtwCAPI_SetPath ( mge4gz3cxc -> DataMapInfo . mmi , ( NULL ) ) ; rtwCAPI_SetFullPath ( mge4gz3cxc -> DataMapInfo . mmi , ( NULL ) ) ; tyre_model_v3_InitializeLoggingFunctions ( mge4gz3cxc -> DataMapInfo . loggingPtrs ) ; rtwCAPI_SetLoggingPtrs ( mge4gz3cxc -> DataMapInfo . mmi , mge4gz3cxc -> DataMapInfo . loggingPtrs ) ; rtwCAPI_SetInstanceLoggingInfo ( mge4gz3cxc -> DataMapInfo . mmi , & mge4gz3cxc -> DataMapInfo . mmiLogInstanceInfo ) ; rtwCAPI_SetChildMMIArray ( mge4gz3cxc -> DataMapInfo . mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen ( mge4gz3cxc -> DataMapInfo . mmi , 0 ) ; tyre_model_v3_InitializeSystemRan ( mge4gz3cxc , mge4gz3cxc -> DataMapInfo . systemRan , localDW , mge4gz3cxc -> DataMapInfo . systemTid , sysRanPtr , contextTid ) ; rtwCAPI_SetSystemRan ( mge4gz3cxc -> DataMapInfo . mmi , mge4gz3cxc -> DataMapInfo . systemRan ) ; rtwCAPI_SetSystemTid ( mge4gz3cxc -> DataMapInfo . mmi , mge4gz3cxc -> DataMapInfo . systemTid ) ; rtwCAPI_SetGlobalTIDMap ( mge4gz3cxc -> DataMapInfo . mmi , & mge4gz3cxc -> Timing . mdlref_GlobalTID [ 0 ] ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void tyre_model_v3_host_InitializeDataMapInfo ( tyre_model_v3_host_DataMapInfo_T
* dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ; rtwCAPI_SetPath
( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
