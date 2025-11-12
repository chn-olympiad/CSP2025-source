#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
const int N = 550;
int s[N],c[N];
bool vis[N];
int ans=0;
long long A(int n,int m){
	int ans=1;
	for(int i = n-m+1; i <= n; i++) ans=(ans*i)%MOD;
	return ans;
}
int n,m;
void f(int b){
	ans+=b;
	while(ans>=MOD) ans-=MOD;
}
//set<vector<int> > st;
void ptint(vector<int> &v){
	for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';
	cout << '\n';
}
void dfs(int num,int cnt/*,vector<int> stt*/,int sum){
	if(cnt>=m&&num<n){
		f(A(n-num+1,n-num+1));
		return ;
	}
	else if(num>n){
//		cout << "Ywa " << cnt << '\n';
		if(cnt>=m){
//			ptint(stt);
//			st.insert(stt);
			f(1);
		}
		return ;
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
//			cout << num << ' ' << cnt << ' ' << mx[num] << ' ' << c[i] << '\n';
			
			if(sum<c[i]&&s[num]==1){
				vis[i]=true;
//				stt.push_back(i);
				dfs(num+1,cnt+1/*,stt*/,sum);
//				stt.pop_back();
				vis[i]=false;
			}else{
				vis[i]=true;
//				stt.push_back(i);
				dfs(num+1,cnt/*,stt*/,sum+1);
//				stt.pop_back();
				vis[i]=false;
			}
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	string ss; cin >> ss;
	bool flag=true;
	for(int i = 0; i < n; i++){
		s[i+1]=ss[i]-'0';
//		cout << "s " << ss[i] << '\n';
		flag=(s[i]==1&&flag);
	}
	if(flag){
		cout << A(n,n);
		return 0;
	}
	for(int i = 1; i <= n; i++) cin >> c[i];
	vector<int> v;
	dfs(1,0/*,v*/,0);
//	f(st.size());
	cout << ans;
}
