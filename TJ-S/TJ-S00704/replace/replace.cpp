#include<bits/stdc++.h>
using namespace std;
int n,T;
string a[200005],b[200005],x,y;
int ans,flag[200005];
void dfs(int o){
	if(x==y){
		ans=ans+1;
		return;
	}
	for(int i=o;i<x.size();i++){
		for(int j=1;j<=n;j++){
			int u=0;
			for(int k=0;k<a[j].size();k++){
				if(x[k+i]==a[j][k]){
				}else{
					u=1;
					break;
				}
			}
			if(u==0&&flag[j]==0){
				flag[j]=1;
				string t=x;
				for(int k=0;k<a[j].size();k++){
					x[k+i]=b[j][k];
				}

				dfs(a[j].size()+i);
				x=t;
				flag[j]=0;

			}
		}
	}
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&T);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	
	for(int op=1;op<=T;op++){
		cin>>x>>y;
		ans=0;
		if(x.size()!=y.size()){
			printf("0\n");
			
		}else {
			dfs(0);
			printf("%d\n",ans);
		}
	}
	return 0;
}
