#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m,r,w,l,h,a[110];
bool flag=1;
bool cmp(int A,int B){
	return A>B;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>r;
	for(int i=1;i<n*m;i++)cin>>a[i];
	sort(a+1,a+n*m,cmp);
	for(int i=1;i<n*m;i++){
		if(a[i]<r&&flag){
			w=i;
			flag=0;
		}
	}
	if(w==0)w=n*m;
	l=(w+n-1)/n;
	h=w%n;if(h==0)h=n;
	if(l%2==0)h=n-h+1;
	cout<<l<<" "<<h<<endl;
	return 0;
}
