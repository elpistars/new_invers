#include "LINK.h"
#include "basic_func.h"
#include <iostream>

Eigen::RowVectorXd idx(20);

int FindRoute(int to,int n){
    int i=uLINK.joint_data[to].mother;
    std::cout<<"i,n= "<<i<<","<<n<<std::endl;
    if(i==0){
        return n;
    }
    else{
        idx(n)=to;
        if(n!=19){
            idx(idx.size()-1)=n;
        }
        FindRoute(i,n+1);
    }
}