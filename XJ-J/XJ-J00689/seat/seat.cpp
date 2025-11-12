#include<bits/stdc++.h>
using namespace std;
int f[110],n,m,xh,xx,a=1,b=1;
struct node{
	int x,y;
}f1[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>f[i];
	}
	xh=f[1];
	sort(f+1,f+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(f[i]==xh){
			xx=i;
		}
	}
	int bz=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			f1[bz].x=i;
			bz++;
		}
	}
	if(m%2==1){
		bz=1;
		for(int i=1;i<=m/2;i++){
			for(int j=1;j<=n;j++){
				f1[bz].y=j;
				bz++;
			}
			for(int j=n;j>=1;j--){
				f1[bz].y=j;
				bz++;
			}
		}
		for(int j=1;j<=n;j++){
			f1[bz].y=j;
			bz++;
		}
	}
	if(m%2==0){
		bz=1;
		for(int i=1;i<=m/2;i++){
			for(int j=1;j<=n;j++){
				f1[bz].y=j;
				bz++;
			}
			for(int j=n;j>=1;j--){
				f1[bz].y=j;
				bz++;
			}
		}
	}
	cout<<f1[xx].x<<" "<<f1[xx].y;
	return 0;
}


