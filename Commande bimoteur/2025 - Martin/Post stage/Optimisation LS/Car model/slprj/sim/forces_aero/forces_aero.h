#ifndef forces_aero_h_
#define forces_aero_h_
#ifndef forces_aero_COMMON_INCLUDES_
#define forces_aero_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "math.h"
#endif
#include "forces_aero_types.h"
#include "rtw_modelmap_simtarget.h"
#include "rt_nonfinite.h"
#include <string.h>
#include <stddef.h>
typedef struct { real_T ktnfp1m5k4 ; } hdzujdgzdj ; struct dxgthqwwn4k_ {
real_T P_4 ; } ; struct nlvqana2u4 { struct SimStruct_tag * _mdlRefSfcnS ;
struct { rtwCAPI_ModelMappingInfo mmi ; rtwCAPI_ModelMapLoggingInstanceInfo
mmiLogInstanceInfo ; sysRanDType * systemRan [ 2 ] ; int_T systemTid [ 2 ] ;
} DataMapInfo ; struct { int_T mdlref_GlobalTID [ 2 ] ; } Timing ; } ;
typedef struct { hdzujdgzdj rtb ; muzbqn0dqg rtm ; } gix3e13jsxw ; extern
real_T rtP_A ; extern real_T rtP_CD ; extern real_T rtP_CL ; extern real_T
rtP_rho ; extern void b4osbtaao3 ( SimStruct * _mdlRefSfcnS , int_T
mdlref_TID0 , int_T mdlref_TID1 , muzbqn0dqg * const bdevpbo1dh , hdzujdgzdj
* localB , void * sysRanPtr , int contextTid , rtwCAPI_ModelMappingInfo *
rt_ParentMMI , const char_T * rt_ChildPath , int_T rt_ChildMMIIdx , int_T
rt_CSTATEIdx ) ; extern void mr_forces_aero_MdlInfoRegFcn ( SimStruct *
mdlRefSfcnS , char_T * modelName , int_T * retVal ) ; extern mxArray *
mr_forces_aero_GetDWork ( const gix3e13jsxw * mdlrefDW ) ; extern void
mr_forces_aero_SetDWork ( gix3e13jsxw * mdlrefDW , const mxArray * ssDW ) ;
extern void mr_forces_aero_RegisterSimStateChecksum ( SimStruct * S ) ;
extern mxArray * mr_forces_aero_GetSimStateDisallowedBlocks ( ) ; extern
const rtwCAPI_ModelMappingStaticInfo * forces_aero_GetCAPIStaticMap ( void )
; extern void forces_aero ( const real_T * eitcfujc5p , real_T * ootlnjqmgf ,
real_T * budbzkw2fm , hdzujdgzdj * localB ) ; extern void forces_aeroTID1 ( hdzujdgzdj * localB ) ; extern void mea4we2vim ( muzbqn0dqg * const bdevpbo1dh ) ;
#endif
