#ifndef calcul_alpha_beta_gamma_v2_cap_host_h__
#define calcul_alpha_beta_gamma_v2_cap_host_h__
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap_simtarget.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
calcul_alpha_beta_gamma_v2_host_DataMapInfo_T ;
#ifdef __cplusplus
extern "C" {
#endif
void calcul_alpha_beta_gamma_v2_host_InitializeDataMapInfo ( calcul_alpha_beta_gamma_v2_host_DataMapInfo_T * dataMap , const char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif
