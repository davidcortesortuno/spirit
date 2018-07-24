#pragma once
#ifndef INTERFACE_SIMULATION_H
#define INTERFACE_SIMULATION_H
#include "DLL_Define_Export.h"

struct State;

#include <vector>

// Start/Stop functionality
DLLEXPORT void Simulation_Start(State *state, const char * c_method_type, const char * c_solver_type="", 
    int n_iterations=-1, int n_iterations_log=-1, int idx_image=-1, int idx_chain=-1) noexcept;

// Start a simulation, where iterations will be called manually
DLLEXPORT void Simulation_Start_SingleShot(State *state, const char * c_method_type, const char * c_solver_type="", 
    int n_iterations=-1, int n_iterations_log=-1, int idx_image=-1, int idx_chain=-1) noexcept;

// Single iteration of a Method
//  If Simulation_Start_SingleShot was called before, this will be reasonably efficient.
//  Otherwise, a Method will be instantiated and used, potentially also producing output.
DLLEXPORT void Simulation_SingleShot(State *state, int idx_image=-1, int idx_chain=-1) noexcept;

// Stop a simulation running on an image or chain
DLLEXPORT void Simulation_Stop(State *state, int idx_image=-1, int idx_chain=-1) noexcept;

// Stop all simulations
DLLEXPORT void Simulation_Stop_All(State *state) noexcept;


// Get maximum torque component
//      If a MC, LLG, MMF or EMA simulation is running this returns the max. torque on the current image.
//      If a GNEB simulation is running this returns the max. torque on the current chain.
DLLEXPORT float Simulation_Get_MaxTorqueComponent(State * state, int idx_image=-1, int idx_chain=-1) noexcept;

// Get maximum torque components on the images of a chain
//      Will only work if a GNEB simulation is running.
DLLEXPORT void Simulation_Get_Chain_MaxTorqueComponents(State * state, float * torques, int idx_chain=-1) noexcept;

// Get IPS
//      If a MC, LLG, MMF or EMA simulation is running this returns the IPS on the current image.
//      If a GNEB simulation is running this returns the IPS on the current chain.
DLLEXPORT float Simulation_Get_IterationsPerSecond(State *state, int idx_image=-1, int idx_chain=-1) noexcept;

// Get number of done iterations
DLLEXPORT int Simulation_Get_Iteration(State *state, int idx_image=-1, int idx_chain=-1) noexcept;

// Get time passed by the simulation in picoseconds
//      If an LLG simulation is running this returns the cumulatively summed dt.
//      Otherwise it returns 0.
DLLEXPORT float Simulation_Get_Time(State *state, int idx_image=-1, int idx_chain=-1) noexcept;

// Get number of miliseconds since the simulation was started
DLLEXPORT int Simulation_Get_Wall_Time(State *state, int idx_image=-1, int idx_chain=-1) noexcept;

// Get name of the currently used method
//      If a MC, LLG, MMF or EMA simulation is running this returns the Solver name on the current image.
//      If a GNEB simulation is running this returns the Solver name on the current chain.
DLLEXPORT const char * Simulation_Get_Solver_Name(State *state, int idx_image=-1, int idx_chain=-1) noexcept;

// Get name of the currently used method
//      If a MC, LLG, MMF or EMA simulation is running this returns the Method name on the current image.
//      If a GNEB simulation is running this returns the Method name on the current chain.
DLLEXPORT const char * Simulation_Get_Method_Name(State *state, int idx_image=-1, int idx_chain=-1) noexcept;


// Check if a simulation is running on specific image of specific chain
DLLEXPORT bool Simulation_Running_On_Image(State *state, int idx_image=-1, int idx_chain=-1) noexcept;
// Check if a simulation is running across a specific chain
DLLEXPORT bool Simulation_Running_On_Chain(State *state, int idx_chain=-1) noexcept;

// Check if a simulation is running on any or all images of a chain
DLLEXPORT bool Simulation_Running_Anywhere_On_Chain(State *state, int idx_chain=-1) noexcept;

#include "DLL_Undefine_Export.h"
#endif
