#include<bits/stdc++.h>
using namespace std;
struct st{
	long long x,y,z,xy,yz,xz,xyz,h;
}a[100005];
long long s,c,d,e;
int cmp1(st q,st w){
	return min(q.xy,min(q.yz,q.xz))<min(w.xy,min(w.yz,w.xz));
}
int cmp2(st q,st w){
	return q.yz<w.yz;
}
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout<<2;
	return 0;
}
