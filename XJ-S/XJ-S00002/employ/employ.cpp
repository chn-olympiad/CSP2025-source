#include<bits/stdc++.h>

using namespace std;

int nx[600],nd[600];
int ans=0;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>nx[i];
		nd[i]=s[i-1]-'0';
	}
	int loss=0,win=0,k=1;
	while(1){
		loss=0,win=0;
		for(int i=1;i<=n;i++){
			loss=0,win=0;
			for(int j=1;j<=n;j++){
				for(int z=1;z<=n;z++){
					if(loss>=nx[j]){
					loss++;
				}
				} 
				 
				
				for(int z=1;z<=n;z++){
					if(i!=j&&i!=z&&j!=z){
						for(int x=1;x<=n;x++){
							if(loss>=nx[z]){
								loss++;
								continue;
							}
							if(nd[x]==0){
								loss++;
							}
							if(nd[x]==1){
								win++;
							}
							if(win==m){
								ans++;
								break;
							}
						}
						
					}
					
				}
				
			}
			
		}
		break;
	}
	cout<<ans%998244353;
	return 0;
}
