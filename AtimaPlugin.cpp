#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "AtimaPlugin.h"

void AtimaPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }
}

void AtimaPlugin::run() {
   
}

void AtimaPlugin::output(std::string file) {
   std::string command = "export MOCADI_DIR="+parameters["MOCADI_DIR"]+"; ";
   command += "atima < "+parameters["inputfile"]+" > "+file;
 std::cout << command << std::endl;

 system(command.c_str());
}

PluginProxy<AtimaPlugin> AtimaPluginProxy = PluginProxy<AtimaPlugin>("Atima", PluginManager::getInstance());
