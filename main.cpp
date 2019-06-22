#include <iostream>
#include <iomanip>
#include <cstdio>
#include <sstream>
#include <time.h>
#include <map>
#include <random>
#include <algorithm>
#include <iterator>


#define MACRO_VARIABLE_TO_STRING(Variable) (void(Variable),#Variable)

long long int play_lottery(int num_tickets);
long long int get_prize_money_won(int random_integer);



const int MATCH_5_2_LUCKY = 139838160;
const int MATCH_5_1_LUCKY = 6991908;
const int MATCH_5 = 3107515;
const int MATCH_4_2_LUCKY = 621503;
const int MATCH_4_1_LUCKY = 31075;
const int MATCH_4 = 13811;
const int MATCH_3_2_LUCKY = 14125;
const int MATCH_3_1_LUCKY = 706;
const int MATCH_3 = 314;
const int MATCH_2_2_LUCKY = 985;
const int MATCH_2_1_LUCKY = 49;
const int MATCH_2 = 22;
const int MATCH_1_2_LUCKY = 188;


std::map<int, std::string> name_map = {
        {MATCH_5_2_LUCKY, "MATCH_5_2_LUCKY"},
        {MATCH_5_1_LUCKY, "MATCH_5_1_LUCKY"},
        {MATCH_5, "MATCH_5"},
        {MATCH_4_2_LUCKY, "MATCH_4_2_LUCKY"},
        {MATCH_4_1_LUCKY, "MATCH_4_1_LUCKY"},
        {MATCH_4, "MATCH_4"},
        {MATCH_3_2_LUCKY, "MATCH_3_2_LUCKY"},
        {MATCH_3_1_LUCKY, "MATCH_3_1_LUCKY"},
        {MATCH_3, "MATCH_3"},
        {MATCH_2_2_LUCKY, "MATCH_2_2_LUCKY"},
        {MATCH_2_1_LUCKY, "MATCH_2_1_LUCKY"},
        {MATCH_2, "MATCH_2"},
        {MATCH_1_2_LUCKY, "MATCH_1_2_LUCKY"},
};

const int priority_list[] = {
        MATCH_5_2_LUCKY, MATCH_5_1_LUCKY, MATCH_5, MATCH_4_2_LUCKY, MATCH_4_1_LUCKY, MATCH_4, MATCH_3_2_LUCKY,
        MATCH_3_1_LUCKY,
        MATCH_2_2_LUCKY, // comes before 3 in terms of likelihood
        MATCH_3,
        MATCH_1_2_LUCKY, // comes before 2_1 in terms of likelihood
        MATCH_2_1_LUCKY, MATCH_2
};

// mapping prize name to amount (in pennies, using this data: https://www.euro-millions.com/odds-of-winning)
std::map<int, long long int> prize_money = {
    {MATCH_5_2_LUCKY, 4218833600},
    {MATCH_5_1_LUCKY, 29688600},
    {MATCH_5, 5022400},
    {MATCH_4_2_LUCKY, 298100},
    {MATCH_4_1_LUCKY, 13600},
    {MATCH_4, 6200},
    {MATCH_3_2_LUCKY, 5300},
    {MATCH_3_1_LUCKY, 1000},
    {MATCH_3, 800},
    {MATCH_2_2_LUCKY, 1300},
    {MATCH_2_1_LUCKY, 500},
    {MATCH_2, 300},
    {MATCH_1_2_LUCKY, 700},
};



int min = 0;
int max = MATCH_5_2_LUCKY + 1;
int big_wins[] = {MATCH_5_2_LUCKY};  //, MATCH_5_1_LUCKY};



int main(int argc, char** argv) {
    // used for putting commas to separate thousands
    std::locale loc("");
    std::cout << loc.name();
    setlocale(LC_NUMERIC, "");

    printf("%d\n", argc);

    if (argc < 2) {
        printf("You must specify the number of times to play.");
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
                printf("You won prize %s !\n", name_map[prize_odds].c_str());
                printf("Here's your money: %llu\n", prize_money[prize_odds]);
            }

            return prize_money[prize_odds];
        }
    }

    // if no matches, return 0
    return 0;
}