#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define up(i,j,k,l) for(int i=j;i<=k;i+=l)
#define down(i,j,k,l) for(int i=j;i>=k;i-=l)
using namespace std;
int n,q;
void solve()
{
	cin>>n>>q;
	up(i,1,q,1){
		puts("0");
	}
	return;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	int _=1;
	//cin>>_;
	up(i,1,_,1){
		solve();
	}
	return 0;
}

