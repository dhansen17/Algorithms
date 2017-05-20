#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//int maximum(int a, int b) {
//	return a > b;
//}

int main()
{
	long long testCases;
	long long monster;
	vector<long long> coins;
	vector<long long> DP;
	vector<long long> ans;
	//cout << "entering test cases: ";

	cin >> testCases;

	for (long long i = 0; i < testCases; i++)
	{
		//cout << "Now give me the number of monsters: ";
		cin >> monster;
		long long temp;

		for (long long j = 0; j < monster; j++)
		{
			cin >> temp;
			coins.push_back(temp);
		}
		for (long long i = 0; i < coins.size(); i++)
		{
			if (i == 0)
				DP.push_back(coins[0]);
			else if (i == 1)
				DP.push_back(max(coins[0], coins[1]));
			else
			{
				int value = coins[i];
				DP.push_back(max(DP[i - 1], DP[i - 2] + value));
			}
		}
			long long maxcoin = 0;

			for (long long l = 0; l < DP.size(); l++)
			{
				if (DP[l] > maxcoin)
					maxcoin = DP[l];
			}
			ans.push_back(maxcoin);
			DP.clear();
			coins.clear();

		}


	for (int b = 0; b < ans.size(); b++)
	{
		cout << "Case " << b+1 << ": " << ans[b] << "\n";
	}

	}
