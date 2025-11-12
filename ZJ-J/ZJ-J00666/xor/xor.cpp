#include<iostream>
#include<cstdio>
using namespace std;
long long n,k,a[500005],ans;
void f(long long x,long long y,long long z,bool b){
	if(y==k&&b)z++,y=0;
	if(x>=n){
		ans=max(ans,z);
		return;
	}
	f(x+1,y^a[x],z,1);
	f(x+1,0,z,0);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=0;i<n;i++)cin>>a[i];
	f(0,0,0,0);
	cout<<ans;
	return 0;
}
