#ifndef COMMANDBASE_H
#define COMMANDBASE_H

#include "Align16.h"

class CommandBase : public Align16
{
public:
	CommandBase() {};
	~CommandBase() {};
	CommandBase(const CommandBase&) = delete;
	CommandBase& operator=(const  CommandBase&) = delete;

	virtual void execute() {};
};

#endif
