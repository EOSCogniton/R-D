#include <stddef.h>
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "state_variables_capi_host.h"
#define sizeof(...) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 19
#endif
#ifndef SS_INT64
#define SS_INT64 20
#endif
#else
#include "builtin_typeid_types.h"
#include "state_variables.h"
#include "state_variables_capi.h"
#include "state_variables_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static rtwCAPI_States rtBlockStates [ ] = { { 0 , - 1
, TARGET_STRING ( "state_variables/Discrete-Time\nIntegrator" ) ,
TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } , { 1 , -
1 , TARGET_STRING ( "state_variables/Discrete-Time\nIntegrator1" ) ,
TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } , { 2 , -
1 , TARGET_STRING ( "state_variables/Discrete-Time\nIntegrator2" ) ,
TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } , { 0 , -
1 , ( NULL ) , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } } ;
static int_T rt_LoggedStateIdxList [ ] = { 0 , 1 , 2 } ;
#ifndef HOST_CAPI_BUILD
static void state_variables_InitializeDataAddr ( void * dataAddr [ ] ,
pvhntfwfsp * localDW ) { dataAddr [ 0 ] = ( void * ) ( & localDW ->
nvp2xt1lh3 ) ; dataAddr [ 1 ] = ( void * ) ( & localDW -> fuowqjhyt4 ) ;
dataAddr [ 2 ] = ( void * ) ( & localDW -> lbrxbvl2dk ) ; }
#endif
#ifndef HOST_CAPI_BUILD
static void state_variables_InitializeVarDimsAddr ( int32_T * vardimsAddr [ ]
) { vardimsAddr [ 0 ] = ( NULL ) ; }
#endif
#ifndef HOST_CAPI_BUILD
static void state_variables_InitializeLoggingFunctions ( RTWLoggingFcnPtr
loggingPtrs [ ] ) { loggingPtrs [ 0 ] = ( NULL ) ; loggingPtrs [ 1 ] = ( NULL
) ; loggingPtrs [ 2 ] = ( NULL ) ; }
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } }
;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } } ; static uint_T rtDimensionArray [ ] = { 1 , 1
} ; static const real_T rtcapiStoredFloats [ ] = { 0.001 , 0.0 } ; static
rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , } ; static
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , ( int8_T ) 1 , ( uint8_T ) 0 } } ; static int_T rtContextSystems [ 2 ] ; static rtwCAPI_LoggingMetaInfo loggingMetaInfo [ ] = { { 0 , 0 , "" , 0 } } ; static rtwCAPI_ModelMapLoggingStaticInfo mmiStaticInfoLogging = { 2 , rtContextSystems , loggingMetaInfo , 0 , ( NULL ) , { 0 , ( NULL ) , ( NULL ) } , 0 , ( NULL ) } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 0 , ( NULL ) , 0 , ( NULL ) , 0 } , { ( NULL ) , 0 , ( NULL ) , 0 } , { rtBlockStates , 3 } , { rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float" , { 1112348415U , 1148312901U , 626812221U , 3084247911U } , & mmiStaticInfoLogging , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ; const rtwCAPI_ModelMappingStaticInfo * state_variables_GetCAPIStaticMap ( void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
static void state_variables_InitializeSystemRan ( pdplqnup32 * const
nf4xfde0xq , sysRanDType * systemRan [ ] , pvhntfwfsp * localDW , int_T
systemTid [ ] , void * rootSysRanPtr , int rootTid ) { UNUSED_PARAMETER ( nf4xfde0xq ) ; UNUSED_PARAMETER ( localDW ) ; systemRan [ 0 ] = ( sysRanDType * ) rootSysRanPtr ; systemRan [ 1 ] = ( NULL ) ; systemTid [ 1 ] = nf4xfde0xq -> Timing . mdlref_GlobalTID [ 0 ] ; systemTid [ 0 ] = rootTid ; rtContextSystems [ 0 ] = 0 ; rtContextSystems [ 1 ] = 0 ; }
#endif
#ifndef HOST_CAPI_BUILD
void state_variables_InitializeDataMapInfo ( pdplqnup32 * const nf4xfde0xq ,
pvhntfwfsp * localDW , void * sysRanPtr , int contextTid ) {
rtwCAPI_SetVersion ( nf4xfde0xq -> DataMapInfo . mmi , 1 ) ;
rtwCAPI_SetStaticMap ( nf4xfde0xq -> DataMapInfo . mmi , & mmiStatic ) ;
rtwCAPI_SetLoggingStaticMap ( nf4xfde0xq -> DataMapInfo . mmi , &
mmiStaticInfoLogging ) ; state_variables_InitializeDataAddr ( nf4xfde0xq ->
DataMapInfo . dataAddress , localDW ) ; rtwCAPI_SetDataAddressMap ( nf4xfde0xq
-> DataMapInfo . mmi , nf4xfde0xq -> DataMapInfo . dataAddress ) ;
state_variables_InitializeVarDimsAddr ( nf4xfde0xq -> DataMapInfo .
vardimsAddress ) ; rtwCAPI_SetVarDimsAddressMap ( nf4xfde0xq -> DataMapInfo .
mmi , nf4xfde0xq -> DataMapInfo . vardimsAddress ) ; rtwCAPI_SetPath ( nf4xfde0xq -> DataMapInfo . mmi , ( NULL ) ) ; rtwCAPI_SetFullPath ( nf4xfde0xq -> DataMapInfo . mmi , ( NULL ) ) ; state_variables_InitializeLoggingFunctions ( nf4xfde0xq -> DataMapInfo . loggingPtrs ) ; rtwCAPI_SetLoggingPtrs ( nf4xfde0xq -> DataMapInfo . mmi , nf4xfde0xq -> DataMapInfo . loggingPtrs ) ; rtwCAPI_SetInstanceLoggingInfo ( nf4xfde0xq -> DataMapInfo . mmi , & nf4xfde0xq -> DataMapInfo . mmiLogInstanceInfo ) ; rtwCAPI_SetChildMMIArray ( nf4xfde0xq -> DataMapInfo . mmi , nf4xfde0xq -> DataMapInfo . childMMI ) ; rtwCAPI_SetChildMMIArrayLen ( nf4xfde0xq -> DataMapInfo . mmi , 2 ) ; state_variables_InitializeSystemRan ( nf4xfde0xq , nf4xfde0xq -> DataMapInfo . systemRan , localDW , nf4xfde0xq -> DataMapInfo . systemTid , sysRanPtr , contextTid ) ; rtwCAPI_SetSystemRan ( nf4xfde0xq -> DataMapInfo . mmi , nf4xfde0xq -> DataMapInfo . systemRan ) ; rtwCAPI_SetSystemTid ( nf4xfde0xq -> DataMapInfo . mmi , nf4xfde0xq -> DataMapInfo . systemTid ) ; rtwCAPI_SetGlobalTIDMap ( nf4xfde0xq -> DataMapInfo . mmi , & nf4xfde0xq -> Timing . mdlref_GlobalTID [ 0 ] ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void state_variables_host_InitializeDataMapInfo ( state_variables_host_DataMapInfo_T * dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) ) ; rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ; rtwCAPI_SetPath ( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , ( NULL ) ) ; dataMap -> childMMI [ 0 ] = & ( dataMap -> child0 . mmi ) ; calcul_alpha_beta_gamma_v2_host_InitializeDataMapInfo ( & ( dataMap -> child0 ) , "state_variables/Model" ) ; dataMap -> childMMI [ 1 ] = & ( dataMap -> child1 . mmi ) ; calcul_vitesse_yawrate_host_InitializeDataMapInfo ( & ( dataMap -> child1 ) , "state_variables/Model1" ) ; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , dataMap -> childMMI ) ; rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 2 ) ; }
#ifdef __cplusplus
}
#endif
#endif
