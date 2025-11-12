#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define N 200050
#define M 5000050
typedef long long ll;
typedef pair<ll,ll> pii;
#define int long long

int nxt[M];
vector<int> v1,v2;
void kmp(string s1,string s2,vector<int> &v){
	int l1=s1.size();
	int l2=s2.size();
	s1=" "+s1;
	s2=" "+s2;
	
	v.clear();
	int len=max(l1,l2);
	for(int i=0; i<=len; i++) nxt[i]=0;
	
	for(int i=2,j=0; i<=l2; i++){
		while(j && s2[j+1]!=s2[i]) j=nxt[j];
		if(s2[j+1]==s2[i]) j++;
		nxt[i]=j;
	}
	for(int i=1,j=0; i<=l1; i++){
		while(j && s2[j+1]!=s1[i]) j=nxt[j];
		if(s2[j+1]==s1[i]) j++;
		if(j==l2) v.push_back(j);
	}
}

int n,q;
ll cnt=0;
string s[N][2];
string str1,str2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>q;
	for(int i=1; i<=n; i++)
		cin>>s[i][0]>>s[i][1];
		
	for(int i=1; i<=q; i++){
		cin>>str1>>str2;
		if(str1.size()!=str2.size()){
			cout<<0<<endl;
			continue;
		}
		cnt=0;
		for(int j=1; j<=n; j++){
			kmp(str1,s[j][0],v1);
			kmp(str2,s[j][1],v2);
			if(v1.size()==1&&v2.size()==1&&v1[0]==v2[0])
				cnt++;
		}
		cout<<cnt<<endl;
	}
	
	return 0;
}
