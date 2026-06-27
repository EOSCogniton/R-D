#include "calcul_vitesse_yawrate.h"
#include "rtwtypes.h"
#include "calcul_vitesse_yawrate_private.h"
#include "calcul_vitesse_yawrate_capi.h"
static RegMdlInfo rtMdlInfo_calcul_vitesse_yawrate [ 42 ] = { { "ae1yjtrwpfr"
, MDL_INFO_NAME_MDLREF_DWORK , 0 , - 1 , ( void * ) "calcul_vitesse_yawrate"
} , { "obn50b0iqc" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_vitesse_yawrate" } , { "hxf2g0xoxd" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_vitesse_yawrate" } , { "bpxv40t0ea" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_vitesse_yawrate" } , { "aabkk2wpo2" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_vitesse_yawrate" } , { "fkoibwxiri" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_vitesse_yawrate" } , { "jmxktsuefc" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_vitesse_yawrate" } , { "go5kwkhplm" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_vitesse_yawrate" } , { "dwujmxxrw2" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_vitesse_yawrate" } , { "bxbs1tvas4" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_vitesse_yawrate" } , { "ps4yyoquny" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_vitesse_yawrate" } , { "cexlfvcojl" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_vitesse_yawrate" } , { "dihilfmdpe" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_vitesse_yawrate" } , { "kdomceyykj" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_vitesse_yawrate" } , { "j5wk5skfqt" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_vitesse_yawrate" } , { "kwjyg1mjo3" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_vitesse_yawrate" } , { "oi1cdlgda3" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_vitesse_yawrate" } , { "bxhbbgv4j2" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_vitesse_yawrate" } , { "eoicgzqlle" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_vitesse_yawrate" } , { "m5x0o1ug2l" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_vitesse_yawrate" } , { "hfekmzu4zr" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_vitesse_yawrate" } , { "h43vbf3hwp" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_vitesse_yawrate" } , { "icnl0qfcgc" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_vitesse_yawrate" } , { "calcul_vitesse_yawrate" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , 0 , ( NULL ) } , { "ep1kb4tr0b" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_vitesse_yawrate" } , { "m4bxcs41zwq" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_vitesse_yawrate" } , { "cv1bir1gyq" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_vitesse_yawrate" } , { "fqqiewyclh" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_vitesse_yawrate" } , {
"mr_calcul_vitesse_yawrate_GetSimStateDisallowedBlocks" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "calcul_vitesse_yawrate" }
, { "mr_calcul_vitesse_yawrate_extractBitFieldFromCellArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "calcul_vitesse_yawrate" }
, { "mr_calcul_vitesse_yawrate_cacheBitFieldToCellArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "calcul_vitesse_yawrate" }
, { "mr_calcul_vitesse_yawrate_restoreDataFromMxArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "calcul_vitesse_yawrate" }
, { "mr_calcul_vitesse_yawrate_cacheDataToMxArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "calcul_vitesse_yawrate" }
, { "mr_calcul_vitesse_yawrate_extractBitFieldFromMxArray" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "calcul_vitesse_yawrate" }
, { "mr_calcul_vitesse_yawrate_cacheBitFieldToMxArray" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "calcul_vitesse_yawrate" }
, { "mr_calcul_vitesse_yawrate_restoreDataFromMxArray" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "calcul_vitesse_yawrate" }
, { "mr_calcul_vitesse_yawrate_cacheDataAsMxArray" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "calcul_vitesse_yawrate" }
, { "mr_calcul_vitesse_yawrate_RegisterSimStateChecksum" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "calcul_vitesse_yawrate" }
, { "mr_calcul_vitesse_yawrate_SetDWork" , MDL_INFO_ID_MODEL_FCN_NAME , 0 , -
1 , ( void * ) "calcul_vitesse_yawrate" } , {
"mr_calcul_vitesse_yawrate_GetDWork" , MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 ,
( void * ) "calcul_vitesse_yawrate" } , { "calcul_vitesse_yawrate.h" ,
MDL_INFO_MODEL_FILENAME , 0 , - 1 , ( NULL ) } , { "calcul_vitesse_yawrate.c"
, MDL_INFO_MODEL_FILENAME , 0 , - 1 , ( void * ) "calcul_vitesse_yawrate" } }
; m4bxcs41zwq m4bxcs41zw = { 0.0 , 0.0 } ; void m5x0o1ug2l ( dihilfmdpe *
localDW ) { localDW -> p3vt5eqsli = m4bxcs41zw . P_4 ; localDW -> hwyn4wrt55
= m4bxcs41zw . P_5 ; localDW -> jm3pyr5zsn = rtP_v0 ; } void eoicgzqlle ( dihilfmdpe * localDW ) { localDW -> p3vt5eqsli = m4bxcs41zw . P_4 ; localDW -> hwyn4wrt55 = m4bxcs41zw . P_5 ; localDW -> jm3pyr5zsn = rtP_v0 ; } void calcul_vitesse_yawrate ( const real_T * ckwrzk5mdl , const real_T * cfrsahjtnl , const real_T * bm02ej3k54 , real_T * afn1olkb2o , real_T * pkqbd2kwgr , real_T * frrxr0frih , dihilfmdpe * localDW ) { real_T tmp ; * frrxr0frih = rtP_Ts / rtP_Izz * * bm02ej3k54 + localDW -> p3vt5eqsli ; tmp = rtP_Ts / rtP_m ; * afn1olkb2o = ( localDW -> p3vt5eqsli * localDW -> hwyn4wrt55 * rtP_Ts + tmp * * ckwrzk5mdl ) + localDW -> jm3pyr5zsn ; * pkqbd2kwgr = ( tmp * * cfrsahjtnl - localDW -> p3vt5eqsli * localDW -> jm3pyr5zsn * rtP_Ts ) + localDW -> hwyn4wrt55 ; } void bxhbbgv4j2 ( real_T * afn1olkb2o , real_T * pkqbd2kwgr , real_T * frrxr0frih , dihilfmdpe * localDW ) { localDW -> p3vt5eqsli = * frrxr0frih ; localDW -> hwyn4wrt55 = * pkqbd2kwgr ; localDW -> jm3pyr5zsn = * afn1olkb2o ; } void kwjyg1mjo3 ( fqqiewyclh * const hfgf31v1sn ) { if ( ! slIsRapidAcceleratorSimulating ( ) ) { slmrRunPluginEvent ( hfgf31v1sn -> _mdlRefSfcnS , "calcul_vitesse_yawrate" , "SIMSTATUS_TERMINATING_MODELREF_ACCEL_EVENT" ) ; } } void hfekmzu4zr ( SimStruct * _mdlRefSfcnS , int_T mdlref_TID0 , fqqiewyclh * const hfgf31v1sn , dihilfmdpe * localDW , void * sysRanPtr , int contextTid , rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T * rt_ChildPath , int_T rt_ChildMMIIdx , int_T rt_CSTATEIdx ) { ( void ) memset ( ( void * ) hfgf31v1sn , 0 , sizeof ( fqqiewyclh ) ) ; hfgf31v1sn -> Timing . mdlref_GlobalTID [ 0 ] = mdlref_TID0 ; hfgf31v1sn -> _mdlRefSfcnS = ( _mdlRefSfcnS ) ; if ( ! slIsRapidAcceleratorSimulating ( ) ) { slmrRunPluginEvent ( hfgf31v1sn -> _mdlRefSfcnS , "calcul_vitesse_yawrate" , "START_OF_SIM_MODEL_MODELREF_ACCEL_EVENT" ) ; } localDW -> p3vt5eqsli = 0.0 ; localDW -> hwyn4wrt55 = 0.0 ; localDW -> jm3pyr5zsn = 0.0 ; calcul_vitesse_yawrate_InitializeDataMapInfo ( hfgf31v1sn , localDW , sysRanPtr , contextTid ) ; if ( ( rt_ParentMMI != ( NULL ) ) && ( rt_ChildPath != ( NULL ) ) ) { rtwCAPI_SetChildMMI ( * rt_ParentMMI , rt_ChildMMIIdx , & ( hfgf31v1sn -> DataMapInfo . mmi ) ) ; rtwCAPI_SetPath ( hfgf31v1sn -> DataMapInfo . mmi , rt_ChildPath ) ; rtwCAPI_MMISetContStateStartIndex ( hfgf31v1sn -> DataMapInfo . mmi , rt_CSTATEIdx ) ; } } void mr_calcul_vitesse_yawrate_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T * modelName , int_T * retVal ) { * retVal = 0 ; { boolean_T regSubmodelsMdlinfo = false ; ssGetRegSubmodelsMdlinfo ( mdlRefSfcnS , & regSubmodelsMdlinfo ) ; if ( regSubmodelsMdlinfo ) { } } * retVal = 0 ; ssRegModelRefMdlInfo ( mdlRefSfcnS , modelName , rtMdlInfo_calcul_vitesse_yawrate , 42 ) ; * retVal = 1 ; } static void mr_calcul_vitesse_yawrate_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j , const void * srcData , size_t numBytes ) ; static void mr_calcul_vitesse_yawrate_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j , const void * srcData , size_t numBytes ) { mxArray * newArray = mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS , mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T * ) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray ) ; } static void mr_calcul_vitesse_yawrate_restoreDataFromMxArray ( void * destData , const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static void mr_calcul_vitesse_yawrate_restoreDataFromMxArray ( void * destData , const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( ( uint8_T * ) destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i , j ) ) , numBytes ) ; } static void mr_calcul_vitesse_yawrate_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int j , uint_T bitVal ) ; static void mr_calcul_vitesse_yawrate_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int j , uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j , mxCreateDoubleScalar ( ( real_T ) bitVal ) ) ; } static uint_T mr_calcul_vitesse_yawrate_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i , int j , uint_T numBits ) ; static uint_T mr_calcul_vitesse_yawrate_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T ) mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( ( 1u << numBits ) - 1u ) ; } static void mr_calcul_vitesse_yawrate_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex i , int j , mwIndex offset , const void * srcData , size_t numBytes ) ; static void mr_calcul_vitesse_yawrate_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex i , int j , mwIndex offset , const void * srcData , size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData ( mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData [ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static void mr_calcul_vitesse_yawrate_restoreDataFromMxArrayWithOffset ( void * destData , const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ; static void mr_calcul_vitesse_yawrate_restoreDataFromMxArrayWithOffset ( void * destData , const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData , ( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static void mr_calcul_vitesse_yawrate_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static void mr_calcul_vitesse_yawrate_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) { mxSetCell ( mxGetFieldByNumber ( destArray , i , j ) , offset , mxCreateDoubleScalar ( ( real_T ) fieldVal ) ) ; } static uint_T mr_calcul_vitesse_yawrate_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static uint_T mr_calcul_vitesse_yawrate_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) { const uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber ( srcArray , i , j ) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u ) ; } mxArray * mr_calcul_vitesse_yawrate_GetDWork ( const ae1yjtrwpfr * mdlrefDW ) { static const char_T * ssDWFieldNames [ 3 ] = { "NULL->rtb" , "rtdw" , "NULL->rtzce" , } ; mxArray * ssDW = mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ; { static const char_T * rtdwDataFieldNames [ 3 ] = { "mdlrefDW->rtdw.p3vt5eqsli" , "mdlrefDW->rtdw.hwyn4wrt55" , "mdlrefDW->rtdw.jm3pyr5zsn" , } ; mxArray * rtdwData = mxCreateStructMatrix ( 1 , 1 , 3 , rtdwDataFieldNames ) ; mr_calcul_vitesse_yawrate_cacheDataAsMxArray ( rtdwData , 0 , 0 , ( const void * ) & ( mdlrefDW -> rtdw . p3vt5eqsli ) , sizeof ( mdlrefDW -> rtdw . p3vt5eqsli ) ) ; mr_calcul_vitesse_yawrate_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const void * ) & ( mdlrefDW -> rtdw . hwyn4wrt55 ) , sizeof ( mdlrefDW -> rtdw . hwyn4wrt55 ) ) ; mr_calcul_vitesse_yawrate_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * ) & ( mdlrefDW -> rtdw . jm3pyr5zsn ) , sizeof ( mdlrefDW -> rtdw . jm3pyr5zsn ) ) ; mxSetFieldByNumber ( ssDW , 0 , 1 , rtdwData ) ; } ( void ) mdlrefDW ; return ssDW ; } void mr_calcul_vitesse_yawrate_SetDWork ( ae1yjtrwpfr * mdlrefDW , const mxArray * ssDW ) { ( void ) ssDW ; ( void ) mdlrefDW ; { const mxArray * rtdwData = mxGetFieldByNumber ( ssDW , 0 , 1 ) ; mr_calcul_vitesse_yawrate_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW -> rtdw . p3vt5eqsli ) , rtdwData , 0 , 0 , sizeof ( mdlrefDW -> rtdw . p3vt5eqsli ) ) ; mr_calcul_vitesse_yawrate_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW -> rtdw . hwyn4wrt55 ) , rtdwData , 0 , 1 , sizeof ( mdlrefDW -> rtdw . hwyn4wrt55 ) ) ; mr_calcul_vitesse_yawrate_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW -> rtdw . jm3pyr5zsn ) , rtdwData , 0 , 2 , sizeof ( mdlrefDW -> rtdw . jm3pyr5zsn ) ) ; } } void mr_calcul_vitesse_yawrate_RegisterSimStateChecksum ( SimStruct * S ) { const uint32_T chksum [ 4 ] = { 1608133889U , 4259910782U , 565238543U , 98080535U , } ; slmrModelRefRegisterSimStateChecksum ( S , "calcul_vitesse_yawrate" , & chksum [ 0 ] ) ; } mxArray * mr_calcul_vitesse_yawrate_GetSimStateDisallowedBlocks ( ) { return ( NULL ) ; }
#if defined(_MSC_VER)
#pragma warning(disable: 4505) //unreferenced local function has been removed
#endif
