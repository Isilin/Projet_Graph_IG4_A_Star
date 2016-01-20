#include "Office.hpp"

#include <string>
#include <iostream>

using namespace core::com;
using namespace app::def;

Office::Office(): mailbox()
{
}


Office::~Office()
{
}

void Office::registerAccount(const AccountID accountIn)
{
	if (this->mailbox.find(accountIn) != this->mailbox.end()) {
		std::string tmp = "This office account (" + std::to_string(accountIn) + ") already exists.";
		throw std::exception(tmp.c_str());
	}
	else {
		this->mailbox.insert(std::pair<AccountID, std::queue<std::shared_ptr<AbstractMessage>>>(accountIn, std::queue < std::shared_ptr<AbstractMessage>>()));
	}
}

void Office::distributeMessage(std::shared_ptr<AbstractMessage> messageIn, const AccountID recipientIn)
{
	this->mailbox[recipientIn].push(messageIn);
}

void Office::broadcastMessage(std::shared_ptr<AbstractMessage> messageIn)
{
	for (auto it : this->mailbox) {
		this->distributeMessage(messageIn, it.first);
	}
}

bool Office::isNewMessages(const AccountID accountIn)
{
	return !this->mailbox[accountIn].empty();
}

std::shared_ptr<AbstractMessage> Office::withdrawMessage(const AccountID accountIn)
{
	std::shared_ptr<AbstractMessage> message(this->mailbox[accountIn].front());
	this->mailbox[accountIn].pop();
	return message;
}
