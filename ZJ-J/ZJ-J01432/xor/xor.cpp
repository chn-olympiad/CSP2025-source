#include<bits/stdc++.h> 
using namespace std;
const int N=1e3+10,M=1e6+2;
int n,m,a[N],b[N],ct=0,maxx=-1e9;
struct node{
	int l,r;
}e[M];
bool cmp(node xx,node yy){
	if(xx.l!=yy.l) return xx.l<yy.l;
	else return xx.r<yy.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=b[i-1]^a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if((b[i]^b[j-1])==m) {
				e[++ct].l=j,e[ct].r=i;
			}
		}
	}
	sort(e+1,e+ct+1,cmp);
	for(int i=1;i<=ct;i++){
		int l=e[i].l,r=e[i].r,cnt=1;
		for(int j=i+1;j<=ct;j++){
			if(e[j].l>=l&&e[j].l<=r) continue;
			cnt++;
			l=e[j].l,r=e[j].r;
		}
		maxx=max(maxx,cnt);
	}
	cout<<maxx<<endl;
}
/*
4 3
2 1 0 3
4 2
2 1 0 3
4 0
2 1 0 3
100 1
1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 
1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 
1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 
1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1


*/

