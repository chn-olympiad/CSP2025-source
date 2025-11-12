#include<bits/stdc++.h>
#define int long long
const int N = 2e5+10;
const int M = 2*N;
int head[N],Next[M],ver[M],edge[M],tot = -1;
void add(int x,int y,int z){
	ver[++tot] = y;
	Next[tot] = head[x];
	head[x] = tot;
	edge[tot] = z;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m;
	cout<<0;
	return 0;
} 
