#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],w,cnt1=1,cnt2=1,cnt=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]==r){
			w=n*m-i+1;
			break;
		}
	}
	while(cnt1<=m){
		cnt++;
		if(cnt==w){
			cout<<cnt1<<" "<<cnt2;
			return 0;
		}
		if(cnt1%2==1){
			if(cnt2==n){
				cnt2=n;
				cnt1++;
			}
			else cnt2++;
		}
		else{
			if(cnt2==1){
				cnt2=1;
				cnt1++;
			}
			else cnt2--;
		}
	}
	return 0;
}
