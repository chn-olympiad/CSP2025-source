#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],b[15][15],s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1);
	int x=0,y=1,c=1;
	int p=n*m;
	bool f=1;
	for(int i=1;i<=m*n;i++){
		if((x==n||(x==1&&y!=1))&&f==1){
			y++;
			b[y][x]=a[m*n-i+1];
			c=-c;
			f=0;
		}else{
			x+=c;
			b[y][x]=a[m*n-i+1];
			f=1;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]==s){
				cout<<i<<' '<<j;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
