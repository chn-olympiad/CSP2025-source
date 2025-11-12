//SN-J00627 —Ó„ÎÃŒ ≥§«Ï∞À÷–
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10005];
int cnt=0;
int cnt1;
int s;
int h,l;
int q=1,d[10005];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
		cnt++;
	}
	s=a[1];
	sort(a+1,a+cnt+1);
	for(int i=n*m;i>=1;i--){
		d[q]=a[i];
		q++;
}
	for(int i=1; i<=n*m; i++) {
		if(d[i]==s) {
			cnt1=i;
			break;
		}
	}
	l=(cnt1-1)/m+1;
	if(l%2==0) {
		h=(n+1)-cnt1%m;
	} else {
		if(cnt1==m) {
			h=m;
		} else {
			h=cnt1%m;
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
