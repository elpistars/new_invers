#include "LINK.h"
#include "basic_func.h"
void FindMother(int j){
    if(j != 0){
        if(j == 1){
            uLINK.joint_data[j].mother=0;
        }
        if(uLINK.joint_data[j].child != 0){
            uLINK.joint_data[uLINK.joint_data[j].child].mother=j;
            FindMother(uLINK.joint_data[j].child);
        }
        if(uLINK.joint_data[j].sister != 0){
            uLINK.joint_data[uLINK.joint_data[j].sister].mother=uLINK.joint_data[j].mother;
            FindMother(uLINK.joint_data[j].sister);
        }
    }
}