#include<bits/stdc++.h>
using namespace std;
int n,m,q,xb;
int x[110],y[110];
int a[1010],b[1010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	q=a[1];
	sort(a+1,a+1+n*m);
	int x=1;
	for(int i=n*m;i>0;i--){
		b[x]=a[i];
		x++;
		if(a[i]==q){
			xb=i;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			
		}
	}
	return 0;
}
