#include<bits/stdc++.h>
using namespace std;

int pt[105],n,m,r,q,ls,num;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>pt[i];
	}
	r=pt[0];
	sort(pt,pt+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(pt[i]==r) q=i+1;
	}
	if(q%n) num=q%n;
	else num=n;
	if(q%n==0) ls=q/n;
	else ls=q/n+1;
	if(ls%2) cout<<ls<<" "<<num;
	else cout<<ls<<" "<<n-num+1;
	
	return 0;
}
