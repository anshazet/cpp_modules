/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <ashalagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:14:18 by ashalagi          #+#    #+#             */
/*   Updated: 2023/12/15 10:28:40 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char *argv[])
{
    if (argc != 4)
	{
        std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    // Open file for reading
    std::ifstream file(filename.c_str()); // c_str() to convert to const char*
    if (!file.is_open())
	{
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }

    // Read content into a string
    std::ostringstream ss;
    ss << file.rdbuf();
    std::string content = ss.str();
    file.close();

    // Find and replace occurrences of s1 with s2
    size_t pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos)
	{
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }

    // Write modified content to new file
    std::ofstream outFile((filename + ".replace").c_str());
    if (!outFile.is_open())
	{
        std::cerr << "Error creating output file" << std::endl;
        return 1;
    }
    outFile << content;
    outFile.close();

    std::cout << "File written successfully!" << std::endl;

    return 0;
}

/*
std::cerr: This stands for "console error", and it's a standard output
stream for errors. The primary difference from std::cout is that std::cerr
is unbuffered. This means that each insertion to std::cerr will be written
immediately to the console, which is desirable for error messages because
you would want to see errors immediately.
*/