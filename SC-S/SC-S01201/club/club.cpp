#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int t;
int k[N][4];
int f[4][4];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> t;
	int n;
	while(t--){
		int ans=0;
		cin >> n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++) cin >> k[i][j];
		}
		
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++){
				f[i][j]=k[1][i]+k[2][j];
				if(i!=j) ans=max(ans,f[i][j]);
			}
		}
		
		cout << ans << endl;
	}
	
	
} 