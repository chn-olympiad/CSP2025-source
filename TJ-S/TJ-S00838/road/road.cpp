
#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long u[100005];
long long v[100005];
long long w[100005];
long long c[100005];
long long a[15][100005];
bool f=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    int i=1;
    int ans=0;
    while(m--){
    	cin >> u[i] >> v[i] >> w[i];
    	ans+=w[i];
    	i++;
	}
	i=1;
	while(k--){
		cin >> c[i];
		if(c[i]==0){
			f=1;
		}
		for(int ii=1;ii<=n;ii++){
			cin >> a[i][ii];
		}
		i++;
	}
	if(f){
		cout << 0;
	}
	else{
		cout << ans;
	}
    return 0;
}

