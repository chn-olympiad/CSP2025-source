#include<bits/stdc++.h>
using namespace std;
int n,q;
unsigned long long g[200005],g2[200005],tg[5000006],tg2[5000005],bs[5000006];
long long gt[200005],g2t[200005],tgt[5000006],tg2t[5000005],bst[5000006];
int l[200005];
const long long mod=910000967;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	string s,s2;
	for(int i=1;i<=n;i++){
		cin>>s>>s2;
		l[i]=s.size();
		for(int j=0;j<s.size();j++){
			g[i]=g[i]*29+s[j]-'a'+1;
			g2[i]=g2[i]*29+s2[j]-'a'+1;
			gt[i]=(gt[i]*31+s[j]-'a'+1)%mod;
			g2t[i]=(g2t[i]*31+s2[j]-'a'+1)%mod;
		}
		//cerr<<i<<" "<<g[i]<<" "<<g2[i]<<" "<<gt[i]<<" "<<g2t[i]<<endl;
	}
	string t,t2;
	bs[0]=1;
	bst[0]=1;
	for(int i=1;i<=5e6;i++){
		bs[i]=bs[i-1]*29;
		bst[i]=bst[i-1]*31%mod;
	}
	while(q--){
		cin>>t>>t2;
		for(int i=0;i<t.size();i++){
			tg[i+1]=tg[i]*29+t[i]-'a'+1;
			tg2[i+1]=tg2[i]*29+t2[i]-'a'+1;
			tgt[i+1]=(tgt[i]*31+t[i]-'a'+1)%mod;
			tg2t[i+1]=(tg2t[i]*31+t2[i]-'a'+1)%mod;
			//cerr<<tgt[i+1]<<" "<<tg2t[i+1]<<endl;
		}
		long long ans=0;
		for(int j=1;j<=n;j++){
			for(int i=l[j]-1;i<t.size();i++){
				//cerr<<j<<" "<<i<<" "<<tgt[t.size()]-tgt[i+1]*bst[t.size()-i-1]%mod<<" "<<tg2t[t.size()]-tg2t[i+1]*bst[t.size()-i-1]%mod<<endl;
				if(tg[t.size()]-tg[i+1]*bs[t.size()-i-1]!=tg2[t.size()]-tg2[i+1]*bs[t.size()-i-1]||(tgt[t.size()]-tgt[i+1]*bst[t.size()-i-1]%mod+4*mod)%mod!=(tg2t[t.size()]-tg2t[i+1]*bst[t.size()-i-1]%mod+4*mod)%mod) continue;
				if(tg[i+1-l[j]]!=tg2[i+1-l[j]]||tgt[i+1-l[j]]!=tg2t[i+1-l[j]]) break;
				//cerr<<j<<" "<<i<<" "<<tgt[i+1]-tgt[i+1-l[j]]*bst[l[j]]%mod<<" "<<tg2t[i+1]-tg2t[i+1-l[j]]*bst[l[j]]%mod<<endl;
				if(tg[i+1]-tg[i+1-l[j]]*bs[l[j]]==g[j]&&tg2[i+1]-tg2[i+1-l[j]]*bs[l[j]]==g2[j]&&(tgt[i+1]-tgt[i+1-l[j]]*bst[l[j]]%mod+mod*4)%mod==gt[j]&&(tg2t[i+1]-tg2t[i+1-l[j]]*bst[l[j]]%mod+mod*4)%mod==g2t[j]){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
