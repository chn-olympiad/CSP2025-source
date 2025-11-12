#include<bits/stdc++.h>
using namespace std;
long long n,m,lie,hang,x,l,r,mid,wz,a[110];
bool cmp(long long q,long long h){
	return q>h;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++)cin>>a[i];
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	l=1;r=n*m;
	while(l<=r){
		mid=(l+r)/2;
		if(a[mid]<x)r=mid-1;
		else if(a[mid]>x)l=mid+1;
		else if(a[mid]==x){
			wz=mid;
			break;
		}
	}
	lie=wz/(2*n)*2;
	if(wz%(2*n)>0)lie++;
	if(wz%(2*n)>n)lie++;
	hang=wz%(2*n);
	if(hang>n)hang=n*2-hang+1;
	else if(hang==0)hang=1;
	cout<<lie<<" "<<hang;
	return 0;
}
