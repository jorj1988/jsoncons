```c++
jsoncons::json::is
template <class T>
T as() const
```
Attempts to convert the json value to the template value type using [json_type_traits](json_type_traits).

    X as<X>() const
Type X is integeral: returns integer value if value is integral, performs cast if value has double type, returns 1 or 0 if value has bool type, attempts conversion if value is string, otherwise throws.
Type X is floating point: returns value cast to X if value is integral, returns `NaN` if value is `null`, attempts conversion if value is string, otherwise throws.

    as<bool>()
Returns `true` if value is `bool` and `true`, or if value is integral and non-zero, or if value is floating point and non-zero, or if value is string and parsed value evaluates as `true`. 
Returns `false` if value is `bool` and `false`, or if value is integral and zero, or if value is floating point and zero, or if value is string and parsed value evaluates as `false`. 
Otherwise throws `std::runtime_exception`

    std::string as<std::string>() const noexcept
    std::string as<std::string>(const char_allocator& allocator) const noexcept
If value is string, returns value, otherwise returns result of `dump`.

    as<X<T>>()
If the type `X` is not `std::basic_string` but otherwise satisfies [SequenceContainer](http://en.cppreference.com/w/cpp/concept/SequenceContainer), `as<X<T>>()` returns the `json` value as an `X<T>` if the `json` value is an array and each element is convertible to type `T`, otherwise throws.

    as<X<std::string,T>>()
If the type 'X' satisfies [AssociativeContainer](http://en.cppreference.com/w/cpp/concept/AssociativeContainer) or [UnorderedAssociativeContainer](http://en.cppreference.com/w/cpp/concept/UnorderedAssociativeContainer), `as<X<std::string,T>>()` returns the `json` value as an `X<std::string,T>` if the `json` value is an object and if each member value is convertible to type `T`, otherwise throws.

## Examples

```c++
json j = json::parse(R"(
{
    "k1" : 2147483647,
    "k2" : 2147483648,
    "k3" : -10,
    "k4" : 10.5,
    "k5" : true,
    "k6" : "10.5"
}
)");

std::cout << "(1) " << j["k1"].as<int32_t>() << '\n';
std::cout << "(2) " << j["k2"].as<int32_t>() << '\n';
std::cout << "(3) " << j["k2"].as<long long>() << '\n';
std::cout << "(4) " << j["k3"].as<signed char>() << '\n';
std::cout << "(5) " << j["k3"].as<uint32_t>() << '\n';
std::cout << "(6) " << j["k4"].as<int32_t>() << '\n';
std::cout << "(7) " << j["k4"].as<double>() << '\n';
std::cout << std::boolalpha << "(8) " << j["k5"].as<int>() << '\n';
std::cout << std::boolalpha << "(9) " << j["k5"].as<bool>() << '\n';
std::cout << "(10) " << j["k6"].as<double>() << '\n';

```
Output:
```

(1) 2147483647
(2) -2147483648
(3) 2147483648
(4) �
(5) 4294967286
(6) 10
(7) 10.5
(8) 1
(9) true
(10) 10.5
```

