#include <iostream>
#include <vector>

using namespace std;

pair<int, int> myKnap(int parties, int budget, vector<int> &weight, vector<int> &value, vector<vector<pair <int, int>>> &shawn)
{
	pair <int, int> num1 (0, 0);
	pair <int, int> num2 (0, 0);

	if (shawn[parties][budget].second < 0)
	{
		num1 = myKnap(parties - 1, budget, weight, value, shawn);
		if (budget >= weight[parties])
		{
			num2 = myKnap(parties - 1, budget - weight[parties], weight, value, shawn);
			num2.first += weight[parties];
			num2.second += value[parties];
		}
		if (num1.first >= num2.first && num1.second == num2.second)
			shawn[parties][budget] = num2;
		else if (num1.first < num2.first && num1.second == num2.second)
			shawn[parties][budget] = num1;
		else if (num1.second > num2.second)
			shawn[parties][budget] = num1;
		else
			shawn[parties][budget] = num2;
	}
	return shawn[parties][budget];

}


int main()
{
	int budget;
	int numParties;

	while (cin >> budget >> numParties)
	{
		if (numParties == 0 && budget == 0)
			break;
		vector<int> weight(numParties + 1);
		vector<int> value(numParties +1);

		vector< vector< pair<int, int> > > total(numParties + 1, vector< pair<int, int> >(budget + 1, pair<int, int>(-1, -1)));

		for (int i = 0; i <= numParties; i++) {
			total[i][0].first = 0;
			total[i][0].second = 0;
			if (i < numParties) 
				cin >> weight[i + 1] >> value[i + 1];
		}
		for (int j = 0; j <= budget; j++) {
			total[0][j].first = 0;
			total[0][j].second = 0;
		}

		pair<int, int> best = myKnap(numParties, budget, weight, value, total);

		cout << best.first << " " << best.second << endl;

	}

	return 0;

}