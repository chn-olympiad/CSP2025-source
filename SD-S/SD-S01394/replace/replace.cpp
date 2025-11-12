#include<bits/stdc++.h>
using namespace std;
pair<string,string> rep[200005];
int bi[200005];
pair<string,string> bas[200005];int m;
map<pair<string,string>,int> id;
vector<int> bac[200005];
int n,q;
string s1,s2,l1,l2,t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		rep[i]=make_pair(s1,s2);
		int l,r;
		for(int j=0;j<s1.length();j++){
			if(s1[j]!=s2[j]){l=j;break;}
		}
		for(int j=s1.length()-1;j>=0;j--){
			if(s1[j]!=s2[j]){r=j;break;}
		}
		bi[i]=l;
		l1="";l2="";
		for(int j=0;j<=r-l;j++){
			l1+=s1[l+j];
			l2+=s2[l+j];
		}
		if(id[make_pair(l1,l2)]==0){
			bas[++m]=make_pair(l1,l2);
			id[make_pair(l1,l2)]=m;
		}
		bac[id[make_pair(l1,l2)]].push_back(i);
	}
	while(q--){
		cin>>t1>>t2;
		if(t1.length()!=t2.length()){
			cout<<0<<endl;
			continue;
		}
		int l,r;
		for(int j=0;j<t1.length();j++){
			if(t1[j]!=t2[j]){l=j;break;}
		}
		for(int j=t1.length()-1;j>=0;j--){
			if(t1[j]!=t2[j]){r=j;break;}
		}
		l1="";l2="";
		for(int j=0;j<=r-l;j++){
			l1+=t1[l+j];
			l2+=t2[l+j];
		}
		if(id[make_pair(l1,l2)]==0){
			cout<<0<<endl;
			continue;
		}
		int rm=id[make_pair(l1,l2)];
		int ans=0;
		for(int i=0;i<bac[rm].size();i++){
			int p=bac[rm][i];
			bool flag=1;
			for(int j=0;j<rep[p].first.length();j++){
				if(l-bi[p]+j>=t1.length()||rep[p].first[j]!=t1[l-bi[p]+j]){
					flag=0;break;
				}
			}
			if(flag)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
