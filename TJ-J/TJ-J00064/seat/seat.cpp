#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int s[15][15]={0};
	int a[105];
	int A;
	int n,m;
	cin>>m>>n;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	A=a[1];
	sort(a+1,a+m*n+1);
	int ans=1;
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int j=1;j<=m;j++){
				if(a[n*m-ans+1]==A){
					cout<<i<<" "<<j;
				}
				ans++;
			}
		}else{
			ans=i*m;
			for(int j=m;j>0;j--){
				if(a[n*m-ans+1]==A){
					cout<<i<<" "<<j;
				}
				ans--;
			}
			ans=i*m+1;
		}
	}
	return 0;
}

