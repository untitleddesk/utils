#include "untitled/string.hpp"
namespace Untitled
{
  int String::length_raw(const char *string)
  {
    int length;
    // Each string ends with '\0'. Thanks compiler
    // So, I can do this:
    for(length = 0; string[length] != '\0'; ++length)
      ;
    return length;
  }
  int String::length() const { return length_raw(data); }
  int String::length(const char *string) { return length_raw(string); }

  String::String(const char *from)
  {
    // data = (char*)from; // Not making this. Because it's gonna share the
    // same value as from.

    data = new char[length(from) + 1]; // 1 is for fixing the size

    for(int i = 0; i < length(from); ++i)
      data[i] = from[i];
  }
  String::~String()
  {
    if(data != nullptr)
      {
        delete data;
      }
  }
  String::String() : data(nullptr) {}

  // Returns the raw data for specifics things.
  // As the c_str().
  const char *String::raw() const { return data; }

  String String::operator=(const char *from) { return from; }
  String String::operator=(const String &from) { return from; }
} // namespace Untitled