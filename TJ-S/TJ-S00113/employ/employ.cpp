#include<bits/stdc++.h>
using namespace std;
const int N=510,M=998244353;
int n,m;
char c[N];
int a[N];
int num[N],st[N];
int res;
void dfs(int u){
	if(u>n){
		int o=0;
		for(int i=1;i<=n;i++){
			if(c[i]=='0')o++;
			else if(o>=a[num[i]])o++;
			if(n-o<m)return;
		}
		res=(res+1)%M;
	}
	else{
		for(int i=1;i<=n;i++){
			if(!st[i]){
				st[i]=1;
				num[u]=i;
				dfs(u+1);
				st[i]=0;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	
	dfs(1);
	cout<<res<<endl;
	return 0;
}
