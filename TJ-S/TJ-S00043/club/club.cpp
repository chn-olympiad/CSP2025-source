#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> b(n);
		vector<int> c(n);
		vector<pair<int,int> > d(n);
		vector<pair<int,int> > e(n);
		vector<pair<int,int> > f(n);
		vector<int> g(n);
		for (int i = 0; i < n; i++){
			d[i].second = i;
			cin >> a[i] >> b[i] >> c[i];
			if (max(a[i],max(b[i],c[i])) == a[i]){
				d[i].first = a[i] - max(b[i],c[i]);
				f[i].first = max(b[i],c[i]);
				g[i] = 1;
			}
			else if (max(a[i],max(b[i],c[i])) == b[i]){
				d[i].first = b[i] - max(a[i],c[i]);
				f[i].first = max(a[i],c[i]);
				g[i] = 2;
			}
			else {
				d[i].first = c[i] - max(a[i],b[i]);
				f[i].first = max(b[i],a[i]);
				g[i] = 3;
			}
			e[i].first = max(a[i],max(b[i],c[i]));
			//cout << d[i].first << endl;
		}
		long long ans = 0;
		sort(d.begin(),d.end());
		vector<pair<int,int> > d1(n);
	    for (int i = d.size() - 1; i >= 0; i--){
	    	d1[d.size() - i - 1].first = d[i].first;
	    	d1[d.size() - i - 1].second = d[i].second;
		}
		if (n == 2){
			ans += e[d1[0].second].first;
			if (d1[0].second == 0){
			    if (g[0] == 1){
			    	ans += max(b[1],c[1]);
				}
			    if (g[0] == 2){
			    	ans += max(a[1],c[1]);
				}
			    if (g[0] == 3){
			    	ans += max(a[1],b[1]);
				}
			}
			else if (d1[0].second == 1){
			    if (g[1] == 1){
			    	ans += max(b[0],c[0]);
				}
			    if (g[1] == 2){
			    	ans += max(a[0],c[0]);
				}
			    if (g[1] == 3){
			    	ans += max(a[0],b[0]);
				}
			}
			cout << ans << endl;
			continue;
		}
		int a1 = 0,a2 = 0,a3 = 0;
		for (int i = 0; i < n / 2; i++){
			ans += e[d[i].second].first;
			if (g[d[i].second] == 1){
				a1++;
			}
			if (g[d[i].second] == 2){
				a2++;
			}
			if (g[d[i].second] == 3){
				a3++;
			}
		}
		for (int i = n / 2; i < n; i++){
			if (g[d[i].second] == 1){
				if (a1 <= n / 2){
					ans += e[d[i].second].first;	
					a1++;
				}
				else ans += f[d[i].second].first;
			}
			else if (g[d[i].second] == 2){
				if (a2 <= n / 2){
					ans += e[d[i].second].first;
					a2++;
				}
				else ans += f[d[i].second].first;
			}
			else if (g[d[i].second] == 3){
				if (a3 <= n / 2){
					ans += e[d[i].second].first;		
					a3++;	
				}
				else ans += f[d[i].second].first;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
