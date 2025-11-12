#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll le=200010ll;
ll n,q,mx=0;
string s1[le],s2[le];
map<pair<string,string>,ll>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(ll i=1ll;i<=n;i++){
		scanf("%s%s",s1[i].c_str(),s2[i].c_str());
		//ll l=s1[i].size();
		ll cnt=0ll;
		for(ll j=0ll;j<(long long)s1[i].size();j++){
			if(s1[i][j]==s2[i][j]){
				s1[i].erase(j-cnt,1);
				s2[i].erase(j-cnt,1);
				cnt++;
			}
		}
		mp[make_pair(s1[i],s2[i])]++;
		mx=max(mx,(long long)s1[i].size());
	}
	while(q--){
		string t1,t2;
		scanf("%s%s",t1.c_str(),t2.c_str());
		if(t1.size()!=t2.size()){
			printf("0\n");
			continue;
		}
		ll len=t1.size()/*,cnt=0ll*//*,l=0ll,r=0ll*/;
		string r1="",r2="";
		bool flag=1;
		for(ll i=0ll;i<len;i++){
			if(t1[i]!=t2[i]){
				if(flag==0){
					flag=1;
					break;
				}
				//l=i;
				while(i<len&&t1[i]!=t2[i]){
					r1+=t1[i];
					r2+=t2[i];
					i++;
				}
				//r=i-1;
				flag=0;
			}
		}
		if(flag){
			printf("0\n");
			continue;
		}
		//cout<<l<<" "<<r<<endl;
		//string r1=t1.substr(l,r-l+1),r2=t2.substr(l,r-l+1);
		cout<<r1<<" "<<r2<<endl;
		if(mp.find(make_pair(r1,r2))==mp.end()){
			printf("0\n");
		}
		else{
			printf("%lld\n",mp[make_pair(r1,r2)]);
		}
	}
	return 0;
}
