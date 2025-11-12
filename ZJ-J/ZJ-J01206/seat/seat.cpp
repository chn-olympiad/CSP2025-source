#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[200],k,ops;
int x,y,opt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[++k];
	ops=a[1];x=0;y=1;opt=1;
	sort(a+1,a+k+1,greater<int>());
	for(int i=1;i<=k;i++){
		if(opt==1){
			x++;
			if(x==n+1){
				x=n;y++;
				opt=0;
			}
		}
		else if(opt==0){
			x--;
			if(x==0){
				x=1;y++;
				opt=1;
			}
		}
		if(a[i]==ops){
			cout<<y<<' '<<x;
			return 0;
		}
	}
	return 0;
} 
