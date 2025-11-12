#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=2e5+5;
int L1,L2;
string s1[N],s2[N],t1[N],t2[N];
int n,q;
int ans[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s1[i]>>s2[i];
		L1+=s1[i].size();
	}
	for(int i=1;i<=q;++i){
		cin>>t1[i]>>t2[i];
		L2+=t1[i].size();
	}
	if(L1<=3000&&L2<=3000){
		for(int i=1;i<=q;++i){
			for(int j=1;j<=n;++j){
				for(int ii=0;ii<t1[i].size();++ii){
					if(t1[i].substr(ii,s1[j].size())==s1[j]){
						if(t1[i].substr(0,ii)+s2[j]+t1[i].substr(ii+s2[j].size(),t1[i].size()-ii-s2[j].size())==t2[i]){
							++ans[i];
						}
					}
				}
			}
		}
		for(int i=1;i<=q;++i){
			printf("%d\n",ans[i]);
		}
	}else{
		for(int i=1;i<=q;++i){
			printf("0\n");
		}
	}
	return 0;
}
