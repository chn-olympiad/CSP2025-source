#include<bits/stdc++.h>
#define int unsigned long long
const int N = 2e5+5;
const int base = 231;
using namespace std;
int n,q,l,r;
string s[N][3],t1,t2;
int h1[N],h2[N],hs1[2005][2005],hs2[2005][2005];
int ksm(int x,int y){
	if(y==1)return x;
	int z = ksm(x,y/2);
	if(y&1)return z*z*x;
	return z*z;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> q;
	for(int i = 1;i<=n;i++){
		cin >> s[i][1] >> s[i][2];
		int len = s[i][1].size();
		for(int j = 0;j<len;j++){
			hs1[i][j+1] = (hs1[i][j]*base+(int)s[i][1][j]);
			hs2[i][j+1] = (hs2[i][j]*base+(int)s[i][2][j]);
		}
	}
	for(int i = 1;i<=q;i++){
		int ans = 0;
		cin >> t1 >> t2;
		int len = t1.size();
		for(int j = 0;j<len;j++){
			h1[j+1] = (h1[j]*base+(int)t1[j]);
			h2[j+1] = (h2[j]*base+(int)t2[j]);
		}
		for(int j = 0;j<len;j++){
			if(t1[j]!=t2[j]){
				l = j+1;
				break;
			}
		}
		for(int j = len-1;j>=0;j--){
			if(t1[j]!=t2[j]){
				r = j+1;
				break;
			}
		}
		int dif1 = (h1[r]-h1[l-1]*ksm(base,r-l+1));
		int dif2 = (h2[r]-h2[l-1]*ksm(base,r-l+1));
//		cout << dif1 << " " << dif2 << "\n";
		for(int j = 1;j<=n;j++){
			int flag = 0;
			int lent = s[j][1].size();
			for(int k=0;k+r-l<lent;k++){
				int H1 = hs1[j][k+r-l+1] - hs1[j][k]*ksm(base,r-l+1);
				int H2 = hs2[j][k+r-l+1] - hs2[j][k]*ksm(base,r-l+1);
//				cout << H1 << " " << H2 << "\n"; 
				if(H1==dif1&&H2==dif2){
					int ht1 = h1[l-k-1+lent]-h1[l-k-1]*ksm(base,lent);
					int ht2 = h2[l-k-1+lent]-h1[l-k-1]*ksm(base,lent);
					if(ht1==hs1[j][lent]&&ht2==hs2[j][lent]){
						flag = 1;
						break;
					}
				} 
			}
			ans += flag;
		}
		cout << ans <<"\n";
	}
}
/*
17:40 [10,10]
17:50 [10,25]
*/
