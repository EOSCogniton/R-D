#ifndef calcul_alpha_beta_gamma_v2_h_
#define calcul_alpha_beta_gamma_v2_h_
#ifndef calcul_alpha_beta_gamma_v2_COMMON_INCLUDES_
#define calcul_alpha_beta_gamma_v2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "math.h"
#include "sf_runtime/sfc_sdi.h"
#endif
#include "calcul_alpha_beta_gamma_v2_types.h"
#include "rtw_modelmap_simtarget.h"
#include "rt_nonfinite.h"
#include <string.h>
#include <stddef.h>
struct hjkmg00bse { struct SimStruct_tag * _mdlRefSfcnS ; struct {
rtwCAPI_ModelMappingInfo mmi ; rtwCAPI_ModelMapLoggingInstanceInfo
mmiLogInstanceInfo ; sysRanDType * systemRan [ 5 ] ; int_T systemTid [ 5 ] ;
} DataMapInfo ; struct { int_T mdlref_GlobalTID [ 2 ] ; } Timing ; } ;
typedef struct { cojrrv5v5s rtm ; } cbbpcstriyq ; extern real_T rtP_lf ;
extern real_T rtP_lr ; extern real_T rtP_t ; extern void lfcl4oswx4 ( SimStruct
* _mdlRefSfcnS , int_T mdlref_TID0 , int_T mdlref_TID1 , cojrrv5v5s * const
ozcqrmeidr , void * sysRanPtr , int contextTid , rtwCAPI_ModelMappingInfo *
rt_ParentMMI , const char_T * rt_ChildPath , int_T rt_ChildMMIIdx , int_T
rt_CSTATEIdx ) ; extern void mr_calcul_alpha_beta_gamma_v2_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T * modelName , int_T * retVal ) ; extern mxArray * mr_calcul_alpha_beta_gamma_v2_GetDWork ( const cbbpcstriyq * mdlrefDW ) ; extern void mr_calcul_alpha_beta_gamma_v2_SetDWork ( cbbpcstriyq * mdlrefDW , const mxArray * ssDW ) ; extern void mr_calcul_alpha_beta_gamma_v2_RegisterSimStateChecksum ( SimStruct * S ) ; extern mxArray * mr_calcul_alpha_beta_gamma_v2_GetSimStateDisallowedBlocks ( ) ; extern const rtwCAPI_ModelMappingStaticInfo * calcul_alpha_beta_gamma_v2_GetCAPIStaticMap ( void ) ; extern void calcul_alpha_beta_gamma_v2 ( const real_T mnu302hrdt [ 4 ] , const real_T h31vqbczrg [ 4 ] , const real_T * pxthgweylw , real_T * mllxosbukp , real_T * ewevvbrhys , real_T * hp00kkeexa ) ; extern void ph0uk5pae2 ( cojrrv5v5s * const ozcqrmeidr ) ;
#endif
