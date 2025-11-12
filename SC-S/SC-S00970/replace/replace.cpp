#include<bits/stdc++.h>
using namespace std;
const int N=5e6+100;
map<string,string> vk;
vector<string> q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string a,b;cin>>a>>b;
		vk[a]=b,vk[b]=a;
		q.push_back(a);
		q.push_back(b);
	}
	while(m--){
		string s,r,cha,ch;
		cin>>s;cin>>r;
		int x=s.size(),u,v,f,ans=0;
		s=' '+s,r=' '+r;
		for(int i=1;i<=x;i++){
			if(f==0&&s[i]!=r[i]) u=i,f=1;
			else if(f==1&&s[i]!=r[i]) v=i; 
		}
		for(int i=u;i<=v;i++)
			cha+=s[i],ch+=r[i];
		for(auto c:q){
			if(c.size()!=x)
				if(!c.find(cha)&&!s.find(c)&&!r.find(vk[c])&&!vk[c].find(ch)){
				ans++;	
			}
		}
		cout<<ans<<"\n";
	}	

}