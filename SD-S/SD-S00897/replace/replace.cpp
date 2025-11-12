#include<bits/stdc++.h>
using namespace std;
pair<string,string>s[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		s[i].first="";
		s[i].second="";
		for(int j=0;j<a.length();j++){
			if(a[j]!=b[j]){
				for(int k=a.length();k>=j;k--){
					if(a[k]!=b[k]){
						for(int o=j;o<=k;o++){
							s[i].first+=a[o];
							s[i].second+=b[o];
						}
						break;
					}
				}
				break;
			}
		}
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.length()!=t2.length()){
			cout<<0<<"\n";
			continue;
		}
		string tmp1="",tmp2="";
		for(int i=0;i<t1.length();i++){
			if(t1[i]!=t2[i]){
				for(int j=t1.length()-1;j>=i;j--){
					if(t1[j]!=t2[j]){
						for(int k=i;k<=j;k++){
							tmp1+=t1[k];
							tmp2+=t2[k];
						}
						break;
					}
				}
				break;
			}
		}
		if(tmp1.length()!=tmp2.length()){
			cout<<0<<"\n";
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(s[i].first==tmp1&&s[i].second==tmp2){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

