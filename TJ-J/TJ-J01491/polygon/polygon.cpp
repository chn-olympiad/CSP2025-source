#include<bits/stdc++.h>
using namespace std;
long long n,a[6000];
long long o=998244353;
long long df(int x,int y,int b,long long da){
	if(x==n+1&&b>=3&&da*2<y) {
		return 1; 
	}
	if(x==n+1){
		return 0;
	}
	long long sum=0;
	sum+=df(x+1,y+a[x],b+1,max(da,a[x]));
	sum+=df(x+1,y,b,da);
	return sum%o;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<df(1,0,0,0);
	return 0;
} 
