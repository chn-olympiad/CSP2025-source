#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt;
long long a[200];
long long t,x,y;
bool cmp(long long a,long long b){
	if(a>b) return 1;
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cnt=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==cnt){
			t=i;
			break;
		}
	}
	x=t%n;
	y=(t+n-1)/n;
	if(x==0) x=n;
	if(y%2==0){
		x=n-x+1;
	}
	cout<<y<<" "<<x;
	return 0;
}
/*
2 2
99 100 97 98
2 2
98 99 100 97
3 3
94 95 96 97 98 99 100 93 92
*/
