#include <iostream>
#include <eigen3/Eigen/Dense>
#include <cmath>
#include "LINK.h"
#include "basic_func.h"

void ForwardKinematics(int j){
    int mom;
    if(j==0){return;}
    if(j!= 1){
        mom=uLINK.joint_data[j].mother;
        uLINK.joint_data[j].p=uLINK.joint_data[mom].R * uLINK.joint_data[j].b + uLINK.joint_data[mom].p;
        uLINK.joint_data[j].R=uLINK.joint_data[mom].R * Rodrigues(uLINK.joint_data[j].a,uLINK.joint_data[j].q);
    }
    ForwardKinematics(uLINK.joint_data[j].sister);
    ForwardKinematics(uLINK.joint_data[j].child);   
}