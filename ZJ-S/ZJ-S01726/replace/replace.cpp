#include <bits/stdc++.h>
using namespace std;
int n,q,flag,ans;
int cnta[200010],cntb[200010],flaga,flagb;
string ra[200010],rb[200010];
string sa,sb;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;++i) cin>>ra[i]>>rb[i];
	if (n<=1000&&q<=1000){
		while (q--){
			ans=0;
			cin>>sa>>sb;
			for (int i=1;i<=n;++i){
				for (int j=0;j+ra[i].length()-1<sa.length();++j){
					string ss=sa;flag=0;
					for (int k=0;k<ra[i].length();++k){
						if(sa[j+k]!=ra[i][k]) {break;flag=1;}
						ss[j+k]=rb[i][k];
					}
					if (!flag&&ss==sb) ++ans; 
				}
			}
			cout<<ans<<'\n';
		}
	}
	else{
		for (int i=1;i<=n;++i){
			flaga=0;flagb=0;
			for (int j=0;j<ra[i].length();++j){
				if (ra[i][j]=='b') flaga=1;
				if (rb[i][j]=='b') flagb=1;
				if (flaga==0) ++cnta[i];
				if (flagb==0) ++cntb[i];
			}
		}
		while (q--){
			cin>>sa>>sb;ans=0;
			int indxa=0,indxb=0,lsa=sa.length(),lsb=sb.length();
			for (int i=0;i<lsa;++i){
				if (sa[i]=='b') indxa=i;
				if (sb[i]=='b') indxb=i;
			}
			for (int i=1;i<=n;++i){
				int lra=ra[i].length(),lrb=rb[i].length();
				if (cnta[i]>indxa||lra-cnta[i]-1>lsa-indxa-1) continue;
				if ((indxa-indxb==cnta[i]-cntb[i])&&(lsa-indxa-lsb+indxb==lra-cnta[i]-lrb+cntb[i])) ++ans;
			}
			cout<<ans<<'\n';
		}
		
	}
	return 0;
}
