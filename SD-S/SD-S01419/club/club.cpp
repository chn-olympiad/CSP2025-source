#include<bits/stdc++.h>
#define INF 1e9+9
using namespace std;
const int N=1e5+9;
int t,n,a[4][N],b[4][N];
int mx(int a,int b,int c){
	if(a>b)
		if(a>c)return 1;
		else return 3; 
	if(b>c)
		return 2;
	return 3;
}
int max_(int a,int b,int c){
	int x=0,u=max(max(a,b),c);
	if(u==a&&u==b||u==a&&u==c||u==b&&u==c)return 0;
	if(u==a)
		return u-max(b,c);
	if(u==b)
		return u-max(a,c);
	if(u==c)
		return u-max(a,b);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		int m=0,ans=0;
		for(int i=1;i<=n;i++)cin>>a[1][i]>>a[2][i]>>a[3][i];
		for(int i=1;i<=n/2;i++){
			int g=mx(a[1][i],a[2][i],a[3][i]),h=max_(a[1][i],a[2][i],a[3][i]);
//			cout<<g<<" "<<h<<"\n";
			b[g][++b[g][0]]=h;
			ans+=a[g][i];
		}
		for(int i=n/2+1;i<=n;i++){
			int g=mx(a[1][i],a[2][i],a[3][i]),h=max_(a[1][i],a[2][i],a[3][i]);
			int mi=INF,id=0;
			if(b[g][0]==n/2){
				for(int i=1;i<=b[g][0];i++){
					if(mi>b[g][i]){
						mi=b[g][i],id=i;
					}
				}
			if(mi<h){
				b[g][id]=h,ans=ans-mi+a[g][i];
			}else{
				ans+=a[g][i]-h;
				
			}
		}
			else{
				ans+=a[g][i];
				b[g][++b[g][0]]=h;
			}
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
*/
