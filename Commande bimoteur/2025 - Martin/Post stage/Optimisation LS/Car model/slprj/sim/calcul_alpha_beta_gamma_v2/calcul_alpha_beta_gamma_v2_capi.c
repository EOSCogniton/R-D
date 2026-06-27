#include <stddef.h>
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "calcul_alpha_beta_gamma_v2_capi_host.h"
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
#include "calcul_alpha_beta_gamma_v2.h"
#include "calcul_alpha_beta_gamma_v2_capi.h"
#include "calcul_alpha_beta_gamma_v2_private.h"
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
, ( NULL ) , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } } ;
static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static TARGET_CONST
rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "" , "" , 0 , 0 , 0 , 0 , 0 , 0 ,
0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 0 , 0 } } ; static uint_T rtDimensionArray [ ] = { 0 } ;
static rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , } ; static
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( NULL ) , ( NULL ) , 0 , 0 }
} ; static int_T rtContextSystems [ 5 ] ; static rtwCAPI_LoggingMetaInfo
loggingMetaInfo [ ] = { { 0 , 0 , "" , 0 } } ; static
rtwCAPI_ModelMapLoggingStaticInfo mmiStaticInfoLogging = { 5 ,
rtContextSystems , loggingMetaInfo , 0 , ( NULL ) , { 0 , ( NULL ) , ( NULL )
} , 0 , ( NULL ) } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { {
rtBlockSignals , 0 , ( NULL ) , 0 , ( NULL ) , 0 } , { ( NULL ) , 0 , ( NULL
) , 0 } , { rtBlockStates , 0 } , { rtDataTypeMap , rtDimensionMap ,
rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float" ,
{ 692749473U , 2426110636U , 2706050991U , 1763736035U } , &
mmiStaticInfoLogging , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ; const
rtwCAPI_ModelMappingStaticInfo * calcul_alpha_beta_gamma_v2_GetCAPIStaticMap
( void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
static void calcul_alpha_beta_gamma_v2_InitializeSystemRan ( cojrrv5v5s *
const ozcqrmeidr , sysRanDType * systemRan [ ] , int_T systemTid [ ] , void *
rootSysRanPtr , int rootTid ) { UNUSED_PARAMETER ( ozcqrmeidr ) ; systemRan [
0 ] = ( sysRanDType * ) rootSysRanPtr ; systemRan [ 1 ] = ( NULL ) ;
systemRan [ 2 ] = ( NULL ) ; systemRan [ 3 ] = ( NULL ) ; systemRan [ 4 ] = ( NULL ) ; systemTid [ 1 ] = ozcqrmeidr -> Timing . mdlref_GlobalTID [ 0 ] ; systemTid [ 2 ] = ozcqrmeidr -> Timing . mdlref_GlobalTID [ 0 ] ; systemTid [ 3 ] = ozcqrmeidr -> Timing . mdlref_GlobalTID [ 0 ] ; systemTid [ 4 ] = ozcqrmeidr -> Timing . mdlref_GlobalTID [ 0 ] ; systemTid [ 0 ] = rootTid ; rtContextSystems [ 0 ] = 0 ; rtContextSystems [ 1 ] = 0 ; rtContextSystems [ 2 ] = 0 ; rtContextSystems [ 3 ] = 0 ; rtContextSystems [ 4 ] = 0 ; }
#endif
#ifndef HOST_CAPI_BUILD
void calcul_alpha_beta_gamma_v2_InitializeDataMapInfo ( cojrrv5v5s * const
ozcqrmeidr , void * sysRanPtr , int contextTid ) { rtwCAPI_SetVersion ( ozcqrmeidr -> DataMapInfo . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ozcqrmeidr -> DataMapInfo . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ozcqrmeidr -> DataMapInfo . mmi , & mmiStaticInfoLogging ) ; rtwCAPI_SetPath ( ozcqrmeidr -> DataMapInfo . mmi , ( NULL ) ) ; rtwCAPI_SetFullPath ( ozcqrmeidr -> DataMapInfo . mmi , ( NULL ) ) ; rtwCAPI_SetInstanceLoggingInfo ( ozcqrmeidr -> DataMapInfo . mmi , & ozcqrmeidr -> DataMapInfo . mmiLogInstanceInfo ) ; rtwCAPI_SetChildMMIArray ( ozcqrmeidr -> DataMapInfo . mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen ( ozcqrmeidr -> DataMapInfo . mmi , 0 ) ; calcul_alpha_beta_gamma_v2_InitializeSystemRan ( ozcqrmeidr , ozcqrmeidr -> DataMapInfo . systemRan , ozcqrmeidr -> DataMapInfo . systemTid , sysRanPtr , contextTid ) ; rtwCAPI_SetSystemRan ( ozcqrmeidr -> DataMapInfo . mmi , ozcqrmeidr -> DataMapInfo . systemRan ) ; rtwCAPI_SetSystemTid ( ozcqrmeidr -> DataMapInfo . mmi , ozcqrmeidr -> DataMapInfo . systemTid ) ; rtwCAPI_SetGlobalTIDMap ( ozcqrmeidr -> DataMapInfo . mmi , & ozcqrmeidr -> Timing . mdlref_GlobalTID [ 0 ] ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void calcul_alpha_beta_gamma_v2_host_InitializeDataMapInfo ( calcul_alpha_beta_gamma_v2_host_DataMapInfo_T * dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) ) ; rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ; rtwCAPI_SetPath ( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
