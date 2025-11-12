#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int t,n,ans;
struct stu{
	int a,b,c;
}s[N];
priority_queue<int,vector<int>,greater<int> > qa,qb,qc;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> t;
	while(t--){
		ans = 0;
		while(!qa.empty())
			qa.pop();
		while(!qb.empty())
			qb.pop();
		while(!qc.empty())
			qc.pop();
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> s[i].a >> s[i].b >> s[i].c;
			int maxn = max(max(s[i].a,s[i].b),s[i].c);
			ans += maxn;
			if(maxn == s[i].a){
				if(s[i].b > s[i].c)
					qa.push(s[i].a-s[i].b);
				else
					qa.push(s[i].a-s[i].c);
			}
			if(maxn == s[i].b){
				if(s[i].a > s[i].c)
					qb.push(s[i].b-s[i].a);
				else
					qb.push(s[i].b-s[i].c);
			}
			if(maxn == s[i].c){
				if(s[i].b > s[i].a)
					qc.push(s[i].c-s[i].b);
				else
					qc.push(s[i].c-s[i].a);
			}
		}
		while(qa.size() > n/2){
			ans -= qa.top();
			qa.pop();
		}
		while(qb.size() > n/2){
			ans -= qb.top();
			qb.pop();
		}
		while(qc.size() > n/2){
			ans -= qc.top();
			qc.pop();
		}
		cout << ans << '\n';
	}
	return 0;
}
