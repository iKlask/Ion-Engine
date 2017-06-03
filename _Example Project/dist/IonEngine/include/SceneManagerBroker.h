#ifndef SCENEMANAGERBROKER_H
#define SCENEMANAGERBROKER_H

#include <list>
class CommandBase;

class SceneManagerBroker {
private:
	typedef std::list<CommandBase*> CommandList;
	CommandList list_Commands;

public:
	SceneManagerBroker() = default;									// Private constructor
	SceneManagerBroker(const SceneManagerBroker&) = delete;				// Prevent copy-construction
	SceneManagerBroker& operator=(const SceneManagerBroker&) = delete;	// Prevent assignment
	~SceneManagerBroker();


	void addCommand(CommandBase* cmd);
	void ExecuteCommands();
};

#endif // !SceneManagerBroker_H

