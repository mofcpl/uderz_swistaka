#include<fstream>
#include<iostream>
#include<string>
#include"FileManager.h"


cFileManager::cFileManager()
{

}

cFileManager::~cFileManager()
{

}

void cFileManager::Init(cInterpreter* interpreter)
{
	pInterpreter = interpreter;
}

void cFileManager::LoadScriptFile(std::string path)
{
	SCRIPT_TYPE type;
	
	if (path == "graph.ini") type = GRAPH_SCRIPT;
	if (path == "settings.ini") type = SETTINGS_SCRIPT;
	
	File.open(path, std::ios::in);
	if (File.good() == true)
	{ 
	
		int length,spaceid;
		std::string row;

		while (!File.eof())
		{
			getline(File, row);
			
			sScript tempScript = pInterpreter->Interprete(row,type);
			pInterpreter->RunScript(tempScript);
			
		}
	
	}

	File.close();
}

