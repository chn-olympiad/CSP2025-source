#include<bits/stdc++.h>
using namespace std;
int t,n,a[1000010][4],b[1000010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		bool f=1;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0) f=0;
		}
		if(f){
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+n+1);
			int ans=0;
			for(int i=n;i>=n/2+1;i++){
				ans+=b[i];
			}
			cout<<ans<<endl;
		}
		else{
			int maxx=0;
			if(n==2){
				for(int i=1;i<=3;i++){
					for(int j=1;j<=3;j++){
						if(i==j) continue;
						maxx=max(maxx,a[1][i]+a[2][j]);
					}
				}
			}
			if(n==4){
				for(int i=1;i<=3;i++){
					for(int j=1;j<=3;j++){
						for(int k=1;k<=3;k++){
							for(int l=1;l<=3;l++){
								int cnt1=0,cnt2=0,cnt3=0;
								if(i==1) cnt1++;
								if(j==1) cnt1++;
								if(k==1) cnt1++;
								if(l==1) cnt1++;
								if(i==2) cnt2++;
								if(j==2) cnt2++;
								if(k==2) cnt2++;
								if(l==2) cnt2++;
								if(i==3) cnt3++;
								if(j==3) cnt3++;
								if(k==3) cnt3++;
								if(l==3) cnt3++;
								if(!(cnt1>2||cnt2>2||cnt3>2)) maxx=max(maxx,a[1][i]+a[2][j]+a[3][k]+a[4][l]);
							}
						}
					}
				}
			}
			cout<<maxx<<endl;
		}
	}
	return 0;
}
