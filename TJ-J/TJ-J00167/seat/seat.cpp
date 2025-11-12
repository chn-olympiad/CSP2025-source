#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	
	int n,m;
	int a1,si;
	int r=0;
	int h,l;
	cin>>n>>m;
	cin>>a1;
	for(int i=1;i<n*m;i++){
		cin>>si;
		if(si>a1) r++;
	}
	h=(r/n)+1;
	if(h%2==1) l=r%n+1;
	else l=n-r%n;
	cout<<h<<" "<<l<<endl;
	return 0;
}
