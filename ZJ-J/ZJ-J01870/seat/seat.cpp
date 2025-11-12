#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=105;
int n,m,sc,dis,c,r;
int a[maxn];
map<int,int> mp;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1,j=n;i<=n;i++,j--){
		mp[i]=j;
	}
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) sc=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==sc) dis=i;
	}
	c=(dis+n-1)/n;
	if(c%2==1){
		if(dis%n==0) r=n;
		else r=dis%n;
	}
	else{
		if(dis%n==0) r=mp[n];
		else r=mp[dis%n];
	}
	cout<<c<<" "<<r;
	return 0;
}