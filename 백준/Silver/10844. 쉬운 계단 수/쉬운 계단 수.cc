#include <iostream>

using namespace std;

int main()
{
	long long dp[101][10] = {0,}, n = 0, answer = 0;

	cin >> n;
	
	dp[1][0] = 0;
	
	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;
	
	for (int i = 2; i <= n; i++)
	{
		for(int j = 0; j <= 9; j++) 
		{ 
			if (j == 0) dp[i][j] = dp[i - 1][j + 1] % 1000000000;
			else if (j == 9) dp[i][j] = dp[i - 1][j - 1] % 1000000000;
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000; 
		}
	}

	for (int i = 0; i <= 9; i++)
	{
		answer += dp[n][i];
	}

	cout << answer % 1000000000;

	return 0;
}