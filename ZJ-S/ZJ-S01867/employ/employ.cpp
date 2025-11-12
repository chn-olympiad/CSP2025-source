#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
int n,m,a[510],cnt,b[510];
bool s[510],flag=1;
char c;
ll ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	getchar();
	for(int i=1;i<=n;i++){
		c=getchar();
		s[i]=c-'0';
		flag=flag&s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt+=(a[i]>0);
		b[i]=i;
	}
	if(flag){
		if(cnt>=m){
			ans=1;
			for(int i=1;i<=n;i++) (ans*=i)%=mod;
			cout<<ans<<endl;
		}else cout<<0<<endl;
		return 0;
	}
	do{
		cnt=0;
		for(int i=1;i<=n;i++) if(s[i]&&a[b[i]]>(i-cnt-1)) cnt++;
		ans+=(cnt>=m);
	}while(next_permutation(b+1,b+1+n));
	cout<<ans<<endl;
	return 0;
}
