#include<bits/stdc++.h>
using namespace std;
int n,m,r,cnt;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","rw",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			cnt=n*m-i;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				if(cnt==0){
					cout<<i<<' '<<j;
					return 0;
				}
				cnt--;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(cnt==0){
					cout<<i<<' '<<j;
					return 0;
				}
				cnt--;
			}
		}
	}
	return 0;
}
//Hikari from Eternal Core, Luminous Sky and Final Verdict
