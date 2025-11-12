#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long u,v,w;
long long c,a[100000];
bool ciy[10000];
struct node{
	long long u,v,w;
}lu[100000];
bool cmp(node a,node b){
	return a.w < b.w;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >>k;
	memset(ciy,false,sizeof(ciy));
	long long l = 1;
	for(int i = 1;i <= m;i++){
		cin >> u >> v >> w;
		lu[l].u = u;
		lu[l].v = v;
		lu[l].w = w;
		l++;
	}
	for(int i = 1;i <= k;i++){
		cin >> c;
		for(int j = 1;j <= n;j++){
			cin >> a[j];	
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(i != j){
					lu[l].u = i;
					lu[l].v = j;
					lu[l].w = a[i]+a[j]+c;
					l++;	
				}
			}
		}
	}
	sort(lu+1,lu+1+l,cmp);
	long long sum = 0;
	for(int i = 1;i <= l;i++){
		if(ciy[lu[i].u] == false || ciy[lu[i].v] == false){
			sum += lu[i].w;
			ciy[lu[i].u] = true;
			ciy[lu[i].v] = true;
		}
	}
	cout << sum;
	return 0;
}
