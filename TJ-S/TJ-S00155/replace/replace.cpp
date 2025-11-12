#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
vector<string> s,ss;
int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		s.push_back(s1);
		ss.push_back(s2);
	}
	string s1,s2;
	while(q--){
		cin>>s1>>s2;
		string s_=s1;
		for(int i=0;i<s.size();i++){
            int p=s1.find(s[i]);
            if(p==-1) continue;
//            cout<<p<<" "<<s[i].size()<<" "<<ss[i]<<endl;
            s_.replace(p,s[i].size(),ss[i]);
//            cout<<s_<<endl;
            if(s_==s2) ans++;
            s_=s1;
		}
        cout<<ans;
        ans=0;
	}
	return 0;
}

