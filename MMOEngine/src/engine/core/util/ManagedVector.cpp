/*
 *	engine/core/util/ManagedVector.cpp generated by engine3 IDL compiler 0.60
 */

#include "ManagedVector.h"

/*
 *	ManagedVectorStub
 */

ManagedVector::ManagedVector(DummyConstructorParameter* param) {
}

ManagedVector::~ManagedVector() {
}


/*
 *	ManagedVectorImplementation
 */

ManagedVectorImplementation::ManagedVectorImplementation() {
	_initializeImplementation();
}

ManagedVectorImplementation::ManagedVectorImplementation(DummyConstructorParameter* param) {
	_initializeImplementation();
}

ManagedVectorImplementation::~ManagedVectorImplementation() {
}


void ManagedVectorImplementation::finalize() {
}

void ManagedVectorImplementation::_initializeImplementation() {
	_setClassHelper(ManagedVectorHelper::instance());

	_serializationHelperMethod();
}

void ManagedVectorImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (ManagedVector*) stub;
}

DistributedObjectStub* ManagedVectorImplementation::_getStub() {
	return _this;
}

ManagedVectorImplementation::operator const ManagedVector*() {
	return _this;
}

TransactionalObject* ManagedVectorImplementation::clone() {
	return (TransactionalObject*) new ManagedVectorImplementation(*this);
}


void ManagedVectorImplementation::lock(bool doLock) {
}

void ManagedVectorImplementation::lock(ManagedObject* obj) {
}

void ManagedVectorImplementation::rlock(bool doLock) {
}

void ManagedVectorImplementation::wlock(bool doLock) {
}

void ManagedVectorImplementation::wlock(ManagedObject* obj) {
}

void ManagedVectorImplementation::unlock(bool doLock) {
}

void ManagedVectorImplementation::runlock(bool doLock) {
}

void ManagedVectorImplementation::_serializationHelperMethod() {
	_setClassName("ManagedVector");

}

/*
 *	ManagedVectorAdapter
 */

ManagedVectorAdapter::ManagedVectorAdapter(ManagedVectorImplementation* obj) : DistributedObjectAdapter((DistributedObjectServant*) obj) {
}

Packet* ManagedVectorAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	default:
		return NULL;
	}

	return resp;
}

/*
 *	ManagedVectorHelper
 */

ManagedVectorHelper* ManagedVectorHelper::staticInitializer = ManagedVectorHelper::instance();

ManagedVectorHelper::ManagedVectorHelper() {
	className = "ManagedVector";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void ManagedVectorHelper::finalizeHelper() {
	ManagedVectorHelper::finalize();
}

DistributedObject* ManagedVectorHelper::instantiateObject() {
	return new ManagedVector(DummyConstructorParameter::instance());
}

DistributedObjectServant* ManagedVectorHelper::instantiateServant() {
	return new ManagedVectorImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ManagedVectorHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ManagedVectorAdapter((ManagedVectorImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

