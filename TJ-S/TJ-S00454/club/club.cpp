#include<bits/stdc++.h>
using namespace std;
int T,n,a[100009],b[100009],c[100009],flaga,flagb;
long long f[509][509][509],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T){
		T--;
		ans=0;
		flaga=1;
		flagb=1;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(c[i]!=0){
				flaga=0;
				flagb=0;
			}
			if(b[i]!=0){
				flaga=0;
			}
		}
		if(flaga){
			sort(a+1,a+n+1);
			for(int i=n;i>n/2;i--){
				ans+=a[i];
			}
			cout<<ans<<endl;
			continue;
		}
		if(flagb){
			
		}
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					int now=i+j+k;
					if(now>n)break;
					if(now==0)continue;
					int x=0,y=0,z=0;
					if(i>0)x=f[i-1][j][k]+a[now];
					if(j>0)y=f[i][j-1][k]+b[now];
					if(k>0)z=f[i][j][k-1]+c[now];
					f[i][j][k]=max(max(x,y),z);
					ans=max(ans,f[i][j][k]);
				}
			}
		}
		cout<<ans<<endl;
	}
return 0;}
