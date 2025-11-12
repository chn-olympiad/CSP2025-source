#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b[15][15],s=0,f=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	f=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++)
				b[i][j]=a[++s];
		}
		else{
			for(int i=n;i>=1;i--)
				b[i][j]=a[++s];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==f){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
