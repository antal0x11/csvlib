
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

namespace csv
{

    /**
     * @brief Description of csv write function.
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
    template <class T>
    int write(const std::string &file_name, const std::vector<T> &data, const std::string &delimeter, const std::vector<std::string> &headers)
    {
        std::ofstream file;
        file.open(file_name);

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

    void read()
    {
        // TODO
    }
}
