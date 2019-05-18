#include <iostream>
#include <eigen3/Eigen/Dense>
#include <cmath>
#include "LINK.h"

Eigen::Matrix3f Rodrigues(Eigen::Vector3f w, float dt){
    float norm_w=w.norm();
    double eps=pow(2,-52);
    float th;
    Eigen::Vector3f wn;
    Eigen::Matrix3f R,w_wedge;
    if(norm_w<eps){
        R=Eigen::Matrix3f::Identity();
    }
    else{
        wn=w/norm_w;
        th=norm_w*dt;
        w_wedge<<0, -wn(2), wn(1), 
                wn(2), 0, -wn(0),
                -wn(1), wn(0), 0;
        R=Eigen::Matrix3f::Identity()+w_wedge*sin(th) + w_wedge*w_wedge*(1-cos(th)); 
    }
    return R;
}