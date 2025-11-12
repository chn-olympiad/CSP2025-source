#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1001];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int cnt=a[1];
	int sum=0,qwq=1;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==cnt){
			sum=qwq;
		}
		qwq++;
	}
	int x,y;
	if(sum%n==0){
		x=sum/n;
	}else {
		x=sum/n+1;
	}
	if(x%2!=0){
		if(sum%m!=0){
			y=sum%m;
		}else {
			y=m;
		}
	}else{
		if(sum%m!=0){
			y=m-sum%m+1;
		}else {
			y=1;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}