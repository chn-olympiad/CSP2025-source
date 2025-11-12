#include<bits/stdc++.h>
using namespace std;
#define int long long
int m,n;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k,seat;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
		
	}
	k=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;++i){
		
		if(a[i]==k){
			seat=i;
			break;
		}
		
	}
	int l,h;
	l=(seat-1)/n+1;
	
	if(l%2==1){
		h=seat%n;
		if(h==0){
			h=n;
		}
	}
	else{
		h=(n-(seat%n)+1)%n;
		if(h==0){
			h=n;
		}
	}
	cout<<l<<' '<<h;
	return 0;
} 
