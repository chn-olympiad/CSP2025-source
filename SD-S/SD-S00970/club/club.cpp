#include<bits/stdc++.h>
using namespace std;
int n;
int t;
int cnt;
int m;
int ar[100005][3]={};
void dfs(int a,int b,int c,int nn,int i){
	if(i>n){
		if(cnt<nn){
			cnt=nn;
		}
		return ;
	}
	if(a<m){
		dfs(a+1,b,c,nn+ar[i][1],i+1);
	}
	if(b<m){
		dfs(a,b+1,c,nn+ar[i][2],i+1);
	}
	if(c<m){
		dfs(a,b,c+1,nn+ar[i][3],i+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>ar[i][j];
			}
		}
		cnt=0;
		m=n/2;
		dfs(0,0,0,0,1);
		cout<<cnt<<endl;
	}
	return 0;
}
