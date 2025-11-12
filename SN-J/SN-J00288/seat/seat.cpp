#include<bits/stdc++.h>
using namespace std;
freopen("seat.in","r",stdin);
freopen("seat.in","w",stdout);
int main(){
	int n,m,s[1005],maxx=0,o=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	} 
	int q=s[1];
	sort(s,s+n*m+1);
	for(int i=n*m;i>=1;i--){
		o++;
		if(s[i]==q) break;
		
	}
	int r,c;
	r=o/n;
	if(o%n!=0) r++;
	if(r%2!=0){
		c=o/n*n+o%n;
	}
	else c=o%n+1;
	cout<<r<<" "<<c;
	return 0;
}

