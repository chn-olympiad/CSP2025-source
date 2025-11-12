//平晁宇  SN-S00188  西安铁一中滨河高级中学  
#include<bits/stdc++.h>
using namespace std;

long long n;
int T;
int ans=0;
int s[4][100005];
void dfs(int h,int l,int m,int r,int d){
	int k=0;
	if(h>n){
		ans=max(d,ans);
		return;
	}
	if(l<0||m<0||r<0)return;
	k=d;
	if(l>0)dfs(h+1,l-1,m,r,s[0][h+1]+k);
	if(m>0)dfs(h+1,l,m-1,r,s[1][h+1]+k);
	if(r>0)dfs(h+1,l,m,r-1,s[2][h+1]+k);
	
	return;
}



int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	
	cin>>T;
	
	while(T--)
	{
		memset(s,0,sizeof(s));
		cin>>n;
		for(int i=0;i<3;i++)
		for(int j=1;j<=n;j++){
			cin>>s[i][j];
		}
		
		int u=n/2;
		dfs(0,u,u,u,0);
		cout<<ans<<endl;

		ans=0;
		
	}
	return 0;
}
