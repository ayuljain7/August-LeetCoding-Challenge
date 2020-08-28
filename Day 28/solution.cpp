// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
       int rand40=40;
        while(rand40>=40)
        {
	    //This distribution gives equal probability of each number
	    // There is only a single way to get a number from 0 to 48 therefore it's a uniform distribution
            rand40=(rand7()-1)*7+rand7()-1;
        }
	// On an average this function calls rand7() 2.45 times .
        return rand40%10+1;
    }
};