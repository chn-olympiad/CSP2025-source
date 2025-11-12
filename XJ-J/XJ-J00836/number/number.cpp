#include <iostream>
#include <algorithm>
using namespace std;

string str;
int nums[1000010];

bool cmp(int x, int y);

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> str;
	int count = 0;
//	cout << str.size() << endl;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			nums[count] = str[i] - '0';
			count++;
		}
	}
	sort(nums, nums + count, cmp);
	for (int i = 0; i < count; i++)
		cout << nums[i];
	return 0;
}

bool cmp(int x, int y)
{
	return x > y;
}
 
