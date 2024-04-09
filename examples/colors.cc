#include "../csvlib.hpp"

struct Colors
{
    std::string code;
    int id;

    static constexpr size_t num_fields = 2;

    Colors() : code("#C2CEAB"), id(1) {}
    Colors(const std::string &code, int id) : code(code), id(id) {}

    std::string to_string(const std::string &delimeter) const
    {
        std::ostringstream _s;
        _s << code << delimeter << id;
        return _s.str();
    }

    static Colors init(const std::vector<std::string> &_t)
    {
        return Colors(_t[0], std::stoi(_t[1]));
    }
};

int main()
{
    std::vector<Colors> p;
    Colors c1;
    std::vector<std::string> s;
    s.push_back("code");
    s.push_back("id");

    for (int i = 0; i < 20; i++)
    {
        p.push_back(c1);
    }

    csvlib::CSV<Colors>::write("../tests/example.csv", p, ",", s);

    std::vector<Colors> rs(csvlib::CSV<Colors>::read("../tests/example.csv", ","));
    for (auto x : rs)
    {
        std::cout << x.to_string(",") << std::endl;
    }
    std::cout << std::endl;
    std::cout << rs[0].code << " " << rs[0].id << std::endl;
    return 0;
}