#include "Account.hpp"

#include <iostream>

using namespace core::com;
using namespace app::def;

Account::Account(const app::def::AccountID idAccountIn): Communicable(), idAccount(idAccountIn)
{
	Communicable::lockOffice->lock();
	auto tmpOffice = Communicable::office.lock();
	try {
		tmpOffice->registerAccount(this->getId());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	Communicable::lockOffice->unlock();
}

core::com::Account::~Account()
{
}

void Account::receiveMessage()
{
	this->lockOffice->lock();
	auto tempOffice = this->office.lock();
	while (tempOffice->isNewMessages(this->idAccount)) {
		this->waitingMessages.push(tempOffice->withdrawMessage(this->idAccount));
	}
	this->lockOffice->unlock();
}

const AccountID Account::getId() const
{
	return this->idAccount;
}

void Account::processMessages()
{
	while (!this->waitingMessages.empty()) {
		this->process(this->waitingMessages.front());
	}
}
