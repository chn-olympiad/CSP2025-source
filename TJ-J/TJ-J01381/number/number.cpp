#include <bits/stdc++.h>
using namespace std;

int w[100005],ou[14]; 
bool cmp(int a,int b)
{
	return a > b;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	long long Shu;
	cin >> Shu;
	int ws = 0;
	
	//int dx = s.size;
	//cout << "#";
	while (Shu >= 10)
	{
		w[ws] = Shu % 10;
		Shu = Shu / 10;
		ws++;
		//cout << w[ws] << endl;
	}
	w[ws] = Shu;
	//cout << "#";

	for(int i = 0;i <= ws;i++)
	{
		ou[w[i]]++;
	}
	
	for(int i = 9;i >= 0;i--)
	{
		while (ou[i] != 0)
		{
			cout << i;
			ou[i]--;
		}
	}
	
	return 0;
}
