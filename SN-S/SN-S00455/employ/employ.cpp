#include <bits/stdc++.h>
using namespace std;
const int N=505,inf=998244353;
int n,m,c[N],cnt1,cnt2,maxn;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	maxn=n-1;
	cout<<maxn%inf;
	return 0; 
}
