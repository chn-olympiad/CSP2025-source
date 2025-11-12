#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m;
int a[N];
int dx=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int p=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==p){
			p=n*m-i+1;
			break;
		}
	}
	int sum[N][N]{0};
	pair<int,int> l;
	l={1,1};
	int o=1;
	while(l.second<=m){
		int x=l.first,y=l.second;
		
		sum[x][y]=o++;
		x+=dx;
		if(x>n){
			y++;
			dx=-dx;
			x=n;
		}
		if(x<1){
			y++;
			dx=-dx;
			x=1;
		}
		l={x,y};
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++){
			if(sum[i][j]==p){
				cout<<j<<" "<<i<<endl;
				return 0;
			}
		}
	}
	return 0;
}
