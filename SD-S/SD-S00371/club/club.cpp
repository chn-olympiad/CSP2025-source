#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back

const int N=1e5+10;
int T,n,a[N][10],p[10],ans;

signed main(){
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	ios;
	cin >> T;
	while(T--){
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		for(int i=1;i<=n;i++){
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
				if(p[1]<=n/2){
					p[1]++;ans+=a[i][1];
				}else{
					if(p[2]<=n/2){
						
					}
				}
			}
		}
	}
	return 0;
}

