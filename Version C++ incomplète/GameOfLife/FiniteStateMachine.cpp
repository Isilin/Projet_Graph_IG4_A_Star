#include "FiniteStateMachine.hpp"

#include "HeavyMessage.hpp"
#include "OfficeAccount.inl"
#include "Transition.inl"

using namespace core::ecs;
using namespace core::com;
using namespace app::def;

FiniteStateMachine::FiniteStateMachine(): Account(_FSM_), currentState(_PLAY_)
{
}


FiniteStateMachine::~FiniteStateMachine()
{
}

const app::def::State core::ecs::FiniteStateMachine::getCurrentState() const
{
	return this->currentState;
}

void core::ecs::FiniteStateMachine::process(std::shared_ptr<AbstractMessage> messageIn)
{
	if (messageIn->getMessage() == _CHANGE_STATE_) {
		try {
			auto tmpMessage = std::dynamic_pointer_cast<HeavyMessage<Transition>>(messageIn);
			switch (this->currentState) {
			case _PLAY_:
				this->transitionFromPlay(tmpMessage->getParameter());
				break;
			case _STOP_:
				this->transitionFromPlay(tmpMessage->getParameter());
				break;
			default:
				break;
			}
		}
		catch (const std::exception& e) {
		}
	}
}

void FiniteStateMachine::transitionFromPlay(const app::def::Transition transitionIn)
{
	switch (transitionIn) {
	case _QUIT_:
		this->currentState = _STOP_;
		break;
	default:
		break;
	}
}

void FiniteStateMachine::transitionFromStop(const app::def::Transition transitionIn)
{
}
