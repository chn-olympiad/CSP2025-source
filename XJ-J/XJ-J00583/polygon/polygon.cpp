#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[5000+5],ans,b[5000+5];
ll MOD=998224353;
inline void f(int m,int begin,int t,ll sum,ll maxn){
	if(t==0)return;
	ll y=maxn;
	if(t!=1){
		if(begin>=n-t+1)return;
		for(int i=begin+1;i<=n;i++){
			sum+=a[i];
			if(a[i]>maxn)maxn=a[i];
			//cout<<m<<i<<" ";
			f(m,i,t-1,sum,maxn);
			//cout<<'\n';
			maxn=y;
			sum-=a[i];
		}
	}else{
		for(int i=begin+1;i<=n;i++){
			sum+=a[i];
			if(a[i]>maxn)maxn=a[i];
			//cout<<i<<'\n';
			if(sum>2*maxn){
				ans++;
				ans%=MOD;
				//cout<<"exapt";
			}
			sum-=a[i];
			maxn=y;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int minn=2,maxn=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<minn)minn=a[i];
		if(a[i]>maxn)maxn=a[i];
	}
	if(maxn==minn)
	{
		int x=1;
		for(int i=3;i<=n;i++){
			x=1;
			for(int j=i+1;j<=n;j++)
			{
				x+=(j-i+1)*(j-1)/2;
			}
			ans+=x;
			ans%=MOD;
		}
	}else{
		for(int i=3;i<=n;i++)
		{
			f(i,0,i,0,0);
		}
	}
	cout<<ans;
	return 0;
}
