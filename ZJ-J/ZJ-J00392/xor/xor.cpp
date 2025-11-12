#include<bits/stdc++.h>
using namespace std;
int input_nums[500001];

int part_xor(int l_of_part, int r_of_part)
{
	int sum_xor = input_nums[l_of_part];
	for (int i=l_of_part+1;i<r_of_part;i++) sum_xor = (sum_xor xor input_nums[i+1]);
	return sum_xor;
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int input_n, input_k;
	bool be_of_a = true;
	bool be_of_b = true;
	bool be_of_c = true;
	cin >> input_n >> input_k;
	for (int i=0;i<input_n;i++)
	{
		cin >> input_nums[i];
		if (input_nums[i]>255)
		{
			be_of_c = false;
			be_of_b = false;
			be_of_a = false;
		}
		else if (input_nums[i]>1)
		{
			be_of_b = false;
			be_of_a = false;
		}
		else if (input_nums[i]!=1) be_of_a = false;
	}
	if (be_of_a&&input_k==0)
	{
		cout << (input_n/2);
		return 0;
	}
	else if (be_of_b)
	{
		int count_parts = 0;
		for (int i=0;i<input_n;i++)
		{
			if ((input_nums[i]==0)&&(input_nums[i+1]==0||(input_nums[i+1]==1&&input_nums[i+2]==1))) count_parts++;
			else if (input_nums[i]==0&&input_nums[i+1]==1&&input_nums[i+2]==0)
			{
				count_parts++;
				i++;
			}
			else if (input_nums[i]==1&&(input_nums[i+1]==1))
			{
				count_parts++;
				i++;
			}
			else if (input_nums[i]==1&&(input_nums[i+1]==0&&input_nums[i+2]==1))
			{
				count_parts++;
				i+=2;
			}
			else if (input_nums[i]==1&&(input_nums[i+1]==0&&input_nums[i+2]==0))
			{
				continue;
			}
		}
		return 0;
	}
	cout << 0;
	return 0;
}