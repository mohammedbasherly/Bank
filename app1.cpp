#include <iostream>
using namespace std;

#include "/home/hazard/vs code/lib/clients_data.h"
#include "/home/hazard/vs code/lib/matrix_lib.h"
#include "/home/hazard/vs code/lib/global_funcs.h"

using namespace clients_data;
using namespace matrix_lib;
using namespace global_funcs;

enum enOption {
    clientList = 1,
    newClient = 2,
    deleteClient = 3,
    updateClient = 4,
    findClient = 5,
    exitProgram = 6
};

void showMainMenuScreen()
{
    system("clear");
    cout << " ===============================================\n";
    cout << "\t\tMain Menu Screen\n";
    cout << " ===============================================\n";
    cout << "\t" << "[1] Show Clients List\n";
    cout << "\t" << "[2] Add New Client\n";
    cout << "\t" << "[3] Delete Client\n";
    cout << "\t" << "[4] Update Client Info\n";
    cout << "\t" << "[5] Find Client\n";
    cout << "\t" << "[6] Exit\n";
    cout << " ===============================================\n";
}

void showScreenHeader(enOption option)
{
    system("clear");
    switch (option)
    {
    case enOption::clientList:
        cout << " ===============================================\n";
        cout << "\t\tClients List Screen\n";
        cout << " ===============================================\n";
        return;
    case enOption::newClient:
        cout << " ===============================================\n";
        cout << "\t\tAdd New Client Screen\n";
        cout << " ===============================================\n";
        return;
    case enOption::deleteClient:
        cout << " ===============================================\n";
        cout << "\t\tDelete Client Screen\n";
        cout << " ===============================================\n";
        return;
    case enOption::updateClient:
        cout << " ===============================================\n";
        cout << "\t\tUpdate Client Screen\n";
        cout << " ===============================================\n";
        return;
    case enOption::findClient:
        cout << " ===============================================\n";
        cout << "\t\tFind Client Screen\n";
        cout << " ===============================================\n";
        return;
    case enOption::exitProgram:
        cout << " ===============================================\n";
        cout << "\t\tExit Program Screen\n";
        cout << " ===============================================\n";
        return;
    default:
        break;
    }
}

void showScreenBottom()
{
    cout << "\nPress any key to go back to [Main Menu Screen] ...";
    cin.ignore();
    cin.get();
}

void clientListScreen(string filePath, string delim = "#//#")
{
    showScreenHeader(enOption::clientList);
    showAllClients(filePath, delim);
    showScreenBottom();
}

void newClientScreen(string filePath, string delim = "#//#")
{
    cin.ignore();
    showScreenHeader(enOption::newClient);
    addNewClients(filePath, delim);
    showScreenBottom();
}

void deleteClientScreen(string filePath, string delim = "#//#")
{
    cin.ignore();
    showScreenHeader(enOption::deleteClient);
    string accountNumber = readString("Enter Account Number: ");
    deleteClientByAccountNumber(filePath, accountNumber, delim);
    showScreenBottom();
}

void updateClientScreen(string filePath, string delim = "#//#")
{
    cin.ignore();
    showScreenHeader(enOption::updateClient);
    string accountNumber = readString("Enter Account Number: ");
    updateClientData(filePath, accountNumber, delim);
    showScreenBottom();
}

void findClientScreen(string filePath, string delim = "#//#")
{
    cin.ignore();
    showScreenHeader(enOption::findClient);
    string accountNumber = readString("Enter Account Number: ");
    printClientDataCardByAccountNumber(filePath, accountNumber, delim);
    showScreenBottom();
}

void exitProgramScreen()
{
    showScreenHeader(enOption::exitProgram);
    cout << "Press any key to end the program...";
    cin.ignore();
    cin.get();
}

void startScreen(enOption option, string filePath, string delim = "#//#")
{
    switch (option)
    {
    case enOption::clientList:
        clientListScreen(filePath, delim);
        return;
    case enOption::newClient:
        newClientScreen(filePath, delim);
        return;
    case enOption::deleteClient:
        deleteClientScreen(filePath, delim);
        return;
    case enOption::updateClient:
        updateClientScreen(filePath, delim);
        return;
    case enOption::findClient:
        findClientScreen(filePath, delim);
        return;
    case enOption::exitProgram:
        exitProgramScreen();
        return;
    default:
        break;
    }
}

void startProgram(string filePath, string delim = "#//#")
{
    enOption option;
    do
    {
        showMainMenuScreen();
        option = (enOption) readIntNumberInRange(1, 6, "Choose an option? [1-6]? ");
        startScreen(option, filePath, delim);
    } while (option != enOption::exitProgram);
    
}

int main()
{
    string filePath = "Bank_Clients.txt";
    startProgram(filePath);

    return 0;
}