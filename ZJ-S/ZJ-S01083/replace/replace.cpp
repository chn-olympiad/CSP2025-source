#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,q,ans;
string s1[210000],s2[210000];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie();
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		ans=0;
		string sq,sqq;
		cin>>sq>>sqq;
		for(int i=1;i<=n;i++){
			if(sq.find(s1[i])!=-1){
				string ss=sq;
				for(int j=0;j<s1[i].size();j++){
					ss[j+sq.find(s1[i])]=s2[i][j];
				}
				if(ss==sqq)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
