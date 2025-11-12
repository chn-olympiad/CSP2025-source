#include<bits/stdc++.h>
using namespace std;
int a[101];
int t;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i],t=a[1];
	sort(a+1,a+n*m+1);
	int sum=n*m;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				if(a[sum]==t) cout<<i<<" "<<j;
				sum--;
			}
		}
		else{
			for(int j=m;j>0;j--){
				if(a[sum]==t) cout<<i<<" "<<j;
				sum--;
			}
		}
	}
	return 0;
}
