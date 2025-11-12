#include<bits/stdc++.h>
using namespace std;
/*
2 2
99 100 97 98
*/
/*
2 2
98 99 100 97
*/
/*
3 3
94 95 96 97 98 99 100 93 92
*/
int a[105]={};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ans;
	cin>>n>>m;
	int len=n*m;
	for(int i=1;i<=len;i++) cin>>a[i]; 
	ans=a[1];
	sort(a+1,a+len+1);
//	cout<<len<<" ";
//	for(int i=1;i<=len;i++) cout<<a[i]<<" ";
	for(int i=len;i>=1;i--){
		if(a[i]==ans){
//			cout<<a[i]<<" "<<len-i+1<<endl;
			int c=0,r=0;
			c=(len-i)/n+1;
			//m-(i-1)/n
			if(c%2==0) r=(i-1)%n+1;
			else r=n-(i-1)%n;
			cout<<c<<" "<<r<<endl;
			return 0;
		}
	}
	return 0;
} 
