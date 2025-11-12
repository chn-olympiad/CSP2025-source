#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,q;
struct node{
	string s1,s2;
}a[maxn];
int pi1[maxn<<1],pi2[maxn<<1];
string s,ss,sk,ssk;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>a[i].s1>>a[i].s2;	
	}
	while(q--){
		cin>>s>>ss;
		int ans=0;
		for(int i=1;i<=n;++i){
			sk=a[i].s1+"#"+s;
			ssk=a[i].s2+"#"+ss;
			memset(pi1,0,sizeof(pi1));
			memset(pi2,0,sizeof(pi2));
			pi1[0]=pi2[0]=0;
			int cnt=0;
			for(int j=1;j<sk.size();++j){
				int len1=pi1[j-1];
				if(!len1 || sk[j]!=sk[len1]) len1=pi1[len1-1];
				if(sk[j]==sk[len1]) pi1[j]=len1+1;
				int len2=pi2[j-1];
				if(!len2 || ssk[j]!=ssk[len2]) len2=pi2[len2-1];
				if(ssk[j]==ssk[len2]) pi2[j]=len2+1;
				if(j>a[i].s1.size() && pi1[j]==pi2[j] && pi1[j]==a[i].s1.size()) cnt++;
			}
			if(cnt==1) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}