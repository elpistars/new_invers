#include <eigen3/Eigen/Dense>
#include <iostream>
#include "link.h"
#include "basic_func.h"

Eigen::Vector3f rot2omega(Eigen::Matrix3f R){
    Eigen::Vector3f el;
    float norm_el;
    el<<R(3,2)-R(2,3), R(1,3)-R(3,1), R(2,1)-R(1,2);
    norm_el=el.norm();
    if norm_el > __DBL_EPSILON__
        w=(atan2(norm_el,R(1,1)+R(2,2,)+R(3,3)-1)/norm_el)*el
    else if(R(1,1)>0 && R(2,2)>0 && R(3,3)>0){
        w<<0,0,0;
    }
    else{
        w<<R(1,1)+1, R(2,2)+1, R(3,3)+1;
        w*=M_PI/2;
    }
}