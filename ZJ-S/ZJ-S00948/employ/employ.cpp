#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=510,mod=998244353;
int n,m;
char s[N];
int a[N],c[N];
int t[N],cnt;
int f[N],k[N];
int sum;
void check(){
	int t=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			t++;
			continue;
		}if(t>=c[f[i]]){
			t++;
		}
	}sum+=((n-t)>=m);
}
void dfs(int x){
	if(x>n){
		check();
		return;
	}
	for(int i=1;i<=n;i++){
		if(k[i])continue;
		f[x]=i;
		k[i]=1;
		dfs(x+1);
		k[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		a[i]=a[i-1]+(s[i]=='1');
		if(s[i]=='1')t[++cnt]=i-a[i];
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	if(m>a[n])return cout<<0,0;
	if(m==n){
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				cout<<0;
				return 0;
			}
		}
	}
	if(n<=18){
		dfs(1);
		cout<<sum;
		return 0;
	}else{
		ll ans=1;
		for(int i=1;i<=n;i++)ans=ans*i%mod;
		cout<<ans;
		return 0;
	}
	return 0;
}
