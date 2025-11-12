#include<bits/stdc++.h>
using namespace std;
int a[100000] = {0};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int x = 0,m1 = 1,t = 0;
	int n,m;
	cin>>n>>m;
	int R = 0;
	cin>>R;
	a[1] = R;
	for(int i = 2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n*m);
	for(int j = n*m;j>=1;j--){
		t++;
		if(a[j] == R){
			x = t;
			break;
		}
	}
	int bz = 1;
	while(x>n){
		x-=n;
		bz++;
		m1++;
		
	}if(bz%2==0){
		x = n+1-x;
	}cout<<m1<<" "<<x;
	return 0;
}
