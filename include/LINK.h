#ifndef LINK_H
#define LINK_H

#include <eigen3/Eigen/Dense>
#include <cmath>

#define BODY 1
#define RLEG_J0 2
#define RLEG_J1 3
#define RLEG_J2 4
#define RLEG_J3 5
#define RLEG_J4 6
#define RLEG_J5 7
#define LLEG_J0 8
#define LLEG_J1 9
#define LLEG_J2 10
#define LLEG_J3 11
#define LLEG_J4 12
#define LLEG_J5 13

typedef struct{
            char name[10];
            float m,q,dq;
            int sister,child,mother,goal_pos;
            Eigen::Vector3f b,a,p;
            Eigen::RowVector3f v,w;
            Eigen::Matrix3f R;
        }JData;
class LINK{
    public:
        JData joint_data[14];
        void set_data(int i, char* Name, float M, int Sister, int Child, Eigen::Vector3f B, Eigen::Vector3f A, float Q);
        LINK(){};
};
extern LINK uLINK;
extern Eigen::RowVectorXd idx;
extern Eigen::Vector3f UX;
extern Eigen::Vector3f UY;
extern Eigen::Vector3f UZ;
extern Eigen::MatrixXf Jacob;

#endif