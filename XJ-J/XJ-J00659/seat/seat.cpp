#include<bits/stdc++.h>
using namespace std;
int tmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[15][15],s[200];
	int n,m,flag,flag2;
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>s[i];
	}
	int r=s[1];
	sort(s+1,s+n*m+1,tmp);
	for(int i = 1;i<=n*m;i++){
		if(s[i]==r){
			flag=i;
			break;
		}
	}
	

	int l,h;
	if(flag<=n)l=1;
	else if(flag%n==0)l=flag/n;
	else l=flag/n+1;
	if(l&2!=0){
		h=flag-(l-1)*n;
	}
	
	else {
		flag-=(l-1)*n;
		int b[n+5];
		for(int i = 1;i<=n;i++){
			b[i]=i;
		}
//		cout<<l<<endl;
//		cout<<flag<<endl;
		for(int i = n;i>=1;i--){
			if(b[i]==flag)flag2=i;
		}
//		cout<<flag2<<endl;
		for(int i = 1;i<=n;i++){
			h=b[flag2];
			break;
		}
	}
	
	
	cout<<l<<" "<<h;
	return 0;
}
