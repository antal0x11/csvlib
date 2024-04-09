## csvlib
A very simple csv library to read and write csv files.

### Instructions

The struct that is about to be written or read, it has to implement:

- std::string to_string(const std::string &delimeter) const
- static Example init(const std::vector<std::string > &_t)

just like in the example.

```c++
struct Example {
    int a;
    int b;

    Example (int a, int b) : a(a), b(b) {}

    std::string to_string(const std::string &delimeter) const
    {
        std::ostringstream _s;
        _s << a << delimeter << b;
        return _s.str();
    }

    static Example init(const std::vector<std::string> &_t)
    {
        return Example(std::stoi(_t[0]), std::stoi(_t[1]));
    }
}

```
