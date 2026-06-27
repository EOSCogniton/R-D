#include "forces_aero.h"
#include "rtwtypes.h"
#include "forces_aero_private.h"
#include "forces_aero_capi.h"
static RegMdlInfo rtMdlInfo_forces_aero [ 40 ] = { { "gix3e13jsxw" ,
MDL_INFO_NAME_MDLREF_DWORK , 0 , - 1 , ( void * ) "forces_aero" } , {
"cxxpq2cvdw" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"forces_aero" } , { "pxvqgmy45j" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1
, ( void * ) "forces_aero" } , { "d23mg4l3hl" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "forces_aero" } , {
"grhetlt2rx" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"forces_aero" } , { "coay033qkz" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1
, ( void * ) "forces_aero" } , { "mxqbhhm1tc" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "forces_aero" } , {
"nkirvyevkr" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"forces_aero" } , { "bq5iv0tdnl" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1
, ( void * ) "forces_aero" } , { "dmydc0c5of" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "forces_aero" } , {
"lm0sbmlnzg" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"forces_aero" } , { "kuxy0vxc4x" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1
, ( void * ) "forces_aero" } , { "kfidil0vrx" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "forces_aero" } , {
"hdzujdgzdj" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"forces_aero" } , { "my3lfmo2lo" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1
, ( void * ) "forces_aero" } , { "mea4we2vim" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "forces_aero" } , {
"gfbfn4xdor" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"forces_aero" } , { "bndvzapxry" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1
, ( void * ) "forces_aero" } , { "b4osbtaao3" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "forces_aero" } , {
"opt3ozx2hn" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"forces_aero" } , { "lr5xg4mx33" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1
, ( void * ) "forces_aero" } , { "forces_aero" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , 0 , ( NULL ) } , { "eaplga10bl" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "forces_aero" } , {
"dxgthqwwn4k" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"forces_aero" } , { "nlvqana2u4" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1
, ( void * ) "forces_aero" } , { "muzbqn0dqg" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "forces_aero" } , {
"mr_forces_aero_GetSimStateDisallowedBlocks" , MDL_INFO_ID_MODEL_FCN_NAME , 0
, - 1 , ( void * ) "forces_aero" } , {
"mr_forces_aero_extractBitFieldFromCellArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "forces_aero" } , {
"mr_forces_aero_cacheBitFieldToCellArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "forces_aero" } , {
"mr_forces_aero_restoreDataFromMxArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "forces_aero" } , {
"mr_forces_aero_cacheDataToMxArrayWithOffset" , MDL_INFO_ID_MODEL_FCN_NAME ,
0 , - 1 , ( void * ) "forces_aero" } , {
"mr_forces_aero_extractBitFieldFromMxArray" , MDL_INFO_ID_MODEL_FCN_NAME , 0
, - 1 , ( void * ) "forces_aero" } , {
"mr_forces_aero_cacheBitFieldToMxArray" , MDL_INFO_ID_MODEL_FCN_NAME , 0 , -
1 , ( void * ) "forces_aero" } , { "mr_forces_aero_restoreDataFromMxArray" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "forces_aero" } , {
"mr_forces_aero_cacheDataAsMxArray" , MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 ,
( void * ) "forces_aero" } , { "mr_forces_aero_RegisterSimStateChecksum" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "forces_aero" } , {
"mr_forces_aero_SetDWork" , MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * )
"forces_aero" } , { "mr_forces_aero_GetDWork" , MDL_INFO_ID_MODEL_FCN_NAME ,
0 , - 1 , ( void * ) "forces_aero" } , { "forces_aero.h" ,
MDL_INFO_MODEL_FILENAME , 0 , - 1 , ( NULL ) } , { "forces_aero.c" ,
MDL_INFO_MODEL_FILENAME , 0 , - 1 , ( void * ) "forces_aero" } } ;
dxgthqwwn4k dxgthqwwn4 = { 0.5 } ; void forces_aero ( const real_T *
eitcfujc5p , real_T * ootlnjqmgf , real_T * budbzkw2fm , hdzujdgzdj * localB
) { real_T k4r1n13enr ; k4r1n13enr = * eitcfujc5p * * eitcfujc5p * localB ->
ktnfp1m5k4 ; * ootlnjqmgf = rtP_CL * k4r1n13enr ; * budbzkw2fm = k4r1n13enr *
rtP_CD ; } void forces_aeroTID1 ( hdzujdgzdj * localB ) { localB ->
ktnfp1m5k4 = rtP_A * dxgthqwwn4 . P_4 * rtP_rho ; } void mea4we2vim ( muzbqn0dqg
* const bdevpbo1dh ) { if ( ! slIsRapidAcceleratorSimulating ( ) ) {
slmrRunPluginEvent ( bdevpbo1dh -> _mdlRefSfcnS , "forces_aero" ,
"SIMSTATUS_TERMINATING_MODELREF_ACCEL_EVENT" ) ; } } void b4osbtaao3 ( SimStruct
* _mdlRefSfcnS , int_T mdlref_TID0 , int_T mdlref_TID1 , muzbqn0dqg * const
bdevpbo1dh , hdzujdgzdj * localB , void * sysRanPtr , int contextTid ,
rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T * rt_ChildPath , int_T
rt_ChildMMIIdx , int_T rt_CSTATEIdx ) { ( void ) memset ( ( void * )
bdevpbo1dh , 0 , sizeof ( muzbqn0dqg ) ) ; bdevpbo1dh -> Timing .
mdlref_GlobalTID [ 0 ] = mdlref_TID0 ; bdevpbo1dh -> Timing .
mdlref_GlobalTID [ 1 ] = mdlref_TID1 ; bdevpbo1dh -> _mdlRefSfcnS = ( _mdlRefSfcnS ) ; if ( ! slIsRapidAcceleratorSimulating ( ) ) { slmrRunPluginEvent ( bdevpbo1dh -> _mdlRefSfcnS , "forces_aero" , "START_OF_SIM_MODEL_MODELREF_ACCEL_EVENT" ) ; } { localB -> ktnfp1m5k4 = 0.0 ; } forces_aero_InitializeDataMapInfo ( bdevpbo1dh , sysRanPtr , contextTid ) ; if ( ( rt_ParentMMI != ( NULL ) ) && ( rt_ChildPath != ( NULL ) ) ) { rtwCAPI_SetChildMMI ( * rt_ParentMMI , rt_ChildMMIIdx , & ( bdevpbo1dh -> DataMapInfo . mmi ) ) ; rtwCAPI_SetPath ( bdevpbo1dh -> DataMapInfo . mmi , rt_ChildPath ) ; rtwCAPI_MMISetContStateStartIndex ( bdevpbo1dh -> DataMapInfo . mmi , rt_CSTATEIdx ) ; } } void mr_forces_aero_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T * modelName , int_T * retVal ) { * retVal = 0 ; { boolean_T regSubmodelsMdlinfo = false ; ssGetRegSubmodelsMdlinfo ( mdlRefSfcnS , & regSubmodelsMdlinfo ) ; if ( regSubmodelsMdlinfo ) { } } * retVal = 0 ; ssRegModelRefMdlInfo ( mdlRefSfcnS , modelName , rtMdlInfo_forces_aero , 40 ) ; * retVal = 1 ; } static void mr_forces_aero_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j , const void * srcData , size_t numBytes ) ; static void mr_forces_aero_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j , const void * srcData , size_t numBytes ) { mxArray * newArray = mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS , mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T * ) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray ) ; } static void mr_forces_aero_restoreDataFromMxArray ( void * destData , const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static void mr_forces_aero_restoreDataFromMxArray ( void * destData , const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( ( uint8_T * ) destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i , j ) ) , numBytes ) ; } static void mr_forces_aero_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int j , uint_T bitVal ) ; static void mr_forces_aero_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int j , uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j , mxCreateDoubleScalar ( ( real_T ) bitVal ) ) ; } static uint_T mr_forces_aero_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i , int j , uint_T numBits ) ; static uint_T mr_forces_aero_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T ) mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( ( 1u << numBits ) - 1u ) ; } static void mr_forces_aero_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex i , int j , mwIndex offset , const void * srcData , size_t numBytes ) ; static void mr_forces_aero_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex i , int j , mwIndex offset , const void * srcData , size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData ( mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData [ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static void mr_forces_aero_restoreDataFromMxArrayWithOffset ( void * destData , const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ; static void mr_forces_aero_restoreDataFromMxArrayWithOffset ( void * destData , const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData , ( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static void mr_forces_aero_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static void mr_forces_aero_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) { mxSetCell ( mxGetFieldByNumber ( destArray , i , j ) , offset , mxCreateDoubleScalar ( ( real_T ) fieldVal ) ) ; } static uint_T mr_forces_aero_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static uint_T mr_forces_aero_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) { const uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber ( srcArray , i , j ) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u ) ; } mxArray * mr_forces_aero_GetDWork ( const gix3e13jsxw * mdlrefDW ) { static const char_T * ssDWFieldNames [ 3 ] = { "rtb" , "NULL->rtdw" , "NULL->rtzce" , } ; mxArray * ssDW = mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ; mr_forces_aero_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & ( mdlrefDW -> rtb ) , sizeof ( mdlrefDW -> rtb ) ) ; ( void ) mdlrefDW ; return ssDW ; } void mr_forces_aero_SetDWork ( gix3e13jsxw * mdlrefDW , const mxArray * ssDW ) { ( void ) ssDW ; ( void ) mdlrefDW ; mr_forces_aero_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW -> rtb ) , ssDW , 0 , 0 , sizeof ( mdlrefDW -> rtb ) ) ; } void mr_forces_aero_RegisterSimStateChecksum ( SimStruct * S ) { const uint32_T chksum [ 4 ] = { 3236756561U , 2300960183U , 3129534411U , 1728958356U , } ; slmrModelRefRegisterSimStateChecksum ( S , "forces_aero" , & chksum [ 0 ] ) ; } mxArray * mr_forces_aero_GetSimStateDisallowedBlocks ( ) { return ( NULL ) ; }
#if defined(_MSC_VER)
#pragma warning(disable: 4505) //unreferenced local function has been removed
#endif
