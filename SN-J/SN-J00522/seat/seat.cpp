//SN-J00522 李宸昊  西安市曲江第一学校 
#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define ll long long 
#define inf 0x3f3f3f3f
const int maxn=1e5+5;
int n,m,num,pos;
pair<int,int> a[maxn];
bool cmd(pair<int,int> x,pair<int,int> y){
	return x.first>y.first;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>num;
	a[1]=make_pair(num,1);
	rep(i,2,n*m){
		cin>>num;
		a[i]=make_pair(num,0);
	}
	sort(a+1,a+1+n*m,cmd);
	rep(i,1,n*m) if(a[i].second==1){
		pos=i;
		break;
	}
	int l=(pos-1)/n+1;
	cout<<l<<' '<<(l%2?pos%n:n-pos%n+1);
	return 0;
}
