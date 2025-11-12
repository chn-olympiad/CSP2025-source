#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,sum,maxx,s_1,a[5005];
bool flag;
inline int C(int x,int y){
	int s=1;
	for(int i=1;i<=x;i++){
		s*=(y-i+1);
	}
	for(int i=1;i<=x;i++){
		s/=i;
	}
	return s;
}
inline void f(int step,int k,int id){
	if(step>k){
		if(sum>2*maxx){
			ans++;
			ans%=998244353;
		}
		return;
	}
	int t;
	for(int i=id+1;i<=n;i++){
		if(a[i]>maxx){
			t=maxx;
			maxx=a[i];
			flag=1;
		}
		sum+=a[i];
		f(step+1,k,i);
		sum-=a[i];
		if(flag){
			flag=0;
			maxx=t;
		}
	}
	return;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			s_1++;
		}
	}
	if(n<3){
		cout<<0<<"\n";
		return 0;
	}
	if(s_1==n){
		for(int i=3;i<n;i++){
			ans+=C(i,n);
			ans%=998244353;
		}
		ans++;
		cout<<ans<<"\n";
	}else{
		for(int i=3;i<=n;i++){
			f(1,i,0);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
