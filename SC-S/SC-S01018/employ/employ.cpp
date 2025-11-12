#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=505,p=998244353;
int n,m,c[N],s[N],ans=1;
string su;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>su;
	for(int i=1;i<=n;i++) cin>>c[i];
	bool f=0;
	for(int i=0;i<su.size();i++)
	{
		s[i+1]+=su[i]-'0';
		if(su[i]=='0') f=1;
	}
	sort(c+1,c+1+n);
	if(f==0)
	{
		int g=0,gi=0;
		for(int i=1;i<=n;i++)
		{
			if(c[i]==0) g++;
			if(c[i]!=0){
				if(c[i]<=g){
					ans=(ans%p)*(c[i]%p);
					gi++;
				}else{
					break;
				}
			}
		}
		for(int i=g;i>=1;i--) ans=(ans%p)*(i%p);
		for(int i=n-g-gi;i>=1;i--) ans=(ans%p)*(i%p);
		cout<<ans%p;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}