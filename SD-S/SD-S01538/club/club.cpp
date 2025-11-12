#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int T,n,a[20][20],b[10005],ans=0,sum,cnt1,cnt2,cnt3,cnt4,cnt5,cnt6,maxx,maxxx;
int c[10005],d[10005];
int wangxiran=1,wangmingzhen=1;
int flag=0;
int lastans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sypc_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		if(n==2){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					cin>>a[i][j];
					cnt1=a[1][1]+a[2][2];
					cnt2=a[1][1]+a[3][2];
					cnt3=a[2][1]+a[1][2];
					cnt4=a[2][1]+a[3][2];
					cnt5=a[3][1]+a[1][2];
					cnt6=a[3][1]+a[2][2]; 
					maxx=max(cnt1,max(cnt2,max(cnt3,max(cnt4,max(cnt5,cnt6)))));
				}
			}
		}
		else{
			flag=0;
			lastans=0;
			int num;
			for(int i=1;i<=n;i++){
				cin>>b[1]>>b[2]>>b[3];
				c[i]=b[1],d[i]=b[2];
				if((b[2]==0)&&(b[3]==0)){
					flag=1;
					if(b[1]>maxxx) maxxx=b[1];
				}
				else if(b[3]==0){
					num=n/2;
					//for(int j=1;j<=num;j++){
					//	c[j]=b[1];
				//		d[j]=b[2];
					//}
					//sort(c+1,c+n+1);
					//sort(d+1,d+n+1);
					sort(c+1,c+n+1);
					sort(d+1,d+n+1);
					//for(int j=1;j<=num;j++){
					//	cout<<c[j]<<" "; 
					//}
					for(int liuyitong=num;liuyitong>=1;liuyitong--){
						lastans+=c[liuyitong];
						lastans+=d[liuyitong];
					}
				}
				//if(b[1]>maxxx) maxxx=b[1];
			}
		}
		if(n==2){
			cout<<maxx;
		}
		else if(flag==1){
			cout<<maxxx;
			maxxx=0;
		}
		else{
			cout<<lastans;
		}
	}
	return 0;
}
