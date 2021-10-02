//Coin Change
//Rutuja Bhure (rbb-99)
//Approach : Dynamic approach where the array, table, stores minimum number of coins
//required to form the sum i (range : [1,amount])
//so that the values can be reused

//Time Complexity : O(m*amount) where m -> size of coins array
//Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int> &coins, int amount)
{   
    //table[i] stores the minimum number of coins
	//required for i value ergo table[amount] will have the result
    int *table = new int[amount + 1];

    //base case (if given value of amount is 0)
    table[0] = 0;

    //initialize all table values as infinite
    for (int i = 1; i <= amount; i++)
        table[i] = INT_MAX;

    //compute minimum coins required for all values from 1 to amount
    for (int i = 1; i <= amount; i++)
    {
        for (size_t j = 0; j < coins.size(); j++)
        {
            if (coins[j] <= i)
            {
                int intermediate_res = table[i - coins[j]];
                if (intermediate_res != INT_MAX && intermediate_res + 1 < table[i])
                    table[i] = intermediate_res + 1;
            }
        }
    }
    if (table[amount] == INT_MAX)
        return -1;

    return table[amount];
}

//driver code
int main()
{   
    //test case 1
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout<<coinChange(coins, amount)<<endl;  //3
    //test case 2
    coins = {2};
    amount = 3;
    cout<<coinChange(coins, amount)<<endl;  //-1
    //test case 3
    coins = {1};
    amount = 0;
    cout<<coinChange(coins, amount)<<endl;  //0
    //test case 4
    coins = {1};
    amount = 1;
    cout<<coinChange(coins, amount)<<endl;  //1
    //test case 5
    coins = {1};
    amount = 2;
    cout<<coinChange(coins, amount)<<endl;  //2
    return 0;
}   

