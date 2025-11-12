#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int maxn=1e4+10,maxm=1e6+10;
struct node{
	int next,to,w;
}e[2*maxm];
int n,m,k;
int head[maxn],num;
struct village{
	int c;
	int a[maxn];
}v[15];
inline void add(int from,int to,int w){
	e[++num].next=head[from];
	e[num].to=to;
	e[num].w=w;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    memset(head,-1,sizeof head);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
    	int a,b,c;
    	add(a,b,c);
    	add(b,a,c);
	}
	for(int i=1;i<=k;i++){
		cin>>v[i].c;
		for(int j=1;j<=n;j++){
			cin>>v[i].a[j];
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

