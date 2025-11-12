#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N = 1e5+5;
int n;
int a[N][3],cnt[3],bel[N],ans;
int del[N];
void init(){
	n = read();ans = 0;
	cnt[0] = cnt[1] = cnt[2] = 0;
	for(int i=1;i<=n;i++){
		int p = 0;
		for(int j=0;j<3;j++){
			a[i][j] = read();
			if(a[i][j]>a[i][p]){
				p = j;
			}
			
		}
		bel[i] = p;cnt[p]++;
		ans+=a[i][p];
	}
	for(int i=0;i<3;i++){
		if(cnt[i]<=n/2){
			continue;
		}
		int tt = 0;
		for(int j=1;j<=n;j++){
			if(bel[j]==i){
				int res = -1e9;
				for(int k=0;k<3;k++){
					if(k!=i){
						res = max(res,a[j][k]-a[j][i]);
					}
				}
				del[++tt] = -res;
			}
		}
		sort(del+1,del+1+tt);
		for(int j=1;j<=cnt[i]-n/2;j++){
			ans-=del[j];
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T = read();
	while(T--){
		init();
	}
	return 0;
}

