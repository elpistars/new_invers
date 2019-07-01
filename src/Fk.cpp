#include <iostream>
#include <eigen3/Eigen/Dense>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include "LINK.h"
#include "basic_func.h"

//typedef Eigen::Matrix<float,6,1> Vector6f;

int main(){
    const Eigen::IOFormat fmt(3, 0, ", ", ";\n", "", "", "[", "]");
    int nRoute;
    char buff[100];
    Eigen::VectorXf qR1(6),qL1(6);
    SetupBipedRobot();
    //while(1){
        qR1<<-M_PI/2,0,0,0,0,0;
        qL1<<0,0,0,0,0,0;
    
    for(int n=0;n<=5;n++){
        uLINK.joint_data[RLEG_J0+n].q = qR1(n);
        uLINK.joint_data[LLEG_J0+n].q = qL1(n);
        uLINK.joint_data[RLEG_J0+n].goal_pos= (qR1(n)*ToDeg+150)/300 * 1023;
        uLINK.joint_data[LLEG_J0+n].goal_pos= (qL1(n)*ToDeg+150)/300 * 1023;
    }
    
    uLINK.joint_data[BODY].p=Eigen::Vector3f(0,0,19);
    uLINK.joint_data[BODY].R=Eigen::Matrix3f::Identity();
    ForwardKinematics(1);
    for(int i=1;i<=13;i++){
        sprintf(buff,"%s\t: p: ",uLINK.joint_data[i].name);
        std::cout<<buff<<uLINK.joint_data[i].p.transpose().format(fmt);
        sprintf(buff," q: %0.2f goal_pos: %d",uLINK.joint_data[i].q,uLINK.joint_data[i].goal_pos);
        std::cout<<buff<<std::endl;       
    }
    nRoute=FindRoute(RLEG_J5,0);
    Jacob=CalcJacobian(idx,nRoute);
    std::cout<<"idx: "<<idx<<std::endl;
    std::cout<<"n: "<<nRoute<<std::endl;
    std::cout<<"J: "<<Jacob<<std::endl;
}