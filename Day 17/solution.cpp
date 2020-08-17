class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int i=0;
        int candy_given=1;
        vector<int> Candy(num_people,0);
        while(candies>0)
        {
            if(i==num_people)
            {
               i=0; 
            }
            if(candy_given>candies)
            {
                Candy[i]+=candies;
            }
            else
            {
                Candy[i]+=candy_given;
            }
            candies=candies-candy_given;
            candy_given++;
            i++;
        }
        return Candy;
    }
};