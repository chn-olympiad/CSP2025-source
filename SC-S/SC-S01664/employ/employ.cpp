#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int f[505],top=0;
int a[505],g[505];
const ll M=998244353;
ll ans;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;cin>>n>>m;
	int sum=0;
	for(int i=1;i<=n;i++){
		char c;cin>>c;
		if(c=='0')f[++top]=sum;
		sum+=c-48;
	}
	f[++top]=sum;
	for(int i=1;i<=n;i++)cin>>g[i];
	sort(g+1,g+n+1);
	for(int i=1;i<=n;i++)a[i]=f[min(g[i],top)];
	do{
		sum=1;
		int ch=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0||ch>=a[i])continue;
			if(ch>=m)ans+=sum,ans%=M;
			sum*=a[i]-ch;ch++;
		}
		if(ch>=m)ans+=sum,ans%=M;
	}while(next_permutation(a+1,a+n+1));
	cout<<ans;
	return 0;
}