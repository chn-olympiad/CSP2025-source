#include<bits/stdc++.h>
using namespace std;
string s;
int num;
int ls[1000010];
int main()
{ 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int k = 0;
	int len = s.size();
	for(int i = 0;i < s.size();i++)
	{
		if(s[i] >= '0' and s[i] <= '9')
		{
			k++;
			ls[k] = s[i]-'0';
		}
	}
	sort(ls+1,ls+1+k);
	for(int i = k;i >= 1;i--)
	{
		printf("%d",ls[i]);
	}
	return 0;
}
