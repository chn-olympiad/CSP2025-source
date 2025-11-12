#include<bits/stdc++.h>
using namespace std;
int n,k;
int ls[500050];
int check(int st,int ed)
{
	int num = ls[st];
	for(int i = st+1;i <= ed;i++)
	{
		num = num ^ ls[i];
	}
	if(num == k)
	{
		return 1;
	}
	return 0;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> ls[i];
	}
	return 0;
}
