#include "MenuWallet.hpp"

MenuWallet::MenuWallet(WalletController *controller)
    : walletController(controller) {}

void MenuWallet::display()
{
    int option = -1;

    while (true)
    {
        system("cls");

        printInfo("\n=== WALLET MANAGEMENT ===");
        std::cout << "1 - Add new wallet\n"
                  << "2 - Retrieve wallet by ID\n"
                  << "3 - Edit existing wallet\n"
                  << "4 - Delete wallet\n"
                  << "0 - Back\n";

        if (!readOption(option))
        {
            waitForReturn();
            continue;
        }

        switch (option)
        {
        case 1:
            optionAddWallet();
            break;
        case 2:
            optionRetrieveWallet();
            break;
        case 3:
            optionEditWallet();
            break;
        case 4:
            optionDeleteWallet();
            break;
        case 0:
            return;
        default:
            printError("Invalid option, please choose between 0 and 4.");
            break;
        }

        waitForReturn();
    }
}

void MenuWallet::optionAddWallet()
{
    std::string name, broker;

    printInfo("\nCreate Wallet");

    std::cout << "Enter the owner's name: ";
    std::getline(std::cin, name);

    std::cout << "Enter the broker: ";
    std::getline(std::cin, broker);

    int id = walletController->createWallet(name, broker);
    printSuccess("Wallet created successfully! Generated ID: " + std::to_string(id));
}

void MenuWallet::optionRetrieveWallet()
{
    if (!checkWalletsAvailable(walletController))
        return;

    printInfo("\nRetrieve Wallet");
    int walletId = readWalletId();

    if (walletId == -1)
        return;

    auto wallet = walletController->getWallet(walletId);

    if (wallet) {
        displayWallet(*wallet);
    } else {
        printError("Wallet not found.");
    }
}

void MenuWallet::optionEditWallet()
{
    if (!checkWalletsAvailable(walletController))
        return;

    printInfo("\nEdit Wallet");
    int walletId = readWalletId();

    if (walletId == -1)
        return;

    auto wallet = walletController->getWallet(walletId);

    if (!wallet) {
        printError("Wallet not found.");
        return;
    }

    std::string newName, newBroker;

    std::cout << "\nCurrent name: " << wallet->getOwnerName() << "\n";
    std::cout << "Enter new owner name (or leave blank to keep unchanged): ";
    std::getline(std::cin, newName);
    if (!newName.empty())
        wallet->setOwnerName(newName);

    std::cout << "Current broker: " << wallet->getBroker() << "\n";
    std::cout << "Enter new broker (or leave blank to keep unchanged): ";
    std::getline(std::cin, newBroker);
    if (!newBroker.empty())
        wallet->setBroker(newBroker);

    if (walletController->updateWallet(*wallet)) {
        printSuccess("Wallet updated successfully.");
        printInfo("New information for wallet:");
        displayWallet(*wallet);
    } else {
        printError("Failed to update wallet.");
    }
}

void MenuWallet::optionDeleteWallet()
{
    if (!checkWalletsAvailable(walletController))
        return;

    printInfo("\nDelete Wallet");
    int walletId = readWalletId();

    if (walletId == -1)
        return;

    if (walletController->deleteWallet(walletId)) {
        printSuccess("Wallet deleted successfully.");
    } else {
        printError("Wallet not found.");
    }
}
