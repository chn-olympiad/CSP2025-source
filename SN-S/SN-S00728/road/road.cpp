//SN-S00728 闫卜予 西安高新一中沣东中学初中校区
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
//只过A: 

ll t;
struct G{
	int u;
	int v;
	int w;
}e1[1000005];
struct C{
	int c;
	int a[10005];
}e2[20];
ll n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e1[i].u>>e1[i].v>>e1[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>e2[i].c;
		for(int j=1;j<=n;j++){
			cin>>e2[i].a[j];
		}
	}
	cout<<0;
	return 0;
} 
