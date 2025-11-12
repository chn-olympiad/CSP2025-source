#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int x,cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			cout<<(i-1)/n+1<<" ";
			if(((i-1)/n+1)%2==1){
				if(i%n==0){
					cout<<n;
				}else{
					cout<<i%n;
				}
			}else{
				if(i%n==0){
					cout<<1;
				}else{
					cout<<n+1-i%n;
				}
			}
			return 0;
		}
	}
	return 0;
}
