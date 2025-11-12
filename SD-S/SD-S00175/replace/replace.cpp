#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
/*
by qqqaaazzz

key obser : 每一个替换对好像都是命中注定的一样。

在命中注定的对里面，找到真正适合我的子串数量。

查询前面有多少个串是我的子串。

AC-自动机。

有 27 种字符。

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
int n,q;
string s[200010];//自动合并了 
string t[200010];
string a,b;

struct Node{
	int fail;
	int s[27];
	int cnt;
};
Node tree[6000010];
int h[6000010],e[12000010],ne[12000010],cntt;
int idx;

void add(int x,int y){
	++cntt;
	e[cntt] = y;
	ne[cntt] = h[x];
	h[x] = cntt;
}

void dfs(int d){
	for (int i=h[d];i!=-1;i=ne[i]){
		tree[e[i]].cnt += tree[d].cnt;
		dfs(e[i]);
	}
}

void build(){
	queue<int> q;
	for (int i=0;i<27;i++){
		if(tree[0].s[i]){
			q.push(tree[0].s[i]);
			tree[tree[0].s[i]].fail = 0;
		}
	}
	for (int i=0;i<=idx;i++) h[i] = -1;
	while(!q.empty()){
		int f = q.front();
		q.pop();
		add(tree[f].fail,f);
		for (int i=0;i<27;i++){
			if(tree[f].s[i]){
				tree[tree[f].s[i]].fail = tree[tree[f].fail].s[i];
				q.push(tree[f].s[i]);
			}
			else tree[f].s[i] = tree[tree[f].fail].s[i];
		}
	}
	dfs(0);
}

signed main()
{
//	system("fc replace1.ans my.out");
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	FAST;
	cin >> n >> q;
	for (int i=1;i<=n;i++){
		cin >> a >> b;
		int m = a.length();
		if(a==b);//不能加入匹配。
		else{
			int l = 0,r = m-1;
			while(a[l]==b[l]) ++l;
			while(a[r]==b[r]) --r;
			for (int j=0;j<l;j++){
				s[i] += a[j];
				s[i] += b[j];
			}
			s[i] += '{';
			for (int j=l;j<=r;j++){
				s[i] += a[j];
				s[i] += b[j];
			}
			s[i] += '{';
			for (int j=r+1;j<m;j++){
				s[i] += a[j];
				s[i] += b[j];
			}
			int now = 0;
			for (auto j : s[i]){
				if(tree[now].s[j-'a']==0) tree[now].s[j-'a'] = ++idx;
				now = tree[now].s[j-'a'];
			}
			tree[now].cnt++;
		}
	}
	build();
	
	for (int i=1;i<=q;i++){
		cin >> a >> b;
		if(a.length()!=b.length()){
			cout << 0 << "\n";
		}
		else{
			int m = a.length();
			
			int l = 0,r = m-1;
			while(a[l]==b[l]) ++l;
			while(a[r]==b[r]) --r;
			for (int j=0;j<l;j++){
				t[i] += a[j];
				t[i] += b[j];
			}
			t[i] += '{';
			for (int j=l;j<=r;j++){
				t[i] += a[j];
				t[i] += b[j];
			}
			t[i] += '{';
			for (int j=r+1;j<m;j++){
				t[i] += a[j];
				t[i] += b[j];
			}
			int now = 0,cnt = 0;
			for (auto j : t[i]){
				now = tree[now].s[j-'a'];
				cnt += tree[now].cnt;
			}
			cout << cnt << "\n";
		}
	}
	return 0;
}


