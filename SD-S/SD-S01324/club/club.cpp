#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PLL;
int a[210][5];
int f[210][210][210];
int n;
void s1(){
	vector<int>v;
	for(int i=1;i<=n;i++){
		v.push_back(a[i][1]);
	}
	sort(v.begin(),v.end(),greater<int>());
	int ans=0;
	for(int i=0;i<=n/2;i++){
		ans+=v[i];
	}
	cout<<ans;
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		int tepan1=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if(a[i][2]!=0||a[i][3]!=0)tepan1=1;
		}
		if(!tepan1){
			s1();
			return 0;
		}
		int ans=0;
		memset(f,0,sizeof f);
		for(int i=1;i<=n;i++){
			for(int j=0;j<=min(i,n/2);j++){
				for(int k=0;k<=min(i,n/2);k++){
					int g=i-j-k;
					if(g<0){
						continue;
					}
					if(j)f[j][k][g]=max(f[j][k][g],f[j-1][k][g]+a[i][1]);
					if(k)f[j][k][g]=max(f[j][k][g],f[j][k-1][g]+a[i][2]);
					if(g)f[j][k][g]=max(f[j][k][g],f[j][k][g-1]+a[i][3]);
				}
			}
		}
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				if(n-i-j>n/2)continue;
				ans=max(ans,f[i][j][n-i-j]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
