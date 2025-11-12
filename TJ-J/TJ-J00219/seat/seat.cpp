#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[150];
int p;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int x=n*m;
	for(int i=1;i<=x;i++)cin>>a[i];
	int t=a[1];
	sort(a+1,a+x+1,cmp);
	for(int i=1;i<=x;i++)if(t==a[i])p=i;
	int e=p/n;
	if(p<=n)cout<<1<<" ";
	else{
		if(p%n==0)cout<<e<<" ";
		else cout<<e+1<<" ";
	}
	if(p%n!=0){
		if(p<n)cout<<p;
		else{
			if(e%2!=0)cout<<n-(p%n)+1;
			else cout<<p%n;
		}
	}
	else{
		if(e%2!=0)cout<<n;
		else cout<<1;
	}
	return 0;
} 
