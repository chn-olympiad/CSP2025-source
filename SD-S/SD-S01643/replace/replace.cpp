#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int n,q;string s1[maxn],s2[maxn];
map<string,int> ex;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i]; 
	for(int i=1;i<=q;i++){
		string t1,t2;cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0;continue;
		}
		int l1=0,l2=0;
	    while(t1[l1]==t2[l1]) l1++;
	    int r1=t1.size()-1,r2=t2.size()-1;
	    while(t1[r1]==t2[r2]) l2++,r1--,r2--;
	    int ans=0;
	    for(int i=1;i<=n;i++){
	    	if(s1[i].size()<t1.size()-l1-l2) continue;
	    	for(int j=0;j<t1.size();j++)
	    	    if(s1[i]==t1.substr(j,s1[i].size())){
	    	    	string temp=t1.substr(0,j)+s2[i]+t1.substr(j+s2[i].size());
	    	    	if(temp==t2) ans++;
				}
		}
		cout<<ans<<'\n';
	}
} 
