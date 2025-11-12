#include<bits/stdc++.h>
#define N 100010
using namespace std;
struct node{
	string t;
	bool type;
};
int n,b[N];
string s[N][2];
queue<node>q;
map<string,int>mp[2];
void f(string T) {
	memset(b,0,sizeof(b));
	int j=0;
	for (int i=1;i<T.size();i++) {
		if (T[i]==T[j]) b[i]=j++;
		else b[i]=j=0;
	}
}
int bfs() {
	long long ans=0;
	while (!q.empty()) {
		node now=q.front();
		q.pop();
		string T=now.t;
		bool type=now.type;
		if (mp[type^1][T]) {
			ans+=mp[type][T]+mp[type^1][T];
			continue;
		}
		for (int i=1;i<=n;i++) {
			string S=s[i][type];
			f(S);
			int p=0;
			for (int j=0;j<T.size();j++) {
				if (T[j]==S[p]) p++;
				else p=b[p];
				if (p+1==S.size()) {
		string ss=T.substr(0,j-p)+s[i][type^1]+T.substr(j+1);
					q.push({ss,type});
					mp[type][ss]+=mp[type][T];
					p=0;
				}
			}
		}
	}
	return ans;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int Q;
	cin>>n>>Q;
	for (int i=1;i<=n;i++) {
		cin>>s[i][0]>>s[i][1];
	}
	while (Q--) {
		string t1,t2;
		cin>>t1>>t2;
		q.push({t1,0});
		q.push({t2,1});
		cout<<bfs()<<endl;
	}
}
