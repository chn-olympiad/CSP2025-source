#include<bits/stdc++.h>
using namespace std;
int n,T;
string a[200005],b[200005],x,y;
int ans;
void dfs(){
	if(x==y){
		ans=ans+1;
		return;
	}
	for(int i=0;i<x.size();i++){
		for(int j=1;j<=n;j++){
			int u=0;
			for(int k=i;k<=i+a[j].size()-1;k++){
				if(x[k]!=a[j][k-i]){
					u=1;
					break;
				}
			}
			if(u==0){
				string t=x;
				for(int k=i;k<=i+a[j].size();k++){
					x[k]=b[j][k-i];
				}
			}
		}
		return;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&T);
	for(int i=1;i<=n;i++){
		
	}
	return 0;
}
