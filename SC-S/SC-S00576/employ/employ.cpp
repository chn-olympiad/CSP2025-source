#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair<int,int>
#define ull unsigned long long
const int mod=998244353;
const int N=510;
int fct[N];
int a[N],c[N],cnt[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	fct[0]=1;
	for(int i=1;i<N;i++)fct[i]=fct[i-1]*i%mod;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	bool fl=true;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char s;
		cin>>s;
		a[i]=s-'0';
		if(a[i]==0)fl=false;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		cnt[c[i]]++;
	}
	if(m==1){
		int s=0;
		int cr=0;
		int ans=1;
		for(int i=1;i<=n;i++){
			s+=cnt[i-1];
			if(a[i]==0)cr++;
			else{
				ans=ans*s%mod;
				s--;
			}
		}
		ans=ans*fct[s]%mod;
		cout<<((fct[n]-ans)%mod+mod)%mod;
		return 0;
	}
	if(m==n){
		int cr=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0)cr++;
		}
		if(cnt[0]||cr)cout<<0;
		else cout<<fct[n]%mod;
	}
//	if(fl){
//		cout<<fct[n];return 0;
//	}
	return 0;
}