#include <iostream>
#include <stdio.h>
#include <string.h>
#include <eigen3/Eigen/Dense>
#include <cmath>
#include "LINK.h"
#include "basic_func.h"


float lambda=0.9;
float InverseKinematics(Eigen::RowVectorXd to, int target){
    nRoute=FindRoute(to);
    ForwardKinematics(1);
    err=CalcVWerr(target, uLINK.joint_data[to]);
}