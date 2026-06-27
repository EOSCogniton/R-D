#include "calcul_alpha_beta_gamma_v2.h"
#include "rtwtypes.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include "calcul_alpha_beta_gamma_v2_capi.h"
#include "calcul_alpha_beta_gamma_v2_private.h"
static RegMdlInfo rtMdlInfo_calcul_alpha_beta_gamma_v2 [ 41 ] = { {
"cbbpcstriyq" , MDL_INFO_NAME_MDLREF_DWORK , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , { "g3ucbicxnb" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , { "n3vjudvzyc" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , { "podfchc5cb" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , { "iefbdk2alu" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , { "kdxf5ll1mf" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , { "o2aquuuy3q" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , { "jmw3za0kul" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , { "crjsbcogww" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , { "hzzzi3lnqq" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , { "on3bxv2dk5" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , { "m0wbkkgje4" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , { "drymg1ytwr" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , { "ivtm4j0qw4" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , { "lpfq4pqm4p" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , { "ph0uk5pae2" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , { "b2j2wnfvkh" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , { "jxb34u2e3j" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , { "gou3jzgyr2" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , { "lfcl4oswx4" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , { "mszfgk4wtk" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , { "egpftz0x1o" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , { "calcul_alpha_beta_gamma_v2" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , 0 , ( NULL ) } , { "jyv5wdooar" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , { "kui1nb4axka" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , { "hjkmg00bse" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , { "cojrrv5v5s" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , {
"mr_calcul_alpha_beta_gamma_v2_GetSimStateDisallowedBlocks" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , {
"mr_calcul_alpha_beta_gamma_v2_extractBitFieldFromCellArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , {
"mr_calcul_alpha_beta_gamma_v2_cacheBitFieldToCellArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , {
"mr_calcul_alpha_beta_gamma_v2_restoreDataFromMxArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , {
"mr_calcul_alpha_beta_gamma_v2_cacheDataToMxArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , {
"mr_calcul_alpha_beta_gamma_v2_extractBitFieldFromMxArray" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , {
"mr_calcul_alpha_beta_gamma_v2_cacheBitFieldToMxArray" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , {
"mr_calcul_alpha_beta_gamma_v2_restoreDataFromMxArray" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , {
"mr_calcul_alpha_beta_gamma_v2_cacheDataAsMxArray" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , {
"mr_calcul_alpha_beta_gamma_v2_RegisterSimStateChecksum" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , { "mr_calcul_alpha_beta_gamma_v2_SetDWork" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , { "mr_calcul_alpha_beta_gamma_v2_GetDWork" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * )
"calcul_alpha_beta_gamma_v2" } , { "calcul_alpha_beta_gamma_v2.h" ,
MDL_INFO_MODEL_FILENAME , 0 , - 1 , ( NULL ) } , {
"calcul_alpha_beta_gamma_v2.c" , MDL_INFO_MODEL_FILENAME , 0 , - 1 , ( void *
) "calcul_alpha_beta_gamma_v2" } } ; void calcul_alpha_beta_gamma_v2 ( const
real_T mnu302hrdt [ 4 ] , const real_T h31vqbczrg [ 4 ] , const real_T *
pxthgweylw , real_T * mllxosbukp , real_T * ewevvbrhys , real_T * hp00kkeexa
) { __m128d tmp_g ; __m128d tmp_i ; __m128d tmp_m ; real_T tmp_e [ 2 ] ;
real_T tmp ; real_T tmp_p ; tmp = muDoubleScalarCos ( * pxthgweylw ) ; tmp_p
= muDoubleScalarSin ( * pxthgweylw ) ; tmp_i = _mm_set_pd ( tmp_p , tmp ) ;
tmp_m = _mm_set_pd ( tmp , tmp_p ) ; tmp_g = _mm_set_pd ( 1.0 , - 1.0 ) ;
_mm_storeu_pd ( & tmp_e [ 0 ] , _mm_add_pd ( _mm_add_pd ( _mm_add_pd ( _mm_add_pd ( _mm_add_pd ( _mm_mul_pd ( _mm_set1_pd ( h31vqbczrg [ 2 ] ) , tmp_i ) , _mm_mul_pd ( _mm_mul_pd ( _mm_set1_pd ( mnu302hrdt [ 2 ] ) , tmp_m ) , tmp_g ) ) , _mm_mul_pd ( _mm_set1_pd ( h31vqbczrg [ 3 ] ) , tmp_i ) ) , _mm_mul_pd ( _mm_mul_pd ( _mm_set1_pd ( mnu302hrdt [ 3 ] ) , tmp_m ) , tmp_g ) ) , _mm_set_pd ( mnu302hrdt [ 0 ] , h31vqbczrg [ 0 ] ) ) , _mm_set_pd ( mnu302hrdt [ 1 ] , h31vqbczrg [ 1 ] ) ) ) ; * mllxosbukp = tmp_e [ 0 ] ; * ewevvbrhys = tmp_e [ 1 ] ; * hp00kkeexa = ( ( ( ( ( h31vqbczrg [ 2 ] * tmp_p + h31vqbczrg [ 3 ] * tmp_p ) + mnu302hrdt [ 2 ] * tmp ) + mnu302hrdt [ 3 ] * tmp ) * rtP_lf + ( ( ( - h31vqbczrg [ 2 ] * tmp + h31vqbczrg [ 3 ] * tmp ) + mnu302hrdt [ 2 ] * tmp_p ) - mnu302hrdt [ 3 ] * tmp_p ) * ( rtP_t / 2.0 ) ) - ( mnu302hrdt [ 0 ] + mnu302hrdt [ 1 ] ) * rtP_lr ) - rtP_t / 2.0 * ( h31vqbczrg [ 0 ] - h31vqbczrg [ 1 ] ) ; } void ph0uk5pae2 ( cojrrv5v5s * const ozcqrmeidr ) { if ( ! slIsRapidAcceleratorSimulating ( ) ) { slmrRunPluginEvent ( ozcqrmeidr -> _mdlRefSfcnS , "calcul_alpha_beta_gamma_v2" , "SIMSTATUS_TERMINATING_MODELREF_ACCEL_EVENT" ) ; } } void lfcl4oswx4 ( SimStruct * _mdlRefSfcnS , int_T mdlref_TID0 , int_T mdlref_TID1 , cojrrv5v5s * const ozcqrmeidr , void * sysRanPtr , int contextTid , rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T * rt_ChildPath , int_T rt_ChildMMIIdx , int_T rt_CSTATEIdx ) { ( void ) memset ( ( void * ) ozcqrmeidr , 0 , sizeof ( cojrrv5v5s ) ) ; ozcqrmeidr -> Timing . mdlref_GlobalTID [ 0 ] = mdlref_TID0 ; ozcqrmeidr -> Timing . mdlref_GlobalTID [ 1 ] = mdlref_TID1 ; ozcqrmeidr -> _mdlRefSfcnS = ( _mdlRefSfcnS ) ; if ( ! slIsRapidAcceleratorSimulating ( ) ) { slmrRunPluginEvent ( ozcqrmeidr -> _mdlRefSfcnS , "calcul_alpha_beta_gamma_v2" , "START_OF_SIM_MODEL_MODELREF_ACCEL_EVENT" ) ; } calcul_alpha_beta_gamma_v2_InitializeDataMapInfo ( ozcqrmeidr , sysRanPtr , contextTid ) ; if ( ( rt_ParentMMI != ( NULL ) ) && ( rt_ChildPath != ( NULL ) ) ) { rtwCAPI_SetChildMMI ( * rt_ParentMMI , rt_ChildMMIIdx , & ( ozcqrmeidr -> DataMapInfo . mmi ) ) ; rtwCAPI_SetPath ( ozcqrmeidr -> DataMapInfo . mmi , rt_ChildPath ) ; rtwCAPI_MMISetContStateStartIndex ( ozcqrmeidr -> DataMapInfo . mmi , rt_CSTATEIdx ) ; } } void mr_calcul_alpha_beta_gamma_v2_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T * modelName , int_T * retVal ) { * retVal = 0 ; { boolean_T regSubmodelsMdlinfo = false ; ssGetRegSubmodelsMdlinfo ( mdlRefSfcnS , & regSubmodelsMdlinfo ) ; if ( regSubmodelsMdlinfo ) { } } * retVal = 0 ; ssRegModelRefMdlInfo ( mdlRefSfcnS , modelName , rtMdlInfo_calcul_alpha_beta_gamma_v2 , 41 ) ; * retVal = 1 ; } static void mr_calcul_alpha_beta_gamma_v2_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j , const void * srcData , size_t numBytes ) ; static void mr_calcul_alpha_beta_gamma_v2_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j , const void * srcData , size_t numBytes ) { mxArray * newArray = mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS , mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T * ) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray ) ; } static void mr_calcul_alpha_beta_gamma_v2_restoreDataFromMxArray ( void * destData , const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static void mr_calcul_alpha_beta_gamma_v2_restoreDataFromMxArray ( void * destData , const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( ( uint8_T * ) destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i , j ) ) , numBytes ) ; } static void mr_calcul_alpha_beta_gamma_v2_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int j , uint_T bitVal ) ; static void mr_calcul_alpha_beta_gamma_v2_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int j , uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j , mxCreateDoubleScalar ( ( real_T ) bitVal ) ) ; } static uint_T mr_calcul_alpha_beta_gamma_v2_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i , int j , uint_T numBits ) ; static uint_T mr_calcul_alpha_beta_gamma_v2_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T ) mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( ( 1u << numBits ) - 1u ) ; } static void mr_calcul_alpha_beta_gamma_v2_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex i , int j , mwIndex offset , const void * srcData , size_t numBytes ) ; static void mr_calcul_alpha_beta_gamma_v2_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex i , int j , mwIndex offset , const void * srcData , size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData ( mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData [ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static void mr_calcul_alpha_beta_gamma_v2_restoreDataFromMxArrayWithOffset ( void * destData , const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ; static void mr_calcul_alpha_beta_gamma_v2_restoreDataFromMxArrayWithOffset ( void * destData , const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData , ( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static void mr_calcul_alpha_beta_gamma_v2_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static void mr_calcul_alpha_beta_gamma_v2_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) { mxSetCell ( mxGetFieldByNumber ( destArray , i , j ) , offset , mxCreateDoubleScalar ( ( real_T ) fieldVal ) ) ; } static uint_T mr_calcul_alpha_beta_gamma_v2_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static uint_T mr_calcul_alpha_beta_gamma_v2_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) { const uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber ( srcArray , i , j ) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u ) ; } mxArray * mr_calcul_alpha_beta_gamma_v2_GetDWork ( const cbbpcstriyq * mdlrefDW ) { ( void ) mdlrefDW ; return ( NULL ) ; } void mr_calcul_alpha_beta_gamma_v2_SetDWork ( cbbpcstriyq * mdlrefDW , const mxArray * ssDW ) { ( void ) ssDW ; ( void ) mdlrefDW ; } void mr_calcul_alpha_beta_gamma_v2_RegisterSimStateChecksum ( SimStruct * S ) { const uint32_T chksum [ 4 ] = { 307599261U , 328317971U , 1452451475U , 2720093792U , } ; slmrModelRefRegisterSimStateChecksum ( S , "calcul_alpha_beta_gamma_v2" , & chksum [ 0 ] ) ; } mxArray * mr_calcul_alpha_beta_gamma_v2_GetSimStateDisallowedBlocks ( ) { return ( NULL ) ; }
#if defined(_MSC_VER)
#pragma warning(disable: 4505) //unreferenced local function has been removed
#endif
