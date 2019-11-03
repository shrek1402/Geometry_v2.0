#include "ExcImpl.h"

ExcImpl::ExcImpl(const char* what, int code) : m_What(what), m_Code(code) {}

IException* ExcImpl::Clone() const { return new ExcImpl(*this); }

void ExcImpl::Delete() { delete this; }

const char* ExcImpl::What() const { return m_What.c_str(); }

int ExcImpl::Code() const { return m_Code; }
