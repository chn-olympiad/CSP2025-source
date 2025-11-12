#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
void solve(){
	int n,m;
	cin>>n>>m;
	int num=-1;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=0;
	for(int i=1;i<=n*m;i++){
		if(i%n==1){
			y++;
		}
		else{
			if(y%2==1)x++;
			else x--;	
		}
		if(a[i]==num){
			cout<<y<<" "<<x;
			break;
		}
	}
	return; 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	solve();
	return 0;
}