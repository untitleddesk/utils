#pragma once
// @todo My own format.
#include <format>
namespace Recurring
{
  // @todo Move String to a new header file
  struct String
  {
  private:
    static int length_raw(const char *string);
    char *data;

  public:
    String();
    String(const char *from);
    ~String();

    const char *raw() const;

    // Why do I need making a constructor to use operator???
    // Because operator doesn't know what to do. *probably

    String operator=(const char *from);
    String operator=(const String &from);

    int length() const;
    static int length(const char *from);

    // @todo implement push back

    // void push_back (const char *from);
    void push_back(const String &string);

    /**
     * @brief Formats your String!
     *
     */
    template <typename... Args>
    static String format(const String &string, Args... args)
    {
      String formatted = std::format(string.raw(), args...).c_str(); 
      return formatted;
    }
  };
} // namespace Recurring