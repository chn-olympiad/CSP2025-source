#include<bits/stdc++.h>
using namespace std;
string S[200010][3];
int pi[200010];
bool flag[200010];
bool qian[200010],hou[200010];
void cal_pi(string s){
	int j=0;
	pi[0]=0;
	for(int i=1;i<s.size();i++){
		while(j && s[j]!=s[i])j=pi[j-1];
		if(s[j]==s[i])j++;
		pi[i]=j;
	}
}
void match(string s,string t){
	cal_pi(s);
	int j=0;
	for(int i=0;i<t.size();i++){
		while(j && s[j]!=t[i])j=pi[j-1];
		if(s[j]==t[i])j++;
		if(j!=s.size())flag[i]=0;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> S[i][1] >> S[i][2];
	}
	
	while(q--){
		string t,tt;
		cin >> t >> tt;
		int ans=0;
		qian[0]=(t[0]==tt[0]);
		for(int i=1;i<t.size();i++){
			qian[i]=((t[i]==tt[i]) && qian[i-1]);
		}
		hou[(int)(t.size())]=1;
		for(int i=t.size()-1;i>=0;i--){
			hou[i]=((t[i]==tt[i]) && hou[i+1]);
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<t.size();j++)flag[j]=1;
			match(S[i][1],t);
			match(S[i][2],tt);
			for(int j=0;j<t.size();j++){
				if(flag[j]==1 && (((int)(j-S[i][1].size())<0 || qian[j-S[i][1].size()]) && hou[j+1])){
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
