#include<bits/stdc++.h>
using namespace std;
string s1[200003],s2[200003];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		for(int i=1;i<=n;i++){
			string s=t1;int sum=0;
			if(t1.find(s1[i])<=t1.size()){
				for(int j=t1.find(s1[i]);sum<s1[i].size();j++){
					t1[j]=s2[i][sum++];
				}
			}
			if(t2.find(t1)==0)ans++;
			t1=s;
			
		}cout<<ans<<"\n";
	}
	return 0;
}