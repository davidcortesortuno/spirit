#pragma once
#ifndef INTERFACE_PARAMETERS_GNEB_H
#define INTERFACE_PARAMETERS_GNEB_H
#include "IO.h"
#include "DLL_Define_Export.h"
struct State;

#define GNEB_IMAGE_NORMAL     0
#define GNEB_IMAGE_CLIMBING   1
#define GNEB_IMAGE_FALLING    2
#define GNEB_IMAGE_STATIONARY 3

//      Set GNEB
// Output
PREFIX void Parameters_GNEB_Set_Output_Tag(State *state, const char * tag, int idx_chain=-1) SUFFIX;
PREFIX void Parameters_GNEB_Set_Output_Folder(State *state, const char * folder, int idx_chain=-1) SUFFIX;
PREFIX void Parameters_GNEB_Set_Output_General(State *state, bool any, bool initial, bool final, int idx_chain=-1) SUFFIX;
PREFIX void Parameters_GNEB_Set_Output_Energies(State *state, bool energies_step, bool energies_interpolated, bool energies_divide_by_nos, bool energies_add_readability_lines, int idx_chain=-1) SUFFIX;
PREFIX void Parameters_GNEB_Set_Output_Chain(State *state, bool chain_step, int chain_filetype=IO_Fileformat_OVF_text, int idx_chain=-1) SUFFIX;
PREFIX void Parameters_GNEB_Set_N_Iterations(State *state, int n_iterations, int n_iterations_log, int idx_chain=-1) SUFFIX;
// Simulation Parameters
PREFIX void Parameters_GNEB_Set_Convergence(State *state, float convergence, int idx_image=-1, int idx_chain=-1) SUFFIX;
PREFIX void Parameters_GNEB_Set_Spring_Constant(State *state, float spring_constant, int idx_image=-1, int idx_chain=-1) SUFFIX;
PREFIX void Parameters_GNEB_Set_Spring_Force_Ratio(State *state, float ratio, int idx_chain=-1) SUFFIX;
PREFIX void Parameters_GNEB_Set_Path_Shortening_Constant(State *state, float path_shortening_constant, int idx_chain=-1) SUFFIX;
PREFIX void Parameters_GNEB_Set_Climbing_Falling(State *state, int image_type, int idx_image=-1, int idx_chain=-1) SUFFIX;
// Automatically set the image type for a chain.
//    Maxima are set to climbing, minima to falling, others are not changed.
PREFIX void Parameters_GNEB_Set_Image_Type_Automatically(State *state, int idx_chain=-1) SUFFIX;
PREFIX void Parameters_GNEB_Set_N_Energy_Interpolations(State *state, int n, int idx_chain=-1) SUFFIX;

//      Get GNEB
// Output
PREFIX const char * Parameters_GNEB_Get_Output_Tag(State *state, int idx_chain=-1) SUFFIX;
PREFIX const char * Parameters_GNEB_Get_Output_Folder(State *state, int idx_chain=-1) SUFFIX;
PREFIX void Parameters_GNEB_Get_Output_General(State *state, bool * any, bool * initial, bool * final, int idx_chain=-1) SUFFIX;
PREFIX void Parameters_GNEB_Get_Output_Energies(State *state, bool * energies_step, bool * energies_interpolated, bool * energies_divide_by_nos, bool * energies_add_readability_lines, int idx_chain=-1) SUFFIX;
PREFIX void Parameters_GNEB_Get_Output_Chain(State *state, bool * chain_step, int * chain_filetype, int idx_chain=-1) SUFFIX;
PREFIX void Parameters_GNEB_Get_N_Iterations(State *state, int * iterations, int * iterations_log, int idx_chain=-1) SUFFIX;
// Simulation Parameters
PREFIX float Parameters_GNEB_Get_Convergence(State *state, int idx_image=-1, int idx_chain=-1) SUFFIX;
PREFIX float Parameters_GNEB_Get_Spring_Constant(State *state, int idx_image=-1, int idx_chain=-1) SUFFIX;
PREFIX float Parameters_GNEB_Get_Spring_Force_Ratio(State *state, int idx_chain=-1) SUFFIX;
PREFIX float Parameters_GNEB_Get_Path_Shortening_Constant(State *state, int idx_chain=-1) SUFFIX;
PREFIX int Parameters_GNEB_Get_Climbing_Falling(State *state, int idx_image=-1, int idx_chain=-1) SUFFIX;
PREFIX int Parameters_GNEB_Get_N_Energy_Interpolations(State *state, int idx_chain=-1) SUFFIX;

#include "DLL_Undefine_Export.h"
#endif