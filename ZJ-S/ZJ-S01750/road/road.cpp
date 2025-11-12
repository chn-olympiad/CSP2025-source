#include<bits/stdc++.h>
using namespace std;
struct STD{
	int u,v,w;
}a[1000005];
bool cmp(STD q,STD h){
	return q.w<h.w;
}
int n,m,k,b[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	
	for(int i=1;i<=k;i++){
		cin>>b[i];
		int p[10001];
		for(int j=1;j<=n;j++){
			cin>>p[i];
		}
		for(int j=1;j<=n;j++){
			for(int g=1;g<=n;g++){
				if(j!=g){
					m++;
					a[m].u=j;
					a[m].v=g;
					a[m].w=b[i]+p[j]+p[g];
				}
			}
		}
	}
	sort(a+1,a+1+m,cmp);
	int k=0;
	for(int i=1;i<=n-1;i++){
		cout<<a[i].w;
	}
	cout<<k;
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
