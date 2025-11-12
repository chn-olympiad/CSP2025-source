#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],b,d[105][105],c=0,e=0;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>d[i][j];
		}
	}
	b=d[1][1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(d[i][j]>b)
				c++;
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int j=1;j<=m;j++){
				e++;
				if(e==c) cout<<i<<' '<<j;
			}
		}
		else if(i%2!=0){
			for(int j=m;j>=1;j--){
				e++;
				if(e==c) cout<<i<<' '<<j;
			}
		}
	}
	return 0;
}
