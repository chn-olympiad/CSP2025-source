#include <bits/stdc++.h>
using namespace std;

const int N=550,mod=998244353;
int n,m;
int c[N];
bool s[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>s[i];
	int cnt=0;
	for(int i=1; i<=n; i++){
		scanf("%d",&c[i]);
		if(c[i]==0)cnt++;
	}
	n-=cnt;
	long long ans=1;
	for(int i=1; i<=n; i++){
		ans*=i;
		ans%=mod;
	}
	if(n>=m){
		cout<<ans<<endl;
	}else{
		cout<<0;
	}
	return 0;
}