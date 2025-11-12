#include<bits/stdc++.h>
using namespace std;
int n,m,r,o,s;
int a[150];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	cin>>s;
	a[s]++;
	int k=n*m;
	for(int i=2;i<=k;i++){
		cin>>r;
		a[r]++;
	}
	int x=1,y=0;
	o=1;
	for(int i=100;i>=1;i--){
		if(a[i]){	
			y+=o;
			if(y==n+1) x++,y=n,o=-1;
			if(y==0) x++,y=1,o=1;
			if(i==s){
				cout<<x<<" "<<y;
				return 0;
			}	
		}
	}
	
	return 0;
}
