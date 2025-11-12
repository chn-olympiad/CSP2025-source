#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int n,q;
vector<string>st1;
vector<string>st2;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	st1.resize(n);
	st2.resize(n);
	for(int i=0;i<n;i++){
		cin>>st1[i]>>st2[i];
	}
	while(q--){
		int ans=0;
		string s1,s2,s3;
		cin>>s1>>s2;
		for(int i=0;i<n;i++){
			if(s1==st1[i]){
				if(s2==st2[i]){
					ans++;
				}
				continue;
			}
			vector<int>res;
			for(int j=0;j<(int)(s1.size())-(int)(st1[i].size());j++){
				for(int k=0;k<=(int)(st1[i].size());k++){
					if(k==(int)(st1[i].size())){
						res.push_back(j);
						break;
					}
					else if(s1[j+k]!=st1[i][k]){
						break;
					}
				}
			}
			if(res.empty())continue;
			for(auto it:res){
				s3=s1;
				for(int k=0;k<(int)(st1[i].size());k++){
					s3[it+k]=st2[i][k];
				}
				if(s3==s2){
					ans++;
				}
				cout<<s3<<endl;
			}
		}
		cout<<ans<<endl;
	}
}
