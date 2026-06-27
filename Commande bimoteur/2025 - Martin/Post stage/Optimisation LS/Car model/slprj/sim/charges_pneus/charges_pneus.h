#ifndef charges_pneus_h_
#define charges_pneus_h_
#ifndef charges_pneus_COMMON_INCLUDES_
#define charges_pneus_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "math.h"
#endif
#include "charges_pneus_types.h"
#include "rtw_modelmap_simtarget.h"
#include "rt_nonfinite.h"
#include <string.h>
#include <stddef.h>
typedef struct { real_T jibcgank3u ; real_T kxa5aikbeb ; real_T hqmzso3n00 ;
} afbpp532k5 ; struct p2vyvyihr5t_ { real_T P_6 ; real_T P_7 ; real_T P_8 ;
real_T P_9 ; real_T P_10 ; } ; struct onp3o0ajov { struct SimStruct_tag *
_mdlRefSfcnS ; struct { rtwCAPI_ModelMappingInfo mmi ;
rtwCAPI_ModelMapLoggingInstanceInfo mmiLogInstanceInfo ; sysRanDType *
systemRan [ 2 ] ; int_T systemTid [ 2 ] ; } DataMapInfo ; struct { int_T
mdlref_GlobalTID [ 2 ] ; } Timing ; } ; typedef struct { afbpp532k5 rtb ;
c4bom0vtk3 rtm ; } hh3lbtsamd0 ; extern real_T rtP_L ; extern real_T rtP_fr ;
extern real_T rtP_g ; extern real_T rtP_h ; extern real_T rtP_m ; extern
real_T rtP_t ; extern void ljbzawgrsu ( SimStruct * _mdlRefSfcnS , int_T
mdlref_TID0 , int_T mdlref_TID1 , c4bom0vtk3 * const jb0umhodle , afbpp532k5
* localB , void * sysRanPtr , int contextTid , rtwCAPI_ModelMappingInfo *
rt_ParentMMI , const char_T * rt_ChildPath , int_T rt_ChildMMIIdx , int_T
rt_CSTATEIdx ) ; extern void mr_charges_pneus_MdlInfoRegFcn ( SimStruct *
mdlRefSfcnS , char_T * modelName , int_T * retVal ) ; extern mxArray *
mr_charges_pneus_GetDWork ( const hh3lbtsamd0 * mdlrefDW ) ; extern void
mr_charges_pneus_SetDWork ( hh3lbtsamd0 * mdlrefDW , const mxArray * ssDW ) ;
extern void mr_charges_pneus_RegisterSimStateChecksum ( SimStruct * S ) ;
extern mxArray * mr_charges_pneus_GetSimStateDisallowedBlocks ( ) ; extern
const rtwCAPI_ModelMappingStaticInfo * charges_pneus_GetCAPIStaticMap ( void
) ; extern void charges_pneus ( const real_T * pyuckoipxv , const real_T *
dapo0iwrgf , const real_T * mzlmpncwcl , real_T lbzbraaxae [ 4 ] , afbpp532k5
* localB ) ; extern void charges_pneusTID1 ( afbpp532k5 * localB ) ; extern
void eskogmxsu3 ( c4bom0vtk3 * const jb0umhodle ) ;
#endif
