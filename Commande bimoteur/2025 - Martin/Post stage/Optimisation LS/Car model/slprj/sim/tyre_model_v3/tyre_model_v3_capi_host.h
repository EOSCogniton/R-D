#ifndef tyre_model_v3_cap_host_h__
#define tyre_model_v3_cap_host_h__
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap_simtarget.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
tyre_model_v3_host_DataMapInfo_T ;
#ifdef __cplusplus
extern "C" {
#endif
void tyre_model_v3_host_InitializeDataMapInfo ( tyre_model_v3_host_DataMapInfo_T
* dataMap , const char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif
