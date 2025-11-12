#include<bits/stdc++.h>
using namespace std;
int n,m,a[111],k;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		if(i==1) {
			cin>>k;
			a[1]=k;
		}
		else cin>>a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	int l=1,r=n*m,mid,cnt;
	while(l<=r){
		mid=(l+r)>>1;
		if(a[mid]<k){
			r=mid-1;
		}
		else if(a[mid]>k){
			l=mid+1;
		}
		else if(a[mid]==k){
			cnt=mid;
			break;
		}
	}
	int h=cnt/n;
	cnt%=n;
	if(cnt==0) cnt=n;
	if(cnt!=n) h++;
	if(h%2==0){
		cout<<h<<" "<<n-cnt+1;
	}else{
		cout<<h<<" "<<cnt;
	}
	return 0;
}
