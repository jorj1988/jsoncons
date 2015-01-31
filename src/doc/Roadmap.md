Coming next in Release 0.97

- Implement the [JSON Pointer](https://tools.ietf.org/html/rfc6901) specification for identifying a specific value within a `json` document.

Coming in later release:

- Revisit error codes, parsing_context, and opportunities for error recovery. Attempt to support [json 5](http://json5.org/) behaviour through an parse_error_handler and a json_filter.

- Support [JSON Content Rules](http://www.ietf.org/id/draft-newton-json-content-rules-04.txt)

- Improve csv_reader 

- Examine other data storage than vectors that could benefit from custom allocators.

- Add extensions for reading from and serializing to binary formats (bson,bjson,ubjson) 

