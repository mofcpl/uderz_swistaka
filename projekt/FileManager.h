#pragma once

#include<fstream>
#include"Graph.h"
#include"Interpreter.h"


class cFileManager
{
private:

	cInterpreter* pInterpreter;
	std::fstream File;

public:

	cFileManager();
	~cFileManager();

	void Init(cInterpreter* interpreter);

	void LoadScriptFile(std::string path);

};

