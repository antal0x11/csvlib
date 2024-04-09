#include "../csvlib.hpp"

struct Person
{
    std::string name;
    int age;
    int id;

    static constexpr size_t num_fields = 3;

    Person() : name("jenny"), age(17), id(42) {}
    Person(const std::string &name, int age, int id) : name(name), age(age), id(id) {}
    std::string to_string(const std::string &delimeter) const
    {
        std::ostringstream s;
        s << name << delimeter << age << delimeter << id;
        return s.str();
    }

    static Person init(const std::vector<std::string> &_t)
    {
        return Person(_t[0], std::stoi(_t[1]), std::stoi(_t[2]));
    }
};

int main()
{
    std::vector<Person> m;
    Person p1;

    for (int i = 0; i < 40; i++)
    {
        m.push_back(p1);
    }

    std::vector<std::string> q;
    q.push_back("name");
    q.push_back("age");
    q.push_back("id");

    csvlib::CSV<Person>::write("../tests/example1.csv", m, ",", q);

    std::vector<Person> rs_p(csvlib::CSV<Person>::read("../tests/example1.csv", ","));
    for (auto x : rs_p)
    {
        std::cout << x.to_string(",") << std::endl;
    }
    std::cout << std::endl;
    std::cout << rs_p[0].name << " " << rs_p[0].age << " " << rs_p[0].id << std::endl;

    return 0;
}