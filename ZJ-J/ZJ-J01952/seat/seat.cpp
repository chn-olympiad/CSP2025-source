#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000100],grade,k;
int cmp(int q,int h){
	return q>h;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	k=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			grade=i;
			break;
		}
	}
	int cnt=ceil(grade*1.0/n);
	if(cnt%2==0){
		int l=grade-(cnt-1)*n;
		cout<<cnt<<" "<<n-l+1;
	}else{
		int r=grade-(cnt-1)*n;
		cout<<cnt<<" "<<r;
	}
	return 0;
}
