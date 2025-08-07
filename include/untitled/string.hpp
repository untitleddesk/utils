#ifndef UNTITLED_STRING_GUARD
#define UNTITLED_STRING_GUARD
namespace Untitled
{
    // @todo Move String to a new header file
    struct String
    {
    private:
        static int length_raw(const char* string);
        char* data;
    public:

        String();
        String(const char* from);
        ~String();

        const char* raw() const;
        
        // Why do I need making a constructor to use operator???
        // Because operator doesn't know what to do. *probably
        
        String operator=(const char* from);
        String operator=(const String& from);

        int length() const;
        static int length(const char* from);

        // @todo implement push back

        void push_back(const char* from);
        void push_back(const String& string);
    };

    // @todo Make format and understand how it index all '{}' and substitutes them for a variable. move this to it's own file
    struct Format
    {
        template<typename... Args>
        Format(const String& string, Args... args);
    };
}
#endif // UNTITLED_STRING_GUARD