#include <iostream>
#include <eigen3/Eigen/Dense>
#include <cstdio>
#include <cmath>
#include "LINK.h"
#include "basic_func.h"
#include <eigen3/Eigen/Dense>
#include <iostream>
Eigen::MatrixXf Jacob;
    
Eigen::MatrixXf CalcJacobian(Eigen::RowVectorXd idx,int nRoute){
    JData target;
    int xtarget=idx(0);
    target=uLINK.joint_data[xtarget];
    Eigen::MatrixXf jacob(6,nRoute);
    Jacob.resize(jacob.cols(),jacob.rows());
    for(int n=nRoute; n>0;n--){
        int j=idx(n);
        target.a=uLINK.joint_data[j].R* uLINK.joint_data[j].a;
        Eigen::VectorXf temp;
        temp.resize(jacob.rows());
        temp<<target.a.cross(target.p-uLINK.joint_data[j].p),target.a;
        jacob.col(nRoute-n)<<temp;
    }
    return jacob;
}