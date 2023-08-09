#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "WGSimPlugin.h"



void WGSimPlugin::input(std::string file) {
 inputfile = file;
readParameterFile(file);
}

void WGSimPlugin::run() {}

void WGSimPlugin::output(std::string file) {
 std::string outputfile = file;
myCommand += "wgsim";
myCommand += " -N"+myParameters["x"];
myCommand += " -1"+myParameters["y"];
myCommand += " -d0 -S11 -e0 -r"+myParameters["z"];
myCommand += " "+std::string(PluginManager::prefix())+"/"+myParameters["fastafile"];
myCommand += " "+outputfile+" /dev/null";
 system(myCommand.c_str());
 std::cout << myCommand << std::endl;
}

PluginProxy<WGSimPlugin> WGSimPluginProxy = PluginProxy<WGSimPlugin>("WGSim", PluginManager::getInstance());
