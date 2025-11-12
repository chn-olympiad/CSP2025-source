#include <bits/stdc++.h>
using namespace std;
int n,m;
int a;
int t;
int f[10010];
vector<int>  v;
bool cmp(int x, int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> f[1];
	a=f[1];
	for(int i=2;i<=n*m;++i){
		cin >> f[i];
	}
	sort(f+1,f+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(f[i]==a){
			t=i;
			break;
		}
	}
	int u,v;
	u=(t-1)/n+1;
	v=t%n;
	if(v==0)  v=n;
	if(u%2==0) v=n+1-v;
	cout << u << " " << v;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
