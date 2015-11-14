/* 
 * File:   main.cpp
 * Author: valentin
 *
 * Created on November 13, 2015, 10:05 PM
 */

#include <cstdlib>
#include "gtest/gtest.h"

#include "Archive.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

