#include <iostream>

int main (int ac, char **av)
{
    if (ac > 1)
    {
        std::string msg;
       for (int i = 1; i < ac; i++)
        {
            msg.append(av[i]);
//            if (i < ac -1)
//            {
//                msg += " "; // Add a space between arguments, except for the last one.
//            }
        }
        std::transform(msg.begin(), msg.end(), msg.begin(), ::toupper);
        std::cout << msg << std::endl;
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
}
/*
// Include necessary header for input and output operations in C++
#include <iostream>

// The main function is the entry point of the program, and it takes command-line arguments.
int main(int ac, char **av)
{
    // Check if there are more than 1 command-line arguments (excluding the program name itself).
    if (ac > 1)
    {
        // Declare a string variable to store the concatenated and transformed message.
        std::string msg;

        // Iterate through the command-line arguments starting from the second argument (av[1]).
        for (int i = 1; i < ac; i++)
        {
            // Append the current argument to the 'msg' string.
            msg.append(av[i]);

            // Add a space between arguments, except for the last one.
            if (i < ac - 1)
            {
                msg += " "; // Add a space between arguments, except for the last one.
            }
        }

        // Convert the entire 'msg' string to uppercase using std::transform.
        std::transform(msg.begin(), msg.end(), msg.begin(), ::toupper);

        // Print the transformed message to the standard output (console).
        std::cout << msg << std::endl;
    }
    else
    {
        // If there are no command-line arguments (only the program name), print a specific message.
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }

    // Return 0 to indicate successful program execution.
    return 0;
}
*/

/*
std::transform is a function provided by the C++ Standard Library that performs
an operation on each element of a container (like a vector, string, or array)
and stores the results in another container.

Syntax:std::transform(begin1, end1, begin2, function)
begin1 and end1 specify the range of elements to transform in the source container.
begin2 is an iterator specifying the beginning of the destination container.
function is a function or functor (a class or object with the () operator overloaded)
that defines the operation to be applied to each element.

Example: std::transform(myVector.begin(), myVector.end(), myVector2.begin(), ::toupper);
This would transform all elements in myVector to uppercase and store the results
in myVector2.

std::count is another function from the C++ Standard Library that counts the number
of occurrences of a specific value in a container.

Syntax: std::count(begin, end, value)
begin and end specify the range of elements to search for the given value.
value is the element you want to count.

Example: int count = std::count(myVector.begin(), myVector.end(), 42); This would
count the number of occurrences of the value 42 in the myVector.

<< (Stream Output Operator):
<< is used in C++ for output operations. It's known as the stream insertion operator.
It is typically used with std::cout (the standard output stream) to output data
to the console.

Example: std::cout << "Hello, World!" << std::endl;
This code will print the text "Hello, World!" to the console.
*/