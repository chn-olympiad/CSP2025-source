#include <bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int v,id;
}a[10000];

bool cmp(node x,node y){
	return x.v>y.v;
}

int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i=1;i<=n*m;i++){
		cin >> a[i].v;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	
	int tot=0;
	int ansx=0,ansy=0;
	for (int i=1;i<=m;i++){
		if (i%2==1){
			for (int j=1;j<=n;j++){
				tot++;
				if (a[tot].id==1){
					ansx=i,ansy=j;
					break;
				}
			}
		}
		else{
			for (int j=n;j>=1;j--){
				tot++;
				if (a[tot].id==1){
					ansx=i,ansy=j;
					break;
				}
			}
		}
	}
	cout << ansx << ' ' << ansy;
	return 0;
}
