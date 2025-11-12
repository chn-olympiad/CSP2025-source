#include<map>
#include<set>
#include<vector>
#include<iostream>
#define endl '\n'
#define C 98280331
#define int long long
using namespace std;
const int N=2e6+5,mod=1e9+7;
int n,q,tot,CC[N],len[N],dft[N],L[N],R[N],has1[N],has2[N];
string s1,s2,S1[N],S2[N];
vector<int> Id[N],hash1[N],hash2[N];
map<pair<int,int>,int> mo;
set<int> so[N];
void init(int id){
	int l=0,r=-1;
	hash1[id].push_back(0);hash2[id].push_back(0);
	for(int i=1;i<=len[id];i++){
//		dft[id]=(dft[id]*C%mod+(S1[id]==S2[id]?2:1))%mod;
		hash1[id].push_back(0);hash2[id].push_back(0);
		hash1[id][i]=(hash1[id][i-1]*C%mod+(S1[id][i]-'a'+1))%mod;
		hash2[id][i]=(hash2[id][i-1]*C%mod+(S2[id][i]-'a'+1))%mod;
		if(S1[id][i]!=S2[id][i]){
			if(!l) l=i;
			r=i;
		}
	}
	if(l!=0){
		L[id]=l,R[id]=r;
		int k1=(hash1[id][r]-hash1[id][l-1]*CC[r-l+1]%mod+mod)%mod;
		int k2=(hash2[id][r]-hash2[id][l-1]*CC[r-l+1]%mod+mod)%mod;
		if(!mo[{k1,k2}]) mo[{k1,k2}]=++tot;
		Id[mo[{k1,k2}]].push_back(id);
	}
//	cout<<hash1[id][len[id]]<<",,,\n";
}
int work(){
	int llen=s1.size()-1,an=0;
	int l=0,r=-1;
	for(int i=1;i<=llen;i++){
		has1[i]=(has1[i-1]*C%mod+(s1[i]-'a'+1))%mod;
		has2[i]=(has2[i-1]*C%mod+(s2[i]-'a'+1))%mod;
		if(s1[i]!=s2[i]){
			if(!l) l=i;
			r=i;
		}
//		cout<<"???"<<has1[i]<<endl;
	}
	int k1=(has1[r]-has1[l-1]*CC[r-l+1]%mod+mod)%mod;
	int k2=(has2[r]-has2[l-1]*CC[r-l+1]%mod+mod)%mod;
	if(!mo[{k1,k2}]){return 0;}
	for(int id:Id[mo[{k1,k2}]]){
		int awa=L[id]-1;
//		cout<<id<<" "<<l<<"-"<<awa<<endl;
		int st=l-awa;if(st<=0) continue;
		int a=(has1[st+len[id]-1]-has1[st-1]*CC[st+len[id]-1-st+1]%mod+mod)%mod;
		int qwq=len[id];
		int b=hash1[id][qwq];
//		cout<<id<<":"<<a<<"~"<<b<<" "<<has1[st+len[id]-1]<<"-"<<has1[st-1]<<endl;
		if(a==b) an++;
//		cout<<"++"<<id<<endl;
	}
	return an;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;CC[0]=1;
	for(int i=1;i<=N-5;i++) CC[i]=CC[i-1]*C%mod;
	for(int i=1;i<=n;i++){
		cin>>S1[i]>>S2[i];
		S1[i]='6'+S1[i],S2[i]='6'+S2[i];
		len[i]=S1[i].size()-1;init(i);
	}
	while(q--){
		cin>>s1>>s2;s1='6'+s1;s2='6'+s2;
		cout<<work()<<endl;
		for(int i=0;i<=s1.size();i++) has1[i]=has2[i]=0;
	}
	return 0;
}