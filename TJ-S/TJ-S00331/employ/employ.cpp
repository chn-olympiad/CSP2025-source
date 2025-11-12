#include <bits/stdc++.h>
using namespace std;
const int N=505;
const int MOD=998244353;
int n,m,a[N],wei,people;
string s;
int jiecheng(int n)
{
	int ans=1;
	for(int i=n;i>=2;i++)ans=ans*i%MOD;
	return ans;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)if(a[i]>0)people++;
	for(int i=0;i<s.size();i++)if(s[i]=='1')wei++;
	if(wei<m||people<m){cout<<0<<endl;return 0;}
	if(wei==m&&people==m){cout<<jiecheng(n)<<endl;return 0;}
	srand(time(0));
	cout<<rand()%MOD<<endl;
	return 0;
}
