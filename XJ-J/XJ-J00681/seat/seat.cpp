#include<bits/stdc++.h>
using namespace std;
int s[120];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a1,z,a2,x,y,bj=0;
	cin>>n>>m;
	z=m*n;
	for(int i=1;i<=z;i++){
		cin>>s[i];
	}
	a1=s[1];
	for(int i=1;i<=z;i++){
		for(int j=1;j<=z;j++){
			if(s[j]<s[j+1])swap(s[j],s[j+1]);
		}
	}
	for(int i=1;i<=z;i++){
		if(s[i]==a1)a2=i;
	}
	if(a2%n==0){
		x=a2/n;
		if(x%2==0)y=1;
		else y=n;
		bj=1;
	}
	else x=a2/n+1;
//	int qs=(x-1)*m+1,zz=x*m;
	if(x%2==0){
		for(int i=x*m;i>=x*m-x;i--)if(s[i]=a1)y=i;
//		sort(qs+s,qs+s+m);
//		for(int i=qs;i<=zz;i++){
//			if(s[i]==a1)y=i;
//		}
	}
//	y=n-a2%n;
	else if(bj==0)y=a2%n;
	cout<<x<<" "<<y;
	return 0;
} 
