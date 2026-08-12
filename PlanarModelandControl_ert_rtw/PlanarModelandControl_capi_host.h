#ifndef PlanarModelandControl_cap_host_h__
#define PlanarModelandControl_cap_host_h__
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"

struct PlanarModelandControl_host_DataMapInfo_T {
  rtwCAPI_ModelMappingInfo mmi;
};

#ifdef __cplusplus

extern "C"
{

#endif

  void PlanarModelandControl_host_InitializeDataMapInfo
    (PlanarModelandControl_host_DataMapInfo_T *dataMap, const char *path);

#ifdef __cplusplus

}

#endif
#endif                                 // HOST_CAPI_BUILD
#endif                                 // PlanarModelandControl_cap_host_h__

// EOF: PlanarModelandControl_capi_host.h
