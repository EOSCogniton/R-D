#ifndef state_variables_h_
#define state_variables_h_
#ifndef state_variables_COMMON_INCLUDES_
#define state_variables_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "math.h"
#endif
#include "state_variables_types.h"
#include "calcul_alpha_beta_gamma_v2.h"
#include "calcul_vitesse_yawrate.h"
#include "rtw_modelmap_simtarget.h"
#include "rt_nonfinite.h"
#include <string.h>
#include <stddef.h>
typedef struct { real_T fy0g4qxjul ; real_T igrf5sg1iz ; real_T eggdyx1jki ;
real_T dl45wzepwe ; real_T atbec3pavk ; real_T fbxfg11qgk ; } hcddlecsms ;
typedef struct { real_T nvp2xt1lh3 ; real_T fuowqjhyt4 ; real_T lbrxbvl2dk ;
cbbpcstriyq g1npgx4411 ; ae1yjtrwpfr edkt3him5p ; } pvhntfwfsp ; struct
cmeyaxdw20l_ { real_T P_7 ; real_T P_8 ; real_T P_9 ; real_T P_10 ; real_T
P_11 ; real_T P_12 ; real_T P_13 ; real_T P_14 ; real_T P_15 ; } ; struct
g5jrmqdulj { struct SimStruct_tag * _mdlRefSfcnS ; struct {
rtwCAPI_ModelMappingInfo mmi ; rtwCAPI_ModelMapLoggingInstanceInfo
mmiLogInstanceInfo ; void * dataAddress [ 3 ] ; int32_T * vardimsAddress [ 3
] ; RTWLoggingFcnPtr loggingPtrs [ 3 ] ; rtwCAPI_ModelMappingInfo * childMMI
[ 2 ] ; sysRanDType * systemRan [ 2 ] ; int_T systemTid [ 2 ] ; } DataMapInfo
; struct { int_T mdlref_GlobalTID [ 3 ] ; } Timing ; } ; typedef struct {
hcddlecsms rtb ; pvhntfwfsp rtdw ; pdplqnup32 rtm ; } dqwxqx23nty ; extern
real_T rtP_Izz ; extern real_T rtP_Ts ; extern real_T rtP_lf ; extern real_T
rtP_lr ; extern real_T rtP_m ; extern real_T rtP_t ; extern real_T rtP_v0 ;
extern void dliygmlydf ( SimStruct * _mdlRefSfcnS , int_T mdlref_TID0 , int_T
mdlref_TID1 , int_T mdlref_TID2 , pdplqnup32 * const nf4xfde0xq , hcddlecsms
* localB , pvhntfwfsp * localDW , void * sysRanPtr , int contextTid ,
rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T * rt_ChildPath , int_T
rt_ChildMMIIdx , int_T rt_CSTATEIdx ) ; extern void
mr_state_variables_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T *
modelName , int_T * retVal ) ; extern mxArray * mr_state_variables_GetDWork ( const dqwxqx23nty * mdlrefDW ) ; extern void mr_state_variables_SetDWork ( dqwxqx23nty * mdlrefDW , const mxArray * ssDW ) ; extern void mr_state_variables_RegisterSimStateChecksum ( SimStruct * S ) ; extern mxArray * mr_state_variables_GetSimStateDisallowedBlocks ( ) ; extern const rtwCAPI_ModelMappingStaticInfo * state_variables_GetCAPIStaticMap ( void ) ; extern void p5liadvtde ( pvhntfwfsp * localDW ) ; extern void i1raxnm5ts ( pvhntfwfsp * localDW ) ; extern void ndxikdgz0t ( pdplqnup32 * const nf4xfde0xq , real_T * dphy5sodqd , real_T * h0udtahffh , real_T * jihi5jaloc , hcddlecsms * localB , pvhntfwfsp * localDW ) ; extern void state_variables ( pdplqnup32 * const nf4xfde0xq , const real_T kdyullo0x2 [ 4 ] , const real_T kkfjhopckp [ 4 ] , const real_T * cmyfsgu0ji , const real_T * g4mssreik2 , real_T * dphy5sodqd , real_T * h0udtahffh , real_T * jihi5jaloc , real_T * nbljw0uycc , real_T * fwjhvcfspi , real_T * hgoh0tsypf , hcddlecsms * localB , pvhntfwfsp * localDW ) ; extern void o2rpq4pnph ( pvhntfwfsp * localDW , pdplqnup32 * const nf4xfde0xq ) ;
#endif
