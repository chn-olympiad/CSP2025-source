#include<bits/stdc++.h>
using namespace std;
int t,n,a[100000][3],num;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int maxx=0,l=0;
		cin>>n;
		for(int j=0;j<n;j++){
			for(int x=0;x<3;x++){
				cin>>a[j][x];
			}
		}
		for(int l=0;l<=n;l++){
			for(int r=0;r-l<=n/2;r++){
				for(int le=r+1;l<=n;le++){
					for(int ri=r+1;ri-le<=n/2;ri++){
						for(int lef=ri+1;lef<=n;lef++){
							for(int rig=ri+1;rig-lef<=n/2;rig++){
								num=0;
								for(int y=l;y<=r;y++){
									num+=a[y][0];
								}
								for(int y=le;y<=ri;y++){
									num+=a[y][1];
								}
								for(int y=lef;y<=rig;y++){
									num+=a[y][2];
								}
								if(maxx<num){
									maxx=num;
								}
							}
						}
					}
				}
			}
		}
		cout<<maxx;
	}
	return 0;
}
