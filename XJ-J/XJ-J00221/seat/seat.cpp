#include<bits/stdc++.h>
using namespace std;
int a[105],b[15][15];
bool cmp(int a1,int a2){
	return a1<a2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x=1,y=1;
	bool f=0;
	b[1][1]=1;
	for(int i=2;i<=n*m;i++){
		if((i-1)%n==0){
			y++;
			f=(!f);
		}
		else{
			if(f) x--;
			else x++;
		}
		b[x][y]=i;
	}
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+1+m*n,cmp);
	int xi;
	for(int i=1;i<=n*m;i++){
		if(a[i]==x) xi=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==xi){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
