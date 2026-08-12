/*
 * File: PlanarModelandControl_ca.hpp
 *
 * Abstract: Tests assumptions in the generated code.
 */

#ifndef PLANARMODELANDCONTROL_CA_H
#define PLANARMODELANDCONTROL_CA_H

extern "C"
{
  /* preprocessor validation checks */
#include "PlanarModelandControl_ca_preproc.hpp"
#include "coder_assumptions_hwimpl.h"

  /* variables holding test results */
  extern CA_ChecksTestResults CA_PlanarModelandControl_Res;
  extern CA_PWS_TestResults CA_PlanarModelandControl_PWSRes;

  /* variables holding "expected" and "actual" hardware implementation */
  extern const CA_Checks CA_PlanarModelandControl_Exp;
  extern CA_Checks CA_PlanarModelandControl_Act;
  extern const int numberOfImportedTypes;
  extern const int numberOfNonTunableEnumLiterals;

  /* entry point function to run tests */
  void PlanarModelandControl_caRunTests(void);
}

#endif                                 /* PLANARMODELANDCONTROL_CA_H */
