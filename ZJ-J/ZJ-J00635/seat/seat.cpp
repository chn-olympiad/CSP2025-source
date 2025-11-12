#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=1000;
LL n,m,a[N],x,tx,ty,k;
bool cmp(LL i,LL j){return i>j;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	tx=ty=1;k=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){cout<<ty<<" "<<tx;return 0;}
		if(i%n==0){
			if(tx==n) ty++,k=-1;
			else ty++,k=1;
		}else tx+=k;
	}
	return 0;
}