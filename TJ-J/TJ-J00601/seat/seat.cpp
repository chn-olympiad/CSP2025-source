#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,n,m,s[1001];
	cin>>n>>m;
	int t=n*m,t2;
	for(int i=1;i<=t;i++){
		cin>>s[i];
	}
	t2=s[1];
	sort(s,s+t,cmp);
	for(int i=1;i<=t;i++){
		if(t2==s[i]) a=i;
		//cout<<s[i]<<' '<<a<<' ';
	}
	int c,r,x=a/n;
	if(a%n==0){
		if((a/n)%2==0){ c=a/n; r=1; }
		else if(a/n%2!=0){ c=a/n; r=n; }
	}
	else if(a%n!=0){
		if((a/n+1)%2==0){ c=a/n+1; r=n-(a%n)+1; }
		else if((a/n+1)%2!=0){ c=a/n+1; r=a%n; }
	}
	cout<<c<<" "<<r;
	return 0;
}
