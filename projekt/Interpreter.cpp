#include<iostream>
#include<fstream>
#include<string>
#include"Interpreter.h"

void cInterpreter::Init(cGraph* graph)
{
	pGraph = graph;
}

sScript cInterpreter::Interprete(std::string script, SCRIPT_TYPE type)
{
	
	sScript TempScript;
	
	int spaceid;
	int length = script.length();
	for (int i = 0; i < length; i++)
	{
		if (script[i] == ' ') spaceid = i;
	}

	std::string command(script, 0, spaceid);
	std::string value(script, spaceid+1, length-1);

	TempScript.type = type;
	TempScript.command = command;
	TempScript.value = value;

	return TempScript;
}

void cInterpreter::RunSettingsScript(sScript script)
{
	if (script.command == "width")
	{
		int ivalue = std::stoi(script.value);
		sVec2D Resolution = pGraph->GetResolution();
		Resolution.X = ivalue;
		pGraph->SetResolution(Resolution);
		
	}

	if (script.command == "height")
	{
		int ivalue = std::stoi(script.value);
		sVec2D Resolution = pGraph->GetResolution();
		Resolution.Y = ivalue;
		pGraph->SetResolution(Resolution);
	}

	if (script.command == "fullscreen")
	{
		int ivalue = std::stoi(script.value);
		if (ivalue == 1) pGraph->SetFullscreen(true);
		if (ivalue == 0) pGraph->SetFullscreen(false);
	}

	if (script.command == "accelerated")
	{
		int ivalue = std::stoi(script.value);
		if (ivalue == 1) pGraph->SetAccelerated(true);
		if (ivalue == 0) pGraph->SetAccelerated(false);
	}
}

void cInterpreter::RunGraphScript(sScript script)
{
	pGraph->LoadGraph(script.command, script.value);
}

void cInterpreter::RunGameScript(sScript script)
{
}

void cInterpreter::RunScript(sScript script)
{
	switch (script.type)
	{
	case SETTINGS_SCRIPT: {RunSettingsScript(script); break; }
	case GRAPH_SCRIPT: {RunGraphScript(script); break; }
	case GAME_SCRIPT: {RunGameScript(script); break; }
	}
	
}
