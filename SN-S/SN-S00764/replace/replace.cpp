#include<bits/stdc++.h>
using namespace std;

/*
先整理一下思路：
能替换有这么几种可能：
1.两个字符串本身就是可替换的左右
2.两个字符串拥有相同的前驱、后继，同时对中间执行1判断。
可以维护两个set，判断某一个元素可不可以被替换。
再来一个map，对应替换关系。 

如果n <= 1000，或者m = 1，那么做这些操作。
否则，只做特性B。怎么做一会说 
因为只有a和b，并且b只出现一次。
那我可以重新进行一次处理：用结构体，存a的数量和b的变化（-为向左，+为向右）
同时对输入的s进行判断，如果满足同样的b的变化同时a数量>=替换字符串，那么就ans+1 
*/

int n,m,ans;//n个可替换，m次询问，答案 
set<string> S1,S2;//被替换、替换为
map<string,string> M;//替换

struct Change {
	int cnt,move;
};

Change c[200010];

void solve1(string s1,string s2) {
	if(S1.count(s1) && S2.count(s2) && M[s1] == s2)
		ans++;
	//赌他是0和1吧 
	cout<<ans<<endl;
}

void solve2(string s1,string s2) {
	//只看B
	int n_move = s1.find("b") - s2.find("b");
	for(int i = 0;i<n;i++) 
		if(c[i].cnt <= s1.length() && c[i].move == n_move)
			ans++;
	cout<<endl;
}

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i<n;i++) {
		string s1,s2;
		cin>>s1>>s2;
		S1.insert(s1);
		S2.insert(s2);
		M.insert({s1,s2});
		//如果是b处理一下
		c[i].cnt = s1.length();
		c[i].move = s1.find("b") - s2.find("b");
	}
	while(m--) {
		ans = 0;
		string s1,s2;
		cin>>s1>>s2;
		if(s1.length() >= 2010)
			solve2(s1,s2);
		else
			solve1(s1,s2);
	}
	return 0;
} 
