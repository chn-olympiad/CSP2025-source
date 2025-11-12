#include<bits/stdc++.h>
using namespace std;
int n,q,t;
string a[10005][4],b[10005][4];
int x[10005],cnt[10005];
int pd(int o,int a1,int y,int u){
	for(int i=0;i<x[u];i++){
		if(b[o][y][a1+i]!=a[u][y][i]){
			return 0;
		}
	}
	return 1;
}
int pd1(int o,int a1){
	for(int i=0;i<a1;i++){
		if(b[o][1][i]!=b[o][2][i]){
			return 0;
		}
	}
	for(int i=0;i<=t-a1;i++){
		if(b[o][1][a1+i]!=b[o][2][a1+i]){
			return 0;
		}
	}
	
	return 1;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2];
		x[i]=a[i][1].size();
		
	}
	for(int i=1;i<=q;i++){
		cin>>b[i][1]>>b[i][2];
		t=b[i][1].size();
		for(int l=1;l<=n;l++){
			for(int j=1;j<=t;j++){
				if(b[i][1][j]==a[l][1][0] && t-j+1>=x[l]){
					if(pd(i,j,1,l) && pd(i,j,2,l)){
						if(pd1(i,j)){
							cnt[i]+=1;
						}
					}
				}
				
			}
		}
		
	}
	for(int i=1;i<=q;i++){
		cout<<cnt[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

