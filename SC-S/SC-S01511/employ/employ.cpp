#include<bits/stdc++.h>
#define ll long long
#define pq priority_queue
#define pr pair
#define vec vector
/*
feropen
mian
itn
y0
ans
CCF
Never Gonna Give You UP~
guanzhu luogu@chenyuheng01 thank you miao~
log:
[14:26]:enter
[14:34]:start T1 5pts
[14:40]:end T1 5pts
[15:12]:start T4 16pts
[15:18]:T4 16pts faked
[15:18]:try anyway
*/
#define mod 998244353
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;
	cin>>n;
	ll qwq;
	while(n!=1&&n--)
	{
		qwq*=n;
		qwq%=mod;
	}
	cout<<qwq;
}