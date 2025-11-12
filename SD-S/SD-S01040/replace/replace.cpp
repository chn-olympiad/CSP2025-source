#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MX=2e5+10;
map<string,string> v;
string s[MX][2],t[MX][2];
int n,q;
void funca(int id){
	int len=t[id][0].size();
	int cnt=0;
	for(int i=0;i<len;i++){
		for(int j=1;i+j-1<len;j++){
			string su,bs="",tr="",tmp;
			su=t[id][0].substr(i,j);
			if(i!=0)bs=t[id][0].substr(0,i);
			if(i+j-1!=len-1)tr=t[id][0].substr(i+j);
			if(v.find(su)!=v.end()){
				tmp=bs+v[su]+tr;
//				cout << su << "---" << v[su] << "---" << tmp << "\n";
				if(tmp==t[id][1])cnt++;
			}
		}
	}
	cout << cnt << "\n";
	return ;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	int f=0;
	char ch;
	for(int i=1;i<=n;i++){
		cin >> s[i][0] >> s[i][1];
		for(int j=0;j<s[i][0].size();j++){
			if(s[i][0][j]!='a'&&s[i][0][j]!='b')f=1;
		}
		for(int j=0;j<s[i][1].size();j++){
			if(t[i][0][j]!='a'&&t[i][0][j]!='b')f=1;
		}
		v[s[i][0]]=s[i][1];
	}
	for(int i=1;i<=q;i++){
		cin >> t[i][0] >> t[i][1];
		for(int j=0;j<t[i][0].size();j++){
			if(t[i][0][j]!='a'&&t[i][0][j]!='b')f=1;
		}
		for(int j=0;j<t[i][1].size();j++){
			if(t[i][0][j]!='a'&&t[i][0][j]!='b')f=1;
		}
	}
	if(q>=500)while(q--)cout << 0 << "\n";
	else for(int mn=1;mn<=q;mn++)funca(mn);
	return 0;
}
