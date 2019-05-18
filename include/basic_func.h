#ifndef BASIC_FUNC_H
#define BASIC_FUNC_H

#define ToDeg 180/M_PI
#define ToRad M_PI/180

#include <eigen3/Eigen/Dense>

void FindMother(int j);
void ForwardKinematics(int j);
Eigen::Matrix3f Rodrigues(Eigen::Vector3f w, float dt);

#endif