#include<bits/stdc++.h>
using namespace std;
int myd[105][105];
long long ans[10005];
int flag[10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	long long l=0;
	long long n;
	long long m;
	long long js=1,js2=1,js3,js4;
	long long ma=0,bm,am;
	long long lm=0;
	long long lsm=0;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>myd[i][j];
				if(flag[j]<n/2&&l<=myd[i][j]){
					l=myd[i][j];
					js3=j;
				}
				if(ma<=myd[i][j]){
					ma=myd[i][j];
					js4=j;
				}
			}
			if(flag[js4]==n/2){
				bm=lm+l;
				am=lsm+ma;
				if(am>bm){
					ans[js2]-=lm;
					l=am;
					lsm=0;					
				}
			}
			flag[js3]++;
			lm=l;
			for(int j=1;j<=3;j++){
				if(flag[j]<n/2&&lsm<=myd[i][j]){
					lsm=myd[i][j];
				}
			}
			ans[js2]+=l;
			ma=0;
			l=0;	
		}
		js2++;
		for(int i=0;i<=5;i++){
			flag[i]=0;
		}
		ma=0;
		l=0;
		lm=0;
		lsm=0;
	}
	for(int i=1;i<=js2-1;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
