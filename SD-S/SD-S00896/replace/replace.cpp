#include<bits/stdc++.h>
using namespace std;
const long long maxn=200005,mod=3200000000000129ll;
long long n,m,ha[maxn],he[maxn*10];
string s[maxn][2],q,qq;
int qp(long long e,long long md){
	long long modd=md;
	__int128 a=e,ans=1;
	while(modd){
		if(modd%2)ans=ans*a%mod;
		a=a*a%mod;
		modd/=2;
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		for(int j = 0;j<s[i][0].size();j++){
			ha[i]=(ha[i]*26+s[i][0][j]-'a')%mod;
		}
	}
	for(int i = 1;i<=m;i++){
		cin>>q>>qq;
		int nn=q.size();
		he[0]=q[0]-'a';
		for(int j = 1;j<nn;j++){
			he[j]=(he[j-1]*26+q[j]-'a')%mod;
		}
		int ans=0;
		for(int k = 1;k<=n;k++){
			int knn=s[k][0].size();
			if(he[knn-1]==ha[k]){
				int fl=1;
				for(int o = 0;o<nn;o++){
					if(o<knn){
						if(s[k][1][o]!=qq[o]){
							fl=0;
							break;
						}
					}
					else{
						if(q[o]!=qq[0]){
							fl=0;
							break;
						}
					}
				}
				if(fl)ans++;
			}
			
			for(int j = 1;j<nn-knn+1;j++){
				int fll=1;
				for(int o = 0;o<knn;o++){
					if(s[k][0][o]!=q[j+o]){
						fll=0;
						break;
					}
				}
				if(fll){
//					cout<<j;
					int fl=1;
					
					for(int o = 0;o<nn;o++){
						
						if(j<=o&&o<=j+knn-1){
							if(s[k][1][o-j]!=qq[o]){
								fl=0;
								break;
							}
						}
						else{
							if(q[o]!=qq[o]){
								fl=0;
								break;
							}
						}
					}
					if(fl)ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

