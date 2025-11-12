//SN-J00389  张爱熙  西安高新第一中学
#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,a[N],k,num;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	k=a[1];
	sort(a+1,a+n*m+1);
	for(int j=n*m;j>0;j--){
		if(a[j]==k){
			int i=n*m-j+1;
			int x=(i+n-1)/n,y=i%n;
			if(x%2<1){
				if(y>0) y=n-y+1;
				else y=1;
			}
			if(x%2>0 && y<1) y=n;
			cout<<x<<" "<<y;
			return 0;
		}
	}
	return 0;
}
