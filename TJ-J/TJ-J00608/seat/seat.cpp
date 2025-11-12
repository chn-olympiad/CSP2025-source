#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int j=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==j){
			if((i/n)&1){
				cout<<i/n+1<<" "<<n-(i%n);
			}
			else{
				cout<<i/n+1<<" "<<i%n+1;
			}
			return 0;
		}
	}
	return 0;
}
