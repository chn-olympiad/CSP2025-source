#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b) {
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[100005];
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int mark=a[1];
	sort(a+1,a+1+n*m,cmp);
	int t=2*n;
	int pos=0;
	int l=1,r=n*m;
	while(true){
		int mid=(l+r)/2;
		if(a[mid]>mark) l=mid+1;
		if(a[mid]<=mark) r=mid;
		if(mark==a[mid]){
			pos=mid;
			break;
		}
		if(a[l]==mark){
			pos=l;
			break;
		}
		if(a[r]==mark){
			pos=r;
			break;
		}

		
	}
	int c=2*(pos/t);
	if(pos%t == 0) {
		cout<<c<<' '<<1;
		return 0;
	}
	int left=pos-(c/2*t);
	if(left>n){
		c+=2;
		left-=n;
		cout<<c<<' '<<n-left+1;
		return 0;
	}
	if(left<=n){
		c++;
		cout<<c<<' '<<left;
	}
	return 0;
}
