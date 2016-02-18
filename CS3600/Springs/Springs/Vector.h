//
//  Vector.h
//  Springs
//
//  Created by Jeffrey Haberle on 2/10/16.
//  Copyright © 2016 CS3005. All rights reserved.
//

#ifndef Vector_h
#define Vector_h

class Point3
{
public:
    double p[3];
};

class Point4
{
public:
    double p[4];
};

class Vector3
{
public:
    double v[3];
    double Length(); // return vectors length
    double Normalize(); // normalize vector and return length;
};

Vector3 operator-(const Point3 &head, const Point3 &tail);
Vector3 operator-(const Point4 &head, const Point3 &tail);
Vector3 operator*(const Vector3 & v, double s);
Vector3 operator*(double s, const Vector3 & v);
Point3 operator+(const Point3 & p, const Vector3 & v);
Point3 operator+(const Vector3 & v, const Point3 & p);
Point3 operator-(const Point3 & p, const Vector3 & v);
Vector3 CrossProduct(const Vector3 &v1, const Vector3 &v2);
double DotProduct(const Vector3 &v1, const Vector3 &v2);
Point3 AffineSum(const Point3 &start, const Point3 & end, double t);
double DistanceBetweenPoints(const Point3 & p1, const Point3 & p2);
Vector3 operator+(const Vector3 & v1, const Vector3 & v2);


#endif /* Vector_h */
