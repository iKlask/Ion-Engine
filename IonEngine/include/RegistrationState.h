#ifndef REGISTRATIONSTATE_H
#define REGISTRATIONSTATE_H

enum class RegistrationState {
	PENDING_REGISTRATION,
	CURRENTLY_REGISTERED,
	PENDING_DEREGISTRATION,
	CURRENTLY_DEREGISTERED
};

#endif