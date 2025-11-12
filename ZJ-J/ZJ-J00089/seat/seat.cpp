#include<bits/stdc++.h>
using namespace std;
int r,a[1001];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m>>r;
	a[1]=r;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			cout<<x<<" "<<y;
			return 0;
		}
		if(y==1&&x%2==0){
			x++;
			continue;
		}
		if(y==n&&x%2==1){
			x++;
			continue;
		}
		if(x%2==1){
			y++;
		}
		else{
			y--;
		}
	}
	return 0;
}
