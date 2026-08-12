//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PlanarModelandControl.h
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
#ifndef PLANARMODELANDCONTROL_H_
#define PLANARMODELANDCONTROL_H_
#include <cmath>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rtw_modelmap.h"
#ifndef SS_UINT64
#define SS_UINT64                      22
#endif

#ifndef SS_INT64
#define SS_INT64                       23
#endif

// Function to get C API Model Mapping Static Info
extern const rtwCAPI_ModelMappingStaticInfo*
  PlanarModelandControl_GetCAPIStaticMap(void);
extern "C"
{
  static real_T rtGetNaN(void);
  static real32_T rtGetNaNF(void);
}                                      // extern "C"

extern "C"
{
  extern real_T rtInf;
  extern real_T rtMinusInf;
  extern real_T rtNaN;
  extern real32_T rtInfF;
  extern real32_T rtMinusInfF;
  extern real32_T rtNaNF;
  static boolean_T rtIsInf(real_T value);
  static boolean_T rtIsInfF(real32_T value);
  static boolean_T rtIsNaN(real_T value);
  static boolean_T rtIsNaNF(real32_T value);
}                                      // extern "C"

// Class declaration for model PlanarModelandControl
class PlanarModelandControl final
{
  // public data and function members
 public:
  // Block signals and states (default storage) for system '<Root>'
  struct DW {
    real_T RateTransition10;           // '<S1>/Rate Transition10'
    real_T Yaw_limit;                  // '<S12>/Divide'
    real_T Divide1;                    // '<S12>/Divide1'
    real_T yaw_ref;                    // '<S12>/Merge'
    real_T yaw_rate;                   // '<S1>/Rate Transition9'
    real_T nDLookupTable1;             // '<S13>/n-D Lookup Table1'
    real_T nDLookupTable;              // '<S13>/n-D Lookup Table'
    real_T Switch;                     // '<S2>/Switch'
    real_T Limitemin;                  // '<S13>/Limite min'
    real_T Limitemx;                   // '<S13>/Limite máx'
    real_T Sum1;                       // '<S13>/Sum1'
    real_T Abs;                        // '<S185>/Abs'
    real_T steering_inner;             // '<Root>/Zero-Order Hold'
    real_T Cos;                        // '<S221>/Cos'
    real_T Sum_g;                      // '<S143>/Sum'
    real_T Cos1;                       // '<S221>/Cos1'
    real_T Abs_n;                      // '<S193>/Abs'
    real_T steering_outer;             // '<Root>/Zero-Order Hold'
    real_T Cos2;                       // '<S221>/Cos2'
    real_T Sum_j;                      // '<S154>/Sum'
    real_T Cos3;                       // '<S221>/Cos3'
    real_T Abs_n0;                     // '<S201>/Abs'
    real_T Sum_n;                      // '<S165>/Sum'
    real_T Abs_h;                      // '<S209>/Abs'
    real_T Sum_f;                      // '<S176>/Sum'
    real_T Ay_cg;                      // '<S217>/Gain'
    real_T ay_cg;                      // '<S1>/Rate Transition8'
    real_T Switch2;                    // '<S17>/Switch2'
    real_T Limitemin_o;                // '<S10>/Limite min'
    real_T Limitemx_m;                 // '<S10>/Limite máx'
    real_T Switch1;                    // '<S2>/Switch1'
    real_T torque_mx_f;                // '<S114>/torque_máx_f'
    real_T torque_mx_r;                // '<S114>/torque_máx_r'
    real_T Cos_i;                      // '<S219>/Cos'
    real_T Cos1_e;                     // '<S219>/Cos1'
    real_T Cos2_h;                     // '<S219>/Cos2'
    real_T Cos3_i;                     // '<S219>/Cos3'
    real_T Ax_Cg;                      // '<S216>/Gain1'
    real_T Switch_e;                   // '<S24>/Switch'
    real_T Switch1_j;                  // '<S24>/Switch1'
    real_T Switch2_o;                  // '<S24>/Switch2'
    real_T Switch3;                    // '<S24>/Switch3'
    real_T DiscreteTransferFcn1_states;// '<S127>/Discrete Transfer Fcn1'
    real_T DiscreteTransferFcn2_states;// '<S126>/Discrete Transfer Fcn2'
    real_T Integrator_DSTATE;          // '<S216>/Integrator'
    real_T DiscreteTimeIntegrator1_DSTATE;// '<S220>/Discrete-Time Integrator1'
    real_T Integrator_DSTATE_c;        // '<S92>/Integrator'
    real_T DiscreteTimeIntegrator_DSTATE;// '<S112>/Discrete-Time Integrator'
    real_T DiscreteTimeIntegrator1_DSTAT_e;// '<S112>/Discrete-Time Integrator1' 
    real_T DiscreteTimeIntegrator2_DSTATE;// '<S112>/Discrete-Time Integrator2'
    real_T DiscreteTimeIntegrator3_DSTATE;// '<S112>/Discrete-Time Integrator3'
    real_T UnitDelay_DSTATE;           // '<S13>/Unit Delay'
    real_T DiscreteTimeIntegrator_DSTATE_d;// '<S215>/Discrete-Time Integrator'
    real_T DiscreteTimeIntegrator1_DSTAT_d;// '<S215>/Discrete-Time Integrator1' 
    real_T DiscreteTimeIntegrator2_DSTAT_o;// '<S215>/Discrete-Time Integrator2' 
    real_T DiscreteTimeIntegrator3_DSTAT_f;// '<S215>/Discrete-Time Integrator3' 
    real_T UD_DSTATE;                  // '<S31>/UD'
    real_T UD_DSTATE_k;                // '<S37>/UD'
    real_T UD_DSTATE_g;                // '<S43>/UD'
    real_T UD_DSTATE_b;                // '<S49>/UD'
    real_T Integrator1_DSTATE;         // '<S217>/Integrator1'
    real_T Integrator1_DSTATE_b;       // '<S220>/Integrator1'
    real_T Integrator_DSTATE_g;        // '<S218>/Integrator'
    real_T Integrator1_DSTATE_bs;      // '<S218>/Integrator1'
    real_T PrevY;                      // '<S26>/Rate Limiter'
    real_T PrevY_f;                    // '<S27>/Rate Limiter'
    real_T PrevY_g;                    // '<S28>/Rate Limiter'
    real_T PrevY_h;                    // '<S29>/Rate Limiter'
    struct {
      void *TimePtr;
      void *DataPtr;
      void *RSimInfoPtr;
    } FromWorkspace2_PWORK;            // '<Root>/From Workspace2'

    struct {
      int_T PrevIndex;
    } FromWorkspace2_IWORK;            // '<Root>/From Workspace2'
  };

  // Constant parameters (default storage)
  struct ConstP {
    // Pooled Parameter (Expression: Mz_minF)
    //  Referenced by:
    //    '<S10>/Limite min'
    //    '<S13>/Limite min'
    //    '<S14>/Limite min'

    real_T pooled1[26];

    // Pooled Parameter (Expression: pedal)
    //  Referenced by:
    //    '<S10>/Limite min'
    //    '<S10>/Limite máx'
    //    '<S13>/Limite min'
    //    '<S13>/Limite máx'
    //    '<S14>/Limite min'
    //    '<S14>/Limite máx'

    real_T pooled2[26];

    // Pooled Parameter (Expression: fis.outputSamplePoints)
    //  Referenced by:
    //    '<S32>/Output Sample Points'
    //    '<S38>/Output Sample Points'
    //    '<S44>/Output Sample Points'
    //    '<S50>/Output Sample Points'

    real_T pooled12[101];

    // Pooled Parameter (Expression: Cs)
    //  Referenced by:
    //    '<S4>/1-D Lookup Table'
    //    '<S4>/1-D Lookup Table1'
    //    '<S4>/1-D Lookup Table2'
    //    '<S4>/1-D Lookup Table3'

    real_T pooled31[5];

    // Pooled Parameter (Expression: Fz_cs)
    //  Referenced by:
    //    '<S4>/1-D Lookup Table'
    //    '<S4>/1-D Lookup Table1'
    //    '<S4>/1-D Lookup Table2'
    //    '<S4>/1-D Lookup Table3'

    real_T pooled32[5];

    // Expression: Steering_inner
    //  Referenced by: '<S2>/1-D Lookup Table2'

    real_T uDLookupTable2_tableData[21];

    // Pooled Parameter (Expression: steering_vol)
    //  Referenced by:
    //    '<S2>/1-D Lookup Table2'
    //    '<S2>/1-D Lookup Table3'

    real_T pooled34[21];

    // Expression: Steering_outer
    //  Referenced by: '<S2>/1-D Lookup Table3'

    real_T uDLookupTable3_tableData[21];

    // Expression: K_variavel
    //  Referenced by: '<S6>/1-D Lookup Table'

    real_T uDLookupTable_tableData[5];

    // Expression: Vx
    //  Referenced by: '<S6>/1-D Lookup Table'

    real_T uDLookupTable_bp01Data[5];

    // Expression: Ki_data
    //  Referenced by: '<S13>/n-D Lookup Table1'

    real_T nDLookupTable1_tableData[7];

    // Pooled Parameter (Expression: Vx_axis)
    //  Referenced by:
    //    '<S13>/n-D Lookup Table'
    //    '<S13>/n-D Lookup Table1'

    real_T pooled36[7];

    // Expression: Kp_data
    //  Referenced by: '<S13>/n-D Lookup Table'

    real_T nDLookupTable_tableData[7];

    // Pooled Parameter (Expression: torque_355_novo)
    //  Referenced by:
    //    '<S7>/1-D Lookup Table'
    //    '<S7>/1-D Lookup Table1'
    //    '<S7>/1-D Lookup Table2'
    //    '<S7>/1-D Lookup Table3'

    real_T pooled40[28];

    // Pooled Parameter (Expression: rpm_355_novo)
    //  Referenced by:
    //    '<S7>/1-D Lookup Table'
    //    '<S7>/1-D Lookup Table1'
    //    '<S7>/1-D Lookup Table2'
    //    '<S7>/1-D Lookup Table3'

    real_T pooled41[28];

    // Pooled Parameter (Expression: Mz_maxF)
    //  Referenced by:
    //    '<S10>/Limite máx'
    //    '<S13>/Limite máx'
    //    '<S14>/Limite máx'

    real_T pooled42[26];
  };

  // Real-time Model Data Structure
  struct RT_MODEL {
    const char_T *errorStatus;
    RTWSolverInfo solverInfo;

    //
    //  DataMapInfo:
    //  The following substructure contains information regarding
    //  structures generated in the model's C API.

    struct DataMapInfo_T {
      rtwCAPI_ModelMappingInfo mmi;
      void* dataAddress[47];
      int32_T* vardimsAddress[47];
      RTWLoggingFcnPtr loggingPtrs[47];
    };

    DataMapInfo_T DataMapInfo;

    //
    //  Timing:
    //  The following substructure contains information regarding
    //  the timing information for the model.

    struct {
      uint32_T clockTick0;
      time_T stepSize0;
      uint32_T clockTick1;
      struct {
        uint8_T TID[3];
      } TaskCounters;

      SimTimeStep simTimeStep;
      time_T *t;
      time_T tArray[3];
    } Timing;

    time_T** getTPtrPtr();
    time_T* getTPtr() const;
    void setTPtr(time_T* aTPtr);
    boolean_T isMinorTimeStep() const;
    boolean_T isMajorTimeStep() const;
    const char_T** getErrorStatusPtr();
    const char_T* getErrorStatus() const;
    void setErrorStatus(const char_T* const aErrorStatus);
    PlanarModelandControl::RT_MODEL::DataMapInfo_T getDataMapInfo() const;
    void setDataMapInfo(PlanarModelandControl::RT_MODEL::DataMapInfo_T
                        aDataMapInfo);
  };

  // Copy Constructor
  PlanarModelandControl(PlanarModelandControl const&) = delete;

  // Assignment Operator
  PlanarModelandControl& operator= (PlanarModelandControl const&) & = delete;

  // Move Constructor
  PlanarModelandControl(PlanarModelandControl &&) = delete;

  // Move Assignment Operator
  PlanarModelandControl& operator= (PlanarModelandControl &&) = delete;

  // Real-Time Model get method
  PlanarModelandControl::RT_MODEL * getRTM();

  // Block states
  DW rtDW;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // Constructor
  PlanarModelandControl();

  // Destructor
  ~PlanarModelandControl();

  // private data and function members
 private:
  // private member function(s) for subsystem '<S32>/Evaluate Rule Consequents'
  static void EvaluateRuleConsequents(const real_T rtu_antecedentOutputs[28],
    const real_T rtu_samplePoints[101], real_T rty_aggregatedOutputs[101]);

  // private member function(s) for subsystem '<S128>/MATLAB Function4'
  static void MATLABFunction4(real_T rtu_u, real_T *rty_y);

  // private member function(s) for subsystem '<S131>/MATLAB Function'
  static void MATLABFunction(real_T rtu_Fz, real_T rtu_Dy, real_T rtu_Cy, real_T
    rtu_By, real_T rtu_Ey, real_T rtu_SVy, real_T rtu_SAy, real_T *rty_Fy);

  // private member function(s) for subsystem '<S135>/MATLAB Function'
  static void MATLABFunction_m(real_T rtu_Slx, real_T rtu_Dx, real_T rtu_Cx,
    real_T rtu_Bx, real_T rtu_Ex, real_T rtu_SVx, real_T *rty_Fx);

  // Real-Time Model
  RT_MODEL rtM;
};

// Constant parameters (default storage)
extern const PlanarModelandControl::ConstP rtConstP;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S16>/Data Type Duplicate' : Unused code path elimination
//  Block '<S16>/Data Type Propagation' : Unused code path elimination
//  Block '<S17>/Data Type Duplicate' : Unused code path elimination
//  Block '<S17>/Data Type Propagation' : Unused code path elimination
//  Block '<S15>/Data Type Duplicate' : Unused code path elimination
//  Block '<S15>/Data Type Propagation' : Unused code path elimination
//  Block '<S5>/Rate Transition' : Unused code path elimination
//  Block '<S5>/To Workspace1' : Unused code path elimination
//  Block '<S1>/To Workspace' : Unused code path elimination
//  Block '<S1>/To Workspace2' : Unused code path elimination
//  Block '<S23>/Divide' : Unused code path elimination
//  Block '<S23>/Sum24' : Unused code path elimination
//  Block '<S23>/Sum25' : Unused code path elimination
//  Block '<S23>/Sum26' : Unused code path elimination
//  Block '<S31>/Data Type Duplicate' : Unused code path elimination
//  Block '<S37>/Data Type Duplicate' : Unused code path elimination
//  Block '<S43>/Data Type Duplicate' : Unused code path elimination
//  Block '<S49>/Data Type Duplicate' : Unused code path elimination
//  Block '<S118>/Constant4' : Unused code path elimination
//  Block '<S118>/Constant5' : Unused code path elimination
//  Block '<S118>/Constant6' : Unused code path elimination
//  Block '<S118>/Constant7' : Unused code path elimination
//  Block '<S118>/Gain13' : Unused code path elimination
//  Block '<S118>/Gain14' : Unused code path elimination
//  Block '<S118>/Gain15' : Unused code path elimination
//  Block '<S118>/Gain16' : Unused code path elimination
//  Block '<S118>/Gain17' : Unused code path elimination
//  Block '<S118>/Gain18' : Unused code path elimination
//  Block '<S118>/Gain19' : Unused code path elimination
//  Block '<S118>/Gain20' : Unused code path elimination
//  Block '<S118>/Product' : Unused code path elimination
//  Block '<S118>/Product1' : Unused code path elimination
//  Block '<S118>/Product2' : Unused code path elimination
//  Block '<S118>/Product3' : Unused code path elimination
//  Block '<S118>/Sum10' : Unused code path elimination
//  Block '<S118>/Sum11' : Unused code path elimination
//  Block '<S118>/Sum8' : Unused code path elimination
//  Block '<S118>/Sum9' : Unused code path elimination
//  Block '<S111>/Gain6' : Unused code path elimination
//  Block '<S111>/Gain7' : Unused code path elimination
//  Block '<S111>/rad//s para rpm4' : Unused code path elimination
//  Block '<S5>/Gain' : Eliminated nontunable gain of 1
//  Block '<S10>/Signal Conversion' : Eliminate redundant signal conversion block
//  Block '<S1>/Gain' : Eliminated nontunable gain of 1
//  Block '<S1>/Gain1' : Eliminated nontunable gain of 1
//  Block '<S1>/Gain2' : Eliminated nontunable gain of 1
//  Block '<S1>/Gain3' : Eliminated nontunable gain of 1
//  Block '<S32>/InputConversion' : Eliminate redundant data type conversion
//  Block '<S38>/InputConversion' : Eliminate redundant data type conversion
//  Block '<S44>/InputConversion' : Eliminate redundant data type conversion
//  Block '<S50>/InputConversion' : Eliminate redundant data type conversion
//  Block '<S9>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S9>/Zero-Order Hold2' : Eliminated since input and output rates are identical
//  Block '<S9>/Zero-Order Hold3' : Eliminated since input and output rates are identical
//  Block '<S9>/Zero-Order Hold4' : Eliminated since input and output rates are identical
//  Block '<S140>/Gain1' : Eliminated nontunable gain of 1
//  Block '<S151>/Gain1' : Eliminated nontunable gain of 1
//  Block '<S162>/Gain1' : Eliminated nontunable gain of 1
//  Block '<S173>/Gain1' : Eliminated nontunable gain of 1
//  Block '<S184>/Gain2' : Eliminated nontunable gain of 1
//  Block '<S192>/Gain2' : Eliminated nontunable gain of 1
//  Block '<S200>/Gain2' : Eliminated nontunable gain of 1
//  Block '<S208>/Gain2' : Eliminated nontunable gain of 1
//  Block '<S218>/Manual Switch' : Eliminated due to constant selection input
//  Block '<S220>/Gain1' : Eliminated nontunable gain of 1
//  Block '<S220>/Gain11' : Eliminated nontunable gain of 1
//  Block '<S220>/Gain5' : Eliminated nontunable gain of 1
//  Block '<S220>/Gain9' : Eliminated nontunable gain of 1
//  Block '<S7>/Constant' : Unused code path elimination
//  Block '<S7>/Constant1' : Unused code path elimination
//  Block '<S7>/Constant2' : Unused code path elimination
//  Block '<S7>/Constant3' : Unused code path elimination
//  Block '<S7>/Constant4' : Unused code path elimination
//  Block '<S7>/Constant5' : Unused code path elimination
//  Block '<S7>/Constant6' : Unused code path elimination
//  Block '<S7>/Constant7' : Unused code path elimination
//  Block '<S2>/Constant12' : Unused code path elimination
//  Block '<Root>/From Workspace' : Unused code path elimination
//  Block '<Root>/From Workspace1' : Unused code path elimination
//  Block '<S120>/Compare' : Unused code path elimination
//  Block '<S120>/Constant' : Unused code path elimination
//  Block '<S112>/Constant1' : Unused code path elimination
//  Block '<S218>/Constant3' : Unused code path elimination
//  Block '<S218>/Relational Operator' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'PlanarModelandControl'
//  '<S1>'   : 'PlanarModelandControl/Controle'
//  '<S2>'   : 'PlanarModelandControl/Driver'
//  '<S3>'   : 'PlanarModelandControl/Planta'
//  '<S4>'   : 'PlanarModelandControl/Controle/Cornering Stiffness'
//  '<S5>'   : 'PlanarModelandControl/Controle/Direct Yaw Control'
//  '<S6>'   : 'PlanarModelandControl/Controle/Gradiente de estabilidade'
//  '<S7>'   : 'PlanarModelandControl/Controle/Motores'
//  '<S8>'   : 'PlanarModelandControl/Controle/Torque Vectoring'
//  '<S9>'   : 'PlanarModelandControl/Controle/Traction Control'
//  '<S10>'  : 'PlanarModelandControl/Controle/Direct Yaw Control/MDYC'
//  '<S11>'  : 'PlanarModelandControl/Controle/Direct Yaw Control/ON//OFF'
//  '<S12>'  : 'PlanarModelandControl/Controle/Direct Yaw Control/Yaw desejado'
//  '<S13>'  : 'PlanarModelandControl/Controle/Direct Yaw Control/MDYC/Feedback'
//  '<S14>'  : 'PlanarModelandControl/Controle/Direct Yaw Control/MDYC/Feedfoward'
//  '<S15>'  : 'PlanarModelandControl/Controle/Direct Yaw Control/MDYC/Saturation Dynamic'
//  '<S16>'  : 'PlanarModelandControl/Controle/Direct Yaw Control/MDYC/Feedback/Saturation Dynamic'
//  '<S17>'  : 'PlanarModelandControl/Controle/Direct Yaw Control/MDYC/Feedfoward/Saturation Dynamic'
//  '<S18>'  : 'PlanarModelandControl/Controle/Direct Yaw Control/ON//OFF/If Action Subsystem'
//  '<S19>'  : 'PlanarModelandControl/Controle/Direct Yaw Control/ON//OFF/If Action Subsystem1'
//  '<S20>'  : 'PlanarModelandControl/Controle/Direct Yaw Control/Yaw desejado/ref < limit'
//  '<S21>'  : 'PlanarModelandControl/Controle/Direct Yaw Control/Yaw desejado/ref > limit'
//  '<S22>'  : 'PlanarModelandControl/Controle/Torque Vectoring/Distribuição Lateral2'
//  '<S23>'  : 'PlanarModelandControl/Controle/Torque Vectoring/Distribuição longitudinal'
//  '<S24>'  : 'PlanarModelandControl/Controle/Torque Vectoring/Redução TC1'
//  '<S25>'  : 'PlanarModelandControl/Controle/Torque Vectoring/Subsystem'
//  '<S26>'  : 'PlanarModelandControl/Controle/Traction Control/TC_FL'
//  '<S27>'  : 'PlanarModelandControl/Controle/Traction Control/TC_FR'
//  '<S28>'  : 'PlanarModelandControl/Controle/Traction Control/TC_RL'
//  '<S29>'  : 'PlanarModelandControl/Controle/Traction Control/TC_RR'
//  '<S30>'  : 'PlanarModelandControl/Controle/Traction Control/TC_FL/Fuzzy Controller'
//  '<S31>'  : 'PlanarModelandControl/Controle/Traction Control/TC_FL/Fuzzy Controller/Discrete Derivative1'
//  '<S32>'  : 'PlanarModelandControl/Controle/Traction Control/TC_FL/Fuzzy Controller/Fuzzy Logic  Controller'
//  '<S33>'  : 'PlanarModelandControl/Controle/Traction Control/TC_FL/Fuzzy Controller/Fuzzy Logic  Controller/Defuzzify Outputs'
//  '<S34>'  : 'PlanarModelandControl/Controle/Traction Control/TC_FL/Fuzzy Controller/Fuzzy Logic  Controller/Evaluate Rule Antecedents'
//  '<S35>'  : 'PlanarModelandControl/Controle/Traction Control/TC_FL/Fuzzy Controller/Fuzzy Logic  Controller/Evaluate Rule Consequents'
//  '<S36>'  : 'PlanarModelandControl/Controle/Traction Control/TC_FR/Fuzzy Controller'
//  '<S37>'  : 'PlanarModelandControl/Controle/Traction Control/TC_FR/Fuzzy Controller/Discrete Derivative1'
//  '<S38>'  : 'PlanarModelandControl/Controle/Traction Control/TC_FR/Fuzzy Controller/Fuzzy Logic  Controller'
//  '<S39>'  : 'PlanarModelandControl/Controle/Traction Control/TC_FR/Fuzzy Controller/Fuzzy Logic  Controller/Defuzzify Outputs'
//  '<S40>'  : 'PlanarModelandControl/Controle/Traction Control/TC_FR/Fuzzy Controller/Fuzzy Logic  Controller/Evaluate Rule Antecedents'
//  '<S41>'  : 'PlanarModelandControl/Controle/Traction Control/TC_FR/Fuzzy Controller/Fuzzy Logic  Controller/Evaluate Rule Consequents'
//  '<S42>'  : 'PlanarModelandControl/Controle/Traction Control/TC_RL/Fuzzy Controller'
//  '<S43>'  : 'PlanarModelandControl/Controle/Traction Control/TC_RL/Fuzzy Controller/Discrete Derivative1'
//  '<S44>'  : 'PlanarModelandControl/Controle/Traction Control/TC_RL/Fuzzy Controller/Fuzzy Logic  Controller'
//  '<S45>'  : 'PlanarModelandControl/Controle/Traction Control/TC_RL/Fuzzy Controller/Fuzzy Logic  Controller/Defuzzify Outputs'
//  '<S46>'  : 'PlanarModelandControl/Controle/Traction Control/TC_RL/Fuzzy Controller/Fuzzy Logic  Controller/Evaluate Rule Antecedents'
//  '<S47>'  : 'PlanarModelandControl/Controle/Traction Control/TC_RL/Fuzzy Controller/Fuzzy Logic  Controller/Evaluate Rule Consequents'
//  '<S48>'  : 'PlanarModelandControl/Controle/Traction Control/TC_RR/Fuzzy Controller'
//  '<S49>'  : 'PlanarModelandControl/Controle/Traction Control/TC_RR/Fuzzy Controller/Discrete Derivative1'
//  '<S50>'  : 'PlanarModelandControl/Controle/Traction Control/TC_RR/Fuzzy Controller/Fuzzy Logic  Controller'
//  '<S51>'  : 'PlanarModelandControl/Controle/Traction Control/TC_RR/Fuzzy Controller/Fuzzy Logic  Controller/Defuzzify Outputs'
//  '<S52>'  : 'PlanarModelandControl/Controle/Traction Control/TC_RR/Fuzzy Controller/Fuzzy Logic  Controller/Evaluate Rule Antecedents'
//  '<S53>'  : 'PlanarModelandControl/Controle/Traction Control/TC_RR/Fuzzy Controller/Fuzzy Logic  Controller/Evaluate Rule Consequents'
//  '<S54>'  : 'PlanarModelandControl/Driver/Degrees to Radians'
//  '<S55>'  : 'PlanarModelandControl/Driver/Degrees to Radians1'
//  '<S56>'  : 'PlanarModelandControl/Driver/Degrees to Radians2'
//  '<S57>'  : 'PlanarModelandControl/Driver/PID Controller'
//  '<S58>'  : 'PlanarModelandControl/Driver/PID Controller/Anti-windup'
//  '<S59>'  : 'PlanarModelandControl/Driver/PID Controller/D Gain'
//  '<S60>'  : 'PlanarModelandControl/Driver/PID Controller/External Derivative'
//  '<S61>'  : 'PlanarModelandControl/Driver/PID Controller/Filter'
//  '<S62>'  : 'PlanarModelandControl/Driver/PID Controller/Filter ICs'
//  '<S63>'  : 'PlanarModelandControl/Driver/PID Controller/I Gain'
//  '<S64>'  : 'PlanarModelandControl/Driver/PID Controller/Ideal P Gain'
//  '<S65>'  : 'PlanarModelandControl/Driver/PID Controller/Ideal P Gain Fdbk'
//  '<S66>'  : 'PlanarModelandControl/Driver/PID Controller/Integrator'
//  '<S67>'  : 'PlanarModelandControl/Driver/PID Controller/Integrator ICs'
//  '<S68>'  : 'PlanarModelandControl/Driver/PID Controller/N Copy'
//  '<S69>'  : 'PlanarModelandControl/Driver/PID Controller/N Gain'
//  '<S70>'  : 'PlanarModelandControl/Driver/PID Controller/P Copy'
//  '<S71>'  : 'PlanarModelandControl/Driver/PID Controller/Parallel P Gain'
//  '<S72>'  : 'PlanarModelandControl/Driver/PID Controller/Reset Signal'
//  '<S73>'  : 'PlanarModelandControl/Driver/PID Controller/Saturation'
//  '<S74>'  : 'PlanarModelandControl/Driver/PID Controller/Saturation Fdbk'
//  '<S75>'  : 'PlanarModelandControl/Driver/PID Controller/Sum'
//  '<S76>'  : 'PlanarModelandControl/Driver/PID Controller/Sum Fdbk'
//  '<S77>'  : 'PlanarModelandControl/Driver/PID Controller/Tracking Mode'
//  '<S78>'  : 'PlanarModelandControl/Driver/PID Controller/Tracking Mode Sum'
//  '<S79>'  : 'PlanarModelandControl/Driver/PID Controller/Tsamp - Integral'
//  '<S80>'  : 'PlanarModelandControl/Driver/PID Controller/Tsamp - Ngain'
//  '<S81>'  : 'PlanarModelandControl/Driver/PID Controller/postSat Signal'
//  '<S82>'  : 'PlanarModelandControl/Driver/PID Controller/preInt Signal'
//  '<S83>'  : 'PlanarModelandControl/Driver/PID Controller/preSat Signal'
//  '<S84>'  : 'PlanarModelandControl/Driver/PID Controller/Anti-windup/Passthrough'
//  '<S85>'  : 'PlanarModelandControl/Driver/PID Controller/D Gain/Disabled'
//  '<S86>'  : 'PlanarModelandControl/Driver/PID Controller/External Derivative/Disabled'
//  '<S87>'  : 'PlanarModelandControl/Driver/PID Controller/Filter/Disabled'
//  '<S88>'  : 'PlanarModelandControl/Driver/PID Controller/Filter ICs/Disabled'
//  '<S89>'  : 'PlanarModelandControl/Driver/PID Controller/I Gain/Internal Parameters'
//  '<S90>'  : 'PlanarModelandControl/Driver/PID Controller/Ideal P Gain/Passthrough'
//  '<S91>'  : 'PlanarModelandControl/Driver/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S92>'  : 'PlanarModelandControl/Driver/PID Controller/Integrator/Discrete'
//  '<S93>'  : 'PlanarModelandControl/Driver/PID Controller/Integrator ICs/Internal IC'
//  '<S94>'  : 'PlanarModelandControl/Driver/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S95>'  : 'PlanarModelandControl/Driver/PID Controller/N Gain/Disabled'
//  '<S96>'  : 'PlanarModelandControl/Driver/PID Controller/P Copy/Disabled'
//  '<S97>'  : 'PlanarModelandControl/Driver/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S98>'  : 'PlanarModelandControl/Driver/PID Controller/Reset Signal/Disabled'
//  '<S99>'  : 'PlanarModelandControl/Driver/PID Controller/Saturation/Enabled'
//  '<S100>' : 'PlanarModelandControl/Driver/PID Controller/Saturation Fdbk/Disabled'
//  '<S101>' : 'PlanarModelandControl/Driver/PID Controller/Sum/Sum_PI'
//  '<S102>' : 'PlanarModelandControl/Driver/PID Controller/Sum Fdbk/Disabled'
//  '<S103>' : 'PlanarModelandControl/Driver/PID Controller/Tracking Mode/Disabled'
//  '<S104>' : 'PlanarModelandControl/Driver/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S105>' : 'PlanarModelandControl/Driver/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S106>' : 'PlanarModelandControl/Driver/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S107>' : 'PlanarModelandControl/Driver/PID Controller/postSat Signal/Forward_Path'
//  '<S108>' : 'PlanarModelandControl/Driver/PID Controller/preInt Signal/Internal PreInt'
//  '<S109>' : 'PlanarModelandControl/Driver/PID Controller/preSat Signal/Forward_Path'
//  '<S110>' : 'PlanarModelandControl/Planta/Dinamica do Veículo'
//  '<S111>' : 'PlanarModelandControl/Planta/Movimento do Veiculo'
//  '<S112>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Dinamica da Roda'
//  '<S113>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Elipse de tração'
//  '<S114>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Frenagem'
//  '<S115>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Load Transfer'
//  '<S116>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka'
//  '<S117>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Relaxation Length'
//  '<S118>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Rolling Resistance'
//  '<S119>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Slip Angle'
//  '<S120>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Dinamica da Roda/Compare To Constant'
//  '<S121>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Dinamica da Roda/Slip Ratio'
//  '<S122>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Dinamica da Roda/Slip Ratio/Velocity Margin'
//  '<S123>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Dinamica da Roda/Slip Ratio/Velocity Margin1'
//  '<S124>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Dinamica da Roda/Slip Ratio/Velocity Margin2'
//  '<S125>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Dinamica da Roda/Slip Ratio/Velocity Margin3'
//  '<S126>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Load Transfer/Lateral Weight Transfer'
//  '<S127>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Load Transfer/Longitudinal Weight Transfer'
//  '<S128>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Load Transfer/Total Normal Forces'
//  '<S129>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Load Transfer/Total Normal Forces/MATLAB Function4'
//  '<S130>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Load Transfer/Total Normal Forces/MATLAB Function5'
//  '<S131>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat FL'
//  '<S132>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat FR'
//  '<S133>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat RL'
//  '<S134>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat RR'
//  '<S135>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long FL '
//  '<S136>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long FR'
//  '<S137>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long RL'
//  '<S138>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long RR'
//  '<S139>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat FL/By'
//  '<S140>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat FL/Dy'
//  '<S141>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat FL/Ey'
//  '<S142>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat FL/KyIA'
//  '<S143>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat FL/KySA'
//  '<S144>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat FL/MATLAB Function'
//  '<S145>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat FL/SAy'
//  '<S146>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat FL/SHy'
//  '<S147>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat FL/SVy'
//  '<S148>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat FL/SVyIA'
//  '<S149>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat FL/dfzy'
//  '<S150>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat FR/By'
//  '<S151>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat FR/Dy'
//  '<S152>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat FR/Ey'
//  '<S153>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat FR/KyIA'
//  '<S154>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat FR/KySA'
//  '<S155>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat FR/MATLAB Function'
//  '<S156>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat FR/SAy'
//  '<S157>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat FR/SHy'
//  '<S158>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat FR/SVy'
//  '<S159>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat FR/SVyIA'
//  '<S160>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat FR/dfzy'
//  '<S161>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat RL/By'
//  '<S162>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat RL/Dy'
//  '<S163>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat RL/Ey'
//  '<S164>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat RL/KyIA'
//  '<S165>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat RL/KySA'
//  '<S166>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat RL/MATLAB Function'
//  '<S167>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat RL/SAy'
//  '<S168>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat RL/SHy'
//  '<S169>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat RL/SVy'
//  '<S170>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat RL/SVyIA'
//  '<S171>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat RL/dfzy'
//  '<S172>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat RR/By'
//  '<S173>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat RR/Dy'
//  '<S174>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat RR/Ey'
//  '<S175>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat RR/KyIA'
//  '<S176>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat RR/KySA'
//  '<S177>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat RR/MATLAB Function'
//  '<S178>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat RR/SAy'
//  '<S179>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat RR/SHy'
//  '<S180>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat RR/SVy'
//  '<S181>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat RR/SVyIA'
//  '<S182>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Lat RR/dfzy'
//  '<S183>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long FL /Bx'
//  '<S184>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long FL /Dx'
//  '<S185>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long FL /Ex'
//  '<S186>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long FL /Kx'
//  '<S187>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long FL /MATLAB Function'
//  '<S188>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long FL /Slip'
//  '<S189>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long FL /Svx'
//  '<S190>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long FL /dfz'
//  '<S191>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long FR/Bx'
//  '<S192>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long FR/Dx'
//  '<S193>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long FR/Ex'
//  '<S194>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long FR/Kx'
//  '<S195>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long FR/MATLAB Function'
//  '<S196>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long FR/Slip'
//  '<S197>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long FR/Svx'
//  '<S198>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long FR/dfz'
//  '<S199>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long RL/Bx'
//  '<S200>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long RL/Dx'
//  '<S201>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long RL/Ex'
//  '<S202>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long RL/Kx'
//  '<S203>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long RL/MATLAB Function'
//  '<S204>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long RL/Slip'
//  '<S205>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long RL/Svx'
//  '<S206>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long RL/dfz'
//  '<S207>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long RR/Bx'
//  '<S208>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long RR/Dx'
//  '<S209>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long RR/Ex'
//  '<S210>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long RR/Kx'
//  '<S211>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long RR/MATLAB Function'
//  '<S212>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long RR/Slip'
//  '<S213>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long RR/Svx'
//  '<S214>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Pacejka/Pacejka Long RR/dfz'
//  '<S215>' : 'PlanarModelandControl/Planta/Dinamica do Veículo/Relaxation Length/Subsystem'
//  '<S216>' : 'PlanarModelandControl/Planta/Movimento do Veiculo/Movimento X'
//  '<S217>' : 'PlanarModelandControl/Planta/Movimento do Veiculo/Movimento Y'
//  '<S218>' : 'PlanarModelandControl/Planta/Movimento do Veiculo/Ref Inercial - Velocidade'
//  '<S219>' : 'PlanarModelandControl/Planta/Movimento do Veiculo/Xres'
//  '<S220>' : 'PlanarModelandControl/Planta/Movimento do Veiculo/Yaw'
//  '<S221>' : 'PlanarModelandControl/Planta/Movimento do Veiculo/Yres'
//  '<S222>' : 'PlanarModelandControl/Planta/Movimento do Veiculo/Ref Inercial - Velocidade/MATLAB Function'

#endif                                 // PLANARMODELANDCONTROL_H_

//
// File trailer for generated code.
//
// [EOF]
//
