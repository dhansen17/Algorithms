#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;

int main()
{
	vector<map<string, int>> work;
	int num_tests = 0;
	int num_accounts = 0;
	string please;
	cin >> num_tests;
	cin.ignore();
	for (int i = 0; i < num_tests; i++)
	{

		map<string, int> needs;
		cin >> num_accounts;
		cin.ignore();
		for (int j = 0; j < num_accounts; j++)
		{
			getline(cin, please);
			needs[please]++;
			
		}

		work.push_back(needs);
		getline(cin, please);

		
	}

	for (int i = 0; i < work.size(); i++)
	{
		for (map<string, int>::iterator it = work[i].begin(); it!= work[i].end(); it++)
		{
			cout << it->first << " " << it->second << endl;
		}
		cout << endl;
	}

	return 0;
}
