#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	int u[1000023],v[1000023],w[1000023];
	for(int i=0;i<n;i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	int c[1000012],a[1000023][1020003];
	for(int i=0;i<k;i++){
		cin >> c[i];
		for(int j=0;j<n;j++){
			cin >> a[i][j];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			if(i < j && w[i] > w[j]){
				swap(w[i],w[j]);
				swap(u[i],u[j]);
				swap(v[i],v[j]);
			}
		}
	}
	int cnt = 0;
	int mn = 10000034;
	for(int i=0;i<m;i++){
		for(int j=0;j<i;j++){
			cnt += w[j];
			int l = u[j];
			int r = v[j];
			int mni, mnn = 10000033;
			for(int f=0;f<k;f++){
				if(mnn > c[f]){
					mnn = c[f];
					mni = f;
				}
			}
			cnt += mnn;
			for(int f=0;f<n;f++){
				if(f+1 != l && f+1 != r){
					cnt += a[mni][f]; 
				}
			}
		}
		mn = min(mn,cnt);
		cnt = 0;
	}
	cout << mn;
	return 0;
}
