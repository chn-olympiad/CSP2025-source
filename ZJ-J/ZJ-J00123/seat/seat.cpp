#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[205];
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0; i<n*m; i++) {
		cin>>a[i];
	}
	int s=a[0];
	sort(a,a+n*m,cmp);
	int t=1;
	for(int i=0; i<n*m; i++) {
		if(a[i]==s){
			break;
		}
		t++;
	}
	int cnt=0;
	while(t>=n) {
		t-=n;
		cnt++;
	}
	if(t==0) {
		if(cnt%2==0) {
			cout<<cnt<<" "<<1;
		}else{
			cout<<cnt<<" "<<n;
		} 
	}else{
		cnt++;
		if(cnt%2==0){
			cout<<cnt<<" "<<n-t+1;
		}else{
			cout<<cnt<<" "<<t;
		}
	}
	return 0;
}
