#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,i,r,s,k=-1;
	int a[10][10],s1[100];
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
	  	cin>>s;
	    if(s1[i]>k) k=s1[i]==a[1][1];
		if(s>s1[i]) s1[i]=1==a[i-1][1];
		if(s<s1[i]) s1[i]=0==a[i-1][i-1];
	}	
	cout<<s1[n]; 
	return 0;
}
