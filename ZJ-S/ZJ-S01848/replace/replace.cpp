#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,T,i,ln,j,k;
string fx,a,b,s1[200010],s2[200010];
queue<string> q;
map<string,int>f,spfa,bs;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>T;
	for(i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	while(T--){
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<"0\n";
			continue;
		}
		ln=a.size();
		spfa.clear();f.clear();bs.clear();
		q.push(a);f[a]=1;spfa[a]=1;bs[a]=1;
		while(!q.empty()){
			string fx=q.front();q.pop();string S="";
//			cout<<fx<<'\n';
			spfa[a]=0;
			if(bs[fx]==2)continue;
			for(j=0;j<ln;j++){
				if(j>=1)S=S+fx[j-1];
				for(i=1;i<=n;i++){
//					if(j+s1[i].size()>=ln+1)break;
					for(k=0;k<s1[i].size();k++)
						if(fx[j+k]!=s1[i][k])break;
//					if(i==3)cout<<k<<'\n';
					if(k==s1[i].size()){
						string s="";
						for(k=j+s1[i].size();k<ln;k++)
							s+=fx[k];
						string op=S+s2[i]+s;
//						cout<<S<<' '<<s2[i]<<' '<<s<<' '<<op<<endl;
						f[op]+=f[fx];
						if(spfa[op]==0){
							spfa[op]=1;
							bs[op]=bs[fx]+1;
							q.push(op);
						}
					}
				}
			}
		}
		cout<<f[b]<<'\n';
	}
	return 0;
}
/*
30pts
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

4 1
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex

3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
