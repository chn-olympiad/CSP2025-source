#include<bits/stdc++.h>
using namespace std;
int n,k,t[500005],s,j,ans=0;
int a[25],b[25],c[25],al,bl,cl,p=0;
int solve(int x,int y){
	al=0,bl=0,cl=0;
	while(x!=0){
		a[++al]=x%2;
		x/=2;
	}
	while(y!=0){
		b[++bl]=y%2;
		y/=2;
	}
	cl=max(al,bl);
	for(int i=cl;i>=1;i--)
		if(a[i]!=b[i])c[i]=1;
	for(int i=1;i<=cl;i++)
		p+=c[i]*pow(2,i-1);
	return p;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>t[i];
	j=1;
	s=t[1];
	for(int i=2;i<=n;i++){
		if(s==k){
			ans++;
			s=0;
			j=i+1;
		}
		s=solve(s,t[i]);
		if(i==n){
			if(j<n)j++;
			s=t[j];
			i=j;
		}
	}
	cout<<ans;
	return 0;
}