#ifndef PRIZE_PROBABILITIES_H
#define PRIZE_PROBABILITIES_H

#include <string>
#include <iostream>
#include <sstream>
#include <map>

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


const std::map<int, std::string> name_map = {
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

extern const int priority_list[13];

// mapping prize name to amount (in pennies, using this data: https://www.euro-millions.com/odds-of-winning)
const std::map<int, long long int> prize_money = {
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



const int min = 0;
const int max = MATCH_5_2_LUCKY + 1;
extern const int big_wins[1];  //, MATCH_5_1_LUCKY};


#endif