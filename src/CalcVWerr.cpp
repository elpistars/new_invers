#include "link.h"
#include "basic_func.h"
#include <eigen3/Eigen/Dense>
#include <iostream>

Eigen::VectorXf CalcVWerr(JData Cref, JData Cnow){
    Eigen::Vector3f perr,w;
    Eigen::Matrix3f Rerr;
    Eigen::VectorXf err(6);
    Eigen::Vector
    perr=Cref.p-Cnow.p;
    Rerr=Cnow.r.transpose()*Cref.R;
    werr=Cnow.R * rot2omega(Rerr);

    err<<perr,werr;
    return err;
}