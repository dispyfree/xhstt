#include "Util.h"
using namespace khe;


std::list<std::string> Util::strs;
char *Util::sTc(const std::string &str){
     if(str.length() == 0)
         return NULL;
     else{
         strs.push_back(str);
         return const_cast<char*>((*strs.rbegin()).c_str());
     }
 }