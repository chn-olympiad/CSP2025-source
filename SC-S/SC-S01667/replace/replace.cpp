#include<bits/stdc++.h>
using namespace std;
//敬爱的评测机，行行好，放我过 n*len^2 
const int N = 1010;
const int L = 2010;
int n,q,st1,st2;
char s1[N][L],s2[N][L],a[L],b[L],c[L];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s1[i]+1>>s2[i]+1; 
	}
	for(int l=1;l<=q;++l){
		cin>>a+1>>b+1;
		int ans=0;
		st1=strlen(a+1);
		st2=strlen(b+1);
		if(st1!=st2){
			cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<=n;++i){
			int t1=strlen(s1[i]+1);
			int t2=strlen(s2[i]+1);
			for(int j=0;j<=st1-t1;++j){
				int pt=1;
				for(int k=1;k<=t1&&pt;++k){
					if(a[j+k]!=s1[i][k]) pt=0;
				}
				if(pt){
					for(int k=1;k<=st1;++k) c[k]=a[k];
					for(int k=1;k<=t1;++k) c[j+k]=s2[i][k];
					int tp=1;
					for(int k=1;k<=st1&&tp;++k){
						if(c[k]!=b[k]) tp=0;
					}
					if(tp) ++ans;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}