#include <bits/stdc++.h>
using namespace std;
int n,m;
int mp[15][15];
int a[105],ar;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ar=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m*n;i++){
		if(a[i]==ar){
			int rl;
			int rh;
			if(i%n==0){
				rl=i/n;
			}else if(i%n!=0){
				rl=i/n+1;
			}
			if(rl%2==1){
				if(i%n!=0){
					rh=i%n;
				}else{
					rh=n;
				}
			}else if(rl%2==0){
				if(i%n!=0){
					rh=n+1-i%n;
				}else{
					rh=1;
				}
			}
			cout<<rl<<" "<<rh;
			return 0;
		}
	}
}
