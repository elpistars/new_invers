#ifndef BASIC_FUNC_H
#define BASIC_FUNC_H

#define ToDeg 180/M_PI
#define ToRad M_PI/180

#include <eigen3/Eigen/Dense>

void FindMother(int j);
int FindRoute(int to, int n);
void ForwardKinematics(int j);
void SetupBipedRobot();
float InverseKinematics(Eigen::RowVectorXd to, int target);
Eigen::Matrix3f Rodrigues(Eigen::Vector3f w, float dt);
Eigen::MatrixXf CalcJacobian(Eigen::RowVectorXd idx,int nRoute);
Eigen::Vector3f rot2omega(Eigen::Matrix3f R);
Eigen::VectorXf CalcVWerr(JData Cref, JData Cnow);

#endif