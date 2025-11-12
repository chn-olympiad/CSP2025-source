#include<bits/stdc++.h>
using namespace std;
int num_in_s[1000001]={};

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string input_s;
	cin >> input_s;
	int len_of_s = input_s.size();
	int pos = 0;
	for (int i=0;i<len_of_s;i++)
	{
		int convert_to_num = input_s[i]-'0';
		if (convert_to_num>=0&&convert_to_num<=9)
		{
			num_in_s[pos] = convert_to_num;
			pos++;
		}
	}
	sort(num_in_s, num_in_s+pos);
	for (int i=pos-1;i>-1;i--) cout << num_in_s[i];
	cout << flush;
	return 0;
}