
#include<bits/stdc++.h>
using namespace std;
int n,m,s[114][114],a[11451],aa; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	aa=a[1];
	sort(a,a+n*m+1);
	int num=n*m;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[num]==aa) {
					cout<<i<<" "<<j;
					return 0;
				}
				else num--;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(a[num]==aa) {
					cout<<i<<" "<<j;
					return 0;
				}
				else num--;
			}
		}
	}
	return 0;
}
