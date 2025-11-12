#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define R register
#define LL long long
using namespace std;
const int N=105;
int n,m;
bool vis[15][15];
struct Node{
	int x,id;
}a[N];
bool cmp(Node a,Node b){
	return a.x>b.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(R int i=1;i<=n*m;i++) cin>>a[i].x,a[i].id=i;
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=1,idx=1,f;
	vis[1][1]=1;
	while(a[idx].id!=1){
		idx++;
		if(x==1){
			f=1;
			if(!vis[x+1][y]) x++,vis[x][y]=1;
			else y++,vis[x][y]=1;
		}else if(x==n){
			f=-1;
			if(!vis[x-1][y]) x--,vis[x][y]=1;
			else y++,vis[x][y]=1;
		}else{
			x+=f;
			vis[x][y]=1;
		}
	}
	cout<<y<<" "<<x<<'\n';
	return 0;
}
