#pragma once
#include "pch.h"
class Exception {
  IException* const m_Ptr;

 public:
  Exception(const char* what, int code) : m_Ptr(new ExcImpl(what, code)) {}
  Exception(const Exception& src) : m_Ptr(src.m_Ptr->Clone()) {}
  ~Exception() { m_Ptr->Delete(); }
  const IException* Ptr() const { return m_Ptr; }
};