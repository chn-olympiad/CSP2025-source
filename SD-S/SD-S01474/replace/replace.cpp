#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
const int L = 5e6+5;
struct Node{
	vector<int> ad;
	int nex[26],fail;
	Node():
		ad(),fail(0){
		for(int i=0;i<26;i++){
			nex[i] = 0;
		}
	}
}node1[L],node2[L];
int siz[N];
int top1 = 1,top2 = 1,r;
vector<pair<int,int> > s1t,s2t;
void add(Node* node,string& s,int& top,int d){
	int now = 1;
	for(char i : s){
		int nex = i-'a';
		if(node[now].nex[nex]==0){
			node[now].nex[nex] = ++top;
		}
		now = node[now].nex[nex];
	}
	node[now].ad.push_back(d);
}
void refail(Node* node){
	queue<int> q;
	for(int i=0;i<26;i++){
		if(node[1].nex[i]==0){
			node[1].nex[i] = 1;
			continue;
		}
		node[node[1].nex[i]].fail = 1;
		q.push(node[1].nex[i]);
	}
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(int i=0;i<26;i++){
			if(node[now].nex[i]==0){
				node[now].nex[i] = node[node[now].fail].nex[i];
				continue;
			}
			node[node[now].nex[i]].fail = node[node[now].fail].nex[i];
			q.push(node[now].nex[i]);
		}
	}
}
void ask(Node* node,string& s,vector<pair<int,int> >* st){
	int now = 1;
	for(int i=0;i<s.size();i++){
		now = node[now].nex[s[i]-'a'];
		if(i<r){
			continue;
		}
		for(int j=now;j!=1;j=node[j].fail){
			for(int l : node[j].ad){
				st->emplace_back(i,l);
			}
		}
	}
}
void read(string& s){
	char c;
	do{
		c = getchar();
	}while(c<'a'||c>'z');
	while('a'<=c&&c<='z'){
		s+=c;
		c = getchar();
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		read(s1);
		read(s2);
		add(node1,s1,top1,i);
		add(node2,s2,top2,i);
		siz[i] = s1.size();
	}
	refail(node1);
	refail(node2);
	while(q--){
		string t1,t2;
		read(t1);
		read(t2);
		int l = -1;
		for(int i=0;i<t1.size();i++){
			if(t1[i]!=t2[i]){
				if(l==-1){
					l = i;
				}
				r = i;
			}
		}
		s1t.clear();
		s2t.clear();
		ask(node1,t1,&s1t);
		ask(node2,t2,&s2t);
		int ans = 0,p1 = 0;
		for(int p2=0;p2<s2t.size();p2++){
			while(p1<s1t.size()&&s1t[p1].first<s2t[p2].first){
				p1++;
			}
			if(p1==s1t.size()){
				break;
			}
			for(int i=p1;i<s1t.size()&&s1t[i].first==s2t[p2].first;i++){ 
				if(s1t[i].second==s2t[p2].second&&s1t[i].first-siz[s1t[i].second]<l){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
