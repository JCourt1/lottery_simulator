#include <iostream>
#include <iomanip>
#include <cstdio>
#include <sstream>
#include <time.h>
#include <map>
#include <random>
#include <algorithm>
#include <iterator>

#include "boost/program_options.hpp"

#include "PrizeProbabilities.h"
#include "LotteryLogic.h"

#define MACRO_VARIABLE_TO_STRING(Variable) (void(Variable),#Variable)

int main(int argc, char** argv) {

    namespace po = boost::program_options;
    po::options_description desc("Options");
    desc.add_options()
        ("help", "Outputs this help message")
        ("num_tickets", po::value<int>(), "amount of tickets to buy")
    ;

    po::positional_options_description p;
    p.add("num_tickets", 1);

    po::variables_map variables;
    po::store(po::command_line_parser(argc, argv).options(desc).positional(p).run(), variables);
    po::notify(variables);

    if (variables.count("help")) {
        std::cout << desc << "\n";
        return 1;
    }

    int num_tickets;

    if (variables.count("num_tickets")) {
        num_tickets = variables["num_tickets"].as<int>();
    } else {
        std::cout << "Number of tickets was not specified.\n";
        return 1;
    }

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

//    std::istringstream iss(argv[1]);
//    int num_tickets;
//    iss >> num_tickets;
//
//    if (iss.fail()) {
//        printf("command line args not correctly entered\n");
//        return 1;
//    }

    int winnings = play_lottery(num_tickets);

    int total_spent = num_tickets * 250;

    try {
        std::cout << "\n";
        std::cout.imbue(std::locale(""));
        std::cout << "Spent: " << std::showbase << std::put_money(total_spent) << std::endl;
        std::cout << "Earned: " << std::put_money(winnings) << std::endl;
        std::cout << "Net balance: " << std::put_money(winnings - total_spent) << std::endl;
    } catch (const std::exception &ex) {
        std::cerr << ex.what() << std::endl;
    }

    return 0;
}