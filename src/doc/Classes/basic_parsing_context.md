    jsoncons::basic_parsing_context

    template <typename Char>
    class basic_parsing_context<Char>

    typedef basic_parsing_context<Char> parsing_context;
    typedef wbasic_parsing_context<Char> wparsing_context;

Provides contextual information for the element being parsed. This information may be used for error reporting.

### Header

    #include "jsoncons/error_handler.hpp"

### Member functions

    virtual unsigned long line_number() const = 0
Returns the line number to the end of the text being parsed.
Line numbers start at 1.

    virtual unsigned long column_number() const = 0
Returns the column number to the end of the text being parsed.
Column numbers start at 1.

    virtual size_t minimum_structure_capacity() const = 0
Provides a hint to the [basic_json_output_handler](basic_json_output_handler) for how many elements to reserve for a json array or object

    virtual const std::basic_string<Char>& buffer() const = 0;
Returns a reference to a string buffer of text 

