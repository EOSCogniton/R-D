#ifndef calcul_vitesse_yawrate_h_
#define calcul_vitesse_yawrate_h_
#ifndef calcul_vitesse_yawrate_COMMON_INCLUDES_
#define calcul_vitesse_yawrate_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "math.h"
#endif
#include "calcul_vitesse_yawrate_types.h"
#include "rtw_modelmap_simtarget.h"
#include "rt_nonfinite.h"
#include <string.h>
#include <stddef.h>
typedef struct { real_T p3vt5eqsli ; real_T hwyn4wrt55 ; real_T jm3pyr5zsn ;
} dihilfmdpe ; struct m4bxcs41zwq_ { real_T P_4 ; real_T P_5 ; } ; struct
cv1bir1gyq { struct SimStruct_tag * _mdlRefSfcnS ; struct {
rtwCAPI_ModelMappingInfo mmi ; rtwCAPI_ModelMapLoggingInstanceInfo
mmiLogInstanceInfo ; sysRanDType * systemRan [ 2 ] ; int_T systemTid [ 2 ] ;
} DataMapInfo ; struct { int_T mdlref_GlobalTID [ 1 ] ; } Timing ; } ;
typedef struct { dihilfmdpe rtdw ; fqqiewyclh rtm ; } ae1yjtrwpfr ; extern
real_T rtP_Izz ; extern real_T rtP_Ts ; extern real_T rtP_m ; extern real_T
rtP_v0 ; extern void hfekmzu4zr ( SimStruct * _mdlRefSfcnS , int_T
mdlref_TID0 , fqqiewyclh * const hfgf31v1sn , dihilfmdpe * localDW , void *
sysRanPtr , int contextTid , rtwCAPI_ModelMappingInfo * rt_ParentMMI , const
char_T * rt_ChildPath , int_T rt_ChildMMIIdx , int_T rt_CSTATEIdx ) ; extern
void mr_calcul_vitesse_yawrate_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS ,
char_T * modelName , int_T * retVal ) ; extern mxArray *
mr_calcul_vitesse_yawrate_GetDWork ( const ae1yjtrwpfr * mdlrefDW ) ; extern
void mr_calcul_vitesse_yawrate_SetDWork ( ae1yjtrwpfr * mdlrefDW , const
mxArray * ssDW ) ; extern void
mr_calcul_vitesse_yawrate_RegisterSimStateChecksum ( SimStruct * S ) ; extern
mxArray * mr_calcul_vitesse_yawrate_GetSimStateDisallowedBlocks ( ) ; extern
const rtwCAPI_ModelMappingStaticInfo *
calcul_vitesse_yawrate_GetCAPIStaticMap ( void ) ; extern void m5x0o1ug2l ( dihilfmdpe * localDW ) ; extern void eoicgzqlle ( dihilfmdpe * localDW ) ; extern void bxhbbgv4j2 ( real_T * afn1olkb2o , real_T * pkqbd2kwgr , real_T * frrxr0frih , dihilfmdpe * localDW ) ; extern void calcul_vitesse_yawrate ( const real_T * ckwrzk5mdl , const real_T * cfrsahjtnl , const real_T * bm02ej3k54 , real_T * afn1olkb2o , real_T * pkqbd2kwgr , real_T * frrxr0frih , dihilfmdpe * localDW ) ; extern void kwjyg1mjo3 ( fqqiewyclh * const hfgf31v1sn ) ;
#endif
