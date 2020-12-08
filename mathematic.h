/*
 ============================================================================
 Name        : mathematic.h
 Author      : Barracuda-marina
 Version     : 0.9b
 Copyright   : GNU
 Description : functions for BRA conversion for DCS World in C++
 ============================================================================
 */

#ifndef MATHEMATIC_H
#define MATHEMATIC_H

//! [0]
#include <cmath>
//! [0]

//! [1]
#define PI 3.14159265
//! [2]

int interceptor_to_bullseye_course, bullseye_to_bandit_radial, bandit_altitude, bullseye_to_interceptor_radial, gamma_deg;
double interceptor_to_bullseye_distance, bandit_to_bullseye_distance, gamma_rad, beta_rad, cos_gamma_rad, cos_beta_rad, beta_deg, alfa_deg, distance_to_bandit, interceptor_to_bandit_course;

// Radian to degree conversion function
double rad_to_grad (double rda);

// Degree to Radian conversion function
double grad_to_rad (double gra);

// Interceptor Radial counting
double Interceptor_Radial_counting ();

// Angle between Interceptor and Bandit counting
double Angle_Interceptor_Bandit_counting ();

// Distance from Interceptor to Bandit counting
double Distance_Interceptor_Bandit_counting ();

// All angles counting
double beta_angle_counting ();
double alfa_angle_counting ();

// Bandit azimuth counting
double Bandit_azimuth_counting ();

#endif // MATHEMATIC_H
