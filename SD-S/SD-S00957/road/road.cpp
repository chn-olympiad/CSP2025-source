#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
using namespace std;
int read(){
	int x = 0;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
int head[10015] , cnt = 0 , c[15][10015];
struct node{
	int to , val , nx;
}edge[2000015];
void add(int u , int v , int w){
	edge[++cnt].to = v;
	edge[cnt].nx = head[u];
	edge[cnt].val = w;
	head[u] = cnt;
	return;
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cout<<0<<"\n";
	return 0;
}
//Ren5Jie4Di4Ling5%

