#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5,mx=2e5,base=131,mod=1e18;
int n,q,pw[maxn],hsh1[maxn],hsh2[maxn],hshs[maxn][2],ans;
string s[maxn][2],t1,t2;
bool flag=1;
map <int,int> m;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	pw[0]=1;
	for(int i=1;i<=mx;i++) pw[i]=pw[i-1]*base%mod;
	cin >> n >> q ;
	for(int i=1;i<=n;i++) cin >> s[i][0] >> s[i][1] ;
	if(n<=100){
		while(q--){
			cin >> t1 >> t2 ;
			if(t1.size()!=t2.size()){
				cout << "0\n" ;
				continue;
			}int len=t1.size(),ls=0,ans=0;
			for(int i=1;i<=n;i++){
				ls=s[i][0].size();
				for(int j=0;j<len-ls+1;j++){
					flag=1;
					for(int k=j,l=0;k<j+ls;k++,l++){
						if(t1[k]!=s[i][0][l] || t2[k]!=s[i][1][l]){
							flag=0;
							break;
						}
					}for(int k=0;k<j;k++){
						if(t1[k]!=t2[k]){
							flag=0;
							break;
						}
					}for(int k=j+ls;k<len;k++){
						if(t1[k]!=t2[k]){
							flag=0;
							break;
						}
					}if(flag){
						ans++;
						break;
					}
				}
			}cout << ans << "\n" ;
		}return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<s[i][0].size();j++) hshs[i][0]=(hshs[i][0]*base+s[i][0][j])%mod,hshs[i][1]=(hshs[i][1]*base+s[i][1][j])%mod;
		m[hshs[i][0]]+=(hshs[i][0]==hshs[i][1]);
	}while(q--){
		cin >> t1 >> t2 ;
		if(t1.size()!=t2.size()){
			cout << "0\n" ;
			continue;
		}int len=t1.size(),l=-1,r=len;
		for(int i=0;i<len;i++){
			if(t1[i]!=t2[i]) break;
			l=i;
		}for(int i=len-1;i>=0;i--){
			if(t1[i]!=t2[i]) break;
			r=i;
		}hsh1[0]=t1[0],hsh2[0]=t2[0];
//		cout << l << " " << r << "\n" ;
		for(int i=1;i<len;i++) hsh1[i]=(hsh1[i-1]*base+t1[i])%mod,hsh2[i]=(hsh2[i-1]*base+t2[i])%mod;
		if(!r){
			cout << m[hsh1[len-1]] << "\n" ;
		}else{
			ans=0;
			for(int i=1;i<=n;i++){
				int ls=s[i][0].size();
				if(ls<r-l-1) continue;
//				cout << " " << max(0ll,r-ls) << " " << min(l+1,len-ls) << "\n" ;
				flag=0;
				for(int j=max(0ll,r-ls),y=j+ls-1;j<=min(l+1,len-ls);j++,y++){
//					cout << i << ":" << (hsh1[y]-(j ? hsh1[j-1] : 0)*pw[j]%mod+mod)%mod << " " << hshs[i][0]%mod << " " << j << " " << y << "\n" ;
					if((hsh1[y]-(j ? hsh1[j-1] : 0)*pw[j]%mod+mod)%mod==hshs[i][0] && (hsh2[y]-(j ? hsh2[j-1] : 0)*pw[j]%mod+mod)%mod==hshs[i][1]){
						flag=1;
						break;
					}
				}ans+=flag;
			}cout << ans << "\n" ;
		}
	}//cout << (int)'a' << " " << (int)'b' << " " << (int)'x' << " " << hsh1[0] << " " << hsh1[1] << " " << hsh1[2] << " " << hsh1[3] ;
	return 0;
}
//1000 (4000+)
