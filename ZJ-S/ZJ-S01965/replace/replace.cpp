#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e3+5;
string s1[MAXN],s2[MAXN];
string t1,t2,tmp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	long long ans=0;
	while(q--){
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			int sz=s1[i].size();
			for(int l=0;l<t1.size()-sz;l++){
				bool ok=0;
				for(int j=l;j<l+sz;j++){
					if(t1[j]!=s1[i][j]){
						ok=1;
						break;
					}
				}
				if(!ok){
					tmp=t1;
					for(int j=l;j<l+sz;j++){
						tmp[j]=s1[i][j-l];
					}
					if(tmp==t2){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
