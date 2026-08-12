//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PlanarModelandControl_data.cpp
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
#include "PlanarModelandControl.h"

// Constant parameters (default storage)
const PlanarModelandControl::ConstP rtConstP{
  // Pooled Parameter (Expression: Mz_minF)
  //  Referenced by:
  //    '<S10>/Limite min'
  //    '<S13>/Limite min'
  //    '<S14>/Limite min'

  { 0.0, -66.3, -132.6, -198.9, -265.2, -330.23, -396.52, -462.83, -529.112,
    -595.42, -661.73, -728.03, -794.33, -860.62, -926.92, -993.23, -1058.25,
    -1124.55, -1190.85, -1257.15, -1323.45, -1389.75, -1456.05, -1522.35,
    -1588.65, -1654.95 },

  // Pooled Parameter (Expression: pedal)
  //  Referenced by:
  //    '<S10>/Limite min'
  //    '<S10>/Limite máx'
  //    '<S13>/Limite min'
  //    '<S13>/Limite máx'
  //    '<S14>/Limite min'
  //    '<S14>/Limite máx'

  { 0.0, 4.0, 8.0, 12.0, 16.0, 20.0, 24.0, 28.0, 32.0, 36.0, 40.0, 44.0, 48.0,
    52.0, 56.0, 60.0, 64.0, 68.0, 72.0, 76.0, 80.0, 84.0, 88.0, 92.0, 96.0,
    100.0 },

  // Pooled Parameter (Expression: fis.outputSamplePoints)
  //  Referenced by:
  //    '<S32>/Output Sample Points'
  //    '<S38>/Output Sample Points'
  //    '<S44>/Output Sample Points'
  //    '<S50>/Output Sample Points'

  { -0.5, -0.485, -0.47, -0.455, -0.44, -0.425, -0.41000000000000003, -0.395,
    -0.38, -0.365, -0.35, -0.33499999999999996, -0.32, -0.305,
    -0.29000000000000004, -0.275, -0.26, -0.245, -0.22999999999999998,
    -0.21500000000000002, -0.2, -0.185, -0.16999999999999998,
    -0.15500000000000003, -0.14, -0.125, -0.10999999999999999,
    -0.094999999999999973, -0.080000000000000016, -0.065, -0.049999999999999989,
    -0.034999999999999976, -0.020000000000000018, -0.0050000000000000044,
    0.010000000000000009, 0.025000000000000022, 0.040000000000000036,
    0.055000000000000049, 0.069999999999999951, 0.084999999999999964,
    0.099999999999999978, 0.11499999999999999, 0.13, 0.14500000000000002,
    0.16000000000000003, 0.17500000000000004, 0.18999999999999995,
    0.20499999999999996, 0.21999999999999997, 0.235, 0.25, 0.265, 0.28,
    0.29500000000000004, 0.31000000000000005, 0.32499999999999996,
    0.33999999999999997, 0.355, 0.37, 0.385, 0.4, 0.41500000000000004,
    0.43000000000000005, 0.44499999999999995, 0.45999999999999996, 0.475, 0.49,
    0.50499999999999989, 0.52, 0.53499999999999992, 0.55, 0.565,
    0.58000000000000007, 0.595, 0.6100000000000001, 0.625, 0.6399999999999999,
    0.655, 0.66999999999999993, 0.685, 0.7, 0.71500000000000008, 0.73,
    0.74500000000000011, 0.76, 0.77499999999999991, 0.79, 0.80499999999999994,
    0.82000000000000006, 0.835, 0.85000000000000009, 0.865, 0.87999999999999989,
    0.895, 0.90999999999999992, 0.925, 0.94, 0.95500000000000007, 0.97,
    0.9850000000000001, 1.0 },

  // Pooled Parameter (Expression: Cs)
  //  Referenced by:
  //    '<S4>/1-D Lookup Table'
  //    '<S4>/1-D Lookup Table1'
  //    '<S4>/1-D Lookup Table2'
  //    '<S4>/1-D Lookup Table3'

  { 19075.58, 25992.8, 31792.64, 35898.02, 39044.37 },

  // Pooled Parameter (Expression: Fz_cs)
  //  Referenced by:
  //    '<S4>/1-D Lookup Table'
  //    '<S4>/1-D Lookup Table1'
  //    '<S4>/1-D Lookup Table2'
  //    '<S4>/1-D Lookup Table3'

  { 222.41, 444.82, 667.23, 889.64, 1112.05 },

  // Expression: Steering_inner
  //  Referenced by: '<S2>/1-D Lookup Table2'

  { -29.018, -25.595, -22.357, -19.265, -16.292, -13.415, -10.619, -7.89, -5.217,
    -2.589, 0.0, 2.559, 5.093, 7.608, 10.11, 12.604, 15.094, 17.585, 20.082,
    22.589, 25.111 },

  // Pooled Parameter (Expression: steering_vol)
  //  Referenced by:
  //    '<S2>/1-D Lookup Table2'
  //    '<S2>/1-D Lookup Table3'

  { -105.0, -94.5, -84.0, -73.5, -63.0, -52.5, -42.0, -31.5, -21.0, -10.5, 0.0,
    10.5, 21.0, 31.5, 42.0, 52.5, 63.0, 73.5, 84.0, 94.5, 105.0 },

  // Expression: Steering_outer
  //  Referenced by: '<S2>/1-D Lookup Table3'

  { -25.111, -22.589, -20.082, -17.585, -15.094, -12.604, -10.11, -7.608, -5.093,
    -2.559, 0.0, 2.589, 5.217, 7.89, 10.62, 13.415, 16.292, 19.265, 22.357,
    25.595, 29.018 },

  // Expression: K_variavel
  //  Referenced by: '<S6>/1-D Lookup Table'

  { -0.001, 0.0, 0.0008, 0.0012, 0.0015 },

  // Expression: Vx
  //  Referenced by: '<S6>/1-D Lookup Table'

  { 0.0, 12.5, 23.6, 30.0, 35.0 },

  // Expression: Ki_data
  //  Referenced by: '<S13>/n-D Lookup Table1'

  { 2264.9435943999997, 918.65292000000011, 412.7684152, 244.4522752,
    140.20176800000002, 94.1906408, 84.5400008 },

  // Pooled Parameter (Expression: Vx_axis)
  //  Referenced by:
  //    '<S13>/n-D Lookup Table'
  //    '<S13>/n-D Lookup Table1'

  { 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0 },

  // Expression: Kp_data
  //  Referenced by: '<S13>/n-D Lookup Table'

  { 14387.851, 11519.999499999998, 9860.4175, 7784.3875000000007,
    6291.2255000000005, 5113.5425, 4913.9305 },

  // Pooled Parameter (Expression: torque_355_novo)
  //  Referenced by:
  //    '<S7>/1-D Lookup Table'
  //    '<S7>/1-D Lookup Table1'
  //    '<S7>/1-D Lookup Table2'
  //    '<S7>/1-D Lookup Table3'

  { 16.2, 16.2, 16.0, 15.8, 15.6, 15.4, 15.2, 15.0, 14.8, 14.6, 14.4, 14.2, 14.0,
    13.0, 12.0, 11.0, 10.0, 9.0, 8.0, 7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0, 0.5,
    0.0 },

  // Pooled Parameter (Expression: rpm_355_novo)
  //  Referenced by:
  //    '<S7>/1-D Lookup Table'
  //    '<S7>/1-D Lookup Table1'
  //    '<S7>/1-D Lookup Table2'
  //    '<S7>/1-D Lookup Table3'

  { 0.0, 10050.0, 10100.0, 10140.0, 10170.0, 10210.0, 10250.0, 10280.0, 10320.0,
    10360.0, 10390.0, 10420.0, 10460.0, 10620.0, 10770.0, 10920.0, 11050.0,
    11170.0, 11280.0, 11380.0, 11470.0, 11550.0, 11625.0, 11680.0, 11730.0,
    11775.0, 11790.0, 11800.0 },

  // Pooled Parameter (Expression: Mz_maxF)
  //  Referenced by:
  //    '<S10>/Limite máx'
  //    '<S13>/Limite máx'
  //    '<S14>/Limite máx'

  { 0.0, 66.3, 132.6, 198.9, 265.2, 330.23, 396.52, 462.83, 529.112, 595.42,
    661.73, 728.03, 794.33, 860.62, 926.92, 993.23, 1058.25, 1124.55, 1190.85,
    1257.15, 1323.45, 1389.75, 1456.05, 1522.35, 1588.65, 1654.95 }
};

//
// File trailer for generated code.
//
// [EOF]
//
