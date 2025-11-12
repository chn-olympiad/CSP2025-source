#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],r;
bool cmp(int A,int B){
	return A>B;
}
int main(){
	freopen(" seat.in","r",stdin);
	freopen(" seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(r==a[i]){
			if(((i-1)/m+1)%2==1){
				cout<<(i-1)/m+1<<" "<<(i-1)%n+1;
				return 0;
			}
			if(((i-1)/m+1)%2==0){
				cout<<(i-1)/m+1<<" "<<n-(i-1)%n;
				return 0;
			}
		}
	}
	return 0;
}
