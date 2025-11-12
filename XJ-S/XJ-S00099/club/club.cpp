#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int t,n,ans;
int a[N][5]={0};
int cnt1,cnt2,cnt3;
int man[N] = {0};
//int ans[5]={0};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i =1;i<=n;i++){
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
				if(cnt1<(n/2)){
					cnt1++;
					man[i]=1;
					ans+=a[i][1];
				}
				else{
					int tmp = 0 ;
					icida=min(a[i][2],a[i][3]);
					for(int x=1;x<=n;x++){
						xcida=min(a[x][2],a[x][3]);
						if(man[x]==1){//zaiclub1li
							if(ans+icida<ans-a[x][1]+ xcida +a[i][1]){
								tmp=ans-a[x][1]+ xcida +a[i][1];
							}
							
//							if(a[x][2]>a[x][3]){//2weicida
//								if(ans+icida<ans-a[x][1]+a[x][2]+a[i][1]){
//									tmp=ans-a[x][1]+a[x][2]+a[i][1];
//								}
//							}
//							else{//3weicida
//								
//							}
						}
					}
				}
			}
			if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
				club[2]++;
				man[i]=2;
				ans+=a[i][2];
			}
			if(a[i][3]>a[i][1]&&a[i][3]>a[i][2]){
				club[3]++;
				man[i]=3;
				ans+=a[i][3];
			}
		}
//		for(int j=1; j<=3; j++){
//			for(int i = 1; i<=n; i++){
//				if(man[i]==0&&club[j]<(n/2)){
//					ans=+a[i][j];
//					man[i]=1;
//					club[j]++;
//				}
//				if(man[i]==0&&club[j]>=(n/2)){
//					if(ans<ans-a[i-1][j]+a[i][j]){
//						ans = ans-a[i-1][j]+a[i][j];
//						man[i-1]=0;
//						man[i] = 1;
//					}
//				}
//				if(man[i]==1&&club[j]<(n/2)){
//					if(ans<ans-a[i][j-1]+a[i][j]){
//						ans = ans - a[i-1][j] + a[i][j];
//						man[i-1] = 0;
//						man[i] = 1;
//						club[j]++;
//					}
//				}
//				if(ans<ans-a[i][j-1]+a[i][j]){
//					ans = ans - a[i-1][j] + a[i][j];
//					man[i-1] = 0;
//					man[i] = 1;
//					club[j]++;
//				}
//			}
//		}
	}
	
	return 0;
}
