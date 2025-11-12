#include <bits/stdc++.h>
using namespace std;
long long n,m,ans,MOD=998244353;
string s;
int c[505],f[505],d[505],b[505],x;
int ff(int x1){
	int xa=1;
	for(int i=2;i<=x1;i++){
		xa*=i;
		xa%=MOD;
	}
	return xa;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int xy=0;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0)xy++;
	}
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++)
	{
		d[c[i]]++;
		b[c[i]]=d[c[i]];
		
	}
	for(int i=n-1;i>=1;i--)
	{
		d[i]+=d[i+1];
	}
	int t=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='0')t++,f[i+1]=f[i];
		else{
			f[i+1]=t;
		}
	}
	if(t==0){
		if(m+xy<=n)cout<<ff(n);
		else cout<<0;
		return 0;
	} 
	ans=1;x=0;
	d[0]=d[1];
	int xx=0;
	for(int i=n;i>=1;i--)
	{
		ans*=d[f[i]+1]-x;
		ans%=MOD;
		x+=c[f[i]+1];
		if(s[i-1]=='1')xx++;
		if(xx==m)break;
	}
	ans*=ff(n-m);
	ans%=MOD;
	/*for(int i=1;i<=m;i++){
		cout<<d[f[i]+1]-x<<'\n';
		ans*=(d[f[i]+1]-x);
		x+=d[f[i]]-d[f[i]+1];
		cout<<"x:"<<d[f[i]]<<"-"<<d[f[i]+1]<<'\n';
	}*/
	cout<<ans;
	return 0;
}
