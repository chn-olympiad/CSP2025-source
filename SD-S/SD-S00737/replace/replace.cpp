#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
	string s,s1;
}a[N];
map<pair<string,string>,int> mp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	if(q==1){
		int ans=0,st=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].s>>a[i].s1;
		}
		string ss,ss1;
		cin>>ss>>ss1;
		int ed=ss.size()-1;
		if(ss.size()!=ss1.size()){
			cout<<0<<"\n";
			return 0;
		}
		for(int i=0;i<ss.size();i++){
			if(ss[i]!=ss1[i]){
				st=i;break;
			}
		}
		for(int i=ss.size()-1;i>=0;i--){
			if(ss[i]!=ss1[i]){
				ed=i;break;
			}
		}
//		cout<<st<<" "<<ed<<"\n";
		for(int i=1;i<=n;i++){
			long long p1=ss.find(a[i].s),p2=ss1.find(a[i].s1);
			if(p1>=0&&p1<=st&&p1==p2&&p1+a[i].s.size()-1>=ed){
			ans++;
			}
		}
		cout<<ans<<"\n";
		return 0;
	}
	for(int i=1;i<=n;i++){
		string s,s1;
		cin>>s>>s1;
		mp[{s,s1}]++;
	}
	while(q--){
		int ans=0,st=0,ed;
		string s,s1;
		cin>>s>>s1;
		ed=s.size()-1;
		if(s.size()!=s1.size()){
			cout<<0<<"\n";
			continue;
		}
		for(int i=0;i<s.size();i++){
			if(s[i]!=s1[i]){
				st=i;break;
			}
		}
		for(int i=s.size()-1;i>=0;i--){
			if(s[i]!=s1[i]){
				ed=i;break;
			}
		}
//		cout<<st<<" "<<ed<<"\n";
		for(int i=0;i<=st;i++){
			string ss="",ss1="";
			for(int j=i;j<ed;j++) ss+=s[j],ss1+=s1[j];
			for(int j=ed;j<s.size();j++){
				ss+=s[j],ss1+=s1[j];
				ans+=mp[{ss,ss1}];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//	if(n>2000&&q>2000){//ab
//		for(int i=1;i<=n;i++){
//			string s,s1;
//			cin>>s>>s1;
//			for(int j=0;j<s.size();j++){
//				if(s[j]=='b'){
//					p1=j;break;
//				}
//			}
//			for(int j=0;j<s1.size();j++){
//				if(s1[j]=='b'){
//					p2=j;break;
//				}
//			}
//			b[i].fa=min(p1,p2),b[i].jg=p2-p1,b[i].la=s1.size()-max(p1,p2);
//		}
//		for(int )
//	}
