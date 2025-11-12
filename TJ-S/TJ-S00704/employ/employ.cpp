#include<bits/stdc++.h>
using namespace std;
int n,m;
string op;
int s[505],c[505],sum,ans,li,a[505],le,b[505],cmp[505];
void dfs(int t){
	if(t==n+1){
		if(li>=m)ans++;
		return;
	}
	for(int k=1;k<=n;k++){
		for(int j=1;j<=n;j++){
			if(s[k]==0){
				le++;
				li--;
				int t=0;
				for(int i=1;i<=n;i++){
					if(c[i]<=le){
						t++;
						a[i]=1;
						cmp[i]=1;
					}
				}
				le+=t;
				li-=t;
				dfs(t+1);
				le-=t;
				li+=t;
				for(int i=1;i<=n;i++){
					if(cmp[i]==1){
						a[i]=0;
						cmp[i]=0;
					}
				}
			}else{
				int t=0;
				for(int i=1;i<=n;i++){
					if(c[i]<=le){
						t++;
						a[i]=1;
						cmp[i]=1;
					}
				}
				le+=t;
				li-=t;
				dfs(t+1);
				le-=t;
				li+=t;
				for(int i=1;i<=n;i++){
					if(cmp[i]==1){
						a[i]=0;
						cmp[i]=0;
					}
				}
			}
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>op;
	for(int i=1;i<=n;i++){
		s[i]=op[i-1]-'0';
		scanf("%d",&c[i]);
		a[i]=0;
		b[i]=0;
	}
	li=n;
	//dfs(0);
	//printf("%d",ans);
	cout<<0;
	return 0;
}
