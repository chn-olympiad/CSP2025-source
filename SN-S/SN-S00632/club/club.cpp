#include<bits/stdc++.h>
using namespace std;
int n,t,a[10005][1005],m,v,b,ans[105];
int main(){	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int u=n/2;
	for(int i=1;i<=t;i++){
		cin>>n;
			for(int o=1;o<=n;o++){
				for(int j=1;j<=3;j++){
					cin>>a[o][j];
				}
			}
			for(int p=1;p<=n;p++){
				int s=max(a[p][1],a[p][3]);
				int g=max(a[p][2],a[p][3]);
				int f=max(s,g);
				if(f==a[p][1]&&m<=u){
					m++;	
					ans[i]=ans[i]+f;
				}else if(f==a[p][2]&&v<=u){
					v++;
					ans[i]=ans[i]+f;
				}else{
					b++;
					ans[i]=ans[i]+f;
				}
			}

	}
	for(int i=0;i<t;i++){
		cout<<ans[i];
	}
	return 0;
}
