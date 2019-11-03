#include "PrizeProbabilities.h"

const int priority_list[] = {
        MATCH_5_2_LUCKY, MATCH_5_1_LUCKY, MATCH_5, MATCH_4_2_LUCKY, MATCH_4_1_LUCKY, MATCH_4, MATCH_3_2_LUCKY,
        MATCH_3_1_LUCKY,
        MATCH_2_2_LUCKY, // comes before 3 in terms of likelihood
        MATCH_3,
        MATCH_1_2_LUCKY, // comes before 2_1 in terms of likelihood
        MATCH_2_1_LUCKY, MATCH_2
};

const int big_wins[] = {MATCH_5_2_LUCKY};  //, MATCH_5_1_LUCKY};