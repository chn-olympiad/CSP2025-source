#include<bits/stdc++.h>
using namespace std;
const long long P=998244353;
int n,m,c,cnt;
long long f[505],ans;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		if(c==0) cnt++;
	}
	if(n-cnt<m){
		cout<<0;
		return 0;
	}
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		f[i]=(f[i-1]*i)%P;
	}
	cout<<f[n]%P;
	return 0;
}
