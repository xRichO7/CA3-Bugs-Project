#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "Board.h"

int main() {
    Board board;
    int choice;

    do 
    {
        std::cout <<std::endl << "A Bug's Life Simulation Menu" << std::endl;
        std::cout << "1. Load bugs from file" << std::endl;
        std::cout << "2. Display all the bugs" << std::endl;
        std::cout << "3. Find a bug by ID" << std::endl;
        std::cout << "4. Tap the board" << std::endl;
        std::cout << "5. Display life history of all bugs" << std::endl;
        std::cout << "6. Display all bugs (sorted by ID)" << std::endl;
        std::cout << "7. Run simulation" << std::endl;
        std::cout << "8. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) 
        {

            case 1: {
                std::string filename;
                std::cout << "Enter filename: ";
                std::cin >> filename;
                board.load(filename);
                break;
            }

            case 2:
                board.displayAllBugs();
                break;

            case 3: {
                int id;
                std::cout << "Enter bug ID: ";
                std::cin >> id;
                std::cout << board.findBug(id) << std::endl;
                break;
            }

            case 4:
                board.tap();
                break;

            case 5:
                board.displayLifeHistory();
                break;

            case 6:
                board.displayAllBugs(); 

            case 7: {

                std::cout << "Running simulation..." << std::endl;

                while (board.getAliveBugCount() > 1) 
                {
                    board.tap();

                    std::this_thread::sleep_for(std::chrono::seconds(1));
                }

                Bug* winner = board.getLastAliveBug();
                if (winner != nullptr)
                 {
                    std::cout << "Simulation complete. Winner Bug ID: "
                              << winner->getId() << std::endl;
                } else {
                    std::cout << "No bugs remaining." << std::endl;
                }

                break;
            }

            case 8:
                std::cout << "Exiting..." << std::endl;
                break;

            default:
                std::cout << "Invalid choice. Please Try again" << std::endl;
        }

    } while (choice != 8);

    return 0;
}