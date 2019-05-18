#ifndef LINK_H
#define LINK_H

#include <eigen3/Eigen/Dense>
#include <cmath>

class LINK{
    public:
        struct{
            char name[10];
            float m,q,dq;
            int sister,child,mother;
            Eigen::Vector3f b,a,p;
            Eigen::RowVector3f v,w;
            Eigen::Matrix3f R;
        }joint_data[14];
        void set_data(int i, char* Name, float M, int Sister, int Child, Eigen::Vector3f B, Eigen::Vector3f A, float Q);
        LINK(){};
};
extern LINK uLINK;
extern Eigen::Vector3f UX;
extern Eigen::Vector3f UY;
extern Eigen::Vector3f UZ;

#endif