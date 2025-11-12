#include<bits/stdc++.h>
using namespace std;
vector<string>rp;
struct trie{
	int son[5000010][26];
	vector<int>fail;
	int tot=1;
	vector<int>id;
	vector<int>dep;
	void init(){
		fail.push_back(0);
		id.push_back(0);
		dep.push_back(0);
		return;
	}
	void inst(string s,int iid){
		int len=s.length();
		int p=0;
		for(int i=0;i<len;i++){
			if(son[p][s[i]-'a']){
				p=son[p][s[i]-'a'];
			}
			else{
				tot++;
				son[p][s[i]-'a']=tot;
				dep.push_back(dep[p]+1);
				int x=p;
				while(x&&!son[fail[x]][s[i]-'a'])x=fail[x];
				x=fail[x];
				if(son[x][s[i]-'a']){
					fail.push_back(son[x][s[i]-'a']);
				}else fail.push_back(0);
				id.push_back(0);
				p=tot;
			}
		}
		id[p]=iid;
		return;
	}
	int ans(string t1,string t2){
		int cnt=0;
		int len=t1.length();
		int p=0;
		string op;
		int st=0;
		for(int i=0;i<len;i++){
			while(p&&!son[p][t1[i]-'a'])p=fail[p];
			if(son[p][t1[i]-'a']){
				if(p==0)st=i;
				p=son[p][t1[i]-'a'];
				if(id[p]){
					op=t1;
					op.erase(st,dep[p]);
					op.insert(st,rp[id[p]]);
					if(op==t2)cnt++;
				}
			}
		}
		return cnt;
	}
}tr;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);cout.tie(NULL);
	int n,q;
	cin>>n>>q;
	tr.init();
	string s1,s2;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
//		tr.inst(s1,i);
		rp.push_back(s2);
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cout<<tr.ans(t1,t2)<<'\n';
	}
	return 0;
}
