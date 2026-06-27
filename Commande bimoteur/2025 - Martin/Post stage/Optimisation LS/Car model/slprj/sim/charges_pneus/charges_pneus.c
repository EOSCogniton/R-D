#include "charges_pneus.h"
#include "rtwtypes.h"
#include "charges_pneus_private.h"
#include "charges_pneus_capi.h"
static RegMdlInfo rtMdlInfo_charges_pneus [ 41 ] = { { "hh3lbtsamd0" ,
MDL_INFO_NAME_MDLREF_DWORK , 0 , - 1 , ( void * ) "charges_pneus" } , {
"ciiz2e1tju" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"charges_pneus" } , { "duikuvmjwg" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "charges_pneus" } , { "idnk5xvs1d" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "charges_pneus" } , {
"kb35r3mjr0" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"charges_pneus" } , { "pawvspnf31" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "charges_pneus" } , { "fj0b1ls4p0" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "charges_pneus" } , {
"j1kgpgxjew" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"charges_pneus" } , { "f50je4onb3" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "charges_pneus" } , { "jhostgkcm1" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "charges_pneus" } , {
"f3bybe21cp" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"charges_pneus" } , { "duiip2u4ol" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "charges_pneus" } , { "drsoqp3wav" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "charges_pneus" } , {
"afbpp532k5" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"charges_pneus" } , { "ermvc05p1r" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "charges_pneus" } , { "eskogmxsu3" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "charges_pneus" } , {
"mvz1oqyzfj" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"charges_pneus" } , { "dtlzhukfy0" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "charges_pneus" } , { "ppjhqewvq1" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "charges_pneus" } , {
"ljbzawgrsu" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"charges_pneus" } , { "lcsazj2bzu" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "charges_pneus" } , { "pfdjrqlsmd" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "charges_pneus" } , {
"charges_pneus" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , 0 , ( NULL ) } , {
"gbd4lzu0nh" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"charges_pneus" } , { "p2vyvyihr5t" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 ,
- 1 , ( void * ) "charges_pneus" } , { "onp3o0ajov" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "charges_pneus" } , {
"c4bom0vtk3" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"charges_pneus" } , { "mr_charges_pneus_GetSimStateDisallowedBlocks" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "charges_pneus" } , {
"mr_charges_pneus_extractBitFieldFromCellArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "charges_pneus" } , {
"mr_charges_pneus_cacheBitFieldToCellArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "charges_pneus" } , {
"mr_charges_pneus_restoreDataFromMxArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "charges_pneus" } , {
"mr_charges_pneus_cacheDataToMxArrayWithOffset" , MDL_INFO_ID_MODEL_FCN_NAME
, 0 , - 1 , ( void * ) "charges_pneus" } , {
"mr_charges_pneus_extractBitFieldFromMxArray" , MDL_INFO_ID_MODEL_FCN_NAME ,
0 , - 1 , ( void * ) "charges_pneus" } , {
"mr_charges_pneus_cacheBitFieldToMxArray" , MDL_INFO_ID_MODEL_FCN_NAME , 0 ,
- 1 , ( void * ) "charges_pneus" } , {
"mr_charges_pneus_restoreDataFromMxArray" , MDL_INFO_ID_MODEL_FCN_NAME , 0 ,
- 1 , ( void * ) "charges_pneus" } , { "mr_charges_pneus_cacheDataAsMxArray"
, MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "charges_pneus" } , {
"mr_charges_pneus_RegisterSimStateChecksum" , MDL_INFO_ID_MODEL_FCN_NAME , 0
, - 1 , ( void * ) "charges_pneus" } , { "mr_charges_pneus_SetDWork" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "charges_pneus" } , {
"mr_charges_pneus_GetDWork" , MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void *
) "charges_pneus" } , { "charges_pneus.h" , MDL_INFO_MODEL_FILENAME , 0 , - 1
, ( NULL ) } , { "charges_pneus.c" , MDL_INFO_MODEL_FILENAME , 0 , - 1 , ( void
* ) "charges_pneus" } } ; p2vyvyihr5t p2vyvyihr5 = { 0.25 , 0.5 , 0.5 , 30.0
, 0.5 } ; void charges_pneus ( const real_T * pyuckoipxv , const real_T *
dapo0iwrgf , const real_T * mzlmpncwcl , real_T lbzbraaxae [ 4 ] , afbpp532k5
* localB ) { real_T memxvz1igr ; real_T oougdnedt4 ; real_T pj0b3uivht ;
real_T tmp ; real_T u0 ; real_T u0_tmp ; pj0b3uivht = p2vyvyihr5 . P_6 * *
mzlmpncwcl ; memxvz1igr = 1.0 / rtP_L * * pyuckoipxv * localB -> hqmzso3n00 *
p2vyvyihr5 . P_7 ; oougdnedt4 = 1.0 / rtP_t * * dapo0iwrgf * localB ->
hqmzso3n00 * p2vyvyihr5 . P_8 ; tmp = rtP_m * rtP_g ; u0_tmp = localB ->
kxa5aikbeb + memxvz1igr ; u0 = ( u0_tmp - oougdnedt4 ) + pj0b3uivht ; if ( u0
> tmp ) { lbzbraaxae [ 0 ] = tmp ; } else if ( u0 < p2vyvyihr5 . P_9 ) {
lbzbraaxae [ 0 ] = p2vyvyihr5 . P_9 ; } else { lbzbraaxae [ 0 ] = u0 ; } u0 =
( u0_tmp + oougdnedt4 ) + pj0b3uivht ; if ( u0 > tmp ) { lbzbraaxae [ 1 ] =
tmp ; } else if ( u0 < p2vyvyihr5 . P_9 ) { lbzbraaxae [ 1 ] = p2vyvyihr5 .
P_9 ; } else { lbzbraaxae [ 1 ] = u0 ; } u0_tmp = localB -> jibcgank3u -
memxvz1igr ; u0 = ( u0_tmp - oougdnedt4 ) + pj0b3uivht ; if ( u0 > tmp ) {
lbzbraaxae [ 2 ] = tmp ; } else if ( u0 < p2vyvyihr5 . P_9 ) { lbzbraaxae [ 2
] = p2vyvyihr5 . P_9 ; } else { lbzbraaxae [ 2 ] = u0 ; } u0 = ( u0_tmp +
oougdnedt4 ) + pj0b3uivht ; if ( u0 > tmp ) { lbzbraaxae [ 3 ] = tmp ; } else
if ( u0 < p2vyvyihr5 . P_9 ) { lbzbraaxae [ 3 ] = p2vyvyihr5 . P_9 ; } else {
lbzbraaxae [ 3 ] = u0 ; } } void charges_pneusTID1 ( afbpp532k5 * localB ) {
real_T hzsjnet2x5 ; hzsjnet2x5 = rtP_m * rtP_g * p2vyvyihr5 . P_10 ; localB
-> jibcgank3u = ( 1.0 - rtP_fr ) * hzsjnet2x5 ; localB -> kxa5aikbeb = rtP_fr
* hzsjnet2x5 ; localB -> hqmzso3n00 = rtP_h * rtP_m ; } void eskogmxsu3 ( c4bom0vtk3 * const jb0umhodle ) { if ( ! slIsRapidAcceleratorSimulating ( ) ) { slmrRunPluginEvent ( jb0umhodle -> _mdlRefSfcnS , "charges_pneus" , "SIMSTATUS_TERMINATING_MODELREF_ACCEL_EVENT" ) ; } } void ljbzawgrsu ( SimStruct * _mdlRefSfcnS , int_T mdlref_TID0 , int_T mdlref_TID1 , c4bom0vtk3 * const jb0umhodle , afbpp532k5 * localB , void * sysRanPtr , int contextTid , rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T * rt_ChildPath , int_T rt_ChildMMIIdx , int_T rt_CSTATEIdx ) { ( void ) memset ( ( void * ) jb0umhodle , 0 , sizeof ( c4bom0vtk3 ) ) ; jb0umhodle -> Timing . mdlref_GlobalTID [ 0 ] = mdlref_TID0 ; jb0umhodle -> Timing . mdlref_GlobalTID [ 1 ] = mdlref_TID1 ; jb0umhodle -> _mdlRefSfcnS = ( _mdlRefSfcnS ) ; if ( ! slIsRapidAcceleratorSimulating ( ) ) { slmrRunPluginEvent ( jb0umhodle -> _mdlRefSfcnS , "charges_pneus" , "START_OF_SIM_MODEL_MODELREF_ACCEL_EVENT" ) ; } { localB -> jibcgank3u = 0.0 ; localB -> kxa5aikbeb = 0.0 ; localB -> hqmzso3n00 = 0.0 ; } charges_pneus_InitializeDataMapInfo ( jb0umhodle , sysRanPtr , contextTid ) ; if ( ( rt_ParentMMI != ( NULL ) ) && ( rt_ChildPath != ( NULL ) ) ) { rtwCAPI_SetChildMMI ( * rt_ParentMMI , rt_ChildMMIIdx , & ( jb0umhodle -> DataMapInfo . mmi ) ) ; rtwCAPI_SetPath ( jb0umhodle -> DataMapInfo . mmi , rt_ChildPath ) ; rtwCAPI_MMISetContStateStartIndex ( jb0umhodle -> DataMapInfo . mmi , rt_CSTATEIdx ) ; } } void mr_charges_pneus_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T * modelName , int_T * retVal ) { * retVal = 0 ; { boolean_T regSubmodelsMdlinfo = false ; ssGetRegSubmodelsMdlinfo ( mdlRefSfcnS , & regSubmodelsMdlinfo ) ; if ( regSubmodelsMdlinfo ) { } } * retVal = 0 ; ssRegModelRefMdlInfo ( mdlRefSfcnS , modelName , rtMdlInfo_charges_pneus , 41 ) ; * retVal = 1 ; } static void mr_charges_pneus_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j , const void * srcData , size_t numBytes ) ; static void mr_charges_pneus_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j , const void * srcData , size_t numBytes ) { mxArray * newArray = mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS , mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T * ) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray ) ; } static void mr_charges_pneus_restoreDataFromMxArray ( void * destData , const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static void mr_charges_pneus_restoreDataFromMxArray ( void * destData , const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( ( uint8_T * ) destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i , j ) ) , numBytes ) ; } static void mr_charges_pneus_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int j , uint_T bitVal ) ; static void mr_charges_pneus_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int j , uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j , mxCreateDoubleScalar ( ( real_T ) bitVal ) ) ; } static uint_T mr_charges_pneus_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i , int j , uint_T numBits ) ; static uint_T mr_charges_pneus_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T ) mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( ( 1u << numBits ) - 1u ) ; } static void mr_charges_pneus_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex i , int j , mwIndex offset , const void * srcData , size_t numBytes ) ; static void mr_charges_pneus_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex i , int j , mwIndex offset , const void * srcData , size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData ( mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData [ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static void mr_charges_pneus_restoreDataFromMxArrayWithOffset ( void * destData , const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ; static void mr_charges_pneus_restoreDataFromMxArrayWithOffset ( void * destData , const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData , ( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static void mr_charges_pneus_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static void mr_charges_pneus_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) { mxSetCell ( mxGetFieldByNumber ( destArray , i , j ) , offset , mxCreateDoubleScalar ( ( real_T ) fieldVal ) ) ; } static uint_T mr_charges_pneus_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static uint_T mr_charges_pneus_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) { const uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber ( srcArray , i , j ) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u ) ; } mxArray * mr_charges_pneus_GetDWork ( const hh3lbtsamd0 * mdlrefDW ) { static const char_T * ssDWFieldNames [ 3 ] = { "rtb" , "NULL->rtdw" , "NULL->rtzce" , } ; mxArray * ssDW = mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ; mr_charges_pneus_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & ( mdlrefDW -> rtb ) , sizeof ( mdlrefDW -> rtb ) ) ; ( void ) mdlrefDW ; return ssDW ; } void mr_charges_pneus_SetDWork ( hh3lbtsamd0 * mdlrefDW , const mxArray * ssDW ) { ( void ) ssDW ; ( void ) mdlrefDW ; mr_charges_pneus_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW -> rtb ) , ssDW , 0 , 0 , sizeof ( mdlrefDW -> rtb ) ) ; } void mr_charges_pneus_RegisterSimStateChecksum ( SimStruct * S ) { const uint32_T chksum [ 4 ] = { 3789605033U , 3268161114U , 2975140790U , 1105365560U , } ; slmrModelRefRegisterSimStateChecksum ( S , "charges_pneus" , & chksum [ 0 ] ) ; } mxArray * mr_charges_pneus_GetSimStateDisallowedBlocks ( ) { return ( NULL ) ; }
#if defined(_MSC_VER)
#pragma warning(disable: 4505) //unreferenced local function has been removed
#endif
