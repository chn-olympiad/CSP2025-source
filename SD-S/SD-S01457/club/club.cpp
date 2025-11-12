#include<bits/stdc++.h>
using namespace std;
int t,s[100020][4],an[100020][4][2],n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		if(n==2){cin>>n;
			int u[4],v[4],ma=-1,mb=-1,mx,my,mc=-1,md=-1;
			scanf("%d%d%d%d%d%d",&u[1],&u[2],&u[3],&v[1],&v[2],&v[3]);
			for(int j=1;j<=3;j++){
				if(u[j]>ma){
					ma=u[j];mx=j;
				}
			}
			for(int i=3;i>=1;i--){	
				if(v[i]>mb){
					mb=v[i];
					my=i;
				}			
			}if(mx!=my){cout<<ma+mb<<endl;
			}else{
			for(int i=1;i<=3;i++){
				if(i!=mx){
					mc=max(mc,u[i]);
				}
				if(i!=my){
					md=max(md,v[i]);
				}
			}cout<<max(ma+md,mb+mc)<<endl;
			}
		}
		else{int n,ans=0,cnt[4]={0,0,0,0};
		memset(s,0,sizeof s),memset(an,-1,sizeof an);
		
		scanf("%d",&n);
		for(int i=1;i<=n;i++){an[i][3][0]=100000;
			for(int j=1;j<=3;j++){
				scanf("%d",&s[i][j]);
			}
			for(int j=1;j<=3;j++){
				if(an[i][1][0]<s[i][j]){
					an[i][1][0]=s[i][j];an[i][1][1]=j;
				}
				else if(an[i][3][0]>=s[i][j]){
					an[i][3][0]=s[i][j];an[i][3][1]=j;
				}
			}for(int j=1;j<=n;j++){
				if(j!=an[i][1][1]&&j!=an[i][3][1]){
					an[i][2][0]=s[i][j];an[i][2][1]=j;break;
				}
			}for(int j=1;j<=3;j++){
				cout<<an[i][j][0]<<" "<<an[i][j][1]<<endl;
			}
		}
		for(int i=1;i<=n;i++){
			if(cnt[an[i][1][1]]<n/2){
				ans+=an[i][1][0];cnt[an[i][1][1]]++;continue;
			}
			if(cnt[an[i][2][1]]<n/2){
				ans+=an[i][2][0];cnt[an[i][2][1]]++;continue;
			}
			else{
				ans+=an[i][3][0];cnt[an[i][3][1]]++;continue;
			}
		}
		cout<<ans<<endl;
	
		
	}	
	return 0;
}	}
