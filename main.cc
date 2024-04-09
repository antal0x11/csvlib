#include "csv.hpp"

struct Colors
{
    std::string code;
    int id;

    Colors() : code("#C2CEAB"), id(1) {}
    std::string to_string(const std::string &delimeter) const
    {
        std::ostringstream _s;
        _s << code << delimeter << id;
        return _s.str();
    }
};

struct Person
{
    std::string name;
    int age;
    int id;

    Person() : name("jenny"), age(17), id(42) {}
    std::string to_string(const std::string &delimeter) const
    {
        std::ostringstream s;
        s << name << delimeter << age << delimeter << id;
        return s.str();
    }
};

int main()
{
    std::vector<Colors> p;
    Colors c1;
    std::vector<std::string> s;
    s.push_back("code");
    s.push_back("id");

    std::vector<Person> m;
    Person p1;

    for (int i = 0; i < 40; i++)
    {
        p.push_back(c1);
    }

    for (int i = 0; i < 40; i++)
    {
        m.push_back(p1);
    }

    std::vector<std::string> q;
    q.push_back("name");
    q.push_back("age");
    q.push_back("id");

    csv::write("./tests/example.csv", p, ",", s);

    csv::write("./tests/example1.csv", m, ",", q);
    return 0;
}