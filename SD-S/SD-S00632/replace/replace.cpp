#include<bits/stdc++.h>
using namespace std;
typedef pair<string,string> PSS;
const int N=2e5+5;
int n,q,un[N][2];
string s1,s2,q1[N],q2[N],t1,t2;
map<PSS,int> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		int st=0,e=s1.size();
		for(;st<e;st++)if(s1[st]!=s2[st])break;
		for(;e>st;e--)if(s1[e]!=s2[e])break;
		for(int j=st;j<=e;j++)q1[i]+=s1[j],q2[i]+=s2[j];
	}
	for(int i=1;i<=n;i++)mp[{q1[i],q2[i]}]++;
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		int st=0,e=s1.size();
		for(;st<e;st++)if(s1[st]!=s2[st])break;
		for(;e>st;e--)if(s1[e]!=s2[e])break;
		for(int j=st;j<=e;j++)t1+=s1[j],t2+=s2[j];
		cout<<mp[{t1,t2}]<<endl;
	}
	return 0;
}

