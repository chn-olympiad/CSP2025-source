#include<bits/stdc++.h>
using namespace std;
int const N=2e6+5;
int const mod=998244353;
int n,m,c[N],b[N];
long long ans;
char a[N];
bool p,q;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=i;
		if(a[i]=='0') p=1;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) q=1;
	}
	if(p==0&&q==0){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	do{
		int cnt=0,cnt1=0;
		for(int i=1;i<=n;i++){
			if(a[i]=='1'&&c[b[i]]>cnt1){
				cnt++;
			}
			else cnt1++;
		}
		if(cnt>=m)
		{
		ans++;
		ans=ans%mod;	
		}
	}while(next_permutation(b+1,b+1+n));
	cout<<ans;
	return 0;
}