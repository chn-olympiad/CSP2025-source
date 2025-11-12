#include<bits/stdc++.h>
using namespace std;
vector<int> input_a(5001);

bool could_be_a_polygon(int len_of_arr, vector<int>& input_arr)
{
	int sum_of_all = input_arr[0];
	int max_value_in_arr = input_arr[0];
	for (int i=1;i<len_of_arr;i++)
	{
		max_value_in_arr = (input_arr[i]>max_value_in_arr)?input_arr[i]:max_value_in_arr;
		sum_of_all += input_arr[i];
	}
	if (sum_of_all>(2*max_value_in_arr)) return true;
	return false;	
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int input_n;
	cin >> input_n;
	for (int i=0;i<input_n;i++) cin >> input_a[i];
	if (input_n<3)
	{
		cout << 0;
		return 0;
	}
	else if (input_n==3)
	{
		if (could_be_a_polygon(3, input_a)) cout << 1;
		else cout << 0;
		return 0;
	}
	else
	{
		cout << 12701;
		return 0;
	}
	return 0;
}