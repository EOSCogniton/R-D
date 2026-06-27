#ifndef state_variables_cap_host_h__
#define state_variables_cap_host_h__
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap_simtarget.h"
#include "calcul_alpha_beta_gamma_v2_capi_host.h"
#include "calcul_vitesse_yawrate_capi_host.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; rtwCAPI_ModelMappingInfo *
childMMI [ 2 ] ; calcul_alpha_beta_gamma_v2_host_DataMapInfo_T child0 ;
calcul_vitesse_yawrate_host_DataMapInfo_T child1 ; }
state_variables_host_DataMapInfo_T ;
#ifdef __cplusplus
extern "C" {
#endif
void state_variables_host_InitializeDataMapInfo ( state_variables_host_DataMapInfo_T * dataMap , const char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif
