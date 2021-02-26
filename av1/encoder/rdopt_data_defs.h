/*
 * Copyright (c) 2019, Alliance for Open Media. All rights reserved
 *
 * This source code is subject to the terms of the BSD 2 Clause License and
 * the Alliance for Open Media Patent License 1.0. If the BSD 2 Clause License
 * was not distributed with this source code in the LICENSE file, you can
 * obtain it at www.aomedia.org/license/software. If the Alliance for Open
 * Media Patent License 1.0 was not distributed with this source code in the
 * PATENTS file, you can obtain it at www.aomedia.org/license/patent.
 */

#ifndef AOM_AV1_ENCODER_RDOPT_DATA_DEFS_H_
#define AOM_AV1_ENCODER_RDOPT_DATA_DEFS_H_

#ifdef __cplusplus
extern "C" {
#endif

static const THR_MODES intra_to_mode_idx[INTRA_MODE_NUM] = {
  THR_DC,         // DC_PRED,
  THR_V_PRED,     // V_PRED,
  THR_H_PRED,     // H_PRED,
  THR_D45_PRED,   // D45_PRED,
  THR_D135_PRED,  // D135_PRED,
  THR_D113_PRED,  // D113_PRED,
  THR_D157_PRED,  // D157_PRED,
  THR_D203_PRED,  // D203_PRED,
  THR_D67_PRED,   // D67_PRED,
  THR_SMOOTH,     // SMOOTH_PRED,
  THR_SMOOTH_V,   // SMOOTH_V_PRED,
  THR_SMOOTH_H,   // SMOOTH_H_PRED,
  THR_PAETH,      // PAETH_PRED,
};

/* clang-format off */
static const THR_MODES single_inter_to_mode_idx[SINGLE_INTER_MODE_NUM]
    [REF_FRAMES] = {
#if !CONFIG_NEW_INTER_MODES
    // NEARESTMV,
        { THR_INVALID, THR_NEARESTMV, THR_NEARESTL2, THR_NEARESTL3,
        THR_NEARESTG, THR_NEARESTB, THR_NEARESTA2, THR_NEARESTA, },
#endif  // !CONFIG_NEW_INTER_MODES
        // NEARMV,
        { THR_INVALID, THR_NEARMV, THR_NEARL2, THR_NEARL3,
        THR_NEARG, THR_NEARB, THR_NEARA2, THR_NEARA, },
        // GLOBALMV,
        { THR_INVALID, THR_GLOBALMV, THR_GLOBALL2, THR_GLOBALL3,
        THR_GLOBALG, THR_GLOBALB, THR_GLOBALA2, THR_GLOBALA, },
        // NEWMV,
        { THR_INVALID, THR_NEWMV, THR_NEWL2, THR_NEWL3,
        THR_NEWG, THR_NEWB, THR_NEWA2, THR_NEWA, },
};
/* clang-format on */

/* clang-format off */
static const THR_MODES comp_inter_to_mode_idx[COMP_INTER_MODE_NUM][REF_FRAMES]
    [REF_FRAMES] = {
#if !CONFIG_NEW_INTER_MODES
    // NEAREST_NEARESTMV,
        {
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID, THR_INVALID, },
            { THR_INVALID, THR_INVALID,
            THR_COMP_NEAREST_NEARESTLL2, THR_COMP_NEAREST_NEARESTLL3,
            THR_COMP_NEAREST_NEARESTLG, THR_COMP_NEAREST_NEARESTLB,
            THR_COMP_NEAREST_NEARESTLA2, THR_COMP_NEAREST_NEARESTLA, },
            { THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_COMP_NEAREST_NEARESTL2B,
            THR_COMP_NEAREST_NEARESTL2A2, THR_COMP_NEAREST_NEARESTL2A, },
            { THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_COMP_NEAREST_NEARESTL3B,
            THR_COMP_NEAREST_NEARESTL3A2, THR_COMP_NEAREST_NEARESTL3A, },
            { THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_COMP_NEAREST_NEARESTGB,
            THR_COMP_NEAREST_NEARESTGA2, THR_COMP_NEAREST_NEARESTGA, },
            { THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_COMP_NEAREST_NEARESTBA, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID, THR_INVALID, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID, THR_INVALID, },
        },
#endif  // CONFIG_NEW_INTER_MODES
        // NEAR_NEARMV,
        {
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID, THR_INVALID, },
            { THR_INVALID, THR_INVALID,
            THR_COMP_NEAR_NEARLL2, THR_COMP_NEAR_NEARLL3,
            THR_COMP_NEAR_NEARLG, THR_COMP_NEAR_NEARLB,
            THR_COMP_NEAR_NEARLA2, THR_COMP_NEAR_NEARLA, },
            { THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_COMP_NEAR_NEARL2B,
            THR_COMP_NEAR_NEARL2A2, THR_COMP_NEAR_NEARL2A, },
            { THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_COMP_NEAR_NEARL3B,
            THR_COMP_NEAR_NEARL3A2, THR_COMP_NEAR_NEARL3A, },
            { THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_COMP_NEAR_NEARGB,
            THR_COMP_NEAR_NEARGA2, THR_COMP_NEAR_NEARGA, },
            { THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_COMP_NEAR_NEARBA, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID, THR_INVALID, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID, THR_INVALID, },
        },
#if !CONFIG_NEW_INTER_MODES
        // NEAREST_NEWMV,
        {
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID, THR_INVALID, },
            { THR_INVALID, THR_INVALID,
            THR_COMP_NEAREST_NEWLL2, THR_COMP_NEAREST_NEWLL3,
            THR_COMP_NEAREST_NEWLG, THR_COMP_NEAREST_NEWLB,
            THR_COMP_NEAREST_NEWLA2, THR_COMP_NEAREST_NEWLA, },
            { THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_COMP_NEAREST_NEWL2B,
            THR_COMP_NEAREST_NEWL2A2, THR_COMP_NEAREST_NEWL2A, },
            { THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_COMP_NEAREST_NEWL3B,
            THR_COMP_NEAREST_NEWL3A2, THR_COMP_NEAREST_NEWL3A, },
            { THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_COMP_NEAREST_NEWGB,
            THR_COMP_NEAREST_NEWGA2, THR_COMP_NEAREST_NEWGA, },
            { THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_COMP_NEAREST_NEWBA, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID, THR_INVALID, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID, THR_INVALID, },
        },
        // NEW_NEARESTMV,
        {
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID, THR_INVALID, },
            { THR_INVALID, THR_INVALID,
            THR_COMP_NEW_NEARESTLL2, THR_COMP_NEW_NEARESTLL3,
            THR_COMP_NEW_NEARESTLG, THR_COMP_NEW_NEARESTLB,
            THR_COMP_NEW_NEARESTLA2, THR_COMP_NEW_NEARESTLA, },
            { THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_COMP_NEW_NEARESTL2B,
            THR_COMP_NEW_NEARESTL2A2, THR_COMP_NEW_NEARESTL2A, },
            { THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_COMP_NEW_NEARESTL3B,
            THR_COMP_NEW_NEARESTL3A2, THR_COMP_NEW_NEARESTL3A, },
            { THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_COMP_NEW_NEARESTGB,
            THR_COMP_NEW_NEARESTGA2, THR_COMP_NEW_NEARESTGA, },
            { THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_COMP_NEW_NEARESTBA, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID, THR_INVALID, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID, THR_INVALID, },
        },
#endif  // CONFIG_NEW_INTER_MODES
        // NEAR_NEWMV,
        {
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID, THR_INVALID, },
            { THR_INVALID, THR_INVALID,
            THR_COMP_NEAR_NEWLL2, THR_COMP_NEAR_NEWLL3,
            THR_COMP_NEAR_NEWLG, THR_COMP_NEAR_NEWLB,
            THR_COMP_NEAR_NEWLA2, THR_COMP_NEAR_NEWLA, },
            { THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_COMP_NEAR_NEWL2B,
            THR_COMP_NEAR_NEWL2A2, THR_COMP_NEAR_NEWL2A, },
            { THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_COMP_NEAR_NEWL3B,
            THR_COMP_NEAR_NEWL3A2, THR_COMP_NEAR_NEWL3A, },
            { THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_COMP_NEAR_NEWGB,
            THR_COMP_NEAR_NEWGA2, THR_COMP_NEAR_NEWGA, },
            { THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_COMP_NEAR_NEWBA, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID, THR_INVALID, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID, THR_INVALID, },
        },
        // NEW_NEARMV,
        {
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID, THR_INVALID, },
            { THR_INVALID, THR_INVALID,
            THR_COMP_NEW_NEARLL2, THR_COMP_NEW_NEARLL3,
            THR_COMP_NEW_NEARLG, THR_COMP_NEW_NEARLB,
            THR_COMP_NEW_NEARLA2, THR_COMP_NEW_NEARLA, },
            { THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_COMP_NEW_NEARL2B,
            THR_COMP_NEW_NEARL2A2, THR_COMP_NEW_NEARL2A, },
            { THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_COMP_NEW_NEARL3B,
            THR_COMP_NEW_NEARL3A2, THR_COMP_NEW_NEARL3A, },
            { THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_COMP_NEW_NEARGB,
            THR_COMP_NEW_NEARGA2, THR_COMP_NEW_NEARGA, },
            { THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_COMP_NEW_NEARBA, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID, THR_INVALID, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID, THR_INVALID, },
        },
        // GLOBAL_GLOBALMV,
        {
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID, THR_INVALID, },
            { THR_INVALID, THR_INVALID,
            THR_COMP_GLOBAL_GLOBALLL2, THR_COMP_GLOBAL_GLOBALLL3,
            THR_COMP_GLOBAL_GLOBALLG, THR_COMP_GLOBAL_GLOBALLB,
            THR_COMP_GLOBAL_GLOBALLA2, THR_COMP_GLOBAL_GLOBALLA, },
            { THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_COMP_GLOBAL_GLOBALL2B,
            THR_COMP_GLOBAL_GLOBALL2A2, THR_COMP_GLOBAL_GLOBALL2A, },
            { THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_COMP_GLOBAL_GLOBALL3B,
            THR_COMP_GLOBAL_GLOBALL3A2, THR_COMP_GLOBAL_GLOBALL3A, },
            { THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_COMP_GLOBAL_GLOBALGB,
            THR_COMP_GLOBAL_GLOBALGA2, THR_COMP_GLOBAL_GLOBALGA, },
            { THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_COMP_GLOBAL_GLOBALBA, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID, THR_INVALID, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID, THR_INVALID, },
        },
        // NEW_NEWMV,
        {
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID, THR_INVALID, },
            { THR_INVALID, THR_INVALID,
            THR_COMP_NEW_NEWLL2, THR_COMP_NEW_NEWLL3,
            THR_COMP_NEW_NEWLG, THR_COMP_NEW_NEWLB,
            THR_COMP_NEW_NEWLA2, THR_COMP_NEW_NEWLA, },
            { THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_COMP_NEW_NEWL2B,
            THR_COMP_NEW_NEWL2A2, THR_COMP_NEW_NEWL2A, },
            { THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_COMP_NEW_NEWL3B,
            THR_COMP_NEW_NEWL3A2, THR_COMP_NEW_NEWL3A, },
            { THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_COMP_NEW_NEWGB,
            THR_COMP_NEW_NEWGA2, THR_COMP_NEW_NEWGA, },
            { THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID,
            THR_INVALID, THR_COMP_NEW_NEWBA, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID, THR_INVALID, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
            THR_INVALID, THR_INVALID, THR_INVALID, },
        },
#if CONFIG_OPTFLOW_REFINEMENT
        // NEAR_NEARMV_OPTFLOW,
        {
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_INVALID, THR_INVALID, THR_INVALID, },
            { THR_INVALID, THR_INVALID, THR_COMP_NEAR_NEAR_OPTFLOWLL2,
              THR_COMP_NEAR_NEAR_OPTFLOWLL3, THR_COMP_NEAR_NEAR_OPTFLOWLG,
              THR_COMP_NEAR_NEAR_OPTFLOWLB, THR_COMP_NEAR_NEAR_OPTFLOWLA2,
              THR_COMP_NEAR_NEAR_OPTFLOWLA, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_COMP_NEAR_NEAR_OPTFLOWL2B, THR_COMP_NEAR_NEAR_OPTFLOWL2A2,
              THR_COMP_NEAR_NEAR_OPTFLOWL2A, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_COMP_NEAR_NEAR_OPTFLOWL3B, THR_COMP_NEAR_NEAR_OPTFLOWL3A2,
              THR_COMP_NEAR_NEAR_OPTFLOWL3A, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_COMP_NEAR_NEAR_OPTFLOWGB, THR_COMP_NEAR_NEAR_OPTFLOWGA2,
              THR_COMP_NEAR_NEAR_OPTFLOWGA, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_INVALID, THR_INVALID, THR_COMP_NEAR_NEAR_OPTFLOWBA, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_INVALID, THR_INVALID, THR_INVALID, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_INVALID, THR_INVALID, THR_INVALID, },
        },
        // NEAR_NEWMV_OPTFLOW,
        {
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_INVALID, THR_INVALID, THR_INVALID, },
            { THR_INVALID, THR_INVALID, THR_COMP_NEAR_NEW_OPTFLOWLL2,
              THR_COMP_NEAR_NEW_OPTFLOWLL3, THR_COMP_NEAR_NEW_OPTFLOWLG,
              THR_COMP_NEAR_NEW_OPTFLOWLB, THR_COMP_NEAR_NEW_OPTFLOWLA2,
              THR_COMP_NEAR_NEW_OPTFLOWLA, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_COMP_NEAR_NEW_OPTFLOWL2B, THR_COMP_NEAR_NEW_OPTFLOWL2A2,
              THR_COMP_NEAR_NEW_OPTFLOWL2A, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_COMP_NEAR_NEW_OPTFLOWL3B, THR_COMP_NEAR_NEW_OPTFLOWL3A2,
              THR_COMP_NEAR_NEW_OPTFLOWL3A, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_COMP_NEAR_NEW_OPTFLOWGB, THR_COMP_NEAR_NEW_OPTFLOWGA2,
              THR_COMP_NEAR_NEW_OPTFLOWGA, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_INVALID, THR_INVALID, THR_COMP_NEAR_NEW_OPTFLOWBA, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_INVALID, THR_INVALID, THR_INVALID, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_INVALID, THR_INVALID, THR_INVALID, },
        },
        // NEW_NEARMV_OPTFLOW,
        {
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_INVALID, THR_INVALID, THR_INVALID, },
            { THR_INVALID, THR_INVALID, THR_COMP_NEW_NEAR_OPTFLOWLL2,
              THR_COMP_NEW_NEAR_OPTFLOWLL3, THR_COMP_NEW_NEAR_OPTFLOWLG,
              THR_COMP_NEW_NEAR_OPTFLOWLB, THR_COMP_NEW_NEAR_OPTFLOWLA2,
              THR_COMP_NEW_NEAR_OPTFLOWLA, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_COMP_NEW_NEAR_OPTFLOWL2B, THR_COMP_NEW_NEAR_OPTFLOWL2A2,
              THR_COMP_NEW_NEAR_OPTFLOWL2A, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_COMP_NEW_NEAR_OPTFLOWL3B, THR_COMP_NEW_NEAR_OPTFLOWL3A2,
              THR_COMP_NEW_NEAR_OPTFLOWL3A, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_COMP_NEW_NEAR_OPTFLOWGB, THR_COMP_NEW_NEAR_OPTFLOWGA2,
              THR_COMP_NEW_NEAR_OPTFLOWGA, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_INVALID, THR_INVALID, THR_COMP_NEW_NEAR_OPTFLOWBA, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_INVALID, THR_INVALID, THR_INVALID, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_INVALID, THR_INVALID, THR_INVALID, },
        },
        // GLOBAL_GLOBALMV_OPTFLOW,
        {
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_INVALID, THR_INVALID, THR_INVALID, },
            { THR_INVALID, THR_INVALID, THR_COMP_GLOBAL_GLOBAL_OPTFLOWLL2,
              THR_COMP_GLOBAL_GLOBAL_OPTFLOWLL3,
              THR_COMP_GLOBAL_GLOBAL_OPTFLOWLG,
              THR_COMP_GLOBAL_GLOBAL_OPTFLOWLB,
              THR_COMP_GLOBAL_GLOBAL_OPTFLOWLA2,
              THR_COMP_GLOBAL_GLOBAL_OPTFLOWLA, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_COMP_GLOBAL_GLOBAL_OPTFLOWL2B,
              THR_COMP_GLOBAL_GLOBAL_OPTFLOWL2A2,
              THR_COMP_GLOBAL_GLOBAL_OPTFLOWL2A, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_COMP_GLOBAL_GLOBAL_OPTFLOWL3B,
              THR_COMP_GLOBAL_GLOBAL_OPTFLOWL3A2,
              THR_COMP_GLOBAL_GLOBAL_OPTFLOWL3A, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_COMP_GLOBAL_GLOBAL_OPTFLOWGB,
              THR_COMP_GLOBAL_GLOBAL_OPTFLOWGA2,
              THR_COMP_GLOBAL_GLOBAL_OPTFLOWGA, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_INVALID, THR_INVALID, THR_COMP_GLOBAL_GLOBAL_OPTFLOWBA, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_INVALID, THR_INVALID, THR_INVALID, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_INVALID, THR_INVALID, THR_INVALID, },
        },
        // NEW_NEWMV_OPTFLOW,
        {
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_INVALID, THR_INVALID, THR_INVALID, },
            { THR_INVALID, THR_INVALID, THR_COMP_NEW_NEW_OPTFLOWLL2,
              THR_COMP_NEW_NEW_OPTFLOWLL3, THR_COMP_NEW_NEW_OPTFLOWLG,
              THR_COMP_NEW_NEW_OPTFLOWLB, THR_COMP_NEW_NEW_OPTFLOWLA2,
              THR_COMP_NEW_NEW_OPTFLOWLA, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_COMP_NEW_NEW_OPTFLOWL2B, THR_COMP_NEW_NEW_OPTFLOWL2A2,
              THR_COMP_NEW_NEW_OPTFLOWL2A, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_COMP_NEW_NEW_OPTFLOWL3B, THR_COMP_NEW_NEW_OPTFLOWL3A2,
              THR_COMP_NEW_NEW_OPTFLOWL3A, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_COMP_NEW_NEW_OPTFLOWGB, THR_COMP_NEW_NEW_OPTFLOWGA2,
              THR_COMP_NEW_NEW_OPTFLOWGA, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_INVALID, THR_INVALID, THR_COMP_NEW_NEW_OPTFLOWBA, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_INVALID, THR_INVALID, THR_INVALID, },
            { THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID, THR_INVALID,
              THR_INVALID, THR_INVALID, THR_INVALID, },
        },
#endif  // CONFIG_OPTFLOW_REFINEMENT
};

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // AOM_AV1_ENCODER_RDOPT_DATA_DEFS_H_
