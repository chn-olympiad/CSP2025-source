#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10,M=5e6+10,KK=5e6+10;

int pi[M],n,q,sm[M],p[M],vis1[KK],vis2[KK];

string s1[N],s2[N],a,b;

void kmp(string &s){
	memset(pi,0,sizeof pi);
	for(int i=1;i<(int)s.size();i++){
		int c=pi[i-1];
		while(c && s[i]!=s[c])c=pi[c-1];
		pi[i]=c+(s[c]==s[i]); 
	}
	return ;
}

void kmp2(string &s){
	memset(p,0,sizeof pi);
	for(int i=1;i<(int)s.size();i++){
		int c=p[i-1];
		while(c && s[i]!=s[c])c=p[c-1];
		p[i]=c+(s[c]==s[i]); 
	}
	return ;
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		memset(sm,0,sizeof sm);
		cin>>a>>b;
		if((int)a.size() != (int)b.size() ){
			cout<<0<<'\n';
			continue;
		}
		for(int i=0;i<(int)a.size();i++){
			if(a[i]==b[i]){
				sm[i]=1;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			string S=s1[i]+'^'+a,S2=s2[i]+'^'+b;
			kmp(S);
			kmp2(S2);
			int f=0;
			for(int j=(int)s1[i].size()+1;j<=(int)s1[i].size()+(int)a.size();j++){
				if(f==1 && pi[j]!=pi[j-1]+1)f=2;
				if(sm[j-(int)s1[i].size()-1])continue;
				if((f==0 || f==1) && pi[j]==pi[j-1]+1 && pi[j]==p[j]){
					f=1;
				}else{
					f=3;
					break;
				}
			}
			if(f!=3){
				//cout<<i<<' ';
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
