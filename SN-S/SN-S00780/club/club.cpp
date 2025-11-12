#include<bits/stdc++.h>
using namespace std;
int t,n,myd[100010][3],m[100010][3],jc[100010][3],ans,k=1000000,xa[100010][3],xj;
int g[3];

int chao(){
	xj = 0;
	if(g[0] <= n/2 && g[1] <= n/2 && g[2] <= n/2)
		cout << ans << "\n";
	else{
		for(int i=1;i<=n;i++)
			k=min(jc[i][1],k);
		ans -= k;
		for(int i=1;i<=n;i++){
			if(k == jc[i][1]){
				if(xj == 0){
					g[xa[i][0]]--;
					g[xa[i][1]]++;
					xj++;
				}
				else if(xj == 1){
					g[xa[i][1]]--;
					g[xa[i][2]]++;
					xj++;
				}
				jc[i][1] = jc[i][2];
			}
			
		}
		k = 1000000;
		chao();
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int j=1;j<=t;j++){
		cin >> n;
		ans = 0;
		for(int i=1;i<=100010;i++){
			myd[i][0] = 0;
			myd[i][1] = 0;
			myd[i][2] = 0;
			m[i][0] = 0;
			m[i][1] = 0;
			m[i][2] = 0;
			jc[i][0] = 0;
			jc[i][1] = 0;
			jc[i][2] = 0;
			xa[i][0] = 0;
			xa[i][1] = 0;
			xa[i][2] = 0;
		}
		g[0] = 0;
		g[1] = 0;
		g[2] = 0;
		for(int i=1;i<=n;i++){
			for(int l=0;l<=2;l++){
				cin >> myd[n][l];
			}
			m[i][0] = max(max(myd[n][0],myd[n][1]),myd[n][2]);
			if(m[i][0] == myd[n][0]){
				m[i][1] = max(myd[n][1],myd[n][2]);	
				xa[i][0] = 0;
				if(m[i][1] == myd[n][1]){
					xa[i][1] = 1;
					xa[i][2] = 2;
				}
				else{
					xa[i][1] = 2;
					xa[i][2] = 1;
				}
			}
			if(m[i][0] == myd[n][1]){
				m[i][1] = max(myd[n][0],myd[n][2]);
				xa[i][0] = 1;
				if(m[i][1] == myd[n][0]){
					xa[i][1] = 0;
					xa[i][2] = 2;
				}
				else{
					xa[i][1] = 2;
					xa[i][2] = 0;
				}
			}
			if(m[i][0] == myd[n][2]){
				m[i][1] = max(myd[n][0],myd[n][1]);
				xa[i][0] = 2;
				if(m[i][1] == myd[n][0]){
					xa[i][1] = 0;
					xa[i][2] = 1;
				}
				else{
					xa[i][1] = 1;
					xa[i][2] = 0;
				}
			}
			m[i][2] = min(min(myd[n][0],myd[n][1]),myd[n][2]);
			jc[i][0] = m[i][0];
			jc[i][1] = m[i][0] - m[i][1];
			jc[i][2] = m[i][1] - m[i][2];
		}
		for(int i=1;i<=n;i++){
			ans += jc[i][0];
			if(jc[i][0] == myd[i][0])
				g[0]++;
			else if(jc[i][0] == myd[i][1])
				g[1]++;
			else if(jc[i][0] == myd[i][2])
				g[2]++;
		}
		chao();
	}
	return 0;
}
