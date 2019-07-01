//#include "joint_structure.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <eigen3/Eigen/Dense>
#include <cmath>
#include "LINK.h"
#include "basic_func.h"

LINK uLINK;
Eigen::Vector3f UX(1,0,0);
Eigen::Vector3f UY(0,1,0);
Eigen::Vector3f UZ(0,0,1);
void SetupBipedRobot(){
    const Eigen::IOFormat fmt(3, 0, ", ", ";\n", "", "", "[", "]");
    char buff[100];
    //body
    uLINK.set_data(1,"BODY", 10, 0, 2, Eigen::Vector3f (0,0,19), UZ, 0);
    //kaki kanan
    uLINK.set_data(2,"RLEG_J0", 5, 8, 3, Eigen::Vector3f (0,-4,0), UZ, 0);
    uLINK.set_data(3,"RLEG_J1", 1, 0, 4, Eigen::Vector3f (0,0,0), UX, 0);
    uLINK.set_data(4,"RLEG_J2", 5, 0, 5, Eigen::Vector3f (0,0,0), UY, 0);
    uLINK.set_data(5,"RLEG_J3", 1, 0, 6, Eigen::Vector3f (0,0,-8), UY, 0);
    uLINK.set_data(6,"RLEG_J4", 6, 0, 7, Eigen::Vector3f (0,0,-8), UY, 0);
    uLINK.set_data(7,"RLEG_J5", 2, 0, 0, Eigen::Vector3f (0,0,0), UX, 0);
    //kaki kiri
    uLINK.set_data(8,"LLEG_J0", 5, 0, 9, Eigen::Vector3f (0,4,0), UZ, 0);
    uLINK.set_data(9,"LLEG_J1", 1, 0, 10, Eigen::Vector3f (0,0,0), UX, 0);
    uLINK.set_data(10,"LLEG_J2", 5, 0, 11, Eigen::Vector3f (0,0,0), UY, 0);
    uLINK.set_data(11,"LLEG_J3", 1, 0, 12, Eigen::Vector3f (0,0,-8), UY, 0);
    uLINK.set_data(12,"LLEG_J4", 6, 0, 13, Eigen::Vector3f (0,0,-8), UY, 0);
    uLINK.set_data(13,"LLEG_J5", 2, 0, 0, Eigen::Vector3f (0,0,0), UX, 0);
    
    uLINK.joint_data[1].p=Eigen::Vector3f (0,0,19);
    uLINK.joint_data[1].R=Eigen::Matrix3f::Identity();
    
    uLINK.joint_data[1].v=Eigen::RowVector3f (0,0,0);
    uLINK.joint_data[1].w=Eigen::RowVector3f (0,0,0);
    for (int i=1;i<=13;i++){
        uLINK.joint_data[i].dq=0;
    }
    FindMother(1);
    ForwardKinematics(1);
    for(int i=1;i<=13;i++){
        sprintf(buff,"%s\t: p: ",uLINK.joint_data[i].name);
        std::cout<<buff<<uLINK.joint_data[i].p.transpose().format(fmt)<<std::endl;        
    }
  
}
