#include<bits/stdc++.h>
using namespace std;
const int N = 2510;
int dp[10010]; // cause max value of amount = 10^4

int func(int amount, vector<int>& coins){
	if(amount == 0) return 0;
	if(dp[amount] != -1) return dp[amount];

	int ans = INT_MAX;
   for(int coin: coins){
   	   if(amount - coin >= 0)
   	  ans = min(ans + 0LL, func(amount - coin, coins) + 1LL); // because if amount is int max then it will overflow
   }
   return dp[amount] = ans;
}

int coinChange(vector<int>& coins, int amount){
	memset(dp,-1, sizeof(dp));
    int ans = func(amount, coins);
    return ans == INT_MAX ? -1 : ans; // if answer is int_max then return -1

}

int main(){
	vector<int> coins = {2};
	cout << coinChange(coins, 3);
}
