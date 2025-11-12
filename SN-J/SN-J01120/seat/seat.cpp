#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int ans=a[0];
	sort(a,a+n*m);
	for(int i=0;i<n*m;i++){
		if(ans==a[i]){
			int k=n*m-1-i;
			if((k/n)%2==0){
				cout<<k/n+1<<" "<<k%n+1;
			}else{
				cout<<k/n+1<<" "<<n-k%n;
			}
		}
	}
	return 0;
}
