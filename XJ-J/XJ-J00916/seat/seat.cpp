#include<bits/stdc++.h>
using namespace std;

int b[24],tmp=1;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int t=n*m;
	for(int i=1;i<=t;i++){
		cin>>b[i];
	}

	int r=b[1];
	sort(b+1,b+t+1,cmp);
	for(int i=1;i<=t;i++){
		if(r!=b[i]) tmp++;
 		if(r==b[i]) break;
	}
	int c,rr;
	if(tmp%n!=0) c=tmp/n+1;
	if(tmp%n==0) c=tmp/n;
	if(c%2!=0){
		if(tmp%n!=0) rr=tmp%n;
		if(tmp%n==0) rr=tmp/n+1;
	}
	if(c%2==0){
		if(tmp%n!=0) rr=(n+1)-tmp%n;
		if(tmp%n==0) rr=tmp%n+1;
	}
	cout<<c<<" "<<rr;
	return 0;
}
