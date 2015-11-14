KHE Library C++ Wrapper
=======================

The provided library is a basic C++11 wrapper to the KHE library for the XHSTT file format. This library is not maintained by the maintainer of the KHE library (written in C) for XHSTT. It does neither cover the entire functionality offered by KHE nor does it strive to do so. Feel free to use the library as a toolbox for your own purposes, modifying and extending it where you see fit. However, patches for bugs and extensions in coverage are always welcome.

The library in its published form has undergone heavy cuts, with most of the original functionality not being eligible for publication. The cut-down version did not undergo the extensive scrutiny of its predecessor; therefore you may run into problems. When that happens, feel free to write me or file a bug report. If you have any suggestions on how to improve the current implementation, please tell me. 

The library should perform quite well, however it is not optimized for the best performance. Where trade-offs between usability and performance must be made, I am in favor of usability. If you depend on maximum performance, for instance when dealing with a large number of instances (i.e. genetic/memetic algorithms), you might want to consider the C library. Please note that this library is 100% transparent; it only wraps, therefore you may use C and C++ library calls interchangeably. 

The library itself is licensed under the MIT license. 


Requirements
======================
The KHE library is required; for running the tests you need GoogleTest (the KHE library in turn needs pthread and expat).
This library uses C++11; furthermore you need boost-iterator and boost-range. 


Installation
=======================
There are no special requirements to your build system; however using Netbeans is very convenient because its build configuration is shipped with this library (Netbeans relies on Makefiles). 
If you do not have Netbeans installed, you may simply compile all .cpp and .h files below the root except for main.cpp and LibraryTests.cpp. Running the tests (see main.cpp and LibraryTests.cpp) requires a working installation of GoogleTest, the flag is "-lgtest". Furthermore, standalone libraries need "-lpthread" and "-lexpat" for the pthread and expat libraries. 


Usage
=======================
As the library mainly wraps KHE's capabilities, no extra documentation is required. 
Please note that this library does provide some helper functionality such as dummy objects (both for time and resources) which may be harnessed by your code. Furthermore it provides a mechanism to automatically assign unique IDs to objects; this may be helpful for storing objects in containers. 
