#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],j,nm,ans;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	nm=n*m;
	for(int i=0;i<nm;i++)cin>>a[i];
	ans=a[0];
	sort(a,a+nm,cmp);
	for(int i=0;i<n;i++){
		if(i%2==0){
			for(;j<m;j++){
				if(a[i*m+j]==ans){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
			}
			j--;
		}else{
			for(;j>=0;j--){
				if(a[i*m+m-j-1]==ans){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
			}
			j++;
		}
	}
	return 0;
}