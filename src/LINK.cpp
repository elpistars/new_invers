#include "LINK.h"

void LINK::set_data(int i, char* Name, float M, int Sister, int Child, Eigen::Vector3f B, Eigen::Vector3f A, float Q){
    strcpy(this->joint_data[i].name,Name);
    this->joint_data[i].m=M;
    this->joint_data[i].sister=Sister;
    this->joint_data[i].child=Child;
    this->joint_data[i].b=B;
    this->joint_data[i].a=A;
}