#include "TPathParser.h"

#ifndef BOOST_FILESYSTEM_NO_DEPRECATED
#define BOOST_FILESYSTEM_NO_DEPRECATED
#endif

TPathParser::TPathParser()
{
    
}

TPathParser::~TPathParser()
{
    
}

void TPathParser::GeneratePathInfo(const std::string& rootpath)
{
    
}

void TPathParser::DumpFilePathName()
{
    TVectorString::iterator it = ResourcePathData.begin();
    while(it!=ResourcePathData.end()){
        std::cout<<*it<<"\n";
        ++it;
    }
}

const char * TPathParser::GetBoolText(bool b)
{
    return b ? "true" : "false";
}

