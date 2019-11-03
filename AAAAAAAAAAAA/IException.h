#pragma once
class IException {
  friend class Exception;

  virtual IException* Clone() const = 0;
  virtual void Delete() = 0;

 protected:
  virtual ~IException() = default;

 public:
  virtual const char* What() const = 0;
  virtual int Code() const = 0;

  IException& operator=(const IException&) = delete;
};