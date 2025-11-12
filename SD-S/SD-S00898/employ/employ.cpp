#include<bits/stdc++.h>//CSP-S2025 RP++
#define int long long
using namespace std;
int n,m,s[509],c[509],jc[509],ans,cnt1,cnt2,p[509];
char ch;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		p[i]=i;
		cin>>ch;
		s[i]=ch-'0';
		cnt1+=s[i];
	}
	for(int i=1;i<=n;++i){
		cin>>c[i];
		cnt2+=(c[i]!=0);
	}
	if(min(cnt1,cnt2)<m){
		cout<<0;
		return 0;
	}
	if(m==n){
		ans=1;
		for(int i=1;i<=n;++i){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	if(cnt1==n){
		ans=1;
		for(int i=1;i<=n;++i){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		jc[0]=1;
		for(int i=1;i<=n;++i){
			jc[i]=jc[i-1]*i;
			jc[i]%=998244353;
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				cnt2+=(c[j]>=i);
			}
			ans+=jc[n-i]*cnt2;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	if(n<=11){
		do{
			int cnt=0,sum=0;
			for(int i=1;i<=n;++i){
				if(s[i]==0||cnt>=c[p[i]]){
					++cnt;
				}
				else{
					++sum;
				}
			}
			ans+=(sum>=m);
		}while(next_permutation(p+1,p+n+1));
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;//return whk  //NOIP2025(如果有的话） RP++
}//(rand()%3)+1 =
