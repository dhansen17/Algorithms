#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long tailRecurtion(long long numMon, long long prev, long long valuemax)
{
	long long coins;
	long long temp;
	if (numMon == 0)
		return valuemax;
	cin >> coins;
	temp = valuemax;
	valuemax = max(valuemax, prev + coins);
	prev = temp;
	tailRecurtion(numMon - 1, prev, valuemax);
	
}

int main()
{
	long long testCases;
	long long monster;
	vector<long long> ans;
	//cout << "entering test cases: ";

	cin >> testCases;

	for (long long i = 0; i < testCases; i++)
	{
		cin >> monster;
		ans.push_back(tailRecurtion(monster, 0, 0));
	}
	for (long long i = 0; i < ans.size(); i++)
	{
		cout << "Case " << i + 1 << ": " << ans[i] << "\n";
	}
}