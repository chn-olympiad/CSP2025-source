#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>
#define int long long
const int MAXN=1e5+5;
using namespace std;
int t,n,t1,t2,t3; 
int a[MAXN][10];
int c[10][MAXN];
int maxx,minn,sum=0,ans=0;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		t1=t2=t3=ans=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			maxx=max(a[i][1],max(a[i][2],a[i][3]));
			minn=min(a[i][1],min(a[i][2],a[i][3]));
			sum=a[i][1]+a[i][2]+a[i][3];
			a[i][4]=maxx-(sum-maxx-minn);
			if(a[i][1]==maxx){
				c[1][++t1]=a[i][4];
				ans+=a[i][1];
			}
			else if(a[i][2]==maxx){
				c[2][++t2]=a[i][4];
				ans+=a[i][2];
			}
			else if(a[i][3]==maxx){
				c[3][++t3]=a[i][4];
				ans+=a[i][3];
			}
		}
		if(t1<=n/2&&t2<=n/2&&t3<=n/2){
			cout<<ans<<endl;
		}
		else{
			if(t1>n/2){
				sort(c[1]+1,c[1]+t1+1);
				for(int i=1;i<=t1-(n/2);i++){
					ans-=c[1][i];
				}
			}
			else if(t2>n/2){
				sort(c[2]+1,c[2]+t2+1);
				for(int i=1;i<=t2-(n/2);i++){
					ans-=c[2][i];
				}
			}
			else if(t3>n/2){
				sort(c[3]+1,c[3]+t3+1);
				for(int i=1;i<=t3-(n/2);i++){
					ans-=c[3][i];
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}


