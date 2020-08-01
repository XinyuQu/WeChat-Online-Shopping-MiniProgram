//
//  MPorder.cpp
//  miniProgram
//
//  Created by Xinyu Qu on 6/7/20.
//  Copyright © 2020 Xinyu Qu. All rights reserved.
//

#include "MPorder.hpp"
#include <string>
using namespace std;

int MPorder::MPorder_delete(string order_id){
    if(!is_del){
        is_del = true;
        return 0;
    }else return -1;
}

int MPorder::MPorder_getPrice(){
    return price;
}
