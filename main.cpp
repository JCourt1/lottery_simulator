#include <iostream>
#include <iomanip>
#include <cstdio>
#include <sstream>
#include <time.h>
#include <map>
#include <random>
#include <algorithm>
#include <iterator>

#include "PrizeProbabilities.h"
#include "LotteryLogic.h"

#define MACRO_VARIABLE_TO_STRING(Variable) (void(Variable),#Variable)

int main(int argc, char** argv) {
    // used for putting commas to separate thousands
    std::locale loc("");
    std::cout << loc.name();
    setlocale(LC_NUMERIC, "");


    // parse cmd line arguments
    if (argc < 2) {
        printf("Program file name: %s\n", argv[0]);
        printf("You must specify the number of times to play as a second argument.\n");
        return 1;
    }


    long long int x = 12345434543;
    printf("size of long long int is: %lu", sizeof(x));

    std::istringstream iss(argv[1]);
    int num_tries;
    iss >> num_tries;

    if (iss.fail()) {
        printf("command line args not correctly entered\n");
        return 1;
    }

    printf("\n\n\n");
    int winnings = play_lottery(num_tries);

    printf("\n\n\n");

    int total_spent = num_tries * 250;

    try {
        std::cout.imbue(std::locale(""));
        std::cout << "Spent: " << std::showbase << std::put_money(total_spent) << std::endl;
        std::cout << "Earned: " << std::put_money(winnings) << std::endl;
        std::cout << "Net balance: " << std::put_money(winnings - total_spent) << std::endl;
    } catch (const std::exception &ex) {
        std::cerr << ex.what() << std::endl;
    }

    return 0;
}