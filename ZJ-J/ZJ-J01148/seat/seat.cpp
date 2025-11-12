#include<bits/stdc++.h>
using namespace std;

int n,m;
int num;
int cnt;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	cin>>num;
	a[1]=num;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>num)cnt++;
	}cnt++;
	int x=1,y=1;
	if(cnt%n==0){
		if(cnt/n%2==0){
			x=cnt/n;y=0;
		}
		else {
			x=cnt/n;y=n;
		}
	}
	else{
		x+=cnt/n;
		int b=cnt%n;
		if(x%2==0){
			y=n-b+1;
		}
		else y=b;
	}
	
	cout<<x<<" "<<y;
	return 0;
}