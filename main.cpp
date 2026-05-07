#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "Board/Board.h"

int main() {
    Board board;
    int choice;

    do
    {
        std::cout << std::endl << "=== A Bug's Life Simulation Menu ===" << std::endl;
        std::cout << "1. Initialize Bug Board (load data from file)" << std::endl;
        std::cout << "2. Display all Bugs" << std::endl;
        std::cout << "3. Find a Bug (given an id)" << std::endl;
        std::cout << "4. Tap the Bug Board (move all, then fight/eat)" << std::endl;
        std::cout << "5. Display Life History of all Bugs" << std::endl;
        std::cout << "6. Display all Cells listing their Bugs" << std::endl;
        std::cout << "7. Run simulation" << std::endl;
        std::cout << "8. Exit (write Life History to file)" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;


        switch (choice)
        {
            case 1: {
                std::string filename = "bugs.txt";
                board.loadBugs(filename);
                std::cout << "\nPress Enter to continue...";
                std::cin.ignore();
                std::cin.get();
                break;
            }

            case 2:
                board.displayAllBugs();
                std::cout << "\nPress Enter to continue...";
                std::cin.ignore();
                std::cin.get();
                break;

            case 3: {
                int id;
                std::cout << "Enter bug ID: ";
                std::cin >> id;
                std::cout << board.findBug(id) << std::endl;
                std::cout << "\nPress Enter to continue...";
                std::cin.ignore();
                std::cin.get();
                break;
            }

            case 4:
                board.tapBoard();
                std::cout << "\nPress Enter to continue...";
                std::cin.ignore();
                std::cin.get();
                break;

            case 5:
                board.displayLifeHistory();
                std::cout << "\nPress Enter to continue...";
                std::cin.ignore();
                std::cin.get();
                break;

            case 6:
                board.displayAllCells();
                std::cout << "\nPress Enter to continue...";
                std::cin.ignore();
                std::cin.get();
                break;

            case 7: {
                std::cout << "Running simulation..." << std::endl;

                while (board.getAliveBugCount() > 1)
                {
                    board.tapBoard();
                    board.displayAllBugs();
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                }

                Bug* winner = board.getLastAliveBug();
                if (winner != nullptr)
                {
                    std::cout << "\n=== Simulation Complete! ===" << std::endl;
                    std::cout << "Winner: Bug " << winner->getId() << " is the Last Bug Standing!" << std::endl;
                    std::cout << "\nPress Enter to continue...";
                    std::cin.ignore();
                    std::cin.get();
                } else {
                    std::cout << "No bugs remaining." << std::endl;
                    std::cout << "\nPress Enter to continue...";
                    std::cin.ignore();
                    std::cin.get();
                }
                break;
            }

            case 8:
                std::cout << "Exiting - writing life history to file..." << std::endl;
                board.writeLifeHistoryToFile();
                std::cout << "\nPress Enter to continue...";
                std::cin.ignore();
                std::cin.get();
                break;

            default:
                std::cout << "Invalid choice. Please try again" << std::endl;
        }

    } while (choice != 8);

    return 0;
}
