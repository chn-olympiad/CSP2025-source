#include<bits/stdc++.h>
using namespace std;
int n,q,ans=0;
map<string,string> mp;
string s[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		cin>>mp[s[i]];
	}
	for(int j=1;j<=q;j++){
		ans=0;
		string a,b;
		cin>>a>>b;
		for(int i=1;i<=n;i++){
			int kk=0;
			int sum=0;
			for(int k=0;k<=n && sum!=s[i].size();k++){
				if(a[k]!=s[i][sum]){
					kk++;
					sum=0;
					continue;
				}else{
					sum++;
				}
			}
			if(sum==s[i].size()){
				int f=1;
				for(int k=0;k<n;k++){
					if(k<kk || kk+s[i].size()-1<k){
						if(a[k]!=b[k]){
							f=0;
							break;
						}
					}else{
						if(mp[s[i]][k-kk]!=b[k]){
							f=0;
							break;
						}
					}
				}
				if(f) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
