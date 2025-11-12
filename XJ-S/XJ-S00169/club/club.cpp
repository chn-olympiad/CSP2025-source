#include <bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int id,a,b,c,maxn;
	int maxtype;
};
map<int,int> mp;
bool cmp(node q,node h){
	return q.maxn > h.maxn;
} 
node member[100005];
vector<int> tempa,tempb,tempc;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		long long ans = 0;
		int can = n / 2;
		for(int i=1;i<=n;i++){
			member[i].id = i;
			cin >> member[i].a >> member[i].b >> member[i].c;
			int want = max(member[i].a,max(member[i].b,member[i].c));
			member[i].maxn = want;
			if(want == member[i].c) member[i].maxtype = 3;
			if(want == member[i].b) member[i].maxtype = 2;
			if(want == member[i].a) member[i].maxtype = 1;
		}
		sort(member+1,member+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(mp[member[i].maxtype] != can){
				if(member[i].maxtype == 1) ans += member[i].a;
				if(member[i].maxtype == 2) ans += member[i].b;
				if(member[i].maxtype == 3) ans += member[i].c;
				mp[member[i].maxtype] ++;
			}
		}
		cout << ans << endl;
		mp[1] = 0;
		mp[2] = 0;
		mp[3] = 0;
	}
	return 0;
}
