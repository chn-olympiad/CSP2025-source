#include <bits/stdc++.h>
using namespace std;
//inline int read(){
//	int ans = 0,f = 1;
//	char ch = getchar();
//	while(!isdigit(ch)){
//		if(ch == '-') f = -1;
//		ch = getchar();
//	}
//	while(isdigit(ch)){
//		ans = ans*10 + ch - '0';
//		ch = getchar(); 
//	}
//	return ans*f;
//}
//struct dsu{
//	vector<int> pa,size;
//	int count;
//	dsu(int n){
//		int find(long long x){
//			return x==pa[x] ? x : pa[x]==find(pa[x]);
//		}
//		void merge(long long x,long long y){
//			x = find(x),y = find(y);
//			if(x==y) return
//		}
//	} 
//};
string s1,s2,t1,t2;
long long ans;
void solve(){
	cin>>s1>>s2;
	for(int i=1;i<=n;i++){
		cin>>t1>>t2;
		if(s1.find(t1)==s2.find(t2)) ans++;
	}
	cout<<ans<<'\n';
	
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int t = 1;
	cin>>n>>t;
	while(t--){
		solve();
	}
	
	
	return 0;
} 
