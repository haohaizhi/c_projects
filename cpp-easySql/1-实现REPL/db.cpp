#include <iostream>


class DB {
public:
    void print_prompt();
    bool parse_meta_command(std::string command);
    void start();
};


void DB::print_prompt()
{
    std::cout << "db > ";
}




bool DB::parse_meta_command(std::string command)
{
    if (command == ".exit")
    {
        std::cout << "Bye!" << std::endl;
        exit(EXIT_SUCCESS);
    }
    else
    {
        std::cout << "Unrecognized command: " << command << std::endl;
        return true;
    }
    return false;
}


void DB::start()
{
    while (true)
    {
        print_prompt();
        
        std::string input_line;
        std::getline(std::cin, input_line);




        if (parse_meta_command(input_line))
        {
            continue;
        }
    }
}


int main()
{
    DB db;
    db.start();
    return 0;
}