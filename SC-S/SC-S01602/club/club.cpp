#include<bits/stdc++.h>
#define endl '\n'
#define ri register int
#define int long long
#define fixedset(a) fixed << setprecision(a)
#define pii pair<int,int>
#define mp make_pair
#define ls(x) x<<1
#define rs(x) x<<1|1
#define eps 1e-7
#define inf 104514
#define mf 5011
#define sf 511
#define MOD 114514
#define mod(x) (x+MOD)%MOD;
using namespace std;
int n,ans,num[inf][4],dp1[2][sf][sf],dp2[2][inf];
//dp1[i][j][k]:在getans1()中，滚动处理下，前 i 位中满足选择了 j 个A俱乐部，k个B俱乐部的最大满意度
//dp2[i][j]:在getans3()中，滚动处理下，前 i 位中满足选择了 j 个A俱乐部的最大满意度
bool checkans1(){
	if(n<sf) return true;
	else return false;
}
bool checkans2(){
	for(ri i=1;i<=n;i++) if(num[i][2]!=0 || num[i][3]!=0) return false;
	return true;
}
bool checkans3(){
	for(ri i=1;i<=n;i++) if(num[i][3]!=0) return false;
	return true;
}
void getans1(){
	memset(dp1,-1,sizeof(dp1)); ans=-inf;
	dp1[0][0][0]=0;
	for(ri i=1;i<=n;i++){
		memset(dp1[i%2],-1,sizeof(dp1[i%2]));
		for(ri j=0;j<=n/2;j++) for(ri k=0;k<=n/2;k++){
			if(i-j-k>n/2) continue;
			//本次选择A俱乐部
			if(j>=1) dp1[i%2][j][k]=max(dp1[i%2][j][k],dp1[(i+1)%2][j-1][k]+num[i][1]);
			//本次选择B俱乐部
			if(k>=1) dp1[i%2][j][k]=max(dp1[i%2][j][k],dp1[(i+1)%2][j][k-1]+num[i][2]);
			//本次选择C俱乐部
			if(i-j-k<=n/2) dp1[i%2][j][k]=max(dp1[i%2][j][k],dp1[(i+1)%2][j][k]+num[i][3]);
		}
	}
	
	for(ri i=0;i<=n/2;i++) for(ri j=0;j<=n/2;j++){
		if(n-i-j<=n/2) ans=max(ans,dp1[n%2][i][j]);
	}
	return ;
}
void getans2(){
	ans=0;
	vector<int> tmp;
	for(ri i=1;i<=n;i++) tmp.push_back(num[i][1]);
	sort(tmp.begin(),tmp.end());
	reverse(tmp.begin(),tmp.end());
	for(ri i=1;i<=n/2;i++) ans+=tmp[i-1];
	return ;
}
void getans3(){
	memset(dp2,-1,sizeof(dp2)); ans=-inf;
	dp2[0][0]=0;
	for(ri i=1;i<=n;i++){
		memset(dp2[i%2],-1,sizeof(dp2[i%2]));
		for(ri j=0;j<=n/2;j++){
			if(i-j>n/2) continue;
			//本次选择A俱乐部
			if(j>=1) dp2[i%2][j]=max(dp2[i%2][j],dp2[(i+1)%2][j-1]+num[i][1]);
			//本次选择B俱乐部
			if(i-j<=n/2) dp2[i%2][j]=max(dp2[i%2][j],dp2[(i+1)%2][j]+num[i][2]);
		}
	}
	for(ri i=0;i<=n/2;i++){
		if(n-i<=n/2) ans=max(ans,dp2[n%2][i]);
	}
	return ;
}
void getans4(){
	int ans=0;
	for(ri i=1;i<=n;i++) ans+=max(num[i][1],max(num[i][2],num[i][3]));
	return ;
}
void solve(){
	cin >> n;
	for(ri i=1;i<=n;i++) cin >> num[i][1] >> num[i][2] >> num[i][3];
	if(checkans1()) getans1(); //编号1~11
	else if(checkans2()) getans2(); //编号12
	else if(checkans3()) getans3(); //编号13,14
	else getans4(); //编号15，16
	
	cout << ans << endl;
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T; cin >> T;
	while(T--) solve();
	return 0;
}