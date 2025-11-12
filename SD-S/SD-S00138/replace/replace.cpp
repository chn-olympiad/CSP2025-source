#include<bits/stdc++.h>
#define f(i,a,b) for(auto i=a;i<=b;i++)
#define F(i,a,b) for(auto i=a;i>=b;i--)
using namespace std;
const int maxn=2e5+10,maxm=5e6+10,bas=233,mod=1e9+7;
int hsh[maxn],hsh1[maxn],n,q,hs[maxm],hs1[maxm],cnt,hz[1010][1010],hz1[1010][1010];
map<int,int> m;
vector<int> kk[maxn]; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	f(i,1,n){
		string s1,s2;
		cin>>s1>>s2;
		f(j,0,s1.size()-1) hsh[i]=(1ll*hsh[i]*bas+(s1[j]-'a'+1))%mod;
		f(j,0,s2.size()-1) hsh1[i]=(1ll*hsh1[i]*bas+(s2[j]-'a'+1))%mod;
		if(!m[hsh[i]]) m[hsh[i]]=cnt+1,cnt++;
		kk[m[hsh[i]]].push_back(hsh1[i]);
	}
	while(q--){
		int ans=0,pr=0,hh=0;
		string s1,s2;cin>>s1>>s2;
		f(i,0,s1.size()-1){
			hz[i][i]=s1[i]-'a'+1;
			f(j,i+1,s1.size()-1) hz[i][j]=(1ll*hz[i][j-1]*bas+(s1[j]-'a'+1))%mod;
		}f(i,0,s2.size()-1){
			hz1[i][i]=s2[i]-'a'+1;
			f(j,i+1,s2.size()-1) hz1[i][j]=(1ll*hz1[i][j-1]*bas+(s2[j]-'a'+1))%mod;
		}f(i,0,s1.size()-1){
			if(hz[0][i]!=hz1[0][i]){
				pr=i;break;
			}
		}F(i,s1.size()-1,0){
			if(hz[i][s1.size()-1]!=hz1[i][s1.size()-1]){
				hh=i;break;
			}
		}
		f(i,0,pr) f(j,hh,s1.size()-1) if(m[hz[i][j]]) for(auto it:kk[m[hz[i][j]]]) if(it==hz1[i][j]) ans++;
		cout<<ans<<endl;
	}
	return 0;
}
