#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[105],R,A[15][15];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	int l=0,r=1,L=1,flag=0;
	while(l<n*m){
		if(a[l+1]==R){
			cout<<r<<" "<<L;
			return 0;
		}
		A[r][l%n]=a[l+1];
		if(l%n==n-1) r++;
		if(r%2==1) flag=0;
		else flag=1;
		if(flag){
			if((l+1)%n!=0) L--;
		}
		else{
			if((l+1)%n!=0) L++;
		}
		l++;
	}
	return 0;
}
/*

2 2
99 98 97 100


2 2
98 97 99 100


3 3
94 95 96 97 98 99 100 93 92

*/
