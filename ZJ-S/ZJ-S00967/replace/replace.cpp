#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
int n,q;
int P=29,J=13;
int p[N],pp[130];
vector<int>g;
void fuck(string s1,string s2){
	int k1=0,k2=0;
	for(int i=0;i<s1.size();++i)k1+=pp[s1[i]]*p[i];
	for(int i=0;i<s2.size();++i)k2+=pp[s2[i]]*p[i];
//	cout<<k1<<" "<<k2<<" "<<k1-k2<<"\n";
	g.push_back(k1-k2);
}
void work(string s1,string s2){
	if(s1.size()!=s2.size()){
		cout<<"0\n";return;
	}
	int k1=0,k2=0;
	for(int i=0;i<s1.size();++i)k1+=pp[s1[i]]*p[i];
	for(int i=0;i<s2.size();++i)k2+=pp[s2[i]]*p[i];
//	cout<<k1<<" "<<k2<<" "<<k1-k2<<"\n";
	int ans=0;
	for(int u:g)if(((k1-k2)%u)==0)ans++;
	cout<<max(ans-1,0)<<"\n";
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>q;
	p[0]=1;
	for(int i=1;i<=N-5;++i)p[i]=p[i-1]*P;
	pp['a']=1;
	for(int i='b';i<='z';++i)pp[i]=pp[i-1]*J;
	for(int i=1;i<=n;++i){
		string s1,s2;
		cin>>s1>>s2;
		fuck(s1,s2);
	}
	for(int i=1;i<=q;++i){
		string t1,t2;
		cin>>t1>>t2;
		work(t1,t2);
	}
}
