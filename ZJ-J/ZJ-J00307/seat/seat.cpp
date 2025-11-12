#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[105],scr,seat;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	scr=a[1];
	sort(a+1,a+n*m+1,cmp);
	int l=0,r=n*m+1;
	while(l+1<r){
		int mid=(l+r)/2;
		if(scr<a[mid])
			l=mid;
		else if(scr>a[mid])
			r=mid;
		else l=r=mid;
	}
	if(a[r]==scr)
		seat=r;
	else if(a[l]==scr)
		seat=l;
	int w,h;
	w=ceil(seat*1.0/n);
	int t;
	if(w%2==0){
		t=seat%n;
		if(t!=0)
		 	t=n-t+1;
		else if(t==0){
			t=1;
		}
		h=t;
	}
	else{
		t=seat%n;
		if(t==0)
			t=n;
		h=t;
	}
	cout<<w<<" "<<h;
	return 0;
}