#include<bits/stdc++.h>
using namespace std;
 
 const int MAXN=10005;
long long t,n,a[MAXN][MAXN],f[MAXN][MAXN],num[MAXN],ans; 
bool vis[MAXN];
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	memset(vis,true,sizeof(vis));
	cin>>t; 
	for(int i=1;i<=t;i++){
		cin>>n;
		if(n%2==0){	
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					cin>>a[i][j];
				}
			}
			for(int i=0;i<=n;i++){
				for(int j=0;j<=3;j++){
					f[i][j]=0;	
			}	
		}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
						f[i][j]=max(max(a[i][3],a[i][2]),a[i][1]);
					if(f[i][j]==a[i][1]){
						num[1]++;
					}
					else if(f[i][j]==a[i][2]){
						num[2]++;
					}
					else if(f[i][j]==a[i][3]){
						num[3]++;
					}
					if(vis[i]){
						if(num[j]<=n/2){
							ans+=f[i][j];
						}	
					}	
					vis[i]=false;		
				}		
			}
		
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
