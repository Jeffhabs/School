//
//  forces.cpp
//  Springs
//
//  Created by Jeffrey Haberle on 2/10/16.
//  Copyright © 2016 CS3005. All rights reserved.
//
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;
#include "forces.h"
#include "particle.h"

SpringForce::SpringForce(Particle* p1_temp,
                         Particle* p2_temp,
                         double spring_constant_temp,
                         double damping_constant_temp,
                         double rest_length_temp,
                         double color[4]):
p1(p1_temp),
p2(p2_temp),
spring_constant(spring_constant_temp),
damping_constant(damping_constant_temp),
rest_length(rest_length_temp)
{
    double pos1[DIM];
    double pos2[DIM];
    p1-> GetPosition(pos1);
    p2->GetPosition(pos2);
    double d = sqrt(pow(pos2[0] - pos1[0], 2) + pow(pos2[1] - pos1[1], 2));
    rest_length *= d;
    rgba[0] = color[0];
    rgba[1] = color[1];
    rgba[2] = color[2];
    rgba[3] = color[3];
}

double SpringForce::GetRed()
{
    return rgba[0];
}

double SpringForce::GetGreen()
{
    return rgba[1];
}

double SpringForce::GetBlue()
{
    return rgba[2];
}

void SpringForce::Apply()
{
    double pos1[DIM];
    double pos2[DIM];
    double dir1[DIM];
    double dir2[DIM];
    double f1[DIM];
    double f2[DIM];
    p1->GetPosition(pos1);
    p2->GetPosition(pos2);
    p1->GetDirection(dir1);
    p2->GetDirection(dir2);
    p1->GetForce(f1);
    p2->GetForce(f2);
    
    double pDif[DIM];
    double vDif[DIM];
    double dotProduct = 0.0;
    double pDifSize = 0.0;
    
    int d;
    for(d=0; d<DIM; d++)
    {
        pDif[d] = pos1[d] - pos2[d];
        vDif[d] = dir1[d] - dir2[d];
        pDifSize += pDif[d]*pDif[d];
        dotProduct += pDif[d] * vDif[d];
    }
    pDifSize = sqrt(pDifSize);
    
    double multiplier = -(spring_constant*(pDifSize-rest_length) + damping_constant*dotProduct/pDifSize)/pDifSize;
    for(d=0; d<DIM; d++)
    {
        //f1[d] += multiplier * pDif[d];
        //f2[d] += -(f1[d]);
        double newForce = multiplier * pDif[d];
        f1[d] += newForce;
        f2[d] -= newForce;
    }
    p1->SetForce(f1);
    p2->SetForce(f2);
}

Particle* SpringForce::GetParticle1()
{
    return p1;
}

Particle* SpringForce::GetParticle2()
{
    return p2;
}

FORCE_TYPE SpringForce::Type()
{
    return SPRING_FORCE;
}


GravityForce::GravityForce(double gravity_temp[DIM], ParticleSystem *PS_temp)
: PS(PS_temp)
{
    for(int d=0; d<DIM; d++)
        gravity[d] = gravity_temp[d];
}

void GravityForce::Apply()
{
    
    int i;
    int N = PS->GetNumParticles();
    for(i=0; i<N; i++)
    {
        Particle * p = PS->GetParticle(i);
        double pos[DIM];
        p->GetPosition(pos);
        double dir[DIM];
        p->GetDirection(dir);
        double f[DIM];
        p->GetForce(f);
        double m = p->GetMass();
        
        int d;
        double vel_squared = 0.0;
        for(d=0; d<DIM; d++)
        {
            vel_squared += dir[d]*dir[d];
        }
        
        for(d=0; d<DIM; d++)
            f[d] += gravity[d]*m;
        
        p->SetForce(f);
        
        // BSFIX delete this testing code
        static int see_particles_energy=-1;
        if(i == see_particles_energy)
        {
            cout.precision(2);
            cout.setf(ios::fixed);
            cout.setf(ios::left);
            double kineticEnergy = m*vel_squared;
            double potentialEnergy = m*(pos[1]-p->GetRadius());
            double totalEnergy = kineticEnergy + potentialEnergy;
            cout << " KE = " << setw(10) << kineticEnergy
            << " PE = " << setw(10) << potentialEnergy
            <<	" TE = " << setw(10) << totalEnergy << endl;
        }
    }
}

FORCE_TYPE GravityForce::Type()
{
    return GRAVITY_FORCE;
}

DragForce::DragForce(double friction_temp, ParticleSystem * PS_temp)
: PS(PS_temp), friction(friction_temp)
{
}

void DragForce::Apply()
{
    
    int i;
    int N = PS->GetNumParticles();
    for(i=0; i<N; i++)
    {
        Particle * p = PS->GetParticle(i);
        double dir[DIM];
        p->GetDirection(dir);
        double f[DIM];
        p->GetForce(f);
        double m = p->GetMass();
        
        for(int d=0; d<DIM; d++)
            f[d] -= dir[d]*friction*m;
        
        p->SetForce(f);
    }
}

FORCE_TYPE DragForce::Type()
{
    return DRAG_FORCE;
}