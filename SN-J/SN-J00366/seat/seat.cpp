#include<bits/stdc++.h>
using namespace std;
int a[10005][10005],n,m,b[10005],x; 
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	x=b[1];
	sort(b+n,b+n+1);
	for(int i=1;i<=n*m;i++){
		cout<<b[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=b[j];
			if(b[i]==x){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
