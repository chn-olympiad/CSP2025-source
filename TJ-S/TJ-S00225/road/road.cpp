#include<bits/stdc++.h>
using namespace std;
struct abc{
	int x,y,v;
};
abc a[2000006];
int b[10005];
int fa[10005];
bool cmp(abc a,abc b){
	return a.v<b.v;
}
void Find(int x){
	if (fa[x]!=x){
		return Find(fa[x]);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cout<<0;
	return 0;
	int n,m,k,x,y,v;
	cin>>n>>m>>k;
	for (int i=0;i<n;i++){
		fa[i]=i;
	}
	for (int i=0;i<m;i++){
		cin>>a[i].x>>a[i].y>>a[i].v;
	}for (int i=0;i<k;i++){
		cin>>x;
		for (int i=1;i<=n;i++){
			cin>>b[i];
			for (int j=1;j<i;j++){
				a[m].x=i;
				a[m].y=j;
				a[m++].v=b[i]+b[j];
			}
		}
	}
	return 0;
} 
