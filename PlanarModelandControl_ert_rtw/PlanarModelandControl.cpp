//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PlanarModelandControl.cpp
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
#include <math.h>
#include <float.h>
#include "rtwtypes.h"
#include <cmath>
#include "PlanarModelandControl_capi.h"
#include <limits>

// Used by FromWorkspace Block: '<Root>/From Workspace2'
#ifndef rtInterpolate
# define rtInterpolate(v1,v2,f1,f2)    (((v1)==(v2))?((double)(v1)): (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif

#ifndef rtRound
# define rtRound(v)                    ( ((v) >= 0) ? std::floor((v) + 0.5) : std::ceil((v) - 0.5) )
#endif

static real_T look1_binlx(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
static void rate_scheduler(PlanarModelandControl::RT_MODEL *const rtM);
extern "C"
{
  real_T rtNaN { -std::numeric_limits<real_T>::quiet_NaN() };

  real_T rtInf { std::numeric_limits<real_T>::infinity() };

  real_T rtMinusInf { -std::numeric_limits<real_T>::infinity() };

  real32_T rtNaNF { -std::numeric_limits<real32_T>::quiet_NaN() };

  real32_T rtInfF { std::numeric_limits<real32_T>::infinity() };

  real32_T rtMinusInfF { -std::numeric_limits<real32_T>::infinity() };
}

extern "C"
{
  // Return rtNaN needed by the generated code.
  static real_T rtGetNaN(void)
  {
    return rtNaN;
  }

  // Return rtNaNF needed by the generated code.
  static real32_T rtGetNaNF(void)
  {
    return rtNaNF;
  }
}

extern "C"
{
  // Test if value is infinite
  static boolean_T rtIsInf(real_T value)
  {
    return std::isinf(value);
  }

  // Test if single-precision value is infinite
  static boolean_T rtIsInfF(real32_T value)
  {
    return std::isinf(value);
  }

  // Test if value is not a number
  static boolean_T rtIsNaN(real_T value)
  {
    return std::isnan(value);
  }

  // Test if single-precision value is not a number
  static boolean_T rtIsNaNF(real32_T value)
  {
    return std::isnan(value);
  }
}

static real_T look1_binlx(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T iLeft;

  // Column-major Lookup 1-D
  // Search method: 'binary'
  // Use previous index: 'off'
  // Interpolation method: 'Linear point-slope'
  // Extrapolation method: 'Linear'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  // Prelookup - Index and Fraction
  // Index Search method: 'binary'
  // Extrapolation method: 'Linear'
  // Use previous index: 'off'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    // Binary Search
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  // Column-major Interpolation 1-D
  // Interpolation method: 'Linear point-slope'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Overflow mode: 'wrapping'

  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

//
//         This function updates active task flag for each subrate.
//         The function is called at model base rate, hence the
//         generated code self-manages all its subrates.
//
static void rate_scheduler(PlanarModelandControl::RT_MODEL *const rtM)
{
  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (rtM->Timing.TaskCounters.TID[2])++;
  if ((rtM->Timing.TaskCounters.TID[2]) > 9) {// Sample time: [0.01s, 0.0s]
    rtM->Timing.TaskCounters.TID[2] = 0;
  }
}

//
// Output and update for atomic system:
//    '<S32>/Evaluate Rule Consequents'
//    '<S38>/Evaluate Rule Consequents'
//    '<S44>/Evaluate Rule Consequents'
//    '<S50>/Evaluate Rule Consequents'
//
void PlanarModelandControl::EvaluateRuleConsequents(const real_T
  rtu_antecedentOutputs[28], const real_T rtu_samplePoints[101], real_T
  rty_aggregatedOutputs[101])
{
  real_T outputMFCache[404];
  real_T rtu_samplePoints_0;
  int32_T outputMFCache_tmp;
  static const int8_T b_0[28]{ 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 3, 3, 4, 1, 2, 3, 1,
    2, 3, 3, 3, 4, 3, 4, 4, 4, 4, 4 };

  for (int32_T k{0}; k < 101; k++) {
    rty_aggregatedOutputs[k] = 0.0;
    rtu_samplePoints_0 = rtu_samplePoints[k];
    outputMFCache_tmp = k << 2;
    outputMFCache[outputMFCache_tmp] = std::exp(-((rtu_samplePoints_0 - -0.3) *
      (rtu_samplePoints_0 - -0.3)) / 0.009800000000000001);
    outputMFCache[outputMFCache_tmp + 1] = std::exp(-((rtu_samplePoints_0 - 0.14)
      * (rtu_samplePoints_0 - 0.14)) / 0.0128);
    outputMFCache[outputMFCache_tmp + 2] = std::exp(-((rtu_samplePoints_0 - 0.5)
      * (rtu_samplePoints_0 - 0.5)) / 0.020000000000000004);
    outputMFCache[outputMFCache_tmp + 3] = std::exp(-((rtu_samplePoints_0 - 0.85)
      * (rtu_samplePoints_0 - 0.85)) / 0.08000000000000002);
  }

  for (int32_T k{0}; k < 28; k++) {
    int8_T b;
    b = b_0[k];
    rtu_samplePoints_0 = rtu_antecedentOutputs[k];
    for (outputMFCache_tmp = 0; outputMFCache_tmp < 101; outputMFCache_tmp++) {
      real_T x_idx_0;
      real_T x_idx_0_0;
      x_idx_0 = outputMFCache[((outputMFCache_tmp << 2) + b) - 1];
      x_idx_0_0 = rty_aggregatedOutputs[outputMFCache_tmp];
      if (x_idx_0 > rtu_samplePoints_0) {
        x_idx_0 = rtu_samplePoints_0;
      } else if (std::isnan(x_idx_0)) {
        if (!std::isnan(rtu_samplePoints_0)) {
          x_idx_0 = rtu_samplePoints_0;
        } else {
          x_idx_0 = (rtNaN);
        }
      }

      if (x_idx_0_0 < x_idx_0) {
        rty_aggregatedOutputs[outputMFCache_tmp] = x_idx_0;
      } else if (std::isnan(x_idx_0_0)) {
        if (!std::isnan(x_idx_0)) {
          rty_aggregatedOutputs[outputMFCache_tmp] = x_idx_0;
        } else {
          rty_aggregatedOutputs[outputMFCache_tmp] = (rtNaN);
        }
      }
    }
  }
}

//
// Output and update for atomic system:
//    '<S128>/MATLAB Function4'
//    '<S128>/MATLAB Function5'
//
void PlanarModelandControl::MATLABFunction4(real_T rtu_u, real_T *rty_y)
{
  if (rtu_u <= 0.0) {
    *rty_y = 0.0;
  } else {
    *rty_y = rtu_u;
  }
}

//
// Output and update for atomic system:
//    '<S131>/MATLAB Function'
//    '<S132>/MATLAB Function'
//    '<S133>/MATLAB Function'
//    '<S134>/MATLAB Function'
//
void PlanarModelandControl::MATLABFunction(real_T rtu_Fz, real_T rtu_Dy, real_T
  rtu_Cy, real_T rtu_By, real_T rtu_Ey, real_T rtu_SVy, real_T rtu_SAy, real_T
  *rty_Fy)
{
  if (rtu_Fz <= 0.0) {
    *rty_Fy = 0.0;
  } else {
    real_T tmp;
    tmp = rtu_By * rtu_SAy;
    *rty_Fy = std::sin(std::atan(tmp - (tmp - std::atan(tmp)) * rtu_Ey) * rtu_Cy)
      * rtu_Dy + rtu_SVy;
  }
}

//
// Output and update for atomic system:
//    '<S135>/MATLAB Function'
//    '<S136>/MATLAB Function'
//    '<S137>/MATLAB Function'
//    '<S138>/MATLAB Function'
//
void PlanarModelandControl::MATLABFunction_m(real_T rtu_Slx, real_T rtu_Dx,
  real_T rtu_Cx, real_T rtu_Bx, real_T rtu_Ex, real_T rtu_SVx, real_T *rty_Fx)
{
  real_T tmp;
  tmp = rtu_Bx * rtu_Slx;
  *rty_Fx = std::sin(std::atan(tmp - (tmp - std::atan(tmp)) * rtu_Ex) * rtu_Cx) *
    rtu_Dx + rtu_SVx;
}

// Model step function
void PlanarModelandControl::step()
{
  // local block i/o variables
  real_T rtb_Gain2_d0;
  real_T rtb_DiscreteTimeIntegrator1;
  real_T rtb_Divide_fk;
  real_T rtb_Divide1_i;
  real_T rtb_Divide2_c;
  real_T rtb_Divide3_e;
  real_T rtb_Divide_ov;
  real_T rtb_Divide1_a;
  real_T rtb_Divide2_l;
  real_T rtb_Divide3_f;
  real_T rtb_Sum_bg;
  real_T rtb_Sum1_n;
  real_T rtb_Ax;
  real_T rtb_Ay_cg;
  real_T rtb_DeadZone_f;
  real_T rtb_TSamp;
  real_T rtb_TSamp_n;
  real_T rtb_TSamp_o;
  real_T rtb_TSamp_g;
  real_T rtb_IntegralGain;
  real_T rtb_aggregatedOutputs[101];
  real_T rtb_antecedentOutputs_l[28];
  real_T inputMFCache[11];
  real_T Product;
  real_T inner;
  real_T rtb_Diff;
  real_T rtb_Diff_b;
  real_T rtb_Diff_e;
  real_T rtb_Diff_k;
  real_T rtb_DiscreteTimeIntegrator;
  real_T rtb_DiscreteTimeIntegrator1_c;
  real_T rtb_FL_e0;
  real_T rtb_FL_po_tmp;
  real_T rtb_FR_b_tmp;
  real_T rtb_FR_j;
  real_T rtb_Fyref_FL;
  real_T rtb_Fyref_FR;
  real_T rtb_Gain_no;
  real_T rtb_Limitemx;
  real_T rtb_MathFunction;
  real_T rtb_Product1_j;
  real_T rtb_Product_a3;
  real_T rtb_Product_az;
  real_T rtb_Product_d1;
  real_T rtb_Product_ee;
  real_T rtb_Product_g2;
  real_T rtb_Product_mr;
  real_T rtb_Product_pk;
  real_T rtb_Product_ps;
  real_T rtb_RL_f;
  real_T rtb_RL_i;
  real_T rtb_RR_oe;
  real_T rtb_RateTransition3;
  real_T rtb_Saturation;
  real_T rtb_Saturation3;
  real_T rtb_Saturation3_o;
  real_T rtb_Saturation_c;
  real_T rtb_Sum1_ot;
  real_T rtb_Sum_bb;
  real_T rtb_Sum_if;
  real_T rtb_Sum_jr;
  real_T rtb_Sum_pz;
  real_T rtb_ZeroOrderHold13;
  real_T rtb_antecedentOutputs_b;
  real_T rtb_uDLookupTable;
  real_T rtb_uDLookupTable_tmp;
  real_T rtb_uDLookupTable_tmp_0;
  real_T rtb_v_yaw;
  real_T rtb_y_g;
  real_T rtb_y_h;
  int32_T i;
  boolean_T tmp;
  static const int8_T b[56]{ 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 4, 4, 4, 1, 2, 3, 1,
    1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 1, 1, 1, 2, 2, 2, 3, 3, 3, 1, 2, 3, 4, 4, 4,
    4, 5, 6, 7, 5, 6, 7, 5, 6, 7, 5, 6, 7 };

  // DiscreteTransferFcn: '<S127>/Discrete Transfer Fcn1'
  rtb_DiscreteTimeIntegrator1_c = 0.1813 * rtDW.DiscreteTransferFcn1_states;

  // DiscreteTransferFcn: '<S126>/Discrete Transfer Fcn2'
  rtb_Sum_pz = 0.1813 * rtDW.DiscreteTransferFcn2_states;

  // Gain: '<S126>/Gain4' incorporates:
  //   Gain: '<S126>/Gain7'

  rtb_RL_i = 38.0064 * rtb_Sum_pz;

  // Math: '<S115>/Square' incorporates:
  //   DiscreteIntegrator: '<S216>/Integrator'
  //   Math: '<S216>/Square'

  rtb_uDLookupTable_tmp_0 = rtDW.Integrator_DSTATE * rtDW.Integrator_DSTATE;

  // Gain: '<S115>/Gain10' incorporates:
  //   Math: '<S115>/Square'

  rtb_uDLookupTable = rtb_uDLookupTable_tmp_0 * 1.4884;

  // Sum: '<S126>/Sum' incorporates:
  //   Gain: '<S126>/Gain'
  //   Gain: '<S126>/Gain3'
  //   Gain: '<S126>/Gain4'
  //   Gain: '<S126>/Gain5'
  //   Sum: '<S126>/Sum1'

  rtb_antecedentOutputs_b = (5.0742400000000005 * rtb_Sum_pz + 4.411365228758171
    * rtb_Sum_pz) + rtb_RL_i * 0.3049797845258473;

  // Gain: '<S128>/Gain8' incorporates:
  //   Gain: '<S128>/Gain36'

  inner = 0.35 * rtb_uDLookupTable;

  // MATLAB Function: '<S128>/MATLAB Function4' incorporates:
  //   Constant: '<S128>/Constant20'
  //   Gain: '<S127>/Gain21'
  //   Gain: '<S128>/Gain8'
  //   Sum: '<S126>/Sum'
  //   Sum: '<S128>/Sum20'

  MATLABFunction4(((-24.680697967260294 * rtb_DiscreteTimeIntegrator1_c -
                    rtb_antecedentOutputs_b) + inner) + 662.1750000000001,
                  &rtb_y_g);

  // MATLAB Function: '<S128>/MATLAB Function5' incorporates:
  //   Constant: '<S128>/Constant22'
  //   Gain: '<S127>/Gain24'
  //   Sum: '<S128>/Sum21'

  MATLABFunction4(((-24.6806979672603 * rtb_DiscreteTimeIntegrator1_c +
                    rtb_antecedentOutputs_b) + inner) + 662.1750000000001,
                  &rtb_y_h);

  // Sum: '<S4>/Sum1' incorporates:
  //   Lookup_n-D: '<S4>/1-D Lookup Table'
  //   Lookup_n-D: '<S4>/1-D Lookup Table1'

  rtb_Sum1_ot = look1_binlx(rtb_y_g, rtConstP.pooled32, rtConstP.pooled31, 4U) +
    look1_binlx(rtb_y_h, rtConstP.pooled32, rtConstP.pooled31, 4U);

  // Sum: '<S126>/Sum2' incorporates:
  //   Gain: '<S126>/Gain1'
  //   Gain: '<S126>/Gain2'
  //   Gain: '<S126>/Gain6'
  //   Sum: '<S126>/Sum3'

  rtb_Sum_pz = (5.59136 * rtb_Sum_pz + 7.763752156862746 * rtb_Sum_pz) +
    rtb_RL_i * 0.7114817752978335;

  // Gain: '<S128>/Gain9' incorporates:
  //   Gain: '<S128>/Gain35'

  inner = 0.15 * rtb_uDLookupTable;

  // Sum: '<S128>/Sum22' incorporates:
  //   Constant: '<S128>/Constant21'
  //   Gain: '<S127>/Gain22'
  //   Gain: '<S128>/Gain9'
  //   Sum: '<S126>/Sum2'

  rtb_RL_i = ((24.680697967260294 * rtb_DiscreteTimeIntegrator1_c - rtb_Sum_pz)
              + inner) + 809.325;

  // Sum: '<S128>/Sum23' incorporates:
  //   Constant: '<S128>/Constant23'
  //   Gain: '<S127>/Gain23'

  rtb_DiscreteTimeIntegrator = ((24.6806979672603 *
    rtb_DiscreteTimeIntegrator1_c + rtb_Sum_pz) + inner) + 809.325;

  // Sum: '<S4>/Sum' incorporates:
  //   Lookup_n-D: '<S4>/1-D Lookup Table2'
  //   Lookup_n-D: '<S4>/1-D Lookup Table3'
  //   Sum: '<S128>/Sum22'
  //   Sum: '<S128>/Sum23'

  rtb_Sum_pz = look1_binlx(rtb_RL_i, rtConstP.pooled32, rtConstP.pooled31, 4U) +
    look1_binlx(rtb_DiscreteTimeIntegrator, rtConstP.pooled32, rtConstP.pooled31,
                4U);

  // RateTransition: '<S1>/Rate Transition10' incorporates:
  //   RateTransition generated from: '<Root>/Zero-Order Hold'
  //   RateTransition: '<S1>/Rate Transition3'
  //   RateTransition: '<S1>/Rate Transition4'
  //   RateTransition: '<S1>/Rate Transition6'
  //   RateTransition: '<S1>/Rate Transition8'
  //   RateTransition: '<S1>/Rate Transition9'
  //   RateTransition: '<S9>/Rate Transition4'
  //   RateTransition: '<S9>/Rate Transition5'

  tmp = ((&rtM)->Timing.TaskCounters.TID[2] == 0);
  if (tmp) {
    // RateTransition: '<S1>/Rate Transition10' incorporates:
    //   DiscreteIntegrator: '<S216>/Integrator'

    rtDW.RateTransition10 = rtDW.Integrator_DSTATE;

    // Product: '<S12>/Divide' incorporates:
    //   Abs: '<S12>/Abs'

    rtDW.Yaw_limit = 19.62 / std::abs(rtDW.RateTransition10);
  }

  // End of RateTransition: '<S1>/Rate Transition10'

  // FromWorkspace: '<Root>/From Workspace2'
  {
    real_T *pDataValues{ (real_T *) rtDW.FromWorkspace2_PWORK.DataPtr };

    real_T *pTimeValues{ (real_T *) rtDW.FromWorkspace2_PWORK.TimePtr };

    int_T currTimeIndex{ rtDW.FromWorkspace2_IWORK.PrevIndex };

    real_T t{ (&rtM)->Timing.t[0] };

    const real_T inputTimeTolerance{ 0.0 };

    // Get index
    if (t < pTimeValues[0] ||
        std::abs(t - pTimeValues[0]) <= inputTimeTolerance) {
      currTimeIndex = 0;
    } else if (t > pTimeValues[460] ||
               std::abs(t - pTimeValues[460]) <= inputTimeTolerance) {
      currTimeIndex = 459;
    } else {
      if (t < pTimeValues[currTimeIndex] &&
          std::abs(t - pTimeValues[currTimeIndex]) > inputTimeTolerance) {
        while (t < pTimeValues[currTimeIndex] &&
               std::abs(t - pTimeValues[currTimeIndex]) > inputTimeTolerance) {
          currTimeIndex--;
        }
      } else {
        while (currTimeIndex < 459) {
          double nextT{ pTimeValues[currTimeIndex + 1] };

          double dt{ t - nextT };

          double adt{ std::abs(dt) };

          if ((t > nextT || adt <= inputTimeTolerance)) {
            currTimeIndex++;
          } else if (pTimeValues[currTimeIndex] == nextT) {
            currTimeIndex++;
          } else {
            break;
          }
        }
      }
    }

    rtDW.FromWorkspace2_IWORK.PrevIndex = currTimeIndex;

    // Post output
    {
      real_T t1{ pTimeValues[currTimeIndex] };

      real_T t2{ pTimeValues[currTimeIndex + 1] };

      if (t1 == t2) {
        if (t < t1) {
          rtb_Gain2_d0 = pDataValues[currTimeIndex];
        } else {
          rtb_Gain2_d0 = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1{ (t2 - t) / (t2 - t1) };

        real_T f2{ 1.0 - f1 };

        real_T d1;
        real_T d2;
        int_T TimeIndex{ currTimeIndex };

        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        if (std::abs(t - t1) <= inputTimeTolerance) {
          rtb_Gain2_d0 = (real_T) d1;
          pDataValues += 461;
        } else if (std::abs(t - t2) <= inputTimeTolerance) {
          rtb_Gain2_d0 = (real_T) d2;
          pDataValues += 461;
        } else {
          rtb_Gain2_d0 = (real_T) rtInterpolate(d1, d2, f1, f2);
          pDataValues += 461;
        }
      }
    }
  }

  // Gain: '<S55>/Gain1' incorporates:
  //   Gain: '<S25>/Gain2'
  //   Lookup_n-D: '<S2>/1-D Lookup Table2'

  rtb_Product_az = 0.017453292519943295 * look1_binlx(rtb_Gain2_d0,
    rtConstP.pooled34, rtConstP.uDLookupTable2_tableData, 20U);

  // Gain: '<S54>/Gain1'
  rtb_RL_f = 0.017453292519943295 * rtb_Gain2_d0;

  // Gain: '<S25>/Gain2' incorporates:
  //   Gain: '<S56>/Gain1'
  //   Lookup_n-D: '<S2>/1-D Lookup Table3'

  rtb_Gain2_d0 = look1_binlx(rtb_Gain2_d0, rtConstP.pooled34,
    rtConstP.uDLookupTable3_tableData, 20U);
  rtb_Gain2_d0 *= 0.017453292519943295;

  // Switch: '<S2>/Switch2'
  if (rtb_RL_f > 0.0) {
    // Switch: '<S2>/Switch2'
    inner = rtb_Product_az;
  } else {
    // Switch: '<S2>/Switch2'
    inner = rtb_Gain2_d0;
  }

  // End of Switch: '<S2>/Switch2'

  // Lookup_n-D: '<S6>/1-D Lookup Table' incorporates:
  //   DiscreteIntegrator: '<S216>/Integrator'

  rtb_uDLookupTable = look1_binlx(rtDW.Integrator_DSTATE,
    rtConstP.uDLookupTable_bp01Data, rtConstP.uDLookupTable_tableData, 4U);

  // RateTransition: '<S1>/Rate Transition4'
  if (tmp) {
    // Product: '<S12>/Divide1' incorporates:
    //   Constant: '<S12>/Constant1'
    //   Math: '<S12>/Math Function'
    //   Product: '<S12>/Product'
    //   Sum: '<S12>/Sum'
    //
    //  About '<S12>/Math Function':
    //   Operator: magnitude^2

    rtDW.Divide1 = rtDW.RateTransition10 / (rtDW.RateTransition10 *
      rtDW.RateTransition10 * rtb_uDLookupTable + 1.53);
  }

  // Product: '<S12>/Product1'
  rtb_Saturation3_o = inner * rtDW.Divide1;

  // If: '<S12>/If' incorporates:
  //   Abs: '<S12>/Abs1'

  if (std::abs(rtb_Saturation3_o) > rtDW.Yaw_limit) {
    // Outputs for IfAction SubSystem: '<S12>/ref > limit' incorporates:
    //   ActionPort: '<S21>/Action Port'

    // Signum: '<S21>/Sign'
    if (std::isnan(rtb_Saturation3_o)) {
      rtb_antecedentOutputs_b = (rtNaN);
    } else if (rtb_Saturation3_o < 0.0) {
      rtb_antecedentOutputs_b = -1.0;
    } else {
      rtb_antecedentOutputs_b = (rtb_Saturation3_o > 0.0);
    }

    // Merge: '<S12>/Merge' incorporates:
    //   Product: '<S21>/Product'
    //   Signum: '<S21>/Sign'

    rtDW.yaw_ref = rtDW.Yaw_limit * rtb_antecedentOutputs_b;

    // End of Outputs for SubSystem: '<S12>/ref > limit'
  } else {
    // Outputs for IfAction SubSystem: '<S12>/ref < limit' incorporates:
    //   ActionPort: '<S20>/Action Port'

    // Merge: '<S12>/Merge' incorporates:
    //   SignalConversion generated from: '<S20>/Yaw_ref'

    rtDW.yaw_ref = rtb_Saturation3_o;

    // End of Outputs for SubSystem: '<S12>/ref < limit'
  }

  // End of If: '<S12>/If'

  // DiscreteIntegrator: '<S220>/Discrete-Time Integrator1'
  rtb_DiscreteTimeIntegrator1 = rtDW.DiscreteTimeIntegrator1_DSTATE;

  // RateTransition: '<S1>/Rate Transition9'
  if (tmp) {
    // RateTransition: '<S1>/Rate Transition9'
    rtDW.yaw_rate = rtb_DiscreteTimeIntegrator1;

    // Lookup_n-D: '<S13>/n-D Lookup Table1' incorporates:
    //   RateTransition: '<S1>/Rate Transition10'

    rtDW.nDLookupTable1 = look1_binlx(rtDW.RateTransition10, rtConstP.pooled36,
      rtConstP.nDLookupTable1_tableData, 6U);

    // Lookup_n-D: '<S13>/n-D Lookup Table' incorporates:
    //   RateTransition: '<S1>/Rate Transition10'

    rtDW.nDLookupTable = look1_binlx(rtDW.RateTransition10, rtConstP.pooled36,
      rtConstP.nDLookupTable_tableData, 6U);

    // Sum: '<S101>/Sum' incorporates:
    //   DiscreteIntegrator: '<S216>/Integrator'
    //   DiscreteIntegrator: '<S92>/Integrator'
    //   Gain: '<S97>/Proportional Gain'
    //   Sum: '<S2>/Sum'

    rtb_Limitemx = (5.0 - rtDW.Integrator_DSTATE) * 0.5 +
      rtDW.Integrator_DSTATE_c;

    // Saturate: '<S99>/Saturation'
    if (rtb_Limitemx > 1.0) {
      rtb_Saturation = 1.0;
    } else if (rtb_Limitemx < -1.0) {
      rtb_Saturation = -1.0;
    } else {
      rtb_Saturation = rtb_Limitemx;
    }

    // End of Saturate: '<S99>/Saturation'

    // Switch: '<S2>/Switch'
    if (rtb_Saturation >= 0.0) {
      // Switch: '<S2>/Switch'
      rtDW.Switch = rtb_Saturation;
    } else {
      // Switch: '<S2>/Switch' incorporates:
      //   Constant: '<S2>/Constant1'

      rtDW.Switch = 0.0;
    }

    // End of Switch: '<S2>/Switch'
  }

  // Sum: '<S13>/Sum'
  rtb_RR_oe = rtDW.yaw_ref - rtDW.yaw_rate;

  // Saturate: '<S112>/Saturation' incorporates:
  //   DiscreteIntegrator: '<S112>/Discrete-Time Integrator'

  if (rtDW.DiscreteTimeIntegrator_DSTATE <= 0.0) {
    rtb_Saturation_c = 0.0;
  } else {
    rtb_Saturation_c = rtDW.DiscreteTimeIntegrator_DSTATE;
  }

  // End of Saturate: '<S112>/Saturation'

  // Saturate: '<S112>/Saturation1' incorporates:
  //   DiscreteIntegrator: '<S112>/Discrete-Time Integrator1'

  if (rtDW.DiscreteTimeIntegrator1_DSTAT_e <= 0.0) {
    rtb_MathFunction = 0.0;
  } else {
    rtb_MathFunction = rtDW.DiscreteTimeIntegrator1_DSTAT_e;
  }

  // End of Saturate: '<S112>/Saturation1'

  // Saturate: '<S112>/Saturation2' incorporates:
  //   DiscreteIntegrator: '<S112>/Discrete-Time Integrator2'

  if (rtDW.DiscreteTimeIntegrator2_DSTATE <= 0.0) {
    rtb_DiscreteTimeIntegrator1_c = 0.0;
  } else {
    rtb_DiscreteTimeIntegrator1_c = rtDW.DiscreteTimeIntegrator2_DSTATE;
  }

  // End of Saturate: '<S112>/Saturation2'

  // Saturate: '<S112>/Saturation3' incorporates:
  //   DiscreteIntegrator: '<S112>/Discrete-Time Integrator3'

  if (rtDW.DiscreteTimeIntegrator3_DSTATE <= 0.0) {
    rtb_Saturation3 = 0.0;
  } else {
    rtb_Saturation3 = rtDW.DiscreteTimeIntegrator3_DSTATE;
  }

  // End of Saturate: '<S112>/Saturation3'

  // Product: '<S1>/Product' incorporates:
  //   Gain: '<S7>/Gain'
  //   Gain: '<S7>/Gain1'
  //   Gain: '<S7>/Gain2'
  //   Gain: '<S7>/Gain3'
  //   Lookup_n-D: '<S7>/1-D Lookup Table'
  //   Lookup_n-D: '<S7>/1-D Lookup Table1'
  //   Lookup_n-D: '<S7>/1-D Lookup Table2'
  //   Lookup_n-D: '<S7>/1-D Lookup Table3'
  //   Sum: '<S7>/Sum'
  //   Switch: '<S2>/Switch6'
  //   Switch: '<S7>/Switch'
  //   Switch: '<S7>/Switch1'
  //   Switch: '<S7>/Switch2'
  //   Switch: '<S7>/Switch3'

  Product = (((look1_binlx(111.91775598222081 * rtb_Saturation_c,
    rtConstP.pooled41, rtConstP.pooled40, 27U) + look1_binlx(111.91775598222081 *
    rtb_MathFunction, rtConstP.pooled41, rtConstP.pooled40, 27U)) + look1_binlx
              (111.91775598222081 * rtb_DiscreteTimeIntegrator1_c,
               rtConstP.pooled41, rtConstP.pooled40, 27U)) + look1_binlx
             (111.91775598222081 * rtb_Saturation3, rtConstP.pooled41,
              rtConstP.pooled40, 27U)) * rtDW.Switch;

  // RateTransition: '<S1>/Rate Transition3'
  if (tmp) {
    rtb_RateTransition3 = Product;

    // Lookup_n-D: '<S13>/Limite min'
    rtDW.Limitemin = look1_binlx(Product, rtConstP.pooled2, rtConstP.pooled1,
      25U);

    // Lookup_n-D: '<S13>/Limite máx'
    rtDW.Limitemx = look1_binlx(Product, rtConstP.pooled2, rtConstP.pooled42,
      25U);
  }

  // Sum: '<S13>/Sum1' incorporates:
  //   Gain: '<S13>/Gain'
  //   Product: '<S13>/KI'
  //   UnitDelay: '<S13>/Unit Delay'

  rtDW.Sum1 = rtb_RR_oe * rtDW.nDLookupTable1 * 0.001 + rtDW.UnitDelay_DSTATE;

  // Sum: '<S13>/Sum2' incorporates:
  //   Product: '<S13>/KP'

  rtb_Saturation3_o = rtb_RR_oe * rtDW.nDLookupTable + rtDW.Sum1;

  // Switch: '<S16>/Switch2' incorporates:
  //   RelationalOperator: '<S16>/LowerRelop1'
  //   RelationalOperator: '<S16>/UpperRelop'
  //   Switch: '<S16>/Switch'

  if (rtb_Saturation3_o > rtDW.Limitemx) {
    rtb_RR_oe = rtDW.Limitemx;
  } else if (rtb_Saturation3_o < rtDW.Limitemin) {
    // Switch: '<S16>/Switch'
    rtb_RR_oe = rtDW.Limitemin;
  } else {
    rtb_RR_oe = rtb_Saturation3_o;
  }

  // End of Switch: '<S16>/Switch2'

  // RateTransition: '<S1>/Rate Transition6' incorporates:
  //   RateTransition: '<S1>/Rate Transition5'

  if (tmp) {
    // Lookup_n-D: '<S14>/Limite máx' incorporates:
    //   RateTransition: '<S1>/Rate Transition3'

    rtb_Limitemx = look1_binlx(rtb_RateTransition3, rtConstP.pooled2,
      rtConstP.pooled42, 25U);

    // Gain: '<S6>/Gain2' incorporates:
    //   Gain: '<S14>/Gain'
    //   Product: '<S6>/Product'

    rtb_Saturation3_o = rtb_Sum1_ot * rtb_Sum_pz * 3.06;

    // Product: '<S14>/Product1' incorporates:
    //   Gain: '<S6>/Gain'
    //   Gain: '<S6>/Gain1'
    //   Gain: '<S6>/Gain2'
    //   Gain: '<S6>/Gain3'
    //   Product: '<S14>/Divide'
    //   Product: '<S6>/Divide'
    //   RateTransition: '<S1>/Rate Transition7'
    //   Sum: '<S14>/Add'
    //   Sum: '<S6>/Subtract'
    //   Sum: '<S6>/Subtract1'

    rtb_Product1_j = (rtb_uDLookupTable - (0.8415000000000001 * rtb_Sum1_ot -
      0.6885 * rtb_Sum_pz) * 300.0 / rtb_Saturation3_o) * (rtb_Saturation3_o /
      (rtb_Sum_pz + rtb_Sum1_ot));

    // Abs: '<S185>/Abs' incorporates:
    //   Constant: '<S185>/Constant2'

    rtDW.Abs = 1.0;
  }

  // Abs: '<S121>/Abs' incorporates:
  //   DiscreteIntegrator: '<S216>/Integrator'

  rtb_ZeroOrderHold13 = std::abs(rtDW.Integrator_DSTATE);

  // Product: '<S190>/Divide' incorporates:
  //   Constant: '<S190>/Constant'
  //   Gain: '<S190>/Gain'
  //   Sum: '<S190>/Sum'

  rtb_Sum_pz = (-rtb_y_g - -811.9083) / -811.9083;

  // Gain: '<S186>/Gain3' incorporates:
  //   Gain: '<S186>/Gain'
  //   Gain: '<S186>/Gain1'
  //   Gain: '<S186>/Gain2'
  //   Math: '<S186>/Exp'
  //   Product: '<S186>/Product'
  //   Product: '<S186>/Product1'
  //   Sum: '<S186>/Sum'
  //
  //  About '<S186>/Exp':
  //   Operator: exp

  rtb_Saturation3_o = (22.3857 * rtb_Sum_pz - 36.9039) * -rtb_y_g * std::exp
    (0.61844 * rtb_Sum_pz) * 0.9173523089876809;

  // Gain: '<S121>/Gain' incorporates:
  //   Gain: '<S215>/Gain'

  rtb_FL_po_tmp = 0.2 * rtb_Saturation_c;

  // Product: '<S121>/Divide' incorporates:
  //   Gain: '<S121>/Gain'
  //   Gain: '<S121>/Gain4'
  //   Gain: '<S122>/Gain1'
  //   MinMax: '<S121>/Max'
  //   Product: '<S122>/Product'
  //   Sum: '<S121>/Sum'

  rtb_FL_e0 = (rtb_FL_po_tmp - rtb_ZeroOrderHold13) / std::fmax
    (rtb_ZeroOrderHold13, 0.06231939047619048 * rtb_Saturation3_o * 0.0005 * 1.1);

  // Product: '<S184>/Product' incorporates:
  //   Constant: '<S184>/Constant'
  //   Gain: '<S184>/Gain'
  //   Gain: '<S184>/Gain1'
  //   Gain: '<S184>/Gain3'
  //   Sum: '<S184>/Sum'

  rtb_Product_ps = (-0.065814 * rtb_Sum_pz + 2.1568) * 0.9814642540325506 *
    -rtb_y_g;

  // Signum: '<S185>/Sign'
  if (std::isnan(rtb_FL_e0)) {
    // Signum: '<S201>/Sign'
    rtb_Saturation_c = (rtNaN);
  } else if (rtb_FL_e0 < 0.0) {
    // Signum: '<S201>/Sign'
    rtb_Saturation_c = -1.0;
  } else {
    // Signum: '<S201>/Sign'
    rtb_Saturation_c = (rtb_FL_e0 > 0.0);
  }

  // MATLAB Function: '<S135>/MATLAB Function' incorporates:
  //   Constant: '<S135>/Constant1'
  //   Constant: '<S185>/Constant2'
  //   Gain: '<S183>/Gain'
  //   Gain: '<S185>/Gain'
  //   Gain: '<S185>/Gain1'
  //   Gain: '<S185>/Gain2'
  //   Gain: '<S188>/Gain'
  //   Gain: '<S189>/Gain'
  //   Gain: '<S189>/Gain1'
  //   Math: '<S185>/Square'
  //   MinMax: '<S185>/Min'
  //   Product: '<S183>/Divide'
  //   Product: '<S185>/Product'
  //   Product: '<S185>/Product1'
  //   Product: '<S189>/Product'
  //   Signum: '<S185>/Sign'
  //   Sum: '<S185>/Sum'
  //   Sum: '<S185>/Sum1'
  //   Sum: '<S188>/Sum'
  //   Sum: '<S188>/Sum1'
  //   Sum: '<S189>/Sum'

  MATLABFunction_m(rtb_FL_e0 + (-0.000374 * rtb_Sum_pz - 0.003859),
                   rtb_Product_ps, 1.3668, rtb_Saturation3_o / (1.3668 *
    rtb_Sum_pz), std::fmin(((-0.62529 * rtb_Sum_pz - 0.19815) + 1.3396 *
    (rtb_Sum_pz * rtb_Sum_pz)) * (1.0 - 0.0029464 * (rtDW.Abs * rtb_Saturation_c)),
    1.0), -rtb_y_g * (0.002205 * rtb_Sum_pz - 0.11922), &rtb_v_yaw);

  // Switch: '<S135>/Switch' incorporates:
  //   Constant: '<S135>/Constant'

  if (rtb_FL_e0 != 0.0) {
    rtb_Sum_pz = rtb_v_yaw;
  } else {
    rtb_Sum_pz = 0.0;
  }

  // End of Switch: '<S135>/Switch'

  // Signum: '<S118>/Sign' incorporates:
  //   DiscreteIntegrator: '<S216>/Integrator'

  if (std::isnan(rtDW.Integrator_DSTATE)) {
    rtb_Saturation3_o = (rtNaN);
  } else if (rtDW.Integrator_DSTATE < 0.0) {
    rtb_Saturation3_o = -1.0;
  } else {
    rtb_Saturation3_o = (rtDW.Integrator_DSTATE > 0.0);
  }

  // End of Signum: '<S118>/Sign'

  // Gain: '<S118>/Gain28' incorporates:
  //   Constant: '<S118>/Constant12'
  //   DiscreteIntegrator: '<S216>/Integrator'
  //   Gain: '<S118>/Gain27'
  //   Gain: '<S118>/Gain30'
  //   Gain: '<S118>/Gain32'
  //   Gain: '<S118>/Gain34'
  //   Sum: '<S118>/Sum12'

  rtb_uDLookupTable_tmp = (0.0024 * rtDW.Integrator_DSTATE + 1.0) * 0.01;

  // Product: '<S118>/Product4' incorporates:
  //   Gain: '<S118>/Gain28'

  rtb_uDLookupTable = rtb_uDLookupTable_tmp * rtb_y_g * rtb_Saturation3_o;

  // Saturate: '<S118>/Saturation'
  if (rtb_uDLookupTable <= 0.0) {
    rtb_uDLookupTable = 0.0;
  }

  // End of Saturate: '<S118>/Saturation'

  // RateTransition generated from: '<Root>/Zero-Order Hold'
  if (tmp) {
    // RateTransition generated from: '<Root>/Zero-Order Hold'
    rtDW.steering_inner = inner;

    // Trigonometry: '<S221>/Cos'
    rtDW.Cos = std::sin(rtDW.steering_inner);

    // Abs: '<S143>/Abs' incorporates:
    //   Constant: '<S143>/Constant1'

    rtb_Gain_no = 0.0;

    // Sum: '<S143>/Sum' incorporates:
    //   Constant: '<S143>/Constant2'
    //   Gain: '<S143>/Gain1'

    rtDW.Sum_g = 1.0;
  }

  // MinMax: '<S113>/Min' incorporates:
  //   Gain: '<S113>/Gain4'

  inner = std::fmin(rtb_Sum_pz, -rtb_Product_ps);

  // Product: '<S149>/Divide' incorporates:
  //   Constant: '<S149>/Constant'
  //   Gain: '<S149>/Gain3'
  //   Sum: '<S149>/Sum'

  rtb_Sum1_ot = (-rtb_y_g - -210.9467) / -210.9467;

  // Product: '<S140>/Product' incorporates:
  //   Constant: '<S140>/Constant'
  //   Gain: '<S140>/Gain'
  //   Gain: '<S140>/Gain2'
  //   Gain: '<S140>/Gain4'
  //   Sum: '<S140>/Sum'

  rtb_Product_d1 = (-0.11197 * rtb_Sum1_ot + 2.453) * 0.9701799812761553 *
    -rtb_y_g;

  // Gain: '<S143>/Gain2' incorporates:
  //   Constant: '<S143>/Constant'
  //   Gain: '<S143>/Gain'
  //   Gain: '<S143>/Gain3'
  //   Gain: '<S143>/Gain4'
  //   Product: '<S143>/Divide'
  //   Product: '<S143>/Product'
  //   Trigonometry: '<S143>/Atan'
  //   Trigonometry: '<S143>/Sin'

  rtb_Fyref_FL = std::sin(std::atan(-rtb_y_g / 1517.0796012861272) * 2.9994) *
    rtDW.Sum_g * 1.093601981645556 * 17561.861236419998;

  // Sum: '<S145>/Sum' incorporates:
  //   DiscreteIntegrator: '<S215>/Discrete-Time Integrator'
  //   Gain: '<S142>/Gain'
  //   Gain: '<S142>/Gain1'
  //   Gain: '<S142>/Gain3'
  //   Gain: '<S146>/Gain'
  //   Gain: '<S146>/Gain1'
  //   Gain: '<S148>/Gain'
  //   Gain: '<S148>/Gain1'
  //   Gain: '<S148>/Gain3'
  //   Product: '<S142>/Product'
  //   Product: '<S146>/Divide'
  //   Product: '<S148>/Product'
  //   Sum: '<S142>/Sum'
  //   Sum: '<S146>/Sum'
  //   Sum: '<S146>/Sum1'
  //   Sum: '<S146>/Sum2'
  //   Sum: '<S148>/Sum'

  rtb_Sum_bb = (((-0.91452 * rtb_Sum1_ot - 3.4705) * (0.798856916366887 *
    -rtb_y_g) * 0.0 - (0.53712 * rtb_Sum1_ot - 1.0429) * 0.0 * -rtb_y_g) /
                rtb_Fyref_FL + (-0.000261 * rtb_Sum1_ot - 0.000403)) +
    rtDW.DiscreteTimeIntegrator_DSTATE_d;

  // Signum: '<S141>/Sign'
  if (std::isnan(rtb_Sum_bb)) {
    rtb_antecedentOutputs_b = (rtNaN);
  } else if (rtb_Sum_bb < 0.0) {
    rtb_antecedentOutputs_b = -1.0;
  } else {
    rtb_antecedentOutputs_b = (rtb_Sum_bb > 0.0);
  }

  // MATLAB Function: '<S131>/MATLAB Function' incorporates:
  //   Constant: '<S131>/Constant'
  //   Constant: '<S139>/Constant'
  //   Constant: '<S141>/Constant'
  //   Constant: '<S141>/Constant1'
  //   Constant: '<S147>/Constant'
  //   Gain: '<S141>/Gain'
  //   Gain: '<S141>/Gain1'
  //   Gain: '<S147>/Gain'
  //   Gain: '<S147>/Gain1'
  //   Gain: '<S147>/Gain3'
  //   MinMax: '<S141>/Min'
  //   Product: '<S139>/Divide'
  //   Product: '<S139>/Product'
  //   Product: '<S141>/Product'
  //   Product: '<S147>/Product'
  //   Signum: '<S141>/Sign'
  //   Sum: '<S139>/Sum'
  //   Sum: '<S141>/Sum'
  //   Sum: '<S147>/Sum'

  MATLABFunction(rtb_y_g, rtb_Product_d1, 1.839, rtb_Fyref_FL / (1.839 *
    (rtb_Product_d1 + 0.0001)), std::fmin((-0.28662 * rtb_Sum1_ot + 0.96085) *
    (0.85611 * rtb_antecedentOutputs_b), 1.0), 0.0 * ((0.018068 * rtb_Sum1_ot +
    0.032907) * -rtb_y_g), rtb_Sum_bb, &rtb_v_yaw);

  // Product: '<S113>/Product8' incorporates:
  //   Constant: '<S113>/Constant12'
  //   Math: '<S113>/Square13'
  //   Math: '<S113>/Square14'
  //   Product: '<S113>/Divide4'
  //   Sqrt: '<S113>/Square Root4'
  //   Sum: '<S113>/Sum4'

  inner = std::sqrt(1.0 - inner * inner / (rtb_Product_ps * rtb_Product_ps)) *
    rtb_v_yaw;
  if (tmp) {
    // Trigonometry: '<S221>/Cos1'
    rtDW.Cos1 = std::cos(rtDW.steering_inner);

    // Abs: '<S193>/Abs' incorporates:
    //   Constant: '<S193>/Constant2'

    rtDW.Abs_n = 1.0;
  }

  // Sum: '<S221>/Sum' incorporates:
  //   Sum: '<S219>/Sum'

  rtb_uDLookupTable = rtb_Sum_pz - rtb_uDLookupTable;

  // Sum: '<S221>/Sum1' incorporates:
  //   Product: '<S221>/Product'
  //   Product: '<S221>/Product1'
  //   Sum: '<S221>/Sum'

  rtb_Fyref_FL = rtb_uDLookupTable * rtDW.Cos + inner * rtDW.Cos1;

  // Product: '<S198>/Divide' incorporates:
  //   Constant: '<S198>/Constant'
  //   Gain: '<S198>/Gain'
  //   Sum: '<S198>/Sum'

  rtb_Sum1_ot = (-rtb_y_h - -811.9083) / -811.9083;

  // Gain: '<S194>/Gain3' incorporates:
  //   Gain: '<S194>/Gain'
  //   Gain: '<S194>/Gain1'
  //   Gain: '<S194>/Gain2'
  //   Math: '<S194>/Exp'
  //   Product: '<S194>/Product'
  //   Product: '<S194>/Product1'
  //   Sum: '<S194>/Sum'
  //
  //  About '<S194>/Exp':
  //   Operator: exp

  rtb_Product_ps = (22.3857 * rtb_Sum1_ot - 36.9039) * -rtb_y_h * std::exp
    (0.61844 * rtb_Sum1_ot) * 0.9173523089876809;

  // Gain: '<S121>/Gain1' incorporates:
  //   Gain: '<S215>/Gain1'

  rtb_FR_b_tmp = 0.2 * rtb_MathFunction;

  // Product: '<S121>/Divide1' incorporates:
  //   Gain: '<S121>/Gain1'
  //   Gain: '<S121>/Gain5'
  //   Gain: '<S123>/Gain1'
  //   MinMax: '<S121>/Max1'
  //   Product: '<S123>/Product'
  //   Sum: '<S121>/Sum1'

  rtb_FR_j = (rtb_FR_b_tmp - rtb_ZeroOrderHold13) / std::fmax
    (rtb_ZeroOrderHold13, 0.06231939047619048 * rtb_Product_ps * 0.0005 * 1.1);

  // Product: '<S192>/Product' incorporates:
  //   Constant: '<S192>/Constant'
  //   Gain: '<S192>/Gain'
  //   Gain: '<S192>/Gain1'
  //   Gain: '<S192>/Gain3'
  //   Sum: '<S192>/Sum'

  rtb_MathFunction = (-0.065814 * rtb_Sum1_ot + 2.1568) * 0.9814642540325506 *
    -rtb_y_h;

  // Signum: '<S193>/Sign'
  if (std::isnan(rtb_FR_j)) {
    rtb_antecedentOutputs_b = (rtNaN);
  } else if (rtb_FR_j < 0.0) {
    rtb_antecedentOutputs_b = -1.0;
  } else {
    rtb_antecedentOutputs_b = (rtb_FR_j > 0.0);
  }

  // MATLAB Function: '<S136>/MATLAB Function' incorporates:
  //   Constant: '<S136>/Constant1'
  //   Constant: '<S193>/Constant2'
  //   Gain: '<S191>/Gain'
  //   Gain: '<S193>/Gain'
  //   Gain: '<S193>/Gain1'
  //   Gain: '<S193>/Gain2'
  //   Gain: '<S196>/Gain'
  //   Gain: '<S197>/Gain'
  //   Gain: '<S197>/Gain1'
  //   Math: '<S193>/Square'
  //   MinMax: '<S193>/Min'
  //   Product: '<S191>/Divide'
  //   Product: '<S193>/Product'
  //   Product: '<S193>/Product1'
  //   Product: '<S197>/Product'
  //   Signum: '<S193>/Sign'
  //   Sum: '<S193>/Sum'
  //   Sum: '<S193>/Sum1'
  //   Sum: '<S196>/Sum'
  //   Sum: '<S196>/Sum1'
  //   Sum: '<S197>/Sum'

  MATLABFunction_m(rtb_FR_j + (-0.000374 * rtb_Sum1_ot - 0.003859),
                   rtb_MathFunction, 1.3668, rtb_Product_ps / (1.3668 *
    rtb_Sum1_ot), std::fmin(((-0.62529 * rtb_Sum1_ot - 0.19815) + 1.3396 *
    (rtb_Sum1_ot * rtb_Sum1_ot)) * (1.0 - 0.0029464 * (rtDW.Abs_n *
    rtb_antecedentOutputs_b)), 1.0), -rtb_y_h * (0.002205 * rtb_Sum1_ot -
    0.11922), &rtb_v_yaw);

  // Switch: '<S136>/Switch' incorporates:
  //   Constant: '<S136>/Constant'

  if (rtb_FR_j != 0.0) {
    rtb_Product_ps = rtb_v_yaw;
  } else {
    rtb_Product_ps = 0.0;
  }

  // End of Switch: '<S136>/Switch'

  // Product: '<S118>/Product5'
  rtb_Sum1_ot = rtb_uDLookupTable_tmp * rtb_y_h * rtb_Saturation3_o;

  // Saturate: '<S118>/Saturation1'
  if (rtb_Sum1_ot <= 0.0) {
    rtb_Sum1_ot = 0.0;
  }

  // End of Saturate: '<S118>/Saturation1'

  // RateTransition generated from: '<Root>/Zero-Order Hold'
  if (tmp) {
    // Switch: '<S2>/Switch3'
    if (rtb_RL_f > 0.0) {
      // RateTransition generated from: '<Root>/Zero-Order Hold'
      rtDW.steering_outer = rtb_Gain2_d0;
    } else {
      // RateTransition generated from: '<Root>/Zero-Order Hold'
      rtDW.steering_outer = rtb_Product_az;
    }

    // End of Switch: '<S2>/Switch3'

    // Trigonometry: '<S221>/Cos2'
    rtDW.Cos2 = std::sin(rtDW.steering_outer);

    // Abs: '<S154>/Abs' incorporates:
    //   Constant: '<S154>/Constant1'

    rtb_Gain_no = 0.0;

    // Sum: '<S154>/Sum' incorporates:
    //   Constant: '<S154>/Constant2'
    //   Gain: '<S154>/Gain1'

    rtDW.Sum_j = 1.0;
  }

  // MinMax: '<S113>/Min3' incorporates:
  //   Gain: '<S113>/Gain3'

  rtb_Product_d1 = std::fmin(rtb_Product_ps, -rtb_MathFunction);

  // Product: '<S160>/Divide' incorporates:
  //   Constant: '<S160>/Constant'
  //   Gain: '<S160>/Gain3'
  //   Sum: '<S160>/Sum'

  rtb_Sum_bb = (-rtb_y_h - -210.9467) / -210.9467;

  // Product: '<S151>/Product' incorporates:
  //   Constant: '<S151>/Constant'
  //   Gain: '<S151>/Gain'
  //   Gain: '<S151>/Gain2'
  //   Gain: '<S151>/Gain4'
  //   Sum: '<S151>/Sum'

  rtb_Product_a3 = (-0.11197 * rtb_Sum_bb + 2.453) * 0.9701799812761553 *
    -rtb_y_h;

  // Gain: '<S154>/Gain2' incorporates:
  //   Constant: '<S154>/Constant'
  //   Gain: '<S154>/Gain'
  //   Gain: '<S154>/Gain3'
  //   Gain: '<S154>/Gain4'
  //   Product: '<S154>/Divide'
  //   Product: '<S154>/Product'
  //   Trigonometry: '<S154>/Atan'
  //   Trigonometry: '<S154>/Sin'

  rtb_Fyref_FR = std::sin(std::atan(-rtb_y_h / 1517.0796012861272) * 2.9994) *
    rtDW.Sum_j * 1.093601981645556 * 17561.861236419998;

  // Sum: '<S156>/Sum' incorporates:
  //   DiscreteIntegrator: '<S215>/Discrete-Time Integrator1'
  //   Gain: '<S153>/Gain'
  //   Gain: '<S153>/Gain1'
  //   Gain: '<S153>/Gain3'
  //   Gain: '<S157>/Gain'
  //   Gain: '<S157>/Gain1'
  //   Gain: '<S159>/Gain'
  //   Gain: '<S159>/Gain1'
  //   Gain: '<S159>/Gain3'
  //   Product: '<S153>/Product'
  //   Product: '<S157>/Divide'
  //   Product: '<S159>/Product'
  //   Sum: '<S153>/Sum'
  //   Sum: '<S157>/Sum'
  //   Sum: '<S157>/Sum1'
  //   Sum: '<S157>/Sum2'
  //   Sum: '<S159>/Sum'

  rtb_Product_az = (((-0.91452 * rtb_Sum_bb - 3.4705) * (0.798856916366887 *
    -rtb_y_h) * 0.0 - (0.53712 * rtb_Sum_bb - 1.0429) * 0.0 * -rtb_y_h) /
                    rtb_Fyref_FR + (-0.000261 * rtb_Sum_bb - 0.000403)) +
    rtDW.DiscreteTimeIntegrator1_DSTAT_d;

  // Signum: '<S152>/Sign'
  if (std::isnan(rtb_Product_az)) {
    rtb_antecedentOutputs_b = (rtNaN);
  } else if (rtb_Product_az < 0.0) {
    rtb_antecedentOutputs_b = -1.0;
  } else {
    rtb_antecedentOutputs_b = (rtb_Product_az > 0.0);
  }

  // MATLAB Function: '<S132>/MATLAB Function' incorporates:
  //   Constant: '<S132>/Constant'
  //   Constant: '<S150>/Constant'
  //   Constant: '<S152>/Constant'
  //   Constant: '<S152>/Constant1'
  //   Constant: '<S158>/Constant'
  //   Gain: '<S152>/Gain'
  //   Gain: '<S152>/Gain1'
  //   Gain: '<S158>/Gain'
  //   Gain: '<S158>/Gain1'
  //   Gain: '<S158>/Gain3'
  //   MinMax: '<S152>/Min'
  //   Product: '<S150>/Divide'
  //   Product: '<S150>/Product'
  //   Product: '<S152>/Product'
  //   Product: '<S158>/Product'
  //   Signum: '<S152>/Sign'
  //   Sum: '<S150>/Sum'
  //   Sum: '<S152>/Sum'
  //   Sum: '<S158>/Sum'

  MATLABFunction(rtb_y_h, rtb_Product_a3, 1.839, rtb_Fyref_FR / (1.839 *
    (rtb_Product_a3 + 0.0001)), std::fmin((-0.28662 * rtb_Sum_bb + 0.96085) *
    (0.85611 * rtb_antecedentOutputs_b), 1.0), 0.0 * ((0.018068 * rtb_Sum_bb +
    0.032907) * -rtb_y_h), rtb_Product_az, &rtb_v_yaw);

  // Product: '<S113>/Product3' incorporates:
  //   Constant: '<S113>/Constant3'
  //   Math: '<S113>/Square5'
  //   Math: '<S113>/Square6'
  //   Product: '<S113>/Divide3'
  //   Sqrt: '<S113>/Square Root3'
  //   Sum: '<S113>/Sum3'

  rtb_Product_d1 = std::sqrt(1.0 - rtb_Product_d1 * rtb_Product_d1 /
    (rtb_MathFunction * rtb_MathFunction)) * rtb_v_yaw;
  if (tmp) {
    // Trigonometry: '<S221>/Cos3'
    rtDW.Cos3 = std::cos(rtDW.steering_outer);

    // Abs: '<S201>/Abs' incorporates:
    //   Constant: '<S201>/Constant2'

    rtDW.Abs_n0 = 1.0;
  }

  // Sum: '<S221>/Sum2' incorporates:
  //   Sum: '<S219>/Sum2'

  rtb_Sum1_ot = rtb_Product_ps - rtb_Sum1_ot;

  // Sum: '<S221>/Sum3' incorporates:
  //   Product: '<S221>/Product2'
  //   Product: '<S221>/Product3'
  //   Sum: '<S221>/Sum2'

  rtb_Fyref_FR = rtb_Sum1_ot * rtDW.Cos2 + rtb_Product_d1 * rtDW.Cos3;

  // Product: '<S206>/Divide' incorporates:
  //   Constant: '<S206>/Constant'
  //   Gain: '<S206>/Gain'
  //   Sum: '<S206>/Sum'

  rtb_Sum_bb = (-rtb_RL_i - -811.9083) / -811.9083;

  // Product: '<S200>/Product' incorporates:
  //   Constant: '<S200>/Constant'
  //   Gain: '<S200>/Gain'
  //   Gain: '<S200>/Gain1'
  //   Gain: '<S200>/Gain3'
  //   Sum: '<S200>/Sum'

  rtb_Product_pk = (-0.065814 * rtb_Sum_bb + 2.1568) * 0.9814642540325506 *
    -rtb_RL_i;

  // Gain: '<S202>/Gain3' incorporates:
  //   Gain: '<S202>/Gain'
  //   Gain: '<S202>/Gain1'
  //   Gain: '<S202>/Gain2'
  //   Math: '<S202>/Exp'
  //   Product: '<S202>/Product'
  //   Product: '<S202>/Product1'
  //   Sum: '<S202>/Sum'
  //
  //  About '<S202>/Exp':
  //   Operator: exp

  rtb_Product_az = (22.3857 * rtb_Sum_bb - 36.9039) * -rtb_RL_i * std::exp
    (0.61844 * rtb_Sum_bb) * 0.9173523089876809;

  // MATLAB Function: '<S137>/MATLAB Function' incorporates:
  //   Constant: '<S137>/Constant1'
  //   Constant: '<S201>/Constant2'
  //   Gain: '<S199>/Gain'
  //   Gain: '<S201>/Gain'
  //   Gain: '<S201>/Gain1'
  //   Gain: '<S201>/Gain2'
  //   Gain: '<S204>/Gain'
  //   Gain: '<S205>/Gain'
  //   Gain: '<S205>/Gain1'
  //   Math: '<S201>/Square'
  //   MinMax: '<S201>/Min'
  //   Product: '<S199>/Divide'
  //   Product: '<S201>/Product'
  //   Product: '<S201>/Product1'
  //   Product: '<S205>/Product'
  //   Sum: '<S201>/Sum'
  //   Sum: '<S201>/Sum1'
  //   Sum: '<S204>/Sum'
  //   Sum: '<S204>/Sum1'
  //   Sum: '<S205>/Sum'

  MATLABFunction_m(rtb_FL_e0 + (-0.000374 * rtb_Sum_bb - 0.003859),
                   rtb_Product_pk, 1.3668, rtb_Product_az / (1.3668 * rtb_Sum_bb),
                   std::fmin(((-0.62529 * rtb_Sum_bb - 0.19815) + 1.3396 *
    (rtb_Sum_bb * rtb_Sum_bb)) * (1.0 - 0.0029464 * (rtDW.Abs_n0 *
    rtb_Saturation_c)), 1.0), -rtb_RL_i * (0.002205 * rtb_Sum_bb - 0.11922),
                   &rtb_v_yaw);

  // Switch: '<S137>/Switch' incorporates:
  //   Constant: '<S137>/Constant'

  if (rtb_FL_e0 != 0.0) {
    rtb_Saturation_c = rtb_v_yaw;
  } else {
    rtb_Saturation_c = 0.0;
  }

  // End of Switch: '<S137>/Switch'

  // MinMax: '<S113>/Min2' incorporates:
  //   Gain: '<S113>/Gain2'

  rtb_Sum_bb = std::fmin(rtb_Saturation_c, -rtb_Product_pk);

  // Product: '<S171>/Divide' incorporates:
  //   Constant: '<S171>/Constant'
  //   Gain: '<S171>/Gain3'
  //   Sum: '<S171>/Sum'

  rtb_MathFunction = (-rtb_RL_i - -210.9467) / -210.9467;

  // Product: '<S162>/Product' incorporates:
  //   Constant: '<S162>/Constant'
  //   Gain: '<S162>/Gain'
  //   Gain: '<S162>/Gain2'
  //   Gain: '<S162>/Gain4'
  //   Sum: '<S162>/Sum'

  rtb_Product_g2 = (-0.11197 * rtb_MathFunction + 2.453) * 0.9701799812761553 *
    -rtb_RL_i;
  if (tmp) {
    // Abs: '<S165>/Abs' incorporates:
    //   Constant: '<S165>/Constant1'

    rtb_Gain_no = 0.0;

    // Sum: '<S165>/Sum' incorporates:
    //   Constant: '<S165>/Constant2'
    //   Gain: '<S165>/Gain1'

    rtDW.Sum_n = 1.0;
  }

  // Gain: '<S165>/Gain2' incorporates:
  //   Constant: '<S165>/Constant'
  //   Gain: '<S165>/Gain'
  //   Gain: '<S165>/Gain3'
  //   Gain: '<S165>/Gain4'
  //   Product: '<S165>/Divide'
  //   Product: '<S165>/Product'
  //   Trigonometry: '<S165>/Atan'
  //   Trigonometry: '<S165>/Sin'

  rtb_Product_a3 = std::sin(std::atan(-rtb_RL_i / 1517.0796012861272) * 2.9994) *
    rtDW.Sum_n * 1.093601981645556 * 17561.861236419998;

  // Sum: '<S167>/Sum' incorporates:
  //   DiscreteIntegrator: '<S215>/Discrete-Time Integrator2'
  //   Gain: '<S164>/Gain'
  //   Gain: '<S164>/Gain1'
  //   Gain: '<S164>/Gain3'
  //   Gain: '<S168>/Gain'
  //   Gain: '<S168>/Gain1'
  //   Gain: '<S170>/Gain'
  //   Gain: '<S170>/Gain1'
  //   Gain: '<S170>/Gain3'
  //   Product: '<S164>/Product'
  //   Product: '<S168>/Divide'
  //   Product: '<S170>/Product'
  //   Sum: '<S164>/Sum'
  //   Sum: '<S168>/Sum'
  //   Sum: '<S168>/Sum1'
  //   Sum: '<S168>/Sum2'
  //   Sum: '<S170>/Sum'

  rtb_Sum_if = (((-0.91452 * rtb_MathFunction - 3.4705) * (0.798856916366887 *
    -rtb_RL_i) * 0.0 - (0.53712 * rtb_MathFunction - 1.0429) * 0.0 * -rtb_RL_i) /
                rtb_Product_a3 + (-0.000261 * rtb_MathFunction - 0.000403)) +
    rtDW.DiscreteTimeIntegrator2_DSTAT_o;

  // Signum: '<S163>/Sign'
  if (std::isnan(rtb_Sum_if)) {
    rtb_antecedentOutputs_b = (rtNaN);
  } else if (rtb_Sum_if < 0.0) {
    rtb_antecedentOutputs_b = -1.0;
  } else {
    rtb_antecedentOutputs_b = (rtb_Sum_if > 0.0);
  }

  // MATLAB Function: '<S133>/MATLAB Function' incorporates:
  //   Constant: '<S133>/Constant'
  //   Constant: '<S161>/Constant'
  //   Constant: '<S163>/Constant'
  //   Constant: '<S163>/Constant1'
  //   Constant: '<S169>/Constant'
  //   Gain: '<S163>/Gain'
  //   Gain: '<S163>/Gain1'
  //   Gain: '<S169>/Gain'
  //   Gain: '<S169>/Gain1'
  //   Gain: '<S169>/Gain3'
  //   MinMax: '<S163>/Min'
  //   Product: '<S161>/Divide'
  //   Product: '<S161>/Product'
  //   Product: '<S163>/Product'
  //   Product: '<S169>/Product'
  //   Signum: '<S163>/Sign'
  //   Sum: '<S161>/Sum'
  //   Sum: '<S163>/Sum'
  //   Sum: '<S169>/Sum'

  MATLABFunction(rtb_RL_i, rtb_Product_g2, 1.839, rtb_Product_a3 / (1.839 *
    (rtb_Product_g2 + 0.0001)), std::fmin((-0.28662 * rtb_MathFunction + 0.96085)
    * (0.85611 * rtb_antecedentOutputs_b), 1.0), 0.0 * ((0.018068 *
    rtb_MathFunction + 0.032907) * -rtb_RL_i), rtb_Sum_if, &rtb_v_yaw);

  // Product: '<S113>/Product2' incorporates:
  //   Constant: '<S113>/Constant2'
  //   Math: '<S113>/Square3'
  //   Math: '<S113>/Square4'
  //   Product: '<S113>/Divide2'
  //   Sqrt: '<S113>/Square Root2'
  //   Sum: '<S113>/Sum2'

  rtb_Sum_bb = std::sqrt(1.0 - rtb_Sum_bb * rtb_Sum_bb / (rtb_Product_pk *
    rtb_Product_pk)) * rtb_v_yaw;

  // Product: '<S214>/Divide' incorporates:
  //   Constant: '<S214>/Constant'
  //   Gain: '<S214>/Gain'
  //   Sum: '<S214>/Sum'

  rtb_Product_a3 = (-rtb_DiscreteTimeIntegrator - -811.9083) / -811.9083;

  // Gain: '<S210>/Gain3' incorporates:
  //   Gain: '<S210>/Gain'
  //   Gain: '<S210>/Gain1'
  //   Gain: '<S210>/Gain2'
  //   Math: '<S210>/Exp'
  //   Product: '<S210>/Product'
  //   Product: '<S210>/Product1'
  //   Sum: '<S210>/Sum'
  //
  //  About '<S210>/Exp':
  //   Operator: exp

  rtb_MathFunction = (22.3857 * rtb_Product_a3 - 36.9039) *
    -rtb_DiscreteTimeIntegrator * std::exp(0.61844 * rtb_Product_a3) *
    0.9173523089876809;

  // Gain: '<S121>/Gain3' incorporates:
  //   Gain: '<S215>/Gain3'

  rtb_Saturation3 *= 0.2;

  // Product: '<S121>/Divide3' incorporates:
  //   Gain: '<S121>/Gain3'
  //   Gain: '<S121>/Gain7'
  //   Gain: '<S125>/Gain1'
  //   MinMax: '<S121>/Max3'
  //   Product: '<S125>/Product'
  //   Sum: '<S121>/Sum3'

  rtb_Product_pk = (rtb_Saturation3 - rtb_ZeroOrderHold13) / std::fmax
    (rtb_ZeroOrderHold13, 0.06231939047619048 * rtb_MathFunction * 0.0005 * 1.1);

  // Product: '<S208>/Product' incorporates:
  //   Constant: '<S208>/Constant'
  //   Gain: '<S208>/Gain'
  //   Gain: '<S208>/Gain1'
  //   Gain: '<S208>/Gain3'
  //   Sum: '<S208>/Sum'

  rtb_Product_ee = (-0.065814 * rtb_Product_a3 + 2.1568) * 0.9814642540325506 *
    -rtb_DiscreteTimeIntegrator;
  if (tmp) {
    // Abs: '<S209>/Abs' incorporates:
    //   Constant: '<S209>/Constant2'

    rtDW.Abs_h = 1.0;
  }

  // Signum: '<S209>/Sign'
  if (std::isnan(rtb_Product_pk)) {
    rtb_antecedentOutputs_b = (rtNaN);
  } else if (rtb_Product_pk < 0.0) {
    rtb_antecedentOutputs_b = -1.0;
  } else {
    rtb_antecedentOutputs_b = (rtb_Product_pk > 0.0);
  }

  // MATLAB Function: '<S138>/MATLAB Function' incorporates:
  //   Constant: '<S138>/Constant1'
  //   Constant: '<S209>/Constant2'
  //   Gain: '<S207>/Gain'
  //   Gain: '<S209>/Gain'
  //   Gain: '<S209>/Gain1'
  //   Gain: '<S209>/Gain2'
  //   Gain: '<S212>/Gain'
  //   Gain: '<S213>/Gain'
  //   Gain: '<S213>/Gain1'
  //   Math: '<S209>/Square'
  //   MinMax: '<S209>/Min'
  //   Product: '<S207>/Divide'
  //   Product: '<S209>/Product'
  //   Product: '<S209>/Product1'
  //   Product: '<S213>/Product'
  //   Signum: '<S209>/Sign'
  //   Sum: '<S209>/Sum'
  //   Sum: '<S209>/Sum1'
  //   Sum: '<S212>/Sum'
  //   Sum: '<S212>/Sum1'
  //   Sum: '<S213>/Sum'

  MATLABFunction_m(rtb_Product_pk + (-0.000374 * rtb_Product_a3 - 0.003859),
                   rtb_Product_ee, 1.3668, rtb_MathFunction / (1.3668 *
    rtb_Product_a3), std::fmin(((-0.62529 * rtb_Product_a3 - 0.19815) + 1.3396 *
    (rtb_Product_a3 * rtb_Product_a3)) * (1.0 - 0.0029464 * (rtDW.Abs_h *
    rtb_antecedentOutputs_b)), 1.0), -rtb_DiscreteTimeIntegrator * (0.002205 *
    rtb_Product_a3 - 0.11922), &rtb_v_yaw);

  // Switch: '<S138>/Switch' incorporates:
  //   Constant: '<S138>/Constant'

  if (rtb_Product_pk != 0.0) {
    rtb_Product_a3 = rtb_v_yaw;
  } else {
    rtb_Product_a3 = 0.0;
  }

  // End of Switch: '<S138>/Switch'

  // MinMax: '<S113>/Min1' incorporates:
  //   Gain: '<S113>/Gain1'

  rtb_MathFunction = std::fmin(rtb_Product_a3, -rtb_Product_ee);

  // Product: '<S182>/Divide' incorporates:
  //   Constant: '<S182>/Constant'
  //   Gain: '<S182>/Gain3'
  //   Sum: '<S182>/Sum'

  rtb_Sum_if = (-rtb_DiscreteTimeIntegrator - -210.9467) / -210.9467;

  // Product: '<S173>/Product' incorporates:
  //   Constant: '<S173>/Constant'
  //   Gain: '<S173>/Gain'
  //   Gain: '<S173>/Gain2'
  //   Gain: '<S173>/Gain4'
  //   Sum: '<S173>/Sum'

  rtb_Product_mr = (-0.11197 * rtb_Sum_if + 2.453) * 0.9701799812761553 *
    -rtb_DiscreteTimeIntegrator;
  if (tmp) {
    // Abs: '<S176>/Abs' incorporates:
    //   Constant: '<S176>/Constant1'

    rtb_Gain_no = 0.0;

    // Sum: '<S176>/Sum' incorporates:
    //   Constant: '<S176>/Constant2'
    //   Gain: '<S176>/Gain1'

    rtDW.Sum_f = 1.0;
  }

  // Gain: '<S176>/Gain2' incorporates:
  //   Constant: '<S176>/Constant'
  //   Gain: '<S176>/Gain'
  //   Gain: '<S176>/Gain3'
  //   Gain: '<S176>/Gain4'
  //   Product: '<S176>/Divide'
  //   Product: '<S176>/Product'
  //   Trigonometry: '<S176>/Atan'
  //   Trigonometry: '<S176>/Sin'

  rtb_Product_g2 = std::sin(std::atan(-rtb_DiscreteTimeIntegrator /
    1517.0796012861272) * 2.9994) * rtDW.Sum_f * 1.093601981645556 *
    17561.861236419998;

  // Sum: '<S178>/Sum' incorporates:
  //   DiscreteIntegrator: '<S215>/Discrete-Time Integrator3'
  //   Gain: '<S175>/Gain'
  //   Gain: '<S175>/Gain1'
  //   Gain: '<S175>/Gain3'
  //   Gain: '<S179>/Gain'
  //   Gain: '<S179>/Gain1'
  //   Gain: '<S181>/Gain'
  //   Gain: '<S181>/Gain1'
  //   Gain: '<S181>/Gain3'
  //   Product: '<S175>/Product'
  //   Product: '<S179>/Divide'
  //   Product: '<S181>/Product'
  //   Sum: '<S175>/Sum'
  //   Sum: '<S179>/Sum'
  //   Sum: '<S179>/Sum1'
  //   Sum: '<S179>/Sum2'
  //   Sum: '<S181>/Sum'

  rtb_Sum_jr = (((-0.91452 * rtb_Sum_if - 3.4705) * (0.798856916366887 *
    -rtb_DiscreteTimeIntegrator) * 0.0 - (0.53712 * rtb_Sum_if - 1.0429) * 0.0 *
                 -rtb_DiscreteTimeIntegrator) / rtb_Product_g2 + (-0.000261 *
    rtb_Sum_if - 0.000403)) + rtDW.DiscreteTimeIntegrator3_DSTAT_f;

  // Signum: '<S174>/Sign'
  if (std::isnan(rtb_Sum_jr)) {
    rtb_antecedentOutputs_b = (rtNaN);
  } else if (rtb_Sum_jr < 0.0) {
    rtb_antecedentOutputs_b = -1.0;
  } else {
    rtb_antecedentOutputs_b = (rtb_Sum_jr > 0.0);
  }

  // MATLAB Function: '<S134>/MATLAB Function' incorporates:
  //   Constant: '<S134>/Constant'
  //   Constant: '<S172>/Constant'
  //   Constant: '<S174>/Constant'
  //   Constant: '<S174>/Constant1'
  //   Constant: '<S180>/Constant'
  //   Gain: '<S174>/Gain'
  //   Gain: '<S174>/Gain1'
  //   Gain: '<S180>/Gain'
  //   Gain: '<S180>/Gain1'
  //   Gain: '<S180>/Gain3'
  //   MinMax: '<S174>/Min'
  //   Product: '<S172>/Divide'
  //   Product: '<S172>/Product'
  //   Product: '<S174>/Product'
  //   Product: '<S180>/Product'
  //   Signum: '<S174>/Sign'
  //   Sum: '<S172>/Sum'
  //   Sum: '<S174>/Sum'
  //   Sum: '<S180>/Sum'

  MATLABFunction(rtb_DiscreteTimeIntegrator, rtb_Product_mr, 1.839,
                 rtb_Product_g2 / (1.839 * (rtb_Product_mr + 0.0001)), std::fmin
                 ((-0.28662 * rtb_Sum_if + 0.96085) * (0.85611 *
    rtb_antecedentOutputs_b), 1.0), 0.0 * ((0.018068 * rtb_Sum_if + 0.032907) *
    -rtb_DiscreteTimeIntegrator), rtb_Sum_jr, &rtb_v_yaw);

  // Product: '<S113>/Product1' incorporates:
  //   Constant: '<S113>/Constant1'
  //   Math: '<S113>/Square1'
  //   Math: '<S113>/Square2'
  //   Product: '<S113>/Divide1'
  //   Sqrt: '<S113>/Square Root1'
  //   Sum: '<S113>/Sum1'

  rtb_MathFunction = std::sqrt(1.0 - rtb_MathFunction * rtb_MathFunction /
    (rtb_Product_ee * rtb_Product_ee)) * rtb_v_yaw;

  // Gain: '<S217>/Gain' incorporates:
  //   Sum: '<S217>/Sum'

  rtDW.Ay_cg = (((rtb_Fyref_FL + rtb_Fyref_FR) + rtb_Sum_bb) + rtb_MathFunction)
    * 0.0033333333333333335;

  // RateTransition: '<S1>/Rate Transition8'
  if (tmp) {
    // RateTransition: '<S1>/Rate Transition8'
    rtDW.ay_cg = rtDW.Ay_cg;

    // Product: '<S14>/Product2'
    rtb_Product1_j *= rtDW.ay_cg;

    // Switch: '<S17>/Switch2' incorporates:
    //   RelationalOperator: '<S17>/LowerRelop1'

    if (rtb_Product1_j > rtb_Limitemx) {
      // Switch: '<S17>/Switch2'
      rtDW.Switch2 = rtb_Limitemx;
    } else {
      // Lookup_n-D: '<S14>/Limite min' incorporates:
      //   RateTransition: '<S1>/Rate Transition3'

      rtb_Limitemx = look1_binlx(rtb_RateTransition3, rtConstP.pooled2,
        rtConstP.pooled1, 25U);

      // Switch: '<S17>/Switch' incorporates:
      //   RelationalOperator: '<S17>/UpperRelop'

      if (rtb_Product1_j < rtb_Limitemx) {
        // Switch: '<S17>/Switch2'
        rtDW.Switch2 = rtb_Limitemx;
      } else {
        // Switch: '<S17>/Switch2'
        rtDW.Switch2 = rtb_Product1_j;
      }

      // End of Switch: '<S17>/Switch'
    }

    // End of Switch: '<S17>/Switch2'

    // Lookup_n-D: '<S10>/Limite min' incorporates:
    //   RateTransition: '<S1>/Rate Transition3'

    rtDW.Limitemin_o = look1_binlx(rtb_RateTransition3, rtConstP.pooled2,
      rtConstP.pooled1, 25U);

    // Lookup_n-D: '<S10>/Limite máx' incorporates:
    //   RateTransition: '<S1>/Rate Transition3'

    rtDW.Limitemx_m = look1_binlx(rtb_RateTransition3, rtConstP.pooled2,
      rtConstP.pooled42, 25U);
  }

  // Sum: '<S10>/Sum'
  rtb_RateTransition3 = rtb_RR_oe + rtDW.Switch2;

  // Switch: '<S15>/Switch2' incorporates:
  //   RelationalOperator: '<S15>/LowerRelop1'
  //   RelationalOperator: '<S15>/UpperRelop'
  //   Switch: '<S15>/Switch'

  if (rtb_RateTransition3 > rtDW.Limitemx_m) {
    rtb_RateTransition3 = rtDW.Limitemx_m;
  } else if (rtb_RateTransition3 < rtDW.Limitemin_o) {
    // Switch: '<S15>/Switch'
    rtb_RateTransition3 = rtDW.Limitemin_o;
  }

  // End of Switch: '<S15>/Switch2'

  // If: '<S11>/If' incorporates:
  //   Abs: '<S11>/Abs'

  if ((std::abs(rtb_RL_f) < 0.05) || (rtDW.RateTransition10 < 2.0)) {
    // Outputs for IfAction SubSystem: '<S11>/If Action Subsystem' incorporates:
    //   ActionPort: '<S18>/Action Port'

    // Gain: '<S18>/Gain'
    rtb_RateTransition3 *= 0.0;

    // End of Outputs for SubSystem: '<S11>/If Action Subsystem'
  }

  // End of If: '<S11>/If'

  // RateTransition: '<S9>/Rate Transition4'
  if (tmp) {
    // SampleTimeMath: '<S31>/TSamp'
    //
    //  About '<S31>/TSamp':
    //   y = u * K where K = 1 / ( w * Ts )
    //
    rtb_TSamp = rtb_FL_e0 * 100.0;

    // Sum: '<S31>/Diff' incorporates:
    //   UnitDelay: '<S31>/UD'
    //
    //  Block description for '<S31>/Diff':
    //
    //   Add in CPU
    //
    //  Block description for '<S31>/UD':
    //
    //   Store in Global RAM

    rtb_Diff = rtb_TSamp - rtDW.UD_DSTATE;

    // Outputs for Atomic SubSystem: '<S30>/Fuzzy Logic  Controller'
    // MATLAB Function: '<S32>/Evaluate Rule Antecedents' incorporates:
    //   SignalConversion generated from: '<S34>/ SFunction '

    rtb_Gain_no = 0.0;
    inputMFCache[0] = std::exp(-((rtb_FL_e0 - 0.05) * (rtb_FL_e0 - 0.05)) /
      0.020000000000000004);
    inputMFCache[1] = std::exp(-((rtb_FL_e0 - 0.2) * (rtb_FL_e0 - 0.2)) /
      0.020000000000000004);
    inputMFCache[2] = std::exp(-((rtb_FL_e0 - 0.4) * (rtb_FL_e0 - 0.4)) / 0.0288);
    inputMFCache[3] = std::exp(-((rtb_FL_e0 - 0.7) * (rtb_FL_e0 - 0.7)) / 0.045);
    inputMFCache[4] = std::exp(-((rtb_Diff - -10.0) * (rtb_Diff - -10.0)) / 18.0);
    inputMFCache[5] = std::exp(-((rtb_Diff - -5.0) * (rtb_Diff - -5.0)) / 12.5);
    inputMFCache[6] = std::exp(-((rtb_Diff - -1.0) * (rtb_Diff - -1.0)) / 6.48);
    inputMFCache[7] = std::exp(-(rtb_Diff * rtb_Diff) / 8.0);
    inputMFCache[8] = std::exp(-((rtb_Diff - 3.5) * (rtb_Diff - 3.5)) / 8.0);
    inputMFCache[9] = std::exp(-((rtb_Diff - 7.5) * (rtb_Diff - 7.5)) / 12.5);
    inputMFCache[10] = std::exp(-((rtb_Diff - 12.0) * (rtb_Diff - 12.0)) / 18.0);
    for (i = 0; i < 28; i++) {
      rtb_Limitemx = inputMFCache[b[i] - 1];
      if (rtb_Limitemx < 1.0) {
        rtb_antecedentOutputs_b = rtb_Limitemx;
      } else {
        rtb_antecedentOutputs_b = 1.0;
      }

      rtb_Limitemx = inputMFCache[b[i + 28] + 3];
      if (rtb_antecedentOutputs_b > rtb_Limitemx) {
        rtb_antecedentOutputs_b = rtb_Limitemx;
      }

      rtb_antecedentOutputs_l[i] = rtb_antecedentOutputs_b;
      rtb_Gain_no += rtb_antecedentOutputs_b;
    }

    // MATLAB Function: '<S32>/Evaluate Rule Consequents' incorporates:
    //   Constant: '<S32>/Output Sample Points'

    EvaluateRuleConsequents(rtb_antecedentOutputs_l, rtConstP.pooled12,
      rtb_aggregatedOutputs);

    // MATLAB Function: '<S32>/Defuzzify Outputs' incorporates:
    //   Constant: '<S32>/Output Sample Points'
    //   MATLAB Function: '<S32>/Evaluate Rule Antecedents'

    if (rtb_Gain_no == 0.0) {
      rtb_Diff = 0.25;
    } else {
      rtb_Gain_no = 0.0;
      rtb_RL_f = 0.0;
      for (i = 0; i < 101; i++) {
        rtb_RL_f += rtb_aggregatedOutputs[i];
      }

      if (rtb_RL_f == 0.0) {
        rtb_Diff = 0.25;
      } else {
        for (i = 0; i < 101; i++) {
          rtb_Gain_no += rtConstP.pooled12[i] * rtb_aggregatedOutputs[i];
        }

        rtb_Diff = 1.0 / rtb_RL_f * rtb_Gain_no;
      }
    }

    // End of MATLAB Function: '<S32>/Defuzzify Outputs'
    // End of Outputs for SubSystem: '<S30>/Fuzzy Logic  Controller'

    // Saturate: '<S30>/Saturation'
    if (rtb_Diff > 1.0) {
      rtb_Gain_no = 1.0;
    } else if (rtb_Diff < 0.0) {
      rtb_Gain_no = 0.0;
    } else {
      rtb_Gain_no = rtb_Diff;
    }

    // End of Saturate: '<S30>/Saturation'

    // RateLimiter: '<S26>/Rate Limiter'
    if (rtb_Gain_no - rtDW.PrevY < -0.005) {
      rtb_Diff = rtDW.PrevY - 0.005;
    } else {
      rtb_Diff = rtb_Gain_no;
    }

    rtDW.PrevY = rtb_Diff;

    // End of RateLimiter: '<S26>/Rate Limiter'

    // SampleTimeMath: '<S37>/TSamp' incorporates:
    //   RateTransition: '<S9>/Rate Transition1'
    //
    //  About '<S37>/TSamp':
    //   y = u * K where K = 1 / ( w * Ts )
    //
    rtb_TSamp_n = rtb_FR_j * 100.0;

    // Sum: '<S37>/Diff' incorporates:
    //   UnitDelay: '<S37>/UD'
    //
    //  Block description for '<S37>/Diff':
    //
    //   Add in CPU
    //
    //  Block description for '<S37>/UD':
    //
    //   Store in Global RAM

    rtb_Diff_e = rtb_TSamp_n - rtDW.UD_DSTATE_k;

    // Outputs for Atomic SubSystem: '<S36>/Fuzzy Logic  Controller'
    // MATLAB Function: '<S38>/Evaluate Rule Antecedents' incorporates:
    //   RateTransition: '<S9>/Rate Transition1'
    //   SignalConversion generated from: '<S40>/ SFunction '

    rtb_Gain_no = 0.0;
    inputMFCache[0] = std::exp(-((rtb_FR_j - 0.05) * (rtb_FR_j - 0.05)) /
      0.020000000000000004);
    inputMFCache[1] = std::exp(-((rtb_FR_j - 0.2) * (rtb_FR_j - 0.2)) /
      0.020000000000000004);
    inputMFCache[2] = std::exp(-((rtb_FR_j - 0.4) * (rtb_FR_j - 0.4)) / 0.0288);
    inputMFCache[3] = std::exp(-((rtb_FR_j - 0.7) * (rtb_FR_j - 0.7)) / 0.045);
    inputMFCache[4] = std::exp(-((rtb_Diff_e - -10.0) * (rtb_Diff_e - -10.0)) /
      18.0);
    inputMFCache[5] = std::exp(-((rtb_Diff_e - -5.0) * (rtb_Diff_e - -5.0)) /
      12.5);
    inputMFCache[6] = std::exp(-((rtb_Diff_e - -1.0) * (rtb_Diff_e - -1.0)) /
      6.48);
    inputMFCache[7] = std::exp(-(rtb_Diff_e * rtb_Diff_e) / 8.0);
    inputMFCache[8] = std::exp(-((rtb_Diff_e - 3.5) * (rtb_Diff_e - 3.5)) / 8.0);
    inputMFCache[9] = std::exp(-((rtb_Diff_e - 7.5) * (rtb_Diff_e - 7.5)) / 12.5);
    inputMFCache[10] = std::exp(-((rtb_Diff_e - 12.0) * (rtb_Diff_e - 12.0)) /
      18.0);
    for (i = 0; i < 28; i++) {
      rtb_Limitemx = inputMFCache[b[i] - 1];
      if (rtb_Limitemx < 1.0) {
        rtb_antecedentOutputs_b = rtb_Limitemx;
      } else {
        rtb_antecedentOutputs_b = 1.0;
      }

      rtb_Limitemx = inputMFCache[b[i + 28] + 3];
      if (rtb_antecedentOutputs_b > rtb_Limitemx) {
        rtb_antecedentOutputs_b = rtb_Limitemx;
      }

      rtb_antecedentOutputs_l[i] = rtb_antecedentOutputs_b;
      rtb_Gain_no += rtb_antecedentOutputs_b;
    }

    // MATLAB Function: '<S38>/Evaluate Rule Consequents' incorporates:
    //   Constant: '<S38>/Output Sample Points'
    //   RateTransition: '<S9>/Rate Transition1'

    EvaluateRuleConsequents(rtb_antecedentOutputs_l, rtConstP.pooled12,
      rtb_aggregatedOutputs);

    // MATLAB Function: '<S38>/Defuzzify Outputs' incorporates:
    //   Constant: '<S38>/Output Sample Points'
    //   MATLAB Function: '<S38>/Evaluate Rule Antecedents'

    if (rtb_Gain_no == 0.0) {
      rtb_Diff_e = 0.25;
    } else {
      rtb_Gain_no = 0.0;
      rtb_RL_f = 0.0;
      for (i = 0; i < 101; i++) {
        rtb_RL_f += rtb_aggregatedOutputs[i];
      }

      if (rtb_RL_f == 0.0) {
        rtb_Diff_e = 0.25;
      } else {
        for (i = 0; i < 101; i++) {
          rtb_Gain_no += rtConstP.pooled12[i] * rtb_aggregatedOutputs[i];
        }

        rtb_Diff_e = 1.0 / rtb_RL_f * rtb_Gain_no;
      }
    }

    // End of MATLAB Function: '<S38>/Defuzzify Outputs'
    // End of Outputs for SubSystem: '<S36>/Fuzzy Logic  Controller'

    // Saturate: '<S36>/Saturation'
    if (rtb_Diff_e > 1.0) {
      rtb_Gain_no = 1.0;
    } else if (rtb_Diff_e < 0.0) {
      rtb_Gain_no = 0.0;
    } else {
      rtb_Gain_no = rtb_Diff_e;
    }

    // End of Saturate: '<S36>/Saturation'

    // RateLimiter: '<S27>/Rate Limiter'
    if (rtb_Gain_no - rtDW.PrevY_f < -0.005) {
      rtb_Diff_e = rtDW.PrevY_f - 0.005;
    } else {
      rtb_Diff_e = rtb_Gain_no;
    }

    rtDW.PrevY_f = rtb_Diff_e;

    // End of RateLimiter: '<S27>/Rate Limiter'
  }

  // Gain: '<S121>/Gain2' incorporates:
  //   Gain: '<S215>/Gain2'

  rtb_DiscreteTimeIntegrator1_c *= 0.2;

  // Product: '<S121>/Divide2' incorporates:
  //   Gain: '<S121>/Gain2'
  //   Gain: '<S121>/Gain6'
  //   Gain: '<S124>/Gain1'
  //   MinMax: '<S121>/Max2'
  //   Product: '<S124>/Product'
  //   Sum: '<S121>/Sum2'

  rtb_Product_g2 = (rtb_DiscreteTimeIntegrator1_c - rtb_ZeroOrderHold13) / std::
    fmax(rtb_ZeroOrderHold13, 0.06231939047619048 * rtb_Product_az * 0.0005 *
         1.1);

  // RateTransition: '<S9>/Rate Transition5'
  if (tmp) {
    // SampleTimeMath: '<S43>/TSamp'
    //
    //  About '<S43>/TSamp':
    //   y = u * K where K = 1 / ( w * Ts )
    //
    rtb_TSamp_o = rtb_Product_g2 * 100.0;

    // Sum: '<S43>/Diff' incorporates:
    //   UnitDelay: '<S43>/UD'
    //
    //  Block description for '<S43>/Diff':
    //
    //   Add in CPU
    //
    //  Block description for '<S43>/UD':
    //
    //   Store in Global RAM

    rtb_Diff_b = rtb_TSamp_o - rtDW.UD_DSTATE_g;

    // Outputs for Atomic SubSystem: '<S42>/Fuzzy Logic  Controller'
    // MATLAB Function: '<S44>/Evaluate Rule Antecedents' incorporates:
    //   SignalConversion generated from: '<S46>/ SFunction '

    rtb_Gain_no = 0.0;
    inputMFCache[0] = std::exp(-((rtb_Product_g2 - 0.05) * (rtb_Product_g2 -
      0.05)) / 0.020000000000000004);
    inputMFCache[1] = std::exp(-((rtb_Product_g2 - 0.2) * (rtb_Product_g2 - 0.2))
      / 0.020000000000000004);
    inputMFCache[2] = std::exp(-((rtb_Product_g2 - 0.4) * (rtb_Product_g2 - 0.4))
      / 0.0288);
    inputMFCache[3] = std::exp(-((rtb_Product_g2 - 0.7) * (rtb_Product_g2 - 0.7))
      / 0.045);
    inputMFCache[4] = std::exp(-((rtb_Diff_b - -10.0) * (rtb_Diff_b - -10.0)) /
      18.0);
    inputMFCache[5] = std::exp(-((rtb_Diff_b - -5.0) * (rtb_Diff_b - -5.0)) /
      12.5);
    inputMFCache[6] = std::exp(-((rtb_Diff_b - -1.0) * (rtb_Diff_b - -1.0)) /
      6.48);
    inputMFCache[7] = std::exp(-(rtb_Diff_b * rtb_Diff_b) / 8.0);
    inputMFCache[8] = std::exp(-((rtb_Diff_b - 3.5) * (rtb_Diff_b - 3.5)) / 8.0);
    inputMFCache[9] = std::exp(-((rtb_Diff_b - 7.5) * (rtb_Diff_b - 7.5)) / 12.5);
    inputMFCache[10] = std::exp(-((rtb_Diff_b - 12.0) * (rtb_Diff_b - 12.0)) /
      18.0);
    for (i = 0; i < 28; i++) {
      rtb_Limitemx = inputMFCache[b[i] - 1];
      if (rtb_Limitemx < 1.0) {
        rtb_antecedentOutputs_b = rtb_Limitemx;
      } else {
        rtb_antecedentOutputs_b = 1.0;
      }

      rtb_Limitemx = inputMFCache[b[i + 28] + 3];
      if (rtb_antecedentOutputs_b > rtb_Limitemx) {
        rtb_antecedentOutputs_b = rtb_Limitemx;
      }

      rtb_antecedentOutputs_l[i] = rtb_antecedentOutputs_b;
      rtb_Gain_no += rtb_antecedentOutputs_b;
    }

    // MATLAB Function: '<S44>/Evaluate Rule Consequents' incorporates:
    //   Constant: '<S44>/Output Sample Points'

    EvaluateRuleConsequents(rtb_antecedentOutputs_l, rtConstP.pooled12,
      rtb_aggregatedOutputs);

    // MATLAB Function: '<S44>/Defuzzify Outputs' incorporates:
    //   Constant: '<S44>/Output Sample Points'
    //   MATLAB Function: '<S44>/Evaluate Rule Antecedents'

    if (rtb_Gain_no == 0.0) {
      rtb_Diff_b = 0.25;
    } else {
      rtb_Gain_no = 0.0;
      rtb_RL_f = 0.0;
      for (i = 0; i < 101; i++) {
        rtb_RL_f += rtb_aggregatedOutputs[i];
      }

      if (rtb_RL_f == 0.0) {
        rtb_Diff_b = 0.25;
      } else {
        for (i = 0; i < 101; i++) {
          rtb_Gain_no += rtConstP.pooled12[i] * rtb_aggregatedOutputs[i];
        }

        rtb_Diff_b = 1.0 / rtb_RL_f * rtb_Gain_no;
      }
    }

    // End of MATLAB Function: '<S44>/Defuzzify Outputs'
    // End of Outputs for SubSystem: '<S42>/Fuzzy Logic  Controller'

    // Saturate: '<S42>/Saturation'
    if (rtb_Diff_b > 1.0) {
      rtb_Gain_no = 1.0;
    } else if (rtb_Diff_b < 0.0) {
      rtb_Gain_no = 0.0;
    } else {
      rtb_Gain_no = rtb_Diff_b;
    }

    // End of Saturate: '<S42>/Saturation'

    // RateLimiter: '<S28>/Rate Limiter'
    if (rtb_Gain_no - rtDW.PrevY_g < -0.005) {
      rtb_Diff_b = rtDW.PrevY_g - 0.005;
    } else {
      rtb_Diff_b = rtb_Gain_no;
    }

    rtDW.PrevY_g = rtb_Diff_b;

    // End of RateLimiter: '<S28>/Rate Limiter'

    // SampleTimeMath: '<S49>/TSamp' incorporates:
    //   RateTransition: '<S9>/Rate Transition6'
    //
    //  About '<S49>/TSamp':
    //   y = u * K where K = 1 / ( w * Ts )
    //
    rtb_TSamp_g = rtb_Product_pk * 100.0;

    // Sum: '<S49>/Diff' incorporates:
    //   UnitDelay: '<S49>/UD'
    //
    //  Block description for '<S49>/Diff':
    //
    //   Add in CPU
    //
    //  Block description for '<S49>/UD':
    //
    //   Store in Global RAM

    rtb_Diff_k = rtb_TSamp_g - rtDW.UD_DSTATE_b;

    // Outputs for Atomic SubSystem: '<S48>/Fuzzy Logic  Controller'
    // MATLAB Function: '<S50>/Evaluate Rule Antecedents' incorporates:
    //   RateTransition: '<S9>/Rate Transition6'
    //   SignalConversion generated from: '<S52>/ SFunction '

    rtb_Gain_no = 0.0;
    inputMFCache[0] = std::exp(-((rtb_Product_pk - 0.05) * (rtb_Product_pk -
      0.05)) / 0.020000000000000004);
    inputMFCache[1] = std::exp(-((rtb_Product_pk - 0.2) * (rtb_Product_pk - 0.2))
      / 0.020000000000000004);
    inputMFCache[2] = std::exp(-((rtb_Product_pk - 0.4) * (rtb_Product_pk - 0.4))
      / 0.0288);
    inputMFCache[3] = std::exp(-((rtb_Product_pk - 0.7) * (rtb_Product_pk - 0.7))
      / 0.045);
    inputMFCache[4] = std::exp(-((rtb_Diff_k - -10.0) * (rtb_Diff_k - -10.0)) /
      18.0);
    inputMFCache[5] = std::exp(-((rtb_Diff_k - -5.0) * (rtb_Diff_k - -5.0)) /
      12.5);
    inputMFCache[6] = std::exp(-((rtb_Diff_k - -1.0) * (rtb_Diff_k - -1.0)) /
      6.48);
    inputMFCache[7] = std::exp(-(rtb_Diff_k * rtb_Diff_k) / 8.0);
    inputMFCache[8] = std::exp(-((rtb_Diff_k - 3.5) * (rtb_Diff_k - 3.5)) / 8.0);
    inputMFCache[9] = std::exp(-((rtb_Diff_k - 7.5) * (rtb_Diff_k - 7.5)) / 12.5);
    inputMFCache[10] = std::exp(-((rtb_Diff_k - 12.0) * (rtb_Diff_k - 12.0)) /
      18.0);
    for (i = 0; i < 28; i++) {
      rtb_Limitemx = inputMFCache[b[i] - 1];
      if (rtb_Limitemx < 1.0) {
        rtb_antecedentOutputs_b = rtb_Limitemx;
      } else {
        rtb_antecedentOutputs_b = 1.0;
      }

      rtb_Limitemx = inputMFCache[b[i + 28] + 3];
      if (rtb_antecedentOutputs_b > rtb_Limitemx) {
        rtb_antecedentOutputs_b = rtb_Limitemx;
      }

      rtb_antecedentOutputs_l[i] = rtb_antecedentOutputs_b;
      rtb_Gain_no += rtb_antecedentOutputs_b;
    }

    // MATLAB Function: '<S50>/Evaluate Rule Consequents' incorporates:
    //   Constant: '<S50>/Output Sample Points'
    //   RateTransition: '<S9>/Rate Transition6'

    EvaluateRuleConsequents(rtb_antecedentOutputs_l, rtConstP.pooled12,
      rtb_aggregatedOutputs);

    // MATLAB Function: '<S50>/Defuzzify Outputs' incorporates:
    //   Constant: '<S50>/Output Sample Points'
    //   MATLAB Function: '<S50>/Evaluate Rule Antecedents'

    if (rtb_Gain_no == 0.0) {
      rtb_Diff_k = 0.25;
    } else {
      rtb_Gain_no = 0.0;
      rtb_RL_f = 0.0;
      for (i = 0; i < 101; i++) {
        rtb_RL_f += rtb_aggregatedOutputs[i];
      }

      if (rtb_RL_f == 0.0) {
        rtb_Diff_k = 0.25;
      } else {
        for (i = 0; i < 101; i++) {
          rtb_Gain_no += rtConstP.pooled12[i] * rtb_aggregatedOutputs[i];
        }

        rtb_Diff_k = 1.0 / rtb_RL_f * rtb_Gain_no;
      }
    }

    // End of MATLAB Function: '<S50>/Defuzzify Outputs'
    // End of Outputs for SubSystem: '<S48>/Fuzzy Logic  Controller'

    // Saturate: '<S48>/Saturation'
    if (rtb_Diff_k > 1.0) {
      rtb_Gain_no = 1.0;
    } else if (rtb_Diff_k < 0.0) {
      rtb_Gain_no = 0.0;
    } else {
      rtb_Gain_no = rtb_Diff_k;
    }

    // End of Saturate: '<S48>/Saturation'

    // RateLimiter: '<S29>/Rate Limiter'
    if (rtb_Gain_no - rtDW.PrevY_h < -0.005) {
      rtb_Diff_k = rtDW.PrevY_h - 0.005;
    } else {
      rtb_Diff_k = rtb_Gain_no;
    }

    rtDW.PrevY_h = rtb_Diff_k;

    // End of RateLimiter: '<S29>/Rate Limiter'
  }

  // Outputs for Atomic SubSystem: '<S1>/Torque Vectoring'
  // Gain: '<S23>/Gain'
  rtb_RR_oe = 0.25 * Product;

  // Gain: '<S25>/Gain2' incorporates:
  //   Constant: '<S25>/Constant'
  //   Product: '<S25>/Divide'
  //   Product: '<S25>/Product'

  rtb_Gain2_d0 = 0.2 * rtb_RateTransition3 / 14.65 * 0.5;
  if ((&rtM)->Timing.TaskCounters.TID[2] == 0) {
    // Switch: '<S24>/Switch'
    if (rtb_Diff > 0.0) {
      // Switch: '<S24>/Switch' incorporates:
      //   Constant: '<S24>/Constant2'
      //   Sum: '<S24>/Sum'

      rtDW.Switch_e = 1.0 - rtb_Diff;
    } else {
      // Switch: '<S24>/Switch' incorporates:
      //   Constant: '<S24>/Constant1'

      rtDW.Switch_e = 1.0;
    }

    // End of Switch: '<S24>/Switch'

    // Switch: '<S24>/Switch1'
    if (rtb_Diff_e > 0.0) {
      // Switch: '<S24>/Switch1' incorporates:
      //   Constant: '<S24>/Constant1'
      //   Sum: '<S24>/Sum1'

      rtDW.Switch1_j = 1.0 - rtb_Diff_e;
    } else {
      // Switch: '<S24>/Switch1' incorporates:
      //   Constant: '<S24>/Constant3'

      rtDW.Switch1_j = 1.0;
    }

    // End of Switch: '<S24>/Switch1'

    // Switch: '<S24>/Switch2'
    if (rtb_Diff_b > 0.0) {
      // Switch: '<S24>/Switch2' incorporates:
      //   Constant: '<S24>/Constant3'
      //   Sum: '<S24>/Sum2'

      rtDW.Switch2_o = 1.0 - rtb_Diff_b;
    } else {
      // Switch: '<S24>/Switch2' incorporates:
      //   Constant: '<S24>/Constant7'

      rtDW.Switch2_o = 1.0;
    }

    // End of Switch: '<S24>/Switch2'

    // Switch: '<S24>/Switch3'
    if (rtb_Diff_k > 0.0) {
      // Switch: '<S24>/Switch3' incorporates:
      //   Constant: '<S24>/Constant7'
      //   Sum: '<S24>/Sum3'

      rtDW.Switch3 = 1.0 - rtb_Diff_k;
    } else {
      // Switch: '<S24>/Switch3' incorporates:
      //   Constant: '<S24>/Constant6'

      rtDW.Switch3 = 1.0;
    }

    // End of Switch: '<S24>/Switch3'
  }

  // End of Outputs for SubSystem: '<S1>/Torque Vectoring'

  // RateTransition generated from: '<Root>/Zero-Order Hold'
  if (tmp) {
    // Gain: '<S89>/Integral Gain' incorporates:
    //   DiscreteIntegrator: '<S216>/Integrator'
    //   Sum: '<S2>/Sum'

    rtb_IntegralGain = (5.0 - rtDW.Integrator_DSTATE) * 0.01;

    // Switch: '<S2>/Switch1'
    if (rtb_Saturation >= 0.0) {
      // Switch: '<S2>/Switch1' incorporates:
      //   Constant: '<S2>/Constant'

      rtDW.Switch1 = 0.0;
    } else {
      // Switch: '<S2>/Switch1' incorporates:
      //   Abs: '<S2>/Abs'

      rtDW.Switch1 = std::abs(rtb_Saturation);
    }

    // End of Switch: '<S2>/Switch1'

    // Gain: '<S114>/Gain' incorporates:
    //   Switch: '<S2>/Switch5'

    rtb_Gain_no = 9508.0 * rtDW.Switch1;

    // Gain: '<S114>/torque_máx_f'
    rtDW.torque_mx_f = 0.632 * rtb_Gain_no;
  }

  // Switch: '<S114>/Switch' incorporates:
  //   Constant: '<S114>/Constant'
  //   DiscreteIntegrator: '<S216>/Integrator'

  if (rtDW.Integrator_DSTATE > 0.0) {
    rtb_antecedentOutputs_b = rtDW.torque_mx_f;
  } else {
    rtb_antecedentOutputs_b = 0.0;
  }

  // Gain: '<S112>/Gain13' incorporates:
  //   Switch: '<S114>/Switch'

  rtb_Product_az = 0.2 * rtb_antecedentOutputs_b;

  // Outputs for Atomic SubSystem: '<S1>/Torque Vectoring'
  // Sum: '<S22>/Subtract' incorporates:
  //   Product: '<S23>/Product'

  rtb_Saturation = rtb_RR_oe - rtb_Gain2_d0;

  // Saturate: '<S22>/Saturation'
  if (rtb_Saturation > 16.2) {
    rtb_antecedentOutputs_b = 16.2;
  } else if (rtb_Saturation < 0.0) {
    rtb_antecedentOutputs_b = 0.0;
  } else {
    rtb_antecedentOutputs_b = rtb_Saturation;
  }

  // Product: '<S112>/Divide' incorporates:
  //   Constant: '<S112>/Constant'
  //   Gain: '<S112>/Gain'
  //   Gain: '<S112>/Gain4'
  //   Product: '<S24>/Product'
  //   Saturate: '<S22>/Saturation'
  //   Sum: '<S112>/Sum'

  rtb_Divide_fk = ((rtb_antecedentOutputs_b * rtDW.Switch_e * 11.72 - 0.2 *
                    rtb_Sum_pz) - rtb_Product_az) / 0.7547282719999999;

  // Sum: '<S22>/Sum' incorporates:
  //   Product: '<S23>/Product'

  rtb_RateTransition3 = rtb_RR_oe + rtb_Gain2_d0;

  // Saturate: '<S22>/Saturation1'
  if (rtb_RateTransition3 > 16.2) {
    rtb_antecedentOutputs_b = 16.2;
  } else if (rtb_RateTransition3 < 0.0) {
    rtb_antecedentOutputs_b = 0.0;
  } else {
    rtb_antecedentOutputs_b = rtb_RateTransition3;
  }

  // Product: '<S112>/Divide1' incorporates:
  //   Constant: '<S112>/Constant'
  //   Gain: '<S112>/Gain1'
  //   Gain: '<S112>/Gain5'
  //   Product: '<S24>/Product1'
  //   Saturate: '<S22>/Saturation1'
  //   Sum: '<S112>/Sum1'

  rtb_Divide1_i = ((rtb_antecedentOutputs_b * rtDW.Switch1_j * 11.72 - 0.2 *
                    rtb_Product_ps) - rtb_Product_az) / 0.7547282719999999;

  // End of Outputs for SubSystem: '<S1>/Torque Vectoring'
  if (tmp) {
    // Gain: '<S114>/torque_máx_r'
    rtDW.torque_mx_r = 0.368 * rtb_Gain_no;
  }

  // Switch: '<S114>/Switch1' incorporates:
  //   Constant: '<S114>/Constant'
  //   DiscreteIntegrator: '<S216>/Integrator'

  if (rtDW.Integrator_DSTATE > 0.0) {
    rtb_antecedentOutputs_b = rtDW.torque_mx_r;
  } else {
    rtb_antecedentOutputs_b = 0.0;
  }

  // Gain: '<S112>/Gain12' incorporates:
  //   Switch: '<S114>/Switch1'

  rtb_Sum_if = 0.2 * rtb_antecedentOutputs_b;

  // Outputs for Atomic SubSystem: '<S1>/Torque Vectoring'
  // Saturate: '<S22>/Saturation2' incorporates:
  //   Sum: '<S22>/Subtract1'

  if (rtb_Saturation > 16.2) {
    rtb_Saturation = 16.2;
  } else if (rtb_Saturation < 0.0) {
    rtb_Saturation = 0.0;
  }

  // Product: '<S112>/Divide2' incorporates:
  //   Constant: '<S112>/Constant'
  //   Gain: '<S112>/Gain2'
  //   Gain: '<S112>/Gain6'
  //   Product: '<S24>/Product2'
  //   Saturate: '<S22>/Saturation2'
  //   Sum: '<S112>/Sum2'

  rtb_Divide2_c = ((rtb_Saturation * rtDW.Switch2_o * 11.72 - 0.2 *
                    rtb_Saturation_c) - rtb_Sum_if) / 0.7547282719999999;

  // Saturate: '<S22>/Saturation3' incorporates:
  //   Sum: '<S22>/Sum1'

  if (rtb_RateTransition3 > 16.2) {
    rtb_RateTransition3 = 16.2;
  } else if (rtb_RateTransition3 < 0.0) {
    rtb_RateTransition3 = 0.0;
  }

  // Product: '<S112>/Divide3' incorporates:
  //   Constant: '<S112>/Constant'
  //   Gain: '<S112>/Gain3'
  //   Gain: '<S112>/Gain7'
  //   Product: '<S24>/Product3'
  //   Saturate: '<S22>/Saturation3'
  //   Sum: '<S112>/Sum3'

  rtb_Divide3_e = ((rtb_RateTransition3 * rtDW.Switch3 * 11.72 - 0.2 *
                    rtb_Product_a3) - rtb_Sum_if) / 0.7547282719999999;

  // End of Outputs for SubSystem: '<S1>/Torque Vectoring'

  // DeadZone: '<S119>/Dead Zone'
  if (rtb_DiscreteTimeIntegrator1 > 0.01) {
    rtb_Saturation = rtb_DiscreteTimeIntegrator1 - 0.01;
  } else if (rtb_DiscreteTimeIntegrator1 >= -0.01) {
    rtb_Saturation = 0.0;
  } else {
    rtb_Saturation = rtb_DiscreteTimeIntegrator1 - -0.01;
  }

  // End of DeadZone: '<S119>/Dead Zone'

  // Switch: '<S119>/Switch' incorporates:
  //   DiscreteIntegrator: '<S216>/Integrator'

  if (rtDW.Integrator_DSTATE != 0.0) {
    // DeadZone: '<S119>/Dead Zone1' incorporates:
    //   DiscreteIntegrator: '<S217>/Integrator1'

    if (rtDW.Integrator1_DSTATE > 0.01) {
      rtb_antecedentOutputs_b = rtDW.Integrator1_DSTATE - 0.01;
    } else if (rtDW.Integrator1_DSTATE >= -0.01) {
      rtb_antecedentOutputs_b = 0.0;
    } else {
      rtb_antecedentOutputs_b = rtDW.Integrator1_DSTATE - -0.01;
    }

    // Gain: '<S220>/Gain16' incorporates:
    //   DeadZone: '<S119>/Dead Zone1'
    //   Gain: '<S119>/Gain'
    //   Gain: '<S119>/Gain1'
    //   Product: '<S119>/Divide3'
    //   Sum: '<S119>/Sum'
    //   Sum: '<S119>/Sum2'

    rtb_v_yaw = (0.8415000000000001 * rtb_Saturation + rtb_antecedentOutputs_b) /
      (rtDW.Integrator_DSTATE - 0.5999999999999999 * rtb_Saturation);
  } else {
    // Gain: '<S220>/Gain16' incorporates:
    //   Constant: '<S119>/Constant'

    rtb_v_yaw = 0.0;
  }

  // End of Switch: '<S119>/Switch'

  // Product: '<S215>/Divide' incorporates:
  //   DiscreteIntegrator: '<S215>/Discrete-Time Integrator'
  //   Gain: '<S117>/Gain'
  //   Gain: '<S117>/Gain1'
  //   Gain: '<S117>/Gain8'
  //   Product: '<S215>/Product'
  //   Sum: '<S119>/Sum1'
  //   Sum: '<S215>/Sum'
  //   Trigonometry: '<S117>/Atan'
  //   Trigonometry: '<S117>/Sin'
  //   Trigonometry: '<S119>/Atan'

  rtb_Divide_ov = ((std::atan(rtb_v_yaw) - rtDW.steering_inner) -
                   rtDW.DiscreteTimeIntegrator_DSTATE_d) * rtb_FL_po_tmp / (std::
    sin(std::atan(-0.0002477622368857045 * rtb_y_g) * 2.0) * -1.2116778447999998);

  // Switch: '<S119>/Switch1' incorporates:
  //   DiscreteIntegrator: '<S216>/Integrator'

  if (rtDW.Integrator_DSTATE != 0.0) {
    // DeadZone: '<S119>/Dead Zone2' incorporates:
    //   DiscreteIntegrator: '<S217>/Integrator1'

    if (rtDW.Integrator1_DSTATE > 0.01) {
      rtb_antecedentOutputs_b = rtDW.Integrator1_DSTATE - 0.01;
    } else if (rtDW.Integrator1_DSTATE >= -0.01) {
      rtb_antecedentOutputs_b = 0.0;
    } else {
      rtb_antecedentOutputs_b = rtDW.Integrator1_DSTATE - -0.01;
    }

    // Gain: '<S220>/Gain16' incorporates:
    //   DeadZone: '<S119>/Dead Zone2'
    //   Gain: '<S119>/Gain2'
    //   Gain: '<S119>/Gain3'
    //   Gain: '<S119>/Gain8'
    //   Product: '<S119>/Divide2'
    //   Sum: '<S119>/Sum3'
    //   Sum: '<S119>/Sum4'

    rtb_v_yaw = (0.8415000000000001 * rtb_Saturation + rtb_antecedentOutputs_b) /
      (rtDW.Integrator_DSTATE - (-(0.6000000000000001 * rtb_Saturation)));
  } else {
    // Gain: '<S220>/Gain16' incorporates:
    //   Constant: '<S119>/Constant1'

    rtb_v_yaw = 0.0;
  }

  // End of Switch: '<S119>/Switch1'

  // Product: '<S215>/Divide1' incorporates:
  //   DiscreteIntegrator: '<S215>/Discrete-Time Integrator1'
  //   Gain: '<S117>/Gain2'
  //   Gain: '<S117>/Gain3'
  //   Gain: '<S117>/Gain9'
  //   Product: '<S215>/Product1'
  //   Sum: '<S119>/Sum5'
  //   Sum: '<S215>/Sum1'
  //   Trigonometry: '<S117>/Atan1'
  //   Trigonometry: '<S117>/Sin1'
  //   Trigonometry: '<S119>/Atan1'

  rtb_Divide1_a = ((std::atan(rtb_v_yaw) - rtDW.steering_outer) -
                   rtDW.DiscreteTimeIntegrator1_DSTAT_d) * rtb_FR_b_tmp / (std::
    sin(std::atan(-0.0002477622368857045 * rtb_y_h) * 2.0) * -1.2116778447999998);

  // Switch: '<S119>/Switch2' incorporates:
  //   DiscreteIntegrator: '<S216>/Integrator'

  if (rtDW.Integrator_DSTATE != 0.0) {
    // DeadZone: '<S119>/Dead Zone3' incorporates:
    //   DiscreteIntegrator: '<S217>/Integrator1'

    if (rtDW.Integrator1_DSTATE > 0.01) {
      rtb_antecedentOutputs_b = rtDW.Integrator1_DSTATE - 0.01;
    } else if (rtDW.Integrator1_DSTATE >= -0.01) {
      rtb_antecedentOutputs_b = 0.0;
    } else {
      rtb_antecedentOutputs_b = rtDW.Integrator1_DSTATE - -0.01;
    }

    // Gain: '<S220>/Gain16' incorporates:
    //   DeadZone: '<S119>/Dead Zone3'
    //   Gain: '<S119>/Gain4'
    //   Gain: '<S119>/Gain5'
    //   Product: '<S119>/Divide1'
    //   Sum: '<S119>/Sum6'
    //   Sum: '<S119>/Sum7'

    rtb_v_yaw = (rtb_antecedentOutputs_b - 0.6885 * rtb_Saturation) /
      (rtDW.Integrator_DSTATE - 0.5899999999999999 * rtb_Saturation);
  } else {
    // Gain: '<S220>/Gain16' incorporates:
    //   Constant: '<S119>/Constant2'

    rtb_v_yaw = 0.0;
  }

  // End of Switch: '<S119>/Switch2'

  // Product: '<S215>/Divide2' incorporates:
  //   DiscreteIntegrator: '<S215>/Discrete-Time Integrator2'
  //   Gain: '<S117>/Gain10'
  //   Gain: '<S117>/Gain4'
  //   Gain: '<S117>/Gain5'
  //   Product: '<S215>/Product2'
  //   Sum: '<S215>/Sum2'
  //   Trigonometry: '<S117>/Atan2'
  //   Trigonometry: '<S117>/Sin2'
  //   Trigonometry: '<S119>/Atan2'

  rtb_Divide2_l = (std::atan(rtb_v_yaw) - rtDW.DiscreteTimeIntegrator2_DSTAT_o) *
    rtb_DiscreteTimeIntegrator1_c / (std::sin(std::atan(-0.0002477622368857045 *
    rtb_RL_i) * 2.0) * -1.2116778447999998);

  // Switch: '<S119>/Switch3' incorporates:
  //   DiscreteIntegrator: '<S216>/Integrator'

  if (rtDW.Integrator_DSTATE != 0.0) {
    // DeadZone: '<S119>/Dead Zone4' incorporates:
    //   DiscreteIntegrator: '<S217>/Integrator1'

    if (rtDW.Integrator1_DSTATE > 0.01) {
      rtb_antecedentOutputs_b = rtDW.Integrator1_DSTATE - 0.01;
    } else if (rtDW.Integrator1_DSTATE >= -0.01) {
      rtb_antecedentOutputs_b = 0.0;
    } else {
      rtb_antecedentOutputs_b = rtDW.Integrator1_DSTATE - -0.01;
    }

    // Gain: '<S220>/Gain16' incorporates:
    //   DeadZone: '<S119>/Dead Zone4'
    //   Gain: '<S119>/Gain6'
    //   Gain: '<S119>/Gain7'
    //   Gain: '<S119>/Gain9'
    //   Product: '<S119>/Divide'
    //   Sum: '<S119>/Sum8'
    //   Sum: '<S119>/Sum9'

    rtb_v_yaw = (rtb_antecedentOutputs_b - 0.6885 * rtb_Saturation) /
      (rtDW.Integrator_DSTATE - (-(0.5900000000000001 * rtb_Saturation)));
  } else {
    // Gain: '<S220>/Gain16' incorporates:
    //   Constant: '<S119>/Constant3'

    rtb_v_yaw = 0.0;
  }

  // End of Switch: '<S119>/Switch3'

  // Product: '<S215>/Divide3' incorporates:
  //   DiscreteIntegrator: '<S215>/Discrete-Time Integrator3'
  //   Gain: '<S117>/Gain11'
  //   Gain: '<S117>/Gain6'
  //   Gain: '<S117>/Gain7'
  //   Product: '<S215>/Product3'
  //   Sum: '<S215>/Sum3'
  //   Trigonometry: '<S117>/Atan3'
  //   Trigonometry: '<S117>/Sin3'
  //   Trigonometry: '<S119>/Atan3'

  rtb_Divide3_f = (std::atan(rtb_v_yaw) - rtDW.DiscreteTimeIntegrator3_DSTAT_f) *
    rtb_Saturation3 / (std::sin(std::atan(-0.0002477622368857045 *
    rtb_DiscreteTimeIntegrator) * 2.0) * -1.2116778447999998);

  // Gain: '<S220>/Gain16' incorporates:
  //   Product: '<S118>/Product6'

  rtb_v_yaw = rtb_uDLookupTable_tmp * rtb_RL_i * rtb_Saturation3_o;

  // Product: '<S118>/Product7'
  rtb_Saturation3_o *= rtb_uDLookupTable_tmp * rtb_DiscreteTimeIntegrator;

  // Saturate: '<S118>/Saturation2'
  if (rtb_v_yaw <= 0.0) {
    // Gain: '<S220>/Gain16'
    rtb_v_yaw = 0.0;
  }

  // End of Saturate: '<S118>/Saturation2'

  // Saturate: '<S118>/Saturation3'
  if (rtb_Saturation3_o <= 0.0) {
    rtb_Saturation3_o = 0.0;
  }

  // End of Saturate: '<S118>/Saturation3'

  // MATLAB Function: '<S218>/MATLAB Function' incorporates:
  //   DiscreteIntegrator: '<S216>/Integrator'
  //   DiscreteIntegrator: '<S217>/Integrator1'

  if ((rtDW.Integrator_DSTATE == 0.0) || (rtDW.Integrator1_DSTATE == 0.0)) {
    rtb_y_g = 0.0;
  } else {
    rtb_y_g = rtDW.Integrator1_DSTATE / rtDW.Integrator_DSTATE;
  }

  // End of MATLAB Function: '<S218>/MATLAB Function'

  // Sum: '<S218>/Sum3' incorporates:
  //   DiscreteIntegrator: '<S220>/Integrator1'
  //   Sum: '<S218>/Sum2'
  //   Trigonometry: '<S218>/Atan'

  rtb_y_h = rtDW.Integrator1_DSTATE_b + std::atan(rtb_y_g);

  // Trigonometry: '<S218>/Sin' incorporates:
  //   Sum: '<S218>/Sum3'
  //   Trigonometry: '<S218>/Sin1'

  rtb_y_g = std::sin(rtb_y_h);

  // Trigonometry: '<S218>/Cos' incorporates:
  //   Trigonometry: '<S218>/Cos1'

  rtb_y_h = std::cos(rtb_y_h);

  // Sum: '<S218>/Sum' incorporates:
  //   DiscreteIntegrator: '<S216>/Integrator'
  //   DiscreteIntegrator: '<S217>/Integrator1'
  //   Product: '<S218>/Product'
  //   Product: '<S218>/Product1'
  //   Trigonometry: '<S218>/Cos'
  //   Trigonometry: '<S218>/Sin'

  rtb_Sum_bg = rtDW.Integrator_DSTATE * rtb_y_h - rtDW.Integrator1_DSTATE *
    rtb_y_g;

  // Sum: '<S218>/Sum1' incorporates:
  //   DiscreteIntegrator: '<S216>/Integrator'
  //   DiscreteIntegrator: '<S217>/Integrator1'
  //   Product: '<S218>/Product2'
  //   Product: '<S218>/Product3'

  rtb_Sum1_n = rtDW.Integrator_DSTATE * rtb_y_g + rtDW.Integrator1_DSTATE *
    rtb_y_h;
  if (tmp) {
    // Trigonometry: '<S219>/Cos'
    rtDW.Cos_i = std::cos(rtDW.steering_inner);

    // Trigonometry: '<S219>/Cos1'
    rtDW.Cos1_e = std::sin(rtDW.steering_inner);

    // Trigonometry: '<S219>/Cos2'
    rtDW.Cos2_h = std::cos(rtDW.steering_outer);

    // Trigonometry: '<S219>/Cos3'
    rtDW.Cos3_i = std::sin(rtDW.steering_outer);
  }

  // Sum: '<S219>/Sum1' incorporates:
  //   Product: '<S219>/Product'
  //   Product: '<S219>/Product1'

  rtb_Sum_if = rtb_uDLookupTable * rtDW.Cos_i - inner * rtDW.Cos1_e;

  // Sum: '<S219>/Sum3' incorporates:
  //   Product: '<S219>/Product2'
  //   Product: '<S219>/Product3'

  rtb_Product_az = rtb_Sum1_ot * rtDW.Cos2_h - rtb_Product_d1 * rtDW.Cos3_i;

  // Gain: '<S216>/Gain1' incorporates:
  //   Gain: '<S216>/Gain8'
  //   Sum: '<S216>/Sum3'
  //   Sum: '<S216>/Sum4'
  //   Sum: '<S216>/Sum7'

  rtDW.Ax_Cg = (((((rtb_Sum_if + rtb_Product_az) + rtb_Saturation_c) +
                  rtb_Product_a3) - (rtb_v_yaw + rtb_Saturation3_o)) -
                rtb_uDLookupTable_tmp_0 * 0.81862) * 0.0033333333333333335;

  // Sum: '<S216>/Sum5' incorporates:
  //   DiscreteIntegrator: '<S217>/Integrator1'
  //   Product: '<S216>/Product'

  rtb_Ax = rtDW.Integrator1_DSTATE * rtb_DiscreteTimeIntegrator1 + rtDW.Ax_Cg;

  // DeadZone: '<S217>/Dead Zone'
  if (rtb_DiscreteTimeIntegrator1 > 0.1) {
    rtb_antecedentOutputs_b = rtb_DiscreteTimeIntegrator1 - 0.1;
  } else if (rtb_DiscreteTimeIntegrator1 >= -0.1) {
    rtb_antecedentOutputs_b = 0.0;
  } else {
    rtb_antecedentOutputs_b = rtb_DiscreteTimeIntegrator1 - -0.1;
  }

  // Sum: '<S217>/Sum6' incorporates:
  //   DeadZone: '<S217>/Dead Zone'
  //   DiscreteIntegrator: '<S216>/Integrator'
  //   Product: '<S217>/Product1'

  rtb_Ay_cg = rtDW.Ay_cg - rtDW.Integrator_DSTATE * rtb_antecedentOutputs_b;

  // Gain: '<S220>/Gain16' incorporates:
  //   Gain: '<S220>/Gain'
  //   Gain: '<S220>/Gain10'
  //   Gain: '<S220>/Gain12'
  //   Gain: '<S220>/Gain14'
  //   Gain: '<S220>/Gain2'
  //   Gain: '<S220>/Gain3'
  //   Gain: '<S220>/Gain4'
  //   Gain: '<S220>/Gain6'
  //   Gain: '<S220>/Gain7'
  //   Gain: '<S220>/Gain8'
  //   Sum: '<S220>/Sum'
  //   Sum: '<S220>/Sum1'
  //   Sum: '<S220>/Sum2'
  //   Sum: '<S220>/Sum3'
  //   Sum: '<S220>/Sum5'

  rtb_v_yaw = (((((0.0 - 0.625 * rtb_Sum_if) - (-(0.6000000000000001 *
    rtb_Product_az))) - (rtb_Saturation_c - rtb_v_yaw) * 0.5899999999999999) - (
    -((rtb_Product_a3 - rtb_Saturation3_o) * 0.5900000000000001))) +
               (((0.8415000000000001 * rtb_Fyref_FL + 0.8415000000000001 *
                  rtb_Fyref_FR) - 0.6885 * rtb_Sum_bb) - 0.6885 *
                rtb_MathFunction)) * 0.005555555555555556;

  // DeadZone: '<S220>/Dead Zone'
  if (rtb_v_yaw > 0.1) {
    // DeadZone: '<S220>/Dead Zone'
    rtb_DeadZone_f = rtb_v_yaw - 0.1;
  } else if (rtb_v_yaw >= -0.1) {
    // DeadZone: '<S220>/Dead Zone'
    rtb_DeadZone_f = 0.0;
  } else {
    // DeadZone: '<S220>/Dead Zone'
    rtb_DeadZone_f = rtb_v_yaw - -0.1;
  }

  // End of DeadZone: '<S220>/Dead Zone'

  // Update for DiscreteTransferFcn: '<S127>/Discrete Transfer Fcn1'
  rtDW.DiscreteTransferFcn1_states = rtDW.Ax_Cg - -0.8187 *
    rtDW.DiscreteTransferFcn1_states;

  // Update for DiscreteTransferFcn: '<S126>/Discrete Transfer Fcn2'
  rtDW.DiscreteTransferFcn2_states = rtDW.Ay_cg - -0.8187 *
    rtDW.DiscreteTransferFcn2_states;

  // Update for DiscreteIntegrator: '<S216>/Integrator'
  rtDW.Integrator_DSTATE += 0.001 * rtb_Ax;

  // Update for DiscreteIntegrator: '<S220>/Discrete-Time Integrator1'
  rtDW.DiscreteTimeIntegrator1_DSTATE += 0.001 * rtb_DeadZone_f;
  if ((&rtM)->Timing.TaskCounters.TID[2] == 0) {
    // Update for DiscreteIntegrator: '<S92>/Integrator'
    rtDW.Integrator_DSTATE_c += 0.01 * rtb_IntegralGain;

    // Update for UnitDelay: '<S31>/UD'
    //
    //  Block description for '<S31>/UD':
    //
    //   Store in Global RAM

    rtDW.UD_DSTATE = rtb_TSamp;

    // Update for UnitDelay: '<S37>/UD'
    //
    //  Block description for '<S37>/UD':
    //
    //   Store in Global RAM

    rtDW.UD_DSTATE_k = rtb_TSamp_n;

    // Update for UnitDelay: '<S43>/UD'
    //
    //  Block description for '<S43>/UD':
    //
    //   Store in Global RAM

    rtDW.UD_DSTATE_g = rtb_TSamp_o;

    // Update for UnitDelay: '<S49>/UD'
    //
    //  Block description for '<S49>/UD':
    //
    //   Store in Global RAM

    rtDW.UD_DSTATE_b = rtb_TSamp_g;
  }

  // Update for DiscreteIntegrator: '<S112>/Discrete-Time Integrator'
  rtDW.DiscreteTimeIntegrator_DSTATE += 0.001 * rtb_Divide_fk;

  // Update for DiscreteIntegrator: '<S112>/Discrete-Time Integrator1'
  rtDW.DiscreteTimeIntegrator1_DSTAT_e += 0.001 * rtb_Divide1_i;

  // Update for DiscreteIntegrator: '<S112>/Discrete-Time Integrator2'
  rtDW.DiscreteTimeIntegrator2_DSTATE += 0.001 * rtb_Divide2_c;

  // Update for DiscreteIntegrator: '<S112>/Discrete-Time Integrator3'
  rtDW.DiscreteTimeIntegrator3_DSTATE += 0.001 * rtb_Divide3_e;

  // Update for UnitDelay: '<S13>/Unit Delay'
  rtDW.UnitDelay_DSTATE = rtDW.Sum1;

  // Update for DiscreteIntegrator: '<S215>/Discrete-Time Integrator'
  rtDW.DiscreteTimeIntegrator_DSTATE_d += 0.001 * rtb_Divide_ov;

  // Update for DiscreteIntegrator: '<S215>/Discrete-Time Integrator1'
  rtDW.DiscreteTimeIntegrator1_DSTAT_d += 0.001 * rtb_Divide1_a;

  // Update for DiscreteIntegrator: '<S215>/Discrete-Time Integrator2'
  rtDW.DiscreteTimeIntegrator2_DSTAT_o += 0.001 * rtb_Divide2_l;

  // Update for DiscreteIntegrator: '<S215>/Discrete-Time Integrator3'
  rtDW.DiscreteTimeIntegrator3_DSTAT_f += 0.001 * rtb_Divide3_f;

  // Update for DiscreteIntegrator: '<S217>/Integrator1'
  rtDW.Integrator1_DSTATE += 0.001 * rtb_Ay_cg;

  // Update for DiscreteIntegrator: '<S220>/Integrator1'
  rtDW.Integrator1_DSTATE_b += 0.001 * rtb_DiscreteTimeIntegrator1;

  // Update for DiscreteIntegrator: '<S218>/Integrator'
  rtDW.Integrator_DSTATE_g += 0.001 * rtb_Sum_bg;

  // Update for DiscreteIntegrator: '<S218>/Integrator1'
  rtDW.Integrator1_DSTATE_bs += 0.001 * rtb_Sum1_n;

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  (&rtM)->Timing.t[0] =
    ((time_T)(++(&rtM)->Timing.clockTick0)) * (&rtM)->Timing.stepSize0;

  {
    // Update absolute timer for sample time: [0.001s, 0.0s]
    // The "clockTick1" counts the number of times the code of this task has
    //  been executed. The resolution of this integer timer is 0.001, which is the step size
    //  of the task. Size of "clockTick1" ensures timer will not overflow during the
    //  application lifespan selected.

    (&rtM)->Timing.clockTick1++;
  }

  rate_scheduler((&rtM));
}

// Model initialize function
void PlanarModelandControl::initialize()
{
  // Registration code
  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&(&rtM)->solverInfo, &(&rtM)->Timing.simTimeStep);
    rtsiSetTPtr(&(&rtM)->solverInfo, (&rtM)->getTPtrPtr());
    rtsiSetStepSizePtr(&(&rtM)->solverInfo, &(&rtM)->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&(&rtM)->solverInfo, (&rtM)->getErrorStatusPtr());
    rtsiSetRTModelPtr(&(&rtM)->solverInfo, (&rtM));
  }

  rtsiSetSimTimeStep(&(&rtM)->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&(&rtM)->solverInfo, false);
  rtsiSetIsContModeFrozen(&(&rtM)->solverInfo, false);
  rtsiSetSolverName(&(&rtM)->solverInfo,"FixedStepDiscrete");
  (&rtM)->setTPtr(&(&rtM)->Timing.tArray[0]);
  (&rtM)->Timing.stepSize0 = 0.001;

  // Initialize DataMapInfo substructure containing ModelMap for C API
  PlanarModelandControl_InitializeDataMapInfo((&rtM), &rtDW);

  // Start for FromWorkspace: '<Root>/From Workspace2'
  {
    static real_T pTimeValues0[]{ 0.0, 0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07,
      0.08, 0.09, 0.1, 0.11, 0.12, 0.13, 0.14, 0.15, 0.16, 0.17, 0.18, 0.19, 0.2,
      0.21, 0.22, 0.23, 0.24, 0.25, 0.26, 0.27, 0.28, 0.29, 0.3, 0.31, 0.32,
      0.33, 0.34, 0.35000000000000003, 0.36, 0.37, 0.38, 0.39, 0.4,
      0.41000000000000003, 0.42, 0.43, 0.44, 0.45, 0.46, 0.47000000000000003,
      0.48, 0.49, 0.5, 0.51, 0.52, 0.53, 0.54, 0.55, 0.56, 0.57000000000000006,
      0.58, 0.59, 0.6, 0.61, 0.62, 0.63, 0.64, 0.65, 0.66, 0.67, 0.68,
      0.69000000000000006, 0.70000000000000007, 0.71, 0.72, 0.73, 0.74, 0.75,
      0.76, 0.77, 0.78, 0.79, 0.8, 0.81, 0.82000000000000006,
      0.83000000000000007, 0.84, 0.85, 0.86, 0.87, 0.88, 0.89, 0.9, 0.91, 0.92,
      0.93, 0.94000000000000006, 0.95000000000000007, 0.96, 0.97, 0.98, 0.99,
      1.0, 1.01, 1.02, 1.03, 1.04, 1.05, 1.06, 1.07, 1.08, 1.09, 1.1, 1.11, 1.12,
      1.1300000000000001, 1.1400000000000001, 1.1500000000000001, 1.16, 1.17,
      1.18, 1.19, 1.2, 1.21, 1.22, 1.23, 1.24, 1.25, 1.26, 1.27, 1.28, 1.29, 1.3,
      1.31, 1.32, 1.33, 1.34, 1.35, 1.36, 1.37, 1.3800000000000001,
      1.3900000000000001, 1.4000000000000001, 1.41, 1.42, 1.43, 1.44, 1.45, 1.46,
      1.47, 1.48, 1.49, 1.5, 1.51, 1.52, 1.53, 1.54, 1.55, 1.56, 1.57, 1.58,
      1.59, 1.6, 1.61, 1.62, 1.6300000000000001, 1.6400000000000001,
      1.6500000000000001, 1.6600000000000001, 1.67, 1.68, 1.69, 1.7, 1.71, 1.72,
      1.73, 1.74, 1.75, 1.76, 1.77, 1.78, 1.79, 1.8, 1.81, 1.82, 1.83, 1.84,
      1.85, 1.86, 1.87, 1.8800000000000001, 1.8900000000000001,
      1.9000000000000001, 1.9100000000000001, 1.92, 1.93, 1.94, 1.95, 1.96, 1.97,
      1.98, 1.99, 2.0, 2.0100000000000002, 2.02, 2.0300000000000002, 2.04, 2.05,
      2.06, 2.07, 2.08, 2.09, 2.1, 2.11, 2.12, 2.13, 2.14, 2.15, 2.16, 2.17,
      2.18, 2.19, 2.2, 2.21, 2.22, 2.23, 2.24, 2.25, 2.2600000000000002, 2.27,
      2.2800000000000002, 2.29, 2.3, 2.3099999999999996, 2.3199999999999994,
      2.3299999999999996, 2.3399999999999994, 2.3499999999999996,
      2.3599999999999994, 2.3699999999999997, 2.3799999999999994,
      2.3899999999999997, 2.3999999999999995, 2.4099999999999997,
      2.4199999999999995, 2.4299999999999997, 2.4399999999999995,
      2.4499999999999997, 2.4599999999999995, 2.4699999999999998,
      2.4799999999999995, 2.4899999999999998, 2.4999999999999996, 2.51,
      2.5199999999999996, 2.53, 2.5399999999999996, 2.55, 2.5599999999999996,
      2.5699999999999994, 2.5799999999999996, 2.5899999999999994,
      2.5999999999999996, 2.6099999999999994, 2.6199999999999997, 2.63,
      2.6399999999999997, 2.6499999999999995, 2.6599999999999997, 2.67,
      2.6799999999999997, 2.6899999999999995, 2.6999999999999993,
      2.7099999999999995, 2.7199999999999998, 2.7299999999999995,
      2.7399999999999993, 2.7499999999999996, 2.76, 2.7699999999999996,
      2.7799999999999994, 2.7899999999999996, 2.8, 2.8099999999999996,
      2.8199999999999994, 2.8299999999999996, 2.84, 2.8499999999999996,
      2.8599999999999994, 2.8699999999999997, 2.88, 2.8899999999999997,
      2.8999999999999995, 2.9099999999999997, 2.92, 2.9299999999999997,
      2.9399999999999995, 2.9499999999999993, 2.9599999999999995,
      2.9699999999999998, 2.9799999999999995, 2.9899999999999993,
      2.9999999999999996, 3.01, 3.0199999999999996, 3.0299999999999994,
      3.0399999999999996, 3.05, 3.0599999999999996, 3.0699999999999994,
      3.0799999999999996, 3.09, 3.0999999999999996, 3.1099999999999994,
      3.1199999999999997, 3.13, 3.1399999999999997, 3.1499999999999995,
      3.1599999999999997, 3.17, 3.1799999999999997, 3.1899999999999995,
      3.1999999999999993, 3.2099999999999995, 3.2199999999999998,
      3.2299999999999995, 3.2399999999999993, 3.2499999999999996, 3.26,
      3.2699999999999996, 3.2799999999999994, 3.2899999999999996, 3.3,
      3.3099999999999996, 3.3199999999999994, 3.3299999999999996, 3.34,
      3.3499999999999996, 3.3599999999999994, 3.3699999999999997, 3.38,
      3.3899999999999997, 3.3999999999999995, 3.4099999999999997, 3.42,
      3.4299999999999997, 3.4399999999999995, 3.4499999999999993,
      3.4599999999999995, 3.4699999999999998, 3.4799999999999995,
      3.4899999999999993, 3.4999999999999996, 3.51, 3.5199999999999996,
      3.5299999999999994, 3.5399999999999996, 3.55, 3.5599999999999996,
      3.5699999999999994, 3.5799999999999996, 3.59, 3.5999999999999996,
      3.6099999999999994, 3.6199999999999997, 3.63, 3.6399999999999997,
      3.6499999999999995, 3.6599999999999997, 3.6699999999999995,
      3.6799999999999997, 3.6899999999999995, 3.6999999999999997,
      3.7099999999999995, 3.7199999999999998, 3.7299999999999995,
      3.7399999999999998, 3.7499999999999996, 3.76, 3.7699999999999996,
      3.7799999999999994, 3.7899999999999996, 3.8, 3.8099999999999996,
      3.8199999999999994, 3.8299999999999996, 3.84, 3.8499999999999996,
      3.8599999999999994, 3.8699999999999997, 3.88, 3.8899999999999997,
      3.8999999999999995, 3.9099999999999997, 3.9199999999999995,
      3.9299999999999997, 3.9399999999999995, 3.9499999999999997,
      3.9599999999999995, 3.9699999999999998, 3.9799999999999995,
      3.9899999999999998, 3.9999999999999996, 4.01, 4.02, 4.0299999999999994,
      4.0399999999999991, 4.05, 4.06, 4.0699999999999994, 4.08, 4.09, 4.1,
      4.1099999999999994, 4.1199999999999992, 4.13, 4.14, 4.1499999999999995,
      4.1599999999999993, 4.17, 4.18, 4.1899999999999995, 4.1999999999999993,
      4.21, 4.22, 4.2299999999999995, 4.2399999999999993, 4.25, 4.26, 4.27,
      4.2799999999999994, 4.29, 4.3, 4.31, 4.3199999999999994, 4.33, 4.34, 4.35,
      4.3599999999999994, 4.3699999999999992, 4.38, 4.39, 4.3999999999999995,
      4.4099999999999993, 4.42, 4.43, 4.4399999999999995, 4.4499999999999993,
      4.46, 4.47, 4.4799999999999995, 4.4899999999999993, 4.5, 4.51, 4.52,
      4.5299999999999994, 4.54, 4.55, 4.56, 4.5699999999999994, 4.58, 4.59, 4.6
    } ;

    static real_T pDataValues0[]{ 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      1.5000000000000013, 3.0000000000000027, 4.5000000000000036,
      6.0000000000000053, 7.5000000000000071, 9.0000000000000071,
      10.500000000000009, 11.999999999999995, 13.499999999999995,
      14.999999999999996, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0 } ;

    rtDW.FromWorkspace2_PWORK.TimePtr = static_cast<void *>(pTimeValues0);
    rtDW.FromWorkspace2_PWORK.DataPtr = static_cast<void *>(pDataValues0);
    rtDW.FromWorkspace2_IWORK.PrevIndex = 0;
  }

  // InitializeConditions for DiscreteIntegrator: '<S216>/Integrator'
  rtDW.Integrator_DSTATE = 5.0;

  // InitializeConditions for DiscreteIntegrator: '<S112>/Discrete-Time Integrator' 
  rtDW.DiscreteTimeIntegrator_DSTATE = 25.0;

  // InitializeConditions for DiscreteIntegrator: '<S112>/Discrete-Time Integrator1' 
  rtDW.DiscreteTimeIntegrator1_DSTAT_e = 25.0;

  // InitializeConditions for DiscreteIntegrator: '<S112>/Discrete-Time Integrator2' 
  rtDW.DiscreteTimeIntegrator2_DSTATE = 25.0;

  // InitializeConditions for DiscreteIntegrator: '<S112>/Discrete-Time Integrator3' 
  rtDW.DiscreteTimeIntegrator3_DSTATE = 25.0;
}

time_T** PlanarModelandControl::RT_MODEL::getTPtrPtr()
{
  return &(Timing.t);
}

time_T* PlanarModelandControl::RT_MODEL::getTPtr() const
{
  return (Timing.t);
}

void PlanarModelandControl::RT_MODEL::setTPtr(time_T* aTPtr)
{
  (Timing.t = aTPtr);
}

boolean_T PlanarModelandControl::RT_MODEL::isMinorTimeStep() const
{
  return ((Timing.simTimeStep) == MINOR_TIME_STEP);
}

boolean_T PlanarModelandControl::RT_MODEL::isMajorTimeStep() const
{
  return ((Timing.simTimeStep) == MAJOR_TIME_STEP);
}

const char_T** PlanarModelandControl::RT_MODEL::getErrorStatusPtr()
{
  return &errorStatus;
}

const char_T* PlanarModelandControl::RT_MODEL::getErrorStatus() const
{
  return (errorStatus);
}

void PlanarModelandControl::RT_MODEL::setErrorStatus(const char_T* const
  aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

PlanarModelandControl::RT_MODEL::DataMapInfo_T PlanarModelandControl::RT_MODEL::
  getDataMapInfo() const
{
  return DataMapInfo;
}

void PlanarModelandControl::RT_MODEL::setDataMapInfo(PlanarModelandControl::
  RT_MODEL::DataMapInfo_T aDataMapInfo)
{
  DataMapInfo = aDataMapInfo;
}

// Constructor
PlanarModelandControl::PlanarModelandControl() :
  rtDW(),
  rtM()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
PlanarModelandControl::~PlanarModelandControl() = default;

// Real-Time Model get method
PlanarModelandControl::RT_MODEL * PlanarModelandControl::getRTM()
{
  return (&rtM);
}

//
// File trailer for generated code.
//
// [EOF]
//
