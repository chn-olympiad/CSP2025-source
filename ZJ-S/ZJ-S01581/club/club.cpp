#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
long long t;int n;
int f[100005][4];
int a[100005][4];
int s[100005][4][4]={};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int tp=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			for(int j=0;j<=3;j++){
				s[i][j][0]=s[i][j][1]=s[i][j][2]=s[i][j][3]=0;
			}
			if(a[i][2]==0&&a[i][3]==0)tp++;
			if(a[i][2]!=0||a[i][3]!=0)tp=0;
		}
		for(int i=0;i<=n+1;i++){
			for(int j=0;j<=3;j++){
				f[i][j]=0;
				
			}
		}
		if(tp>=10){
			int b[100005]={};
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+n+1);
			int ans=0;
			for(int i=n;i>=(n/2);i--){
				ans+=b[i];
			}
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				for(int k=1;k<=3;k++){
					if(s[i-1][j][k]<(n/2)){
						if(f[i][k]<f[i-1][j]+a[i][k]){
							f[i][k]=f[i-1][j]+a[i][k];
							for(int h=1;h<=3;h++){
								if(h!=k){
									s[i][k][h]=s[i-1][j][h];
								}
								else 
									s[i][k][k]=s[i-1][j][k]+1;
							}
						}
					}
				}	
			}
		}
		int p=max(max(f[n][1],f[n][2]),f[n][3]);
		cout<<p<<endl;
	}
//hthhthhhhlkikujjyjjjhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
