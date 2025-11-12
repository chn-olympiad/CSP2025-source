#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e6+5;
const int P=1e9+7;
int n,q;
ll mi[N];
struct node{
	int len;
	ll hs1,hs2;
	node():len(0),hs1(0),hs2(0){}
	node(int L,ll H,ll S):len(L),hs1(H),hs2(S){}
};
vector<node>s[30];
ll ts1[N],ts2[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	mi[0]=1;
	for(int i=1;i<=N-5;i++) mi[i]=mi[i-1]*26%P;
	for(int i=1;i<=n;i++){
		string s1,s2;cin>>s1>>s2;
		int len=s1.size();s1=' '+s1;s2=' '+s2;
		ll hs1=0,hs2=0;
		for(int j=1;j<=len;j++){
			hs1=hs1*26%P+s1[j]-'a'+1;
			hs2=hs2*26%P+s2[j]-'a'+1;
		}
		hs1%=P;hs2%=P;
		s[s2[1]-'a'+1].push_back(node(len,hs1,hs2));
	}
	while(q--){
		string t1,t2;cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<'\n';
			continue;
		}
		int l=t1.size();t1=' '+t1,t2=' '+t2;
		for(int i=1;i<=l;i++){
			ts1[i]=(ts1[i-1]*26%P+t1[i]-'a'+1)%P;
			ts2[i]=(ts2[i-1]*26%P+t2[i]-'a'+1)%P;
		}
		ll ans=0;
		for(int i=1;i<=l;i++){
			for(node ed:s[t2[i]-'a'+1]){
				int len=ed.len;ll hs1=ed.hs1,hs2=ed.hs2;
				if(i+len-1>l) continue;
				if((ts1[i+len-1]-ts1[i-1]*mi[len]%P+P)%P==hs1){
					if((ts1[i-1]*mi[l-i+1]%P+hs2*mi[l-i-len+1]%P+ts1[l]-ts1[i+len-1]*mi[l-i-len+1]%P+P)%P==ts2[l]) ans++;
					
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0; 
}