#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 5;
int t,n;
ll ans = 0;
int p[maxn][4],sz[4];
struct node{
	int id,val;
};
node nm1[maxn],nm2[maxn],nm3[maxn];
bool cmp(node a,node b){
	return a.val < b.val;
}
string test(int num){
	int mxn = max(p[num][1],max(p[num][2],p[num][3]));
	int mnn = min(p[num][1],min(p[num][2],p[num][3]));
	if(mxn == p[num][1]){
		if(mnn == p[num][2]) return "132";
		if(mnn == p[num][3]) return "123";
	}
	else if(mxn == p[num][2]){
		if(mnn == p[num][1]) return "231";
		if(mnn == p[num][3]) return "213";
	}
	else if(mxn == p[num][3]){
		if(mnn == p[num][1]) return "321";
		if(mnn == p[num][2]) return "312";
	}
}
void check(int tmp,int a1,int b1){//现在人的id、最大和第二
	if(a1 == 1){
		if(sz[1] >= n / 2){
			int d = nm1[1].id;
			string s = test(d);
			int a2 = s[0] - '0',b2 = s[1] - '0';//队列中最小的人的最大和第二
			if(p[tmp][a1] + p[d][b2] > p[tmp][b1] + p[d][a2]){
				nm1[1] = {tmp,p[tmp][1]};
				ans += p[tmp][1] - p[d][1];
				if(b2 == 2) nm2[++sz[2]] = {d,p[d][2]},ans += p[d][2];
				else nm3[++sz[3]] = {d,p[d][3]},ans += p[d][3];
			}
			else{
				if(b1 == 2) nm2[++sz[2]] = {tmp,p[tmp][2]},ans += p[tmp][2];
				else nm3[++sz[3]] = {tmp,p[tmp][3]},ans += p[tmp][3];
			}
		}
		else{
			nm1[++sz[1]] = {tmp,p[tmp][1]};
			ans += p[tmp][1];
		}
	}
	else if(a1 == 2){
		if(sz[2] >= n / 2){
			int d = nm2[1].id;
//			cout<<d<<endl;
			string s = test(d);
			int a2 = s[0] - '0',b2 = s[1] - '0';//队列中最小的人的最大和第二
			if(p[tmp][a1] + p[d][b2] > p[tmp][b1] + p[d][a2]){
				nm2[1] = {tmp,p[tmp][2]};
				ans += p[tmp][2] - p[d][2];
				if(b2 == 1) nm1[++sz[1]] = {d,p[d][1]},ans += p[d][1];
				else nm3[++sz[3]] = {d,p[d][3]},ans += p[d][3];
			}
			else{
				if(b1 == 1) nm1[++sz[1]] = {tmp,p[tmp][1]},ans += p[tmp][1];
				else nm3[++sz[3]] = {tmp,p[tmp][3]},ans += p[tmp][3];
			}
		}
		else{
			nm2[++sz[2]] = {tmp,p[tmp][2]};
			ans += p[tmp][2];
		}
	}
	else if(a1 == 3){
		if(sz[3] >= n / 2){
			int d = nm3[1].id;
//			cout<<d<<endl;
			string s = test(d);
			int a2 = s[0] - '0',b2 = s[1] - '0';//队列中最小的人的最大和第二
//			cout<<p[tmp][a1] + p[d][b2] <<' '<< p[tmp][b1] + p[d][a2]<<endl;
			if(p[tmp][a1] + p[d][b2] > p[tmp][b1] + p[d][a2]){
				nm3[1] = {tmp,p[tmp][3]};
				ans += p[tmp][3] - p[d][3];
				if(b2 == 1) nm1[++sz[1]] = {d,p[d][1]},ans += p[d][1];
				else nm2[++sz[2]] = {d,p[d][2]},ans += p[d][2];
			}
			else{
				if(b1 == 2) nm2[++sz[2]] = {tmp,p[tmp][2]},ans += p[tmp][2];
				else nm1[++sz[1]] = {tmp,p[tmp][1]},ans += p[tmp][1];
			}
		}
		else{
			nm3[++sz[3]] = {tmp,p[tmp][3]};
			ans += p[tmp][3];
		}
	}
	sort(nm1 + 1,nm1 + sz[1] + 1,cmp);
	sort(nm2 + 1,nm2 + sz[2] + 1,cmp);
	sort(nm3 + 1,nm3 + sz[3] + 1,cmp);
//	cout<<ans<<endl;
}
void solve(){
	for(int i = 1;i <= n;i++){
		string s1 = test(i);
		int a1 = s1[0] - '0',b1 = s1[1] - '0';
		check(i,a1,b1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(sz,0,sizeof sz);
		memset(p,0,sizeof p);
		ans = 0;
		scanf("%d",&n);
		for(int i = 1;i <= n;i++) scanf("%d%d%d",&p[i][1],&p[i][2],&p[i][3]);
		solve();
		printf("%lld\n",ans);
	}
	return 0;
}