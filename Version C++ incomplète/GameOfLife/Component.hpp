#pragma once

#include "IComponent.hpp"

namespace core
{
	namespace ecs
	{
		template<class T>
		class Component : public IComponent
		{
		public:
			Component(const T& valueIn);
			virtual ~Component();

			const T& getValue() const;
			void setValue(const T& valueIn);

		private:
			T value;
		};

		template<class T>
		Component<T>::Component(const T& valueIn): value(valueIn)
		{
		}

		template<class T>
		Component<T>::~Component()
		{
		}

		template<class T>
		const T& Component<T>::getValue() const
		{
			return this->value;
		}

		template<class T>
		void Component<T>::setValue(const T& valueIn)
		{
			this->value = valueIn;
		}
	}
}