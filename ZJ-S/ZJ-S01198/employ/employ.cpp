#include<bits/stdc++.h>
using namespace std;
char a[505];
int b[505];
int v[15],d[15];
map<long long,int>mp;
int f=1,n,m;
long long sum;
void dfs(int k){
	if(k==n+1){
		int p=0,lose=0;
		for(int i=1;i<=n;i++){
			if(b[d[i]]<=lose||a[i]=='0'){
				lose++;
			}else{
				p++;
			}
		}
		if(p>=m){
			sum++;
			sum%=998244353;			
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			d[k]=i;
			dfs(k+1);
			v[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d\n",&n,&m);
	for(int i=1;i<=n;i++)cin>>a[i],f*=(a[i]-'0');
	for(int i=1;i<=n;i++)cin>>b[i];
	if(f==1){
		long long ans=1;
		for(int i=n;i>=1;i--){
			ans*=i;
			ans%=998244353;
		}
		printf("%lld",ans);
	}else if(m==n){
		if(f!=1){
			printf("0");
		}else{
			long long ans=1;
			for(int i=n;i>=1;i--){
				ans*=i;
				ans%=998244353;
			}
			printf("%lld",ans);
		}
	}else if(n<=10){
		dfs(1);
		printf("%d",sum);
	}else{
		cout<<0;
	}
	return 0;
}
