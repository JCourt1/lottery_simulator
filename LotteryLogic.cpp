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

long long int play_lottery(int num_tickets) {

    // setting up random number generation (standard code )
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    //std::mt19937 rng(time(NULL));    // seeding with current time
    std::uniform_int_distribution<int> uni(min,max); // guaranteed unbiased

    long long int prize_pot = 0;
    long long int current_prize = 0;

    for (int i = 0; i < num_tickets; ++i) {
        auto random_integer = uni(rng);
        // printf("the random integer is %'d\n", random_integer);
        current_prize = get_prize_money_won(random_integer);
        prize_pot += current_prize;
    }

    return prize_pot;
}


long long int get_prize_money_won(int random_integer) {

    for (int prize_odds : priority_list) {
        // if the prize's odds divides into the random number cleanly, that prize has been won.
        if (random_integer % prize_odds == 0) {
            // printf("YES! %s\n", MACRO_VARIABLE_TO_STRING(prize_odds));
            // printf("Here's your money: %d\n", prize_money[prize_odds]);

            // std::cout << "You won prize " << name_map[prize_odds] << std::endl;

            // means -> if prize_odds in big_wins
            if (std::find(std::begin(big_wins), std::end(big_wins), prize_odds) != std::end(big_wins)) {
                printf("You won prize %s !\n", name_map.at(prize_odds).c_str());
                printf("Here's your money: %llu\n", prize_money.at(prize_odds));
            }

            return prize_money.at(prize_odds);
        }
    }

    // if no matches, return 0
    return 0;
}