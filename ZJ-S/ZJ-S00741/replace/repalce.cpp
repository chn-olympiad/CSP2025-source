#include<bits/stdc++.h>
#define N 5000010
using namespace std;
typedef long long ll;
string s1[N],s2[N];
int n,q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string fr,to;
		cin>>fr>>to;
		int ans=0;
		for(int i=1;i<=n;i++){
			string tmp=fr;
			int it=tmp.find(s1[i]);
			while(~it){
				string go=fr;
				for(int k=0;k<s1[i].size();k++){
					go[it+k]=s2[i][k];
					tmp[it+k]=s2[i][k];
				}
				if(go==to)ans++;
				it=tmp.find(s1[i]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}