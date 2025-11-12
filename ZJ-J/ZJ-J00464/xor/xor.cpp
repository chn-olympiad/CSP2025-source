#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],ans,st;
long long n,k;
int fun(int x,int y){
	int r=0,f=1;
	while(x>0||y>0){
		if(x%2!=y%2)r+=f;
		x/=2;
		y/=2;
		f*=2;
	}
	return r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int t=0,f=0,d=0,x,y;
		for(int j=i;j<=n;j++){
			t=fun(a[j],t);
			//cout<<t<<"\n";
			if(a[j]==k){
				ans++;
				i=j;
				break;
			}
			else if(t==k){
				ans++;
				i=j;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
