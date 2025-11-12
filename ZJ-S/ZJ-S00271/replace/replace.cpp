#include<bits/stdc++.h>
#define ci const int
#define ri register int
using namespace std;
ci N=1e4+5,L=5e6+5;
int n,q,l,ls[N],p;
string s1[N],s2[N],t1,t2;
long long ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(ri i=1;i<=n;++i){
		cin>>s1[i]>>s2[i];
		ls[i]=s1[i].size();
	}
	while(q--){
		ans=0;
		cin>>t1>>t2;
		l=t1.size();
		p=0;
		string tmp,tmp2;
		bool fl;
		for(ri p=0;p<l;++p){
			for(ri i=1;i<=n;++i){
				if(l-p<ls[i]) continue;
				fl=1;
				for(ri j=0;j<ls[i];++j){
					if(t1[p+j]!=s1[i][j]){
						fl=0;
						break;
					}
				}
				if(!fl) continue;
				tmp2=tmp+s2[i];
				for(ri j=p+ls[i];j<l;++j){
					tmp2+=t1[j];
					if(t1[j]!=t2[j]){
						fl=0;
						break;
					}
				}
				if(!fl) continue;
				if(tmp2==t2){
					++ans;
				}
			}
			if(t1[p]!=t2[p]) break;
			tmp+=t1[p];
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}