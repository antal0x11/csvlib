
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

namespace csvlib
{
    template <class T>
    struct CSV
    {

        /**
         * @brief           Description of csv write function.
         *
         * @tparam T        A vector containing the data structs.
         * @param file_name The name of the file or the path to save the csv output.
         * @param data      A vector containing the structs to write in the csv.
         * @param delimeter The delimeter of the csv file.
         * @param headers   A vector of strings containing the headers of the file.
         * @return int      Returns 0 on success or -1 if it fails.
         *
         * In order to work the struct has to have a method with the following signature
         * { std::string to_string(const std::string &delimeter) const }
         */
        static int write(const std::string &file_name, const std::vector<T> &data, const std::string &delimeter, const std::vector<std::string> &headers)
        {
            std::ofstream file;
            file.open(file_name);
            if (!file.is_open())
            {
                return -1;
            }

            try
            {
                int _size = headers.size();
                if (_size <= 0)
                {
                    throw("headers size is invalid.");
                }

                std::string _s = "";

                for (const std::string &_t : headers)
                {
                    _s.append(_t);
                    if (_size != 1)
                    {
                        _s.append(delimeter);
                    }
                    else
                    {
                        continue;
                    }
                    _size--;
                }

                file << _s << std::endl;
            }
            catch (char const *msg)
            {
                std::cerr << msg << std::endl;
                return -1;
            }

            try
            {
                if (data.size() <= 0)
                {
                    throw("Data block size is invalid.");
                }
            }
            catch (char const *msg)
            {
                std::cerr << msg << std::endl;
                return -1;
            }

            for (const T &x : data)
            {
                file << x.to_string(delimeter) << std::endl;
            }

            file.close();

            return 0;
        }

        /**
         * @brief                 Reading a csv file and storing the extracted data to vector.
         *
         * @param file_name       The name of the file or the path to read from.
         * @param delimeter       The delimeter of the csv file.
         * @return std::vector<T> Returns a vector with struct of type T.
         */
        static std::vector<T> read(const std::string &file_name, const std::string &delimeter)
        {
            std::ifstream file;
            std::vector<T> _res;
            std::string line;

            file.open(file_name);
            if (!file.is_open())
            {
                throw("Error opening file.");
            }

            int _init = 0;

            while (std::getline(file, line))
            {
                if (_init == 0)
                {
                    _init++;
                    continue;
                }
                _res.push_back(from_string(delimeter, line));
            }

            file.close();

            return _res;
        }

        /**
         * @brief           Converts a string to a struct using the init method of the struct.
         *
         * @param delimeter The delimeter of the string represantation of the struct.
         * @param t         The string represanting the struct.
         * @return T        Returns the entity of the given string.
         */
        static T from_string(const std::string &delimeter, const std::string &t)
        {
            std::vector<std::string> tokens;
            std::string token;
            std::stringstream stream(t);
            char _d = delimeter[0];

            while (std::getline(stream, token, _d))
            {
                tokens.push_back(token);
            }

            return T::init(tokens);
        }
    };
}
