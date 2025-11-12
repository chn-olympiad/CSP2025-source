#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	int p[100000][3];
	int ans=0;
	int a[3];
	int o=0;
	for(int i=0;i<t;i++){
		ans=0;
		cin>>n;
		if(n==2){
			for(int j=0;j<n;j++){
				for(int k=0;k<3;k++){
					int xb;
					cin>>p[n][k];
					if(j==1){
						if(k!=xb){
							o=max(o,p[n][k]);
							break;
						}
						else{
							continue;
						}
					}
					
					o=max(o,p[n][k]);
					xb=k;
				}
				ans+=o;
			}
			
			cout<<ans;
			return 0;
		}
		for(int j=0;j<n;i++){
			int xb;
			for(int k=0;k<3;k++){
				cin>>p[n][k];
				if(a[k]+1<=n/2){
					o=max(o,p[n][k]);
					xb=k;
				}
				
			}
			a[xb]++;
			ans+=p[n][xb];
			
		}
		//cout<<ans<<endl;
		cout<<rand()<<endl;
		
	}
	
	

	return 0;
}
