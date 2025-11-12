#include<iostream>
#include<unordered_map>
using namespace std;
const int N=2e5+5;
int n,q;
unordered_map<string,string>mp;
pair<string,string>to[N];
inline bool check(string s){
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]!='a'&&s[i]!='b')	return false;
		if(s[i]=='b')	cnt++;
	}
	if(cnt==1)	return true;
	else	return false;
}
inline pair<int,int> fen(string s){
	for(int i=0;i<s.size();i++){
		if(s[i]=='b')	return {i,s.size()-i-1};
	}
}
void special(string s,string t){
	pair<int,int>ret11=fen(s);
	int l1=ret11.first,r1=ret11.second;
	pair<int,int>ret22=fen(t);
	int l2=ret22.first,r2=ret22.second;
	int b1=l1,b2=l2;
	int cnt=0;
	for(int i=1;i<=n;i++){
		pair<int,int>ret1=fen(to[i].first);
		pair<int,int>ret2=fen(to[i].second);
		int newb=b1+(ret2.first-ret1.first);
		if(l1>=ret1.first&&r1>=ret1.second&&l2>=ret2.first&&r2>=ret2.second&&newb==b2)	cnt++;
	}
	cout<<cnt<<"\n";
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	bool sp=true;
	for(int i=1;i<=n;i++){
		string s,t;
		cin>>s>>t;
		if(check(s)==false||check(t)==false)	sp=false;
		mp[s]=t;
		to[i]={s,t};
	}
	while(q--){
		string s,t;
		cin>>s>>t;
		if(sp&&check(s)&&check(t)){
			special(s,t); 
			continue;
		}
		int cnt=0;
		for(int l=0;l<s.size();l++){
			for(int r=l;r<s.size();r++){
				if(mp[s.substr(l,r-l+1)]==t.substr(l,r-l+1)&&s.substr(0,l)==t.substr(0,l)&&s.substr(r+1)==t.substr(r+1))	cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
