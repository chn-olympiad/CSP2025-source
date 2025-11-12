#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
const int N=505;
int n,m;
string s;
int pa[N];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>pa[i];
	}
	int a=1;
	int b=1;
	for(int i=1;i<=n;i++)
	{
		a=a*i;
	}
	for(int i=1;i<=(n-m);i++)
	{
		b=b*i;	
	}
	int ans=(a/b)%998244353;
	cout<<ans;	
	return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
4 1
2 2
1 3
3 1
2 2
4 3
5 1
3 2
4 3
3 1
5 2
1 3*/
