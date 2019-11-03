#pragma once

#include <iostream>
#include <vector>

#include "GWMetaObject.h"
#include "GWRect.h"
#include "libgwdefs.h"

namespace GW
{
	class GWObjectPrivate;

	class GW_CORE_EXPORT GWObject : public GWMetaObject
	{
		//GW_OBJECT
	public:
		GWObject(GWObject* parent = nullptr);
		GWObject(std::string objectName, GWObject* parent = nullptr);
		virtual ~GWObject();

	public:
		//template<typename GWReceiver, typename ...GWArgs>
		//static int  connect(GWObject* sender, GWSignal<void(GWArgs...)>& signal, GWReceiver* receiver, void (GWReceiver::* SlotFunc) (GWArgs...));

		//template<class Receiver, typename ...Args>
		//static int  disconnect(GWObject* sender, GWSignal<void(Args...)>& signal, Receiver* receiver, void (Receiver::* SlotFunc) (Args...));

	public:
		std::string getObjectName();
		void setObjectName(std::string objectName);
		void setParent(GWObject* object);
		GWObject* getParent();

		void addChild(GWObject* child);
		void removeChild(GWObject* child);
		std::vector<GWObject*> getChilds();
	private:
		GWObjectPrivate* m_private;
	};

	//template<typename GWReceiver, typename ...GWArgs>
	//inline int GWObject::connect(GWObject* sender, GWSignal<void(GWArgs...)>& signal, GWReceiver* receiver, void(GWReceiver::* SlotFunc)(GWArgs...))
	//{
	//	GWMetaObject* _sender = sender->sender();
	//	std::vector<GWSignal<void(GWArgs...) >*>* _signal = static_cast<std::vector<GWSignal<void(GWArgs...) >*>*> (&(signal));

	//	GWMetaObject* _receiver = static_cast<GWObject*>(receiver)->sender();
	//	GWSlot<GWReceiver, void(GWArgs...)> _slot = new GWSlot<GWReceiver, void(GWArgs...)>(receiver, SlotFunc);

	//	_sender->push_receiver(_receiver);
	//	_receiver->push_sender_signals(_sender, _signal);
	//	_signal->push_back(_slot);

	//	return 0;
	//}
	//template<class Receiver, typename ...Args>
	//inline int GWObject::disconnect(GWObject* sender, GWSignal<void(Args...)>& signal, Receiver* receiver, void(Receiver::* SlotFunc)(Args...))
	//{
	//	return 0;
	//}
}
