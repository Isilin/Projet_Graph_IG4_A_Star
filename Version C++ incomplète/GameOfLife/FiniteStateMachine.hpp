#pragma once

#include "Account.hpp"
#include "Message.hpp"
#include "State.inl"
#include "Transition.inl"

namespace core
{
	namespace ecs
	{
		class FiniteStateMachine : public core::com::Account
		{
		public:
			FiniteStateMachine();
			~FiniteStateMachine();

			const app::def::State getCurrentState() const;
		protected:
			virtual void process(std::shared_ptr<core::com::AbstractMessage> messageIn);

		private:
			app::def::State currentState;

			void transitionFromPlay(const app::def::Transition transitionIn);
			void transitionFromStop(const app::def::Transition transitionIn);
		};
	}
}