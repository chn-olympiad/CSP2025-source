#include<bits/stdc++.h>
using namespace std;
int a[505];
int ansc[505];
int n,m;
string s;
bool vis[505];
int c[505];
long long ans=0;
const long long p=998244353; 
void dfs(int step){
	if(step>n){
		int cnt=0;
		int cc=0;
		for(int i=0;i<n;i++){
			int z=s[i]-'0';
			if(cc>=c[ansc[i+1]]){
				cc++;
				continue;
			}
			if(z){
				cnt++;
			}
			else{
				cc++;
			}
		}
		if(cnt>=m){
//			for(int i=1;i<=n;i++){
//				printf("%d ",ansc[])
//			}
			ans=(ans+1)%p;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			ansc[step]=i;
			dfs(step+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	dfs(1);
	printf("%lld",ans%p);
	return 0;
} 
