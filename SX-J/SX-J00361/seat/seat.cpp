#include<bits/stdc++.h>
using namespace std;
long long arr[105];
bool q(long long x,long long y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long rs;
	rs=n*m;
	for(int i=1;i<=rs;i++){
		cin>>arr[i];
	}
	long long r=arr[1];
	long long mc=0;
	sort(arr+1,arr+rs+1,q);
	for(int i=1;i<=rs;i++){
		if(arr[i]==r){
			mc=i;
		}
	}
	if(mc<n||mc==n){
		cout<<1<<" "<<mc;
		return 0;
	}
	long long v=(mc-1)/n;
	if(v%2==0){
		cout<<v+1<<" "<<1;
	}
	else if(v%2!=0){
		cout<<v+1<<" "<<n;
	}
	return 0;
}