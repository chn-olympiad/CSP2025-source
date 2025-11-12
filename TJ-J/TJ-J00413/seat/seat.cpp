#include<bits/stdc++.h>
using namespace std;
int a[110];
int mp[20][20];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	int man=n*m;
	cin>>a[1];
	int xiaoR=a[1];
	for(int i=2;i<=man;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+man,cmp);
	int hang=1,lie=1;
	for(int i=1;i<=man;i++)
	{
		mp[hang][lie]=a[i];
		if(a[i]==xiaoR)
		{
			cout<<lie<<" "<<hang;
			return 0;
		}
		if(lie%2)hang++;
		else hang--;
		if(hang<1)lie++,hang=1;
		else if(hang>n)lie++,hang=n;
	}
	return 0; 
}
/*
差点就忘了写return 0暴扣100pts了
这次比赛好简单qwq 
*/
