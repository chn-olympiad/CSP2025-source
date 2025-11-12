#include<bits/stdc++.h>
using namespace std;

int numbers[500010];

struct XorList{
	int l;
	int r;
	int xorSum;
	XorList(int _l, int _r, int _Sum)
	{
		l = _l, r = _r, xorSum = _Sum;
	}
};

vector<XorList> List;
vector<bool> isUsedPairs;

int main()
{
	freopen("xor.in", "r+", stdin);
	freopen("xor.out", "w+", stdout);
	
	int n, k, answer = 1;
	bool isHavePairs = false;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &numbers[i]);
	}
	for (int l = 1; l < n; l++)
	{
		for (int r = l; r <= n; r++)
		{
			int sum = numbers[l];
			for (int i = l + 1; i <= r; i++)
			{
				sum = sum xor numbers[i];
			}
			List.push_back(XorList(l, r, sum));
			isUsedPairs.push_back(false);
		}
	}
	
	//printf("Debug:\n");
	//for (int i = 0; i < List.size(); i++)
	//{
	//	printf("L = %d,  R = %d, xorSum = %d\n", List.at(i).l, List.at(i).r, List.at(i).xorSum);
	//}
	
	for (int i = 0; i < List.size(); i++)
	{
		for (int j = i + 1; j < List.size(); j++)
		{
			if (List.at(i).xorSum == k && List.at(j).xorSum == k && !isUsedPairs.at(i) && !isUsedPairs.at(j))
			{
				if ((List.at(j).l - List.at(i).l > 0)
				 && (List.at(j).l - List.at(i).r > 0)
				 && (List.at(j).r - List.at(i).r > 0))
				{
					isUsedPairs.at(i) = true;
					isUsedPairs.at(j) = true;
					isHavePairs = true;
					answer++;
				}
			}
		}
	}
	if (!isHavePairs)
	{
		answer = 0;
		for (int i = 0; i < List.size(); i++)
		{
			if (List.at(i).xorSum == k)
			{
				printf("1");
				return 0;
			}
		}
	}
	printf("%d", answer);
	return 0;
}

