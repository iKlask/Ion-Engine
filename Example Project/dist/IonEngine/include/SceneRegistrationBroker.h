#ifndef SCENEREGISTRATIONBROKER_H
#define SCENEREGISTRATIONBROKER_H

#include <list>
class CommandBase;

class SceneRegistrationBroker {
private:
	typedef std::list<CommandBase*> CommandList;
	CommandList list_Commands;

public:
	SceneRegistrationBroker() = default;									// Private constructor
	SceneRegistrationBroker(const SceneRegistrationBroker&) = delete;				// Prevent copy-construction
	SceneRegistrationBroker& operator=(const SceneRegistrationBroker&) = delete;	// Prevent assignment
	~SceneRegistrationBroker();


	void addCommand(CommandBase* cmd);
	void ExecuteCommands();
};

#endif

