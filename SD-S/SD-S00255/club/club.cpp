#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
#define ll long long
#define sf std :: flush
#define lowbit(x) (x & (-x))
#define endl '\n'
const int N = 1e5 + 10;
struct node{
	int id,v;
	friend bool operator <(const node &a,const node &b){
		return a.v > b.v;
	}
};
int getsum(int l,vector<int> &v){
	int sum = 0;
	sort(v.begin(),v.end());
	for(int i = 0;i < v.size()-l;i++) sum += v[i];
	return sum;
}
node a[3];
void Main(){
	int n,ans = 0; cin >> n;
	vector<int> u,v,p;
	for(int i = 1;i <= n;i++){
		cin >> a[0].v >> a[1].v >> a[2].v;
		a[0].id = 0,a[1].id = 1,a[2].id = 2;
		sort(a,a+3);
		int t = a[0].v - a[1].v;
		ans += a[0].v;
		if(a[0].id == 0) u.push_back(t);
		else if(a[0].id == 1) v.push_back(t);
		else p.push_back(t);
	}
	n /= 2;
	int suf = 0;
	if(u.size() > n) suf = getsum(n,u);
	else if(v.size() > n) suf = getsum(n,v);
	else if(p.size() > n) suf = getsum(n,p);
	cout<<ans-suf<<endl;
	return ;
}
int main(){
	ios :: sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t; cin >> t;
	while(t--) Main();
	cout<<sf;
    fclose(stdin);
    fclose(stdout);
	return 0;
}


