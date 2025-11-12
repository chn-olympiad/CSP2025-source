#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500+5,P=998244353;
int n,m,c[N],a[N],nc[N],cc[N];
int ans=0;
string s;
int check(){
	int cnt=0,pre=0;
	for (int i=1;i<=n;i++){
		if (nc[i]>pre && s[i]=='1'){
			cnt++;
		}else{
			pre++;
		}
	}
	if (cnt>=m){
		return 1;
	}
	return 0;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s="&"+s;
	for (int i=1;i<=n;i++){
		cin>>c[i];
		a[i]=i;
	}
	if(n<=10){
		do{
			for (int i=1;i<=n;i++){
				nc[a[i]]=c[i];
			}
			ans+=check();
		}while (next_permutation(a+1,a+n+1));
		cout<<ans<<'\n';
	}else{
		if (m==1){
			for (int i=1;i<=n;i++){
				for (int j=c[i]+1;j<=n;j++){
					cc[j]++;
				}
			}
			ans=1;
			for (int i=1;i<=n;i++){
				ans=ans*(cc[i]-i+1)%P;
			}
			int jc=1;
			for (int i=2;i<=n;i++){
				jc=jc*i%P;
			}
			cout<<(jc-ans+P)%P<<'\n';
		}else{
			int jc=1;
			for (int i=2;i<=n;i++){
				jc=jc*i%P;
			}
			for (int i=1;i<=n;i++){
				if (s[i]=='0'){
					cout<<0<<'\n';
					return 0;
				}
			}
			cout<<jc<<'\n';
		}
	}
	return 0;
}
