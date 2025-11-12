#include<bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],b[10][10];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int ccf=1;
	for(int j=1;j<=m;j++){
		if(j%2){
			for(int i=1;i<=n;i++){
				b[i][j]=ccf;
				ccf++;
			}
		}
		else{
			for(int i=n;i>=1;i--){
				b[i][j]=ccf;
				ccf++;
			}
		}
	}
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	int l=1,r=n*m,cnt;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]==x){
			cnt=mid;
			break;
		}
		else if(a[mid]>x) l=mid+1;
		else r=mid-1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==cnt){
				cout<<j<<' '<<i<<endl;
				return 0;
			}
		}
	}
	return 0;
}
