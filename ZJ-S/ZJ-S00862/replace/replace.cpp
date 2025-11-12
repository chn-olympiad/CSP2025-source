#include<bits/stdc++.h>

using namespace std;
const int N=1e4+5;
int n,q;
struct S{
	string s1,s2;
}s[N];
bool check(string s1,int st,string s2,string s3,string s4){
	for(int i=0;i<s2.size();i++){
		if(s1[i+st]!=s2[i])return 0;
		else s1[i+st]=s3[i];
	}
	if(s1==s4)return 1;
	else return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].s1>>s[i].s2;
	}
	while(q--){
		string t1,t2;
		int ans=0;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			for(int j=0;j+s[i].s1.size()<=t1.size();j++){
				if(check(t1,j,s[i].s1,s[i].s2,t2)){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}