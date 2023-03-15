#include<bits/stdc++.h>
using namespace std;
const int N = 2510;
int dp[310][10010]; 

int func1(int ind,int amount, vector<int>& coins){
	if(amount == 0) return 1;
	if(ind < 0) return 0;
	if(dp[ind][amount] != -1) return dp[ind][amount];

	int ways = 0;
	for(int coin_amount = 0; coin_amount <= amount; coin_amount += coins[ind]) //coin_amount <= amount because if it is only < it will never become 0
   {
   	  ways +=  func1(ind - 1, amount - coin_amount, coins); // because if amount is int max then it will overflow
   }
   return dp[ind][amount] = ways;
}

int coinChange(vector<int>& coins, int amount){
	memset(dp,-1, sizeof(dp));
    return func1(coins.size()- 1, amount, coins);  
}

int main(){
	vector<int> coins = {1,2,5};
	cout << coinChange(coins, 5);
}
