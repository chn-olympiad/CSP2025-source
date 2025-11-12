/*********************************************************************
    程序名: 
    版权: 
    作者: 
    日期: 2025-11-01 17:24
    说明: 
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;
int n,q,k;
string s[200010];
vector<string> t[200010];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,t1;
		cin>>s1>>t1;
		bool f=false;
		for(int j=1;j<=k;j++){
			if(s[j]==s1){
				t[j].push_back(t1);
				f=true;
				break;
			}
		}
		if(!f){
			k++;
			s[k]=s1;
			t[k].push_back(t1);
		}
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int ans=0;
		if(s1.size()!=s2.size()){
			cout<<0<<endl;
			continue;
		}
		int l=-1,r=-1;
		for(int i=0;i<s1.size();i++){
			if(s1[i]!=s2[i]){
				l=i;
				break;
			}
		}
		for(int i=s1.size()-1;i>=0;i--){
			if(s1[i]!=s2[i]){
				r=i;
				break;
			}
		}
//		cout<<l<<' '<<r<<endl;
		for(int ll=0;ll<=l;ll++){
			for(int rr=s1.size()-1;rr>=r;rr--){
				int len=rr-ll+1;
				string qw=s1.substr(ll,len),qwl=s1.substr(0,ll),qwr=s2.substr(rr+1);
//				cout<<qwl<<' '<<qw<<' '<<qwr<<endl;
				for(int i=1;i<=k;i++){
					if(s[i]==qw){
						for(int j=0;j<t[i].size();j++){
							if(qwl+t[i][j]+qwr==s2){
								ans++;
							}
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/