#include<bits/stdc++.h>
using namespace std;
const int md=998244353;
int n,a[5005];
long long cnt;
long long A(int en,int x){
	long long ji=1;
	for(int i=0;i<x;i++)ji*=(en-i);
	for(int i=1;i<=x;i++)ji/=i;
	return ji;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		for(int sz=3;sz<=n-i;sz++){
			int sum=0,en=i+sz-1;
			for(int j=1;j<sz;j++)sum+=a[i+j];
			if(sum<=a[i])continue;
			while(sum>a[i]){
				sum=sum+a[en+1]-a[en-sz+2];
				en++;
			}
			if(en<n)en--;
			cnt+=A(en,sz);
			cnt%=md;
		}
	}
	cout<<cnt/2+1;
	return 0;
}