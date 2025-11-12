#include<bits/stdc++.h>
#define int long 

using namespace std;

const int N=20;

int n,m,a[100];

struct node{
	int idx,num;
}g[N];

bool cmp(node aaa,node bbb){
	return aaa.num>bbb.num;
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 	freopen("seat.in","r",stdin); freopen("seat.out","w",stdout);
	cin>>n>>m; int cnt=n*m;
	for(int i=1;i<=cnt;i++){ cin>>g[i].num; g[i].idx=i; }
	sort(g+1,g+1+cnt,cmp);
	int x=1,y=1,now=1;// x  lie   y   hang 
	while(1){
		if(g[now].idx==1){
			cout<<x<<" "<<y<<"\n";
			return 0;
		}
		if(x%2==1){
			if(y==n) x++;
			else y++;
		}else{
			if(y==1) x++;
			else y--;
		}
		now++;
	}
	return 0;
}
