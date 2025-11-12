#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>
#include<map>
#include<deque>
#include<set>
#define ll long long
using namespace std;
const int N=100005;
int n,a[N],cnt=0,mx=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt=cnt+a[i];
		mx=max(mx,a[i]);
	}
	mx=mx*2;
	if(mx<cnt)
	{
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}

