#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
struct aaa{
	string s1,s2;
}u[200010];
bool bi(string r,string p){
	for(int i=0;i<r.size()-p.size()+1;i+=p.size()){
		string tt;
		for(int j=i;j<i+p.size();j++)
			tt+=r[j];
//		string tt=r.substr(i,p.size());
		if(tt==p)
			return 1;
	}
	return 0;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>u[i].s1>>u[i].s2;
	while(q--){
		int ans=0;
		string s,ss;
		cin>>s>>ss;
		for(int i=1;i<=n;i++){
			string tmp=u[i].s1;
			if(bi(s,tmp)){
				int id=s.find(tmp);
				string t1,t2,t3;
				int len=s.size(),lent=tmp.size();
				for(int j=0;j<id;j++)
					t1+=s[j];
//				t1=s.substr(0,id);
				t2=u[i].s2;
				for(int j=id+lent;j<len;j++)
					t3+=s[j];
//				t3=s.substr(id+lent,len-id-lent);
				string e=t1+t2+t3;
				if(e==ss)
					ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}