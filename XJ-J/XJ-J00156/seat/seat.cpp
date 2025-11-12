#include<bits/stdc++.h>
using namespace std;
int n,m;
int t[1005],r,p,l,h;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>t[i];
		if(t[i]>t[1]) p++;
	}
	p++;
	l=ceil(p*1.0/n);
	if(l%2==0){
		h=n-(p-n*(l-1))+1;
	}else{
		h=p-n*(l-1);
	}
	cout<<l<<" "<<h;
	return 0;
}
