//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PlanarModelandControl_capi.cpp
//
// Code generated for Simulink model 'PlanarModelandControl'.
//
// Model version                  : 11.37
// Simulink Coder version         : 26.1 (R2026a) 20-Nov-2025
// C/C++ source code generated on : Tue Aug 11 13:46:02 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "PlanarModelandControl_capi_host.h"
#define sizeof(...)                    ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#ifndef SS_UINT64
#define SS_UINT64                      22
#endif

#ifndef SS_INT64
#define SS_INT64                       23
#endif

#else                                  // HOST_CAPI_BUILD
#include "builtin_typeid_types.h"
#include "PlanarModelandControl.h"
#include "PlanarModelandControl_capi.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((nullptr))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif                                 // HOST_CAPI_BUILD

// Block output signal information
static rtwCAPI_Signals rtBlockSignals[]{
  // addrMapIndex, sysNum, blockPath,
  //  signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex

  { 0, 0, TARGET_STRING("PlanarModelandControl/Zero-Order Hold"),
    TARGET_STRING("steering_inner"), 0, 0, 0, 0, 0 },

  { 1, 0, TARGET_STRING("PlanarModelandControl/Zero-Order Hold"),
    TARGET_STRING("steering_outer"), 0, 0, 0, 0, 0 },

  { 2, 0, TARGET_STRING("PlanarModelandControl/Controle/Rate Transition10"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 3, 0, TARGET_STRING("PlanarModelandControl/Controle/Rate Transition8"),
    TARGET_STRING("ay_cg"), 0, 0, 0, 0, 0 },

  { 4, 0, TARGET_STRING("PlanarModelandControl/Controle/Rate Transition9"),
    TARGET_STRING("yaw_rate"), 0, 0, 0, 0, 0 },

  { 5, 0, TARGET_STRING("PlanarModelandControl/Driver/Switch"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 6, 0, TARGET_STRING("PlanarModelandControl/Driver/Switch1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 7, 0, TARGET_STRING("PlanarModelandControl/Controle/Direct Yaw Control/Yaw desejado"),
    TARGET_STRING("yaw_ref"), 0, 0, 0, 0, 1 },

  { 8, 0, TARGET_STRING("PlanarModelandControl/Controle/Direct Yaw Control/MDYC/Limite min"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 9, 0, TARGET_STRING("PlanarModelandControl/Controle/Direct Yaw Control/MDYC/Limite máx"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 10, 0, TARGET_STRING(
    "PlanarModelandControl/Controle/Direct Yaw Control/Yaw desejado/ref < limit"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 11, 0, TARGET_STRING(
    "PlanarModelandControl/Controle/Direct Yaw Control/Yaw desejado/ref > limit"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 12, 0, TARGET_STRING(
    "PlanarModelandControl/Controle/Direct Yaw Control/Yaw desejado/Merge"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 13, 0, TARGET_STRING(
    "PlanarModelandControl/Controle/Direct Yaw Control/Yaw desejado/Divide"),
    TARGET_STRING("Yaw_limit"), 0, 0, 0, 0, 0 },

  { 14, 0, TARGET_STRING(
    "PlanarModelandControl/Controle/Direct Yaw Control/Yaw desejado/Divide1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 15, 12, TARGET_STRING(
    "PlanarModelandControl/Controle/Torque Vectoring/Redução TC1/Switch"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 16, 12, TARGET_STRING(
    "PlanarModelandControl/Controle/Torque Vectoring/Redução TC1/Switch1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 17, 12, TARGET_STRING(
    "PlanarModelandControl/Controle/Torque Vectoring/Redução TC1/Switch2"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 18, 12, TARGET_STRING(
    "PlanarModelandControl/Controle/Torque Vectoring/Redução TC1/Switch3"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 19, 0, TARGET_STRING(
    "PlanarModelandControl/Planta/Dinamica do Veículo/Frenagem/torque_máx_f"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 20, 0, TARGET_STRING(
    "PlanarModelandControl/Planta/Dinamica do Veículo/Frenagem/torque_máx_r"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 21, 0, TARGET_STRING(
    "PlanarModelandControl/Planta/Movimento do Veiculo/Movimento X/Gain1"),
    TARGET_STRING("Ax_Cg"), 0, 0, 0, 0, 2 },

  { 22, 0, TARGET_STRING(
    "PlanarModelandControl/Planta/Movimento do Veiculo/Movimento Y/Gain"),
    TARGET_STRING("Ay_cg"), 0, 0, 0, 0, 2 },

  { 23, 0, TARGET_STRING(
    "PlanarModelandControl/Planta/Movimento do Veiculo/Xres/Cos"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 24, 0, TARGET_STRING(
    "PlanarModelandControl/Planta/Movimento do Veiculo/Xres/Cos1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 25, 0, TARGET_STRING(
    "PlanarModelandControl/Planta/Movimento do Veiculo/Xres/Cos2"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 26, 0, TARGET_STRING(
    "PlanarModelandControl/Planta/Movimento do Veiculo/Xres/Cos3"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 27, 0, TARGET_STRING(
    "PlanarModelandControl/Planta/Movimento do Veiculo/Yres/Cos"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 28, 0, TARGET_STRING(
    "PlanarModelandControl/Planta/Movimento do Veiculo/Yres/Cos1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 29, 0, TARGET_STRING(
    "PlanarModelandControl/Planta/Movimento do Veiculo/Yres/Cos2"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 30, 0, TARGET_STRING(
    "PlanarModelandControl/Planta/Movimento do Veiculo/Yres/Cos3"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 31, 0, TARGET_STRING(
    "PlanarModelandControl/Controle/Direct Yaw Control/MDYC/Feedback/Limite min"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 32, 0, TARGET_STRING(
    "PlanarModelandControl/Controle/Direct Yaw Control/MDYC/Feedback/Limite máx"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 33, 0, TARGET_STRING(
    "PlanarModelandControl/Controle/Direct Yaw Control/MDYC/Feedback/n-D Lookup Table"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 34, 0, TARGET_STRING(
    "PlanarModelandControl/Controle/Direct Yaw Control/MDYC/Feedback/n-D Lookup Table1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 35, 0, TARGET_STRING(
    "PlanarModelandControl/Controle/Direct Yaw Control/MDYC/Feedback/Sum1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 36, 0, TARGET_STRING(
    "PlanarModelandControl/Controle/Direct Yaw Control/Yaw desejado/ref < limit/Yaw_ref"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 37, 0, TARGET_STRING(
    "PlanarModelandControl/Controle/Direct Yaw Control/Yaw desejado/ref > limit/Product"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 38, 0, TARGET_STRING(
    "PlanarModelandControl/Controle/Direct Yaw Control/MDYC/Feedfoward/Saturation Dynamic/Switch2"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 39, 0, TARGET_STRING(
    "PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat FL/KySA/Sum"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 40, 0, TARGET_STRING(
    "PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat FR/KySA/Sum"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 41, 0, TARGET_STRING(
    "PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat RL/KySA/Sum"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 42, 0, TARGET_STRING(
    "PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat RR/KySA/Sum"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 43, 0, TARGET_STRING(
    "PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long FL /Ex/Abs"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 44, 0, TARGET_STRING(
    "PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long FR/Ex/Abs"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 45, 0, TARGET_STRING(
    "PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long RL/Ex/Abs"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 46, 0, TARGET_STRING(
    "PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long RR/Ex/Abs"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  {
    0, 0, (nullptr), (nullptr), 0, 0, 0, 0, 0
  }
};

static int_T rt_LoggedStateIdxList[] {
  -1
};

#ifndef HOST_CAPI_BUILD

// Initialize Data Address
static void InitializeDataAddr(void* dataAddr[], PlanarModelandControl::DW *rtDW)
{
  dataAddr[0] = (void*) (&rtDW->steering_inner);
  dataAddr[1] = (void*) (&rtDW->steering_outer);
  dataAddr[2] = (void*) (&rtDW->RateTransition10);
  dataAddr[3] = (void*) (&rtDW->ay_cg);
  dataAddr[4] = (void*) (&rtDW->yaw_rate);
  dataAddr[5] = (void*) (&rtDW->Switch);
  dataAddr[6] = (void*) (&rtDW->Switch1);
  dataAddr[7] = (void*) (&rtDW->yaw_ref);
  dataAddr[8] = (void*) (&rtDW->Limitemin_o);
  dataAddr[9] = (void*) (&rtDW->Limitemx_m);
  dataAddr[10] = (void*) (&rtDW->yaw_ref);
  dataAddr[11] = (void*) (&rtDW->yaw_ref);
  dataAddr[12] = (void*) (&rtDW->yaw_ref);
  dataAddr[13] = (void*) (&rtDW->Yaw_limit);
  dataAddr[14] = (void*) (&rtDW->Divide1);
  dataAddr[15] = (void*) (&rtDW->Switch_e);
  dataAddr[16] = (void*) (&rtDW->Switch1_j);
  dataAddr[17] = (void*) (&rtDW->Switch2_o);
  dataAddr[18] = (void*) (&rtDW->Switch3);
  dataAddr[19] = (void*) (&rtDW->torque_mx_f);
  dataAddr[20] = (void*) (&rtDW->torque_mx_r);
  dataAddr[21] = (void*) (&rtDW->Ax_Cg);
  dataAddr[22] = (void*) (&rtDW->Ay_cg);
  dataAddr[23] = (void*) (&rtDW->Cos_i);
  dataAddr[24] = (void*) (&rtDW->Cos1_e);
  dataAddr[25] = (void*) (&rtDW->Cos2_h);
  dataAddr[26] = (void*) (&rtDW->Cos3_i);
  dataAddr[27] = (void*) (&rtDW->Cos);
  dataAddr[28] = (void*) (&rtDW->Cos1);
  dataAddr[29] = (void*) (&rtDW->Cos2);
  dataAddr[30] = (void*) (&rtDW->Cos3);
  dataAddr[31] = (void*) (&rtDW->Limitemin);
  dataAddr[32] = (void*) (&rtDW->Limitemx);
  dataAddr[33] = (void*) (&rtDW->nDLookupTable);
  dataAddr[34] = (void*) (&rtDW->nDLookupTable1);
  dataAddr[35] = (void*) (&rtDW->Sum1);
  dataAddr[36] = (void*) (&rtDW->yaw_ref);
  dataAddr[37] = (void*) (&rtDW->yaw_ref);
  dataAddr[38] = (void*) (&rtDW->Switch2);
  dataAddr[39] = (void*) (&rtDW->Sum_g);
  dataAddr[40] = (void*) (&rtDW->Sum_j);
  dataAddr[41] = (void*) (&rtDW->Sum_n);
  dataAddr[42] = (void*) (&rtDW->Sum_f);
  dataAddr[43] = (void*) (&rtDW->Abs);
  dataAddr[44] = (void*) (&rtDW->Abs_n);
  dataAddr[45] = (void*) (&rtDW->Abs_n0);
  dataAddr[46] = (void*) (&rtDW->Abs_h);
}

#endif

// Initialize Data Run-Time Dimension Buffer Address
#ifndef HOST_CAPI_BUILD

static void InitializeVarDimsAddr(int32_T* vardimsAddr[])
{
  vardimsAddr[0] = (nullptr);
}

#endif

#ifndef HOST_CAPI_BUILD

// Initialize logging function pointers
static void InitializeLoggingFunctions(RTWLoggingFcnPtr loggingPtrs[])
{
  loggingPtrs[0] = (nullptr);
  loggingPtrs[1] = (nullptr);
  loggingPtrs[2] = (nullptr);
  loggingPtrs[3] = (nullptr);
  loggingPtrs[4] = (nullptr);
  loggingPtrs[5] = (nullptr);
  loggingPtrs[6] = (nullptr);
  loggingPtrs[7] = (nullptr);
  loggingPtrs[8] = (nullptr);
  loggingPtrs[9] = (nullptr);
  loggingPtrs[10] = (nullptr);
  loggingPtrs[11] = (nullptr);
  loggingPtrs[12] = (nullptr);
  loggingPtrs[13] = (nullptr);
  loggingPtrs[14] = (nullptr);
  loggingPtrs[15] = (nullptr);
  loggingPtrs[16] = (nullptr);
  loggingPtrs[17] = (nullptr);
  loggingPtrs[18] = (nullptr);
  loggingPtrs[19] = (nullptr);
  loggingPtrs[20] = (nullptr);
  loggingPtrs[21] = (nullptr);
  loggingPtrs[22] = (nullptr);
  loggingPtrs[23] = (nullptr);
  loggingPtrs[24] = (nullptr);
  loggingPtrs[25] = (nullptr);
  loggingPtrs[26] = (nullptr);
  loggingPtrs[27] = (nullptr);
  loggingPtrs[28] = (nullptr);
  loggingPtrs[29] = (nullptr);
  loggingPtrs[30] = (nullptr);
  loggingPtrs[31] = (nullptr);
  loggingPtrs[32] = (nullptr);
  loggingPtrs[33] = (nullptr);
  loggingPtrs[34] = (nullptr);
  loggingPtrs[35] = (nullptr);
  loggingPtrs[36] = (nullptr);
  loggingPtrs[37] = (nullptr);
  loggingPtrs[38] = (nullptr);
  loggingPtrs[39] = (nullptr);
  loggingPtrs[40] = (nullptr);
  loggingPtrs[41] = (nullptr);
  loggingPtrs[42] = (nullptr);
  loggingPtrs[43] = (nullptr);
  loggingPtrs[44] = (nullptr);
  loggingPtrs[45] = (nullptr);
  loggingPtrs[46] = (nullptr);
}

#endif

// Data Type Map - use dataTypeMapIndex to access this structure
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[]{
  // cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
  //  isComplex, isPointer, enumStorageType
  { "double", "real_T", 0, 0, sizeof(real_T), (uint8_T)SS_DOUBLE, 0, 0, 0 }
};

#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif

// Structure Element Map - use elemMapIndex to access this structure
static TARGET_CONST rtwCAPI_ElementMap rtElementMap[]{
  // elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex
  { (nullptr), 0, 0, 0, 0 },
};

// Dimension Map - use dimensionMapIndex to access elements of ths structure
static rtwCAPI_DimensionMap rtDimensionMap[]{
  // dataOrientation, dimArrayIndex, numDims, vardimsIndex
  { rtwCAPI_SCALAR, 0, 2, 0 }
};

// Dimension Array- use dimArrayIndex to access elements of this array
static uint_T rtDimensionArray[]{
  1,                                   // 0
  1                                    // 1
};

// C-API stores floating point values in an array. The elements of this  *
//  are unique. This ensures that values which are shared across the model*
//  are stored in the most efficient way. These values are referenced by  *
//            - rtwCAPI_FixPtMap.fracSlopePtr,                            *
//            - rtwCAPI_FixPtMap.biasPtr,                                 *
//            - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
//            - rtwCAPI_SampleTimeMap.sampleOffsetPtr
static const real_T rtcapiStoredFloats[]{
  0.01, 0.0, 0.001
};

// Fixed Point Map
static rtwCAPI_FixPtMap rtFixPtMap[]{
  // fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned
  { (nullptr), (nullptr), rtwCAPI_FIX_RESERVED, 0, 0, (boolean_T)0 },
};

// Sample Time Map - use sTimeIndex to access elements of ths structure
static rtwCAPI_SampleTimeMap rtSampleTimeMap[]{
  // samplePeriodPtr, sampleOffsetPtr, tid, samplingMode
  { static_cast<const void *>(&rtcapiStoredFloats[0]), static_cast<const void *>
    (&rtcapiStoredFloats[1]), static_cast<int8_T>(2), static_cast<uint8_T>(0) },

  { static_cast<const void *>(&rtcapiStoredFloats[1]), static_cast<const void *>
    (&rtcapiStoredFloats[1]), static_cast<int8_T>(0), static_cast<uint8_T>(0) },

  { static_cast<const void *>(&rtcapiStoredFloats[2]), static_cast<const void *>
    (&rtcapiStoredFloats[1]), static_cast<int8_T>(1), static_cast<uint8_T>(0) }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic{
  // Signals:{signals, numSignals,
  //            rootInputs, numRootInputs,
  //            rootOutputs, numRootOutputs},
  //  Params: {blockParameters, numBlockParameters,
  //           modelParameters, numModelParameters},
  //  States: {states, numStates},
  //  Maps:   {dataTypeMap, dimensionMap, fixPtMap,
  //           elementMap, sampleTimeMap, dimensionArray},
  //  TargetType: targetType

  { rtBlockSignals, 47,
    (nullptr), 0,
    (nullptr), 0 },

  { (nullptr), 0,
    (nullptr), 0 },

  { (nullptr), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 1207044366U,
    15740295U,
    2719579886U,
    1800890460U },
  (nullptr), 0,
  (boolean_T)0,
  rt_LoggedStateIdxList
};

// Function to get C API Model Mapping Static Info
const rtwCAPI_ModelMappingStaticInfo*
  PlanarModelandControl_GetCAPIStaticMap(void)
{
  return &mmiStatic;
}

// Cache pointers into DataMapInfo substructure of RTModel
#ifndef HOST_CAPI_BUILD

void PlanarModelandControl_InitializeDataMapInfo(PlanarModelandControl::RT_MODEL
  *const rtM, PlanarModelandControl::DW *rtDW)
{
  // Set C-API version
  rtwCAPI_SetVersion(rtM->DataMapInfo.mmi, 1);

  // Cache static C-API data into the Real-time Model Data structure
  rtwCAPI_SetStaticMap(rtM->DataMapInfo.mmi, &mmiStatic);

  // Cache static C-API logging data into the Real-time Model Data structure
  rtwCAPI_SetLoggingStaticMap(rtM->DataMapInfo.mmi, (nullptr));

  // Cache C-API Data Addresses into the Real-Time Model Data structure
  InitializeDataAddr(rtM->DataMapInfo.dataAddress, rtDW);
  rtwCAPI_SetDataAddressMap(rtM->DataMapInfo.mmi, rtM->DataMapInfo.dataAddress);

  // Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure 
  InitializeVarDimsAddr(rtM->DataMapInfo.vardimsAddress);
  rtwCAPI_SetVarDimsAddressMap(rtM->DataMapInfo.mmi,
    rtM->DataMapInfo.vardimsAddress);

  // Set Instance specific path
  rtwCAPI_SetPath(rtM->DataMapInfo.mmi, (nullptr));
  rtwCAPI_SetFullPath(rtM->DataMapInfo.mmi, (nullptr));

  // Cache C-API logging function pointers into the Real-Time Model Data structure 
  InitializeLoggingFunctions(rtM->DataMapInfo.loggingPtrs);
  rtwCAPI_SetLoggingPtrs(rtM->DataMapInfo.mmi, rtM->DataMapInfo.loggingPtrs);

  // Cache the instance C-API logging pointer
  rtwCAPI_SetInstanceLoggingInfo(rtM->DataMapInfo.mmi, (nullptr));

  // Set reference to submodels
  rtwCAPI_SetChildMMIArray(rtM->DataMapInfo.mmi, (nullptr));
  rtwCAPI_SetChildMMIArrayLen(rtM->DataMapInfo.mmi, 0);
}

#else                                  // HOST_CAPI_BUILD
#ifdef __cplusplus

extern "C"
{

#endif

  void PlanarModelandControl_host_InitializeDataMapInfo
    (PlanarModelandControl_host_DataMapInfo_T *dataMap, const char *path)
  {
    // Set C-API version
    rtwCAPI_SetVersion(dataMap->mmi, 1);

    // Cache static C-API data into the Real-time Model Data structure
    rtwCAPI_SetStaticMap(dataMap->mmi, &mmiStatic);

    // host data address map is NULL
    rtwCAPI_SetDataAddressMap(dataMap->mmi, (nullptr));

    // host vardims address map is NULL
    rtwCAPI_SetVarDimsAddressMap(dataMap->mmi, (nullptr));

    // Set Instance specific path
    rtwCAPI_SetPath(dataMap->mmi, path);
    rtwCAPI_SetFullPath(dataMap->mmi, (nullptr));

    // Set reference to submodels
    rtwCAPI_SetChildMMIArray(dataMap->mmi, (nullptr));
    rtwCAPI_SetChildMMIArrayLen(dataMap->mmi, 0);
  }

#ifdef __cplusplus

}

#endif
#endif                                 // HOST_CAPI_BUILD

//
// File trailer for generated code.
//
// [EOF]
//
