#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,k,a[N],b[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	k=a[1];
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=1,i=1;
	while(a[i]!=k&&x<=n&&y<=m){
		b[x][y]=a[i];
		if(y%2==1) {
			if(x==n) y++;
			else x++;
		}
		else{
			if(x==1) y++;
			else x--;
		}
		i++;
	}
	cout<<y<<" "<<x<<endl;
}
/*
(1,1)-> (2,1)-> ^^^ -> (n,1)
-> (n,2) -> (n-1,2)
3 3
94 95 96 97 98 99 100 93 92

*/
