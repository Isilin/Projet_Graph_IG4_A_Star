#include "Communicable.hpp"

#include "Message.hpp"

using namespace core::com;
using namespace app::def;

std::weak_ptr<Office> Communicable::office;
std::shared_ptr<std::mutex> Communicable::lockOffice = nullptr;

Communicable::Communicable()
{
}


Communicable::~Communicable()
{
}

void Communicable::sendMessage(const MessageID messageIn, const AccountID recipientIn)
{
	std::shared_ptr<AbstractMessage> message(new Message(messageIn));

	this->sendMessage(message, recipientIn);
}

void core::com::Communicable::sendMessage(const std::shared_ptr<AbstractMessage> messageIn, const app::def::AccountID recipientIn)
{
	Communicable::lockOffice->lock();
	auto tempOffice = Communicable::office.lock();
	tempOffice->distributeMessage(messageIn, recipientIn);
	Communicable::lockOffice->unlock();
}

void Communicable::broadcast(const MessageID messageIn)
{
	std::shared_ptr<AbstractMessage> message(new Message(messageIn));

	this->broadcast(message);
}

void core::com::Communicable::broadcast(const std::shared_ptr<AbstractMessage> messageIn)
{
	Communicable::lockOffice->lock();
	auto tempOffice = Communicable::office.lock();
	tempOffice->broadcastMessage(messageIn);
	Communicable::lockOffice->unlock();
}

void Communicable::setOffice(std::weak_ptr<Office> officeIn, std::shared_ptr<std::mutex> lockOfficeIn)
{
	Communicable::lockOffice = lockOfficeIn;
	Communicable::office = officeIn;
}
