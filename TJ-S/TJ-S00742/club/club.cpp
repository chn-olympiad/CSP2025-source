#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int t,flag=0,flag1=0;
int main(){
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	cin>>t;
	while(t--){
		int n,ans=0,a[100005][5];
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0) flag=1;
			if(a[i][3]!=0) flag1=1;
		}
		if(!flag){
			for(int i=1;i<=n;i++){
			    ans=max(ans,a[i][1]);	
			}
			cout<<ans<<endl;
			continue;
		}
		if(!flag1){
			int tmp=0,nm1;
			int tmp2=0,nm2;
			for(int i=1;i<=n;i++){
			    if(tmp<a[1][i]){
			    	tmp=a[1][i];
			    	nm1=i;
				}        
				if(tmp2<=a[2][i]){
					tmp2=a[2][i];
					nm2=i;
				}				
				if(nm1!=nm2){
					ans=tmp+tmp2;
				}
				else{
					if(tmp>tmp2){
						ans+=tmp;
						int tt=a[2][nm2];
						a[2][nm2]=0;
						ans+=max(a[2][1],a[2][2]);
						a[1][nm1]=0;
						tt+=max(a[1][1],a[1][2]);
						ans=max(ans,tt);						
					}
					else{
					    ans+=tmp2;
					    int tt=a[1][nm1];
						a[1][nm1]=0;
						ans+=max(a[1][1],a[1][2]);	
						a[2][nm2]=0;
						tt+=max(a[2][1],a[2][2]);
						ans=max(ans,tt);
					}
				}	
			}
			cout<<ans<<endl;
			continue;
		}
		if(n==2){
		    int tmp=0,nm1;
			int tmp2=0,nm2;			
			for(int j=1;j<=3;j++){
				if(tmp<a[1][j]){
				    tmp=a[1][j];
				    nm1=j;
				}
				if(tmp2<=a[2][j]){
				    tmp2=a[2][j];
				    nm2=j;
				}		
			}
			if(nm1!=nm2){
				ans=tmp+tmp2;
			}
			else{
				if(tmp>tmp2){
						ans+=tmp;
						int tt=a[2][nm2];
						a[2][nm2]=0;
						ans+=max(a[2][1],a[2][2]);
						a[1][nm1]=0;
						tt+=max(a[1][1],a[1][2]);
						ans=max(ans,tt);						
				}
				else{
					ans+=tmp2;
					int tt=a[1][nm1];
					a[1][nm1]=0;
					ans+=max(a[1][1],a[1][2]);	
					a[2][nm2]=0;
					tt+=max(a[2][1],a[2][2]);
					ans=max(ans,tt);
				}
			}	
		    cout<<ans<<endl;
		    continue;	
		}
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
} 
