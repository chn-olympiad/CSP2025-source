#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],aa;
bool cmp(int A,int B){
	return A>B;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	aa=a[1];
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=1,now=1,nn=0;
	int i=1;
	while(i<=n*m){
		if(a[i]==aa){
			cout<<x<<' '<<y;
			return 0;
		}
		i++;
		if(now==1) y++;
		if(now==2) x++;
		if(now==3) y--;
		if(now==2){
			if(nn==1) now=3;
			else now=1;
		}
		if(now==1&&y==n){
			nn=1;
			now=2;
		}
		if(now==3&&y==1){
			now=2;
			nn=3;
		}
	}
	return 0;
}