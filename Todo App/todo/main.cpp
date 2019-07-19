#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
    if (argc == 1) {
        std::cout << "Command Line Todo application\n"
                     "=============================\n"
                     "\n"
                     "Command line arguments:\n"
                     "    -l   Lists all the tasks\n"
                     "    -a   Adds a new task\n"
                     "    -r   Removes an task\n"
                     "    -c   Completes an task" << std::endl;
    }

    if (argc == 1) {
        std::cout << "usage information" << std::endl;
        return 0;
    }

    if (argc == 2) {
        std::string argument(argv[1]);
        if (argument == "-l") {
            std::ifstream taskText("../task.txt");
            if (taskText.is_open()) {
                std::string tasks;
                int taskCounter = 0;
                bool fileIsEmpty = true;
                while (getline(taskText, tasks)) {
                    taskCounter++;
                    std::cout << taskCounter << " - " << tasks << std::endl;
                    fileIsEmpty = false;
                }
                if (fileIsEmpty) {
                    std::cout << "No todos for today! :)";

                }

            }

            return 0;

        }


    }else if (argc == 3) {
        std::string argument(argv[1]);
        std::string argument2(argv[2]);
        if (argument == "-a") {
            std::ofstream todoTask("../task.txt", std::ios::app);
            std::string askedInput;
            if (todoTask.is_open()) {
                todoTask << std::endl;

            }else{
                todoTask << std::endl;
                try{
                    throw  "no task provided";
                }
                catch(std::string e){
                    std::cout << "Unable to add: " << e << std::endl;
                }
                return 0;
            }

        }
    } else {
        std::cout << "not supported argument" << std::endl;
        return 2;
    }


    return 0;
}
