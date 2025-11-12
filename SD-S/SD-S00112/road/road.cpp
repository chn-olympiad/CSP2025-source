#include<bits/stdc++.h>
using namespace std;
long long n,m,k,b[11],d[50005],c[11][50005],sum,flag;
struct Node{
	int u,v,w;
}a[500005];
bool cmp(Node A,Node B){
	return A.w < B.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	for(int i = 1;i <= k;i++){
		cin >> b[i];
		for(int j = 1;j <= n;j++){
			cin >> c[i][j];
		}
	}
	for(int i = 1;i <= k;i++){
		for(int j = 1;j <= n;j++){
			for(int o = j + 1;o <= n;o++){
				a[++m].u = j;
				a[m].v = o;
				a[m].w = b[i] + c[i][j] + c[i][o];
			}
		}
	}
	sort(a + 1,a + 1 + m,cmp);
	for(int i = 1;i <= m;i++){
		d[a[i].u]++; d[a[i].v]++; sum += a[i].w;
		if(flag) break;
		for(int j = 1;j <= n;j++){
			if(d[j] < 1) break;
			flag = 1;
		}
	}
	cout << sum;
	return 0;
} 
