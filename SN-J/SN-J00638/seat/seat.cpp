#include<bits/stdc++.h>
using namespace std;
int n,m,cc;
int a[100005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cc=a[1];
	sort(a+1,a+n*m+1);
	int l=1,r=0,x=0;
	for(int i=n*m;i>=1;i--){
		if(!x)r++;
		else r--;
		if(r>n)l++,x=1,r--;
		if(r<1)l++,x=0,r++;
		//cout<<l<<" "<<r<<"  ";
		if(a[i]==cc){
			cout<<l<<" "<<r;
		}
	}
	return 0;
}
