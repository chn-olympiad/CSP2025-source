#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[10005],s[105][105],c=1,r=1,b;
	cin>>n>>m;
	int x=n*m;
	for(int i=0;i<x;i++){
		cin>>a[i];
	}
	b=a[0];
	sort(a,a+x);
	while(1){
		for(int i=0;i<n;i++){
			if(a[i]==b){
				cout<<c<<r;
				return 0;
			}
			c++;
		}
		r++;
	}

	return 0;
}


