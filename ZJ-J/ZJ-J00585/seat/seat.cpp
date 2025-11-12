#include<bits/stdc++.h>
using namespace std;

int n,m,a[111],h;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	h=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		//cout<<a[i]<<"\n";
		if(a[i]==h){
			int c=i/n;
			if(i%n>0)c++;
			int r=i%n;
			if(r==0)r+=n;
			if(c%2==0)r=n-r+1;
			//cout<<i<<" ";
			cout<<c<<" "<<r;
			return 0;
		}
	}
}
