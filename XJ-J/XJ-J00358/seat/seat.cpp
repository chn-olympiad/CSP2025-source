#include<bits/stdc++.h>
using namespace std;
int xy[15][15];
int a[1005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y;
	cin>>x>>y;
	for(int i=1;i<=x*y;i++){
		cin>>a[i];
	}
	int xr=a[1],xrp;
	int ans=x*y;
	int cnt=0;
	sort(a+1,a+ans+1,cmp);
	for(int i=1;i<=y;i++){
		if(i%2!=0){
			for(int j=1;j<=x;j++){
			cnt++;
			xy[j][i]=cnt;
		    }
		}
		else{
			for(int j=x;j>=1;j--){
			cnt++;
			xy[j][i]=cnt;
		    }
		}
	}
	for(int i=1;i<=ans;i++){
		if(a[i]==xr){
			xrp=i;
			break;
		}
	}
	for(int i=1;i<=x;i++){
		for(int j=1;j<=y;j++){
			if(xy[i][j]==xrp){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
} 
