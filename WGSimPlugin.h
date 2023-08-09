#ifndef WGSIMPLUGIN_H
#define WGSIMPLUGIN_H

#include "Plugin.h"
#include "Tool.h"
#include "PluginProxy.h"
#include <string>

class WGSimPlugin : public Plugin, public Tool
{
public: 
 std::string toString() {return "WGSim";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
};

#endif
