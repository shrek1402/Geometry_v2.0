#pragma once
#include "pch.h"

class ExcImpl : IException {
  friend class Exception;

  const std::string m_What;
  const int m_Code;

  ExcImpl(const char* what, int code);
  ExcImpl(const ExcImpl&) = default;

  IException* Clone() const override;

  void Delete() override;

 protected:
  ~ExcImpl() = default;

 public:
  const char* What() const override;
  int Code() const override;
};