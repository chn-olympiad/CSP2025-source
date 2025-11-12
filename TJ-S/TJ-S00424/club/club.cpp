#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
int ans[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for(int i = 0;i < t;i++){
		int n;
		cin >> n;
		for(int j = 1;j <= n;j++){
			cin >>a[j] >> b[j] >> c[j];
		}
		int d;
		d = max(a[1]+b[2],a[1]+c[2]);
		int h;
		h = max(b[1]+a[2],b[1]+c[2]);
		int e;
		e = max(c[1]+a[2],c[1]+b[2]);
		d = max(d,h);
		d = max(d,e);
		ans[i] = d;
	} 
	for(int i = 0;i < t;i++){
		cout << ans[i] <<endl;
	}
} 
