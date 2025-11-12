//rp++
//love CCF 
#include<iostream>
#include<cstring>
using namespace std;
const int N=2e5+10,M=5e6+10;
int n,q,l=-1,r=-1,nxt[M];
string S[N][2],t1,t2;
int kmp(string s1,string s2){
	int cnt=0,j=0;
	for(int i=0;i<s1.size();i++) nxt[i]=0;
	for(int i=1;i<s1.size();i++){
		while(j>0&&s1[i]!=s1[j]) j=nxt[j-1];
		if(s1[i]==s1[j]) j++;
		nxt[i]=j;
	}
	j=0;
	for(int i=0;i<t1.size();i++){
		while(j>0&&s1[j]!=t1[i]) j=nxt[j-1];
		if(s1[j]==t1[i]) j++;
		if(j==s1.size()){
			int ll=i-s1.size()+1,rr=i;
			if(t2.substr(ll,j)==s2&&((ll<=l&&rr>=r)||(l==-1&&r==-1)))cnt++;
		}
	}
	return cnt;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>S[i][0]>>S[i][1];
	while(q--){
		cin>>t1>>t2;
		for(int i=0;i<t1.size();i++){
			if(t1[i]!=t2[i]){
				l=i;
				break;
			}
		}
		for(int i=t1.size()-1;i>=0;i--){
			if(t1[i]!=t2[i]){
				r=i;
				break;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++) ans+=kmp(S[i][0],S[i][1]);
		cout<<ans<<'\n';	
	}
	return 0;
}
