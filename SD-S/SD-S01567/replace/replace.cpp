#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> PII;
const int M=5000005,N=400005;
int n,q,vs1[N],vs2[N],ct,id1,id2;
set<pair<string,string> >st;
vector<PII>vec[N];
string S,T,s1,s2;
map<int,int>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	if(n<=100){
		for(int i=1;i<=n;i++)cin>>S>>T,st.insert({S,T});
		while(q--){
			cin>>s1>>s2,ct=0;
			for(int i=0;i<200;i++)vs1[i]=vs2[i]=0;
			for(int i=0;i<(int)s1.size()&&s1[i]==s2[i];i++)vs1[i]=1;
			for(int i=(int)s1.size()-1;~i&&s1[i]==s2[i];i--)vs2[i]=1;
			for(int i=0;i<(int)s1.size();i++){
				S=T="";
				for(int j=i;j<(int)s1.size();j++){
					S+=s1[j],T+=s2[j];
					if(st.find({S,T})!=st.end()&&(!i||vs1[i-1])&&(j==(int)s1.size()-1||vs2[j+1]))ct++;
				}
			}
			cout<<ct<<'\n';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>S>>T;
		for(int j=0;j<(int)S.size();j++){
			if(S[j]=='b')id1=j;
			if(T[j]=='b')id2=j;
		}
		if(!mp[id1-id2])mp[id1-id2]=++ct;
		vec[mp[id1-id2]].emplace_back(id1,(int)S.size()-id1-1);
	}
	for(int j=1,id;j<=q;j++){
		cin>>s1>>s2,ct=0;
		for(int i=0;i<(int)s1.size();i++){
			if(s1[i]=='b')id1=i;
			if(s2[i]=='b')id2=i;
		}
		id=mp[id1-id2];
		for(pair<int,int> tmp:vec[id])if(tmp.fi<=id1&&tmp.se<=(int)s1.size()-id1-1)ct++;
		cout<<ct<<"\n";
	}
	return 0;
}
