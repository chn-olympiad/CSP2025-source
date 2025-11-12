#include<bits/stdc++.h>
using namespace std;
const int M = 1e6+5;
int n,m,k,town[15],maxx,a;
struct roads{
	int from,to,cost;
}a[M];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 0;i < m;i++){
		cin >> a[i].from >> a[i].to >> a[i].cost;
		a = a[i].from + a[i].to + a[i].cost;
		maxx = max(maxx,a);
	}	
	for(int i=0;i < k;i++){
		cin >> town[i];
	}
	cout << a;  
}
