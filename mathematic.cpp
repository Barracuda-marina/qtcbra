/*
 ============================================================================
 Name        : mathematic.cpp
 Author      : Barracuda-marina
 Version     : 0.9b
 Copyright   : GNU
 Description : functions for BRA conversion for DCS World in C++
 ============================================================================
 */

//! [0]
#include "mathematic.h"
//! [0]

// Radian to Degree conversion function
double rad_to_grad (double rda) {

    double gr;

    gr = (rda*180)/PI;
    return (gr);
}

// Degree to Radian conversion function
double grad_to_rad (double gra) {

    double rd;

    rd = (gra*PI)/180;
    return (rd);
}

// Interceptor Radial counting
double Interceptor_Radial_counting () {

    if 	((interceptor_to_bullseye_course >= 0) && (interceptor_to_bullseye_course <= 179))	{
        bullseye_to_interceptor_radial = (interceptor_to_bullseye_course + 200 - 20);
        }

    if ((interceptor_to_bullseye_course >= 180) && (interceptor_to_bullseye_course <= 359))	{
        bullseye_to_interceptor_radial = (interceptor_to_bullseye_course - 200 + 20);
        }

    return bullseye_to_interceptor_radial;
}

// Angle between Interceptor and Bandit counting
double Angle_Interceptor_Bandit_counting () {

    gamma_deg = abs(bullseye_to_bandit_radial - bullseye_to_interceptor_radial);

    if (gamma_deg >= 180) {
        gamma_deg = 360 - gamma_deg;
        }

    if (gamma_deg == 0) {
        gamma_deg = 179;
        }
    return gamma_deg;
}

// Distance from Interceptor to Bandit counting
double Distance_Interceptor_Bandit_counting () {

    gamma_rad = grad_to_rad(gamma_deg);
    cos_gamma_rad = cos(gamma_rad);
    distance_to_bandit = sqrt(bandit_to_bullseye_distance*bandit_to_bullseye_distance + interceptor_to_bullseye_distance*interceptor_to_bullseye_distance - 2*bandit_to_bullseye_distance*interceptor_to_bullseye_distance*cos_gamma_rad);
    return distance_to_bandit;
}

// All angles counting
double beta_angle_counting () {

    cos_beta_rad = (distance_to_bandit*distance_to_bandit + bandit_to_bullseye_distance*bandit_to_bullseye_distance - interceptor_to_bullseye_distance*interceptor_to_bullseye_distance)/(2*distance_to_bandit*bandit_to_bullseye_distance);
    beta_rad = acos(cos_beta_rad);
    beta_deg = rad_to_grad(beta_rad);
    return beta_deg;
}

double alfa_angle_counting () {

    alfa_deg = 180.0 - (gamma_deg + beta_deg);
    return alfa_deg;
}

// Bandit azimuth counting
double Bandit_azimuth_counting () {

    if (bullseye_to_bandit_radial >= interceptor_to_bullseye_course) {
        interceptor_to_bandit_course = interceptor_to_bullseye_course + alfa_deg;
        }

    if (bullseye_to_bandit_radial < interceptor_to_bullseye_course)  {
        interceptor_to_bandit_course = interceptor_to_bullseye_course - alfa_deg;
        }
    return interceptor_to_bandit_course;
}
