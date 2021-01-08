#pragma once

#include"Graph.h"

enum SCRIPT_TYPE { SETTINGS_SCRIPT, GRAPH_SCRIPT, GAME_SCRIPT };


struct sScript
{
	SCRIPT_TYPE type;
	std::string command;
	std::string value;
};

class cInterpreter
{
private:

	cGraph* pGraph;

	void RunSettingsScript(sScript script);
	void RunGraphScript(sScript script);
	void RunGameScript(sScript script);

public:

	void Init(cGraph* graph);
	sScript Interprete(std::string script,SCRIPT_TYPE type);
	void RunScript(sScript script);
	

};
