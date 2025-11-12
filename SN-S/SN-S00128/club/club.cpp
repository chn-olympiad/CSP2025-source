#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int ans = 0,f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		ans = ans*10 + ch - '0';
		ch = getchar(); 
	}
	return ans*f;
}
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


long long n;
struct ren{
	char yi,er,san;
	long long za,zb,zc;
	bool operater < (const struct ren& rhs) const {
		if(za==0&&zb==0&&rhs.za==0&&rhs.zb==0) return zc>=rhs.zc;
		else if(za==0&&zc==0&&rhs.za==0&&rhs.zc==0) return zb>=rhs.zb;
		else if(zb==0&&zc==0&&rhs.zb==0&&rhs.zc==0) return za>=rhs.za;
	}
}s[100010];
long long a,b,c,suma,sumb,sumc,ans;
void solve(){
	n = read();
	for(int i=1;i<=n;i++){
		a = read(),b = read(),c = read();
		if(a==0&&b==0) s[i].yi = 'c',s[i].zc = c;
		else if(a==0&&c==0) s[i].yi = 'b',s[i].zb = b;
		else if(b==0&&c==0) s[i].yi = 'a',s[i].za = a;
		else if(max(a,max(b,c))==a){
			s[i].yi = 'a',s[i].za = a;
			if(max(b,c)==b) s[i].er = 'b',s[i].zb = b,s[i].san = 'c',s[i].zc = c;
			else s[i].er = 'c',s[i].zc = c,s[i].san = 'b',s[i].zb = b;
		}else if(max(a,max(b,c))==b){
			s[i].yi = 'b',s[i].zb = b;
			if(max(a,c)==a) s[i].er = 'a',s[i].za = a,s[i].san = 'c',s[i].zc = c;
			else s[i].er = 'c',s[i].zc = c,s[i].san = 'a',s[i].za = a;
		}else{
			s[i].yi = 'c',s[i].zc = c;
			if(max(a,b)==a) s[i].er = 'a',s[i].za = a,s[i].san = 'b',s[i].zb = b;
			else s[i].er = 'b',s[i].zb = b,s[i].san = 'a',s[i].za = a;
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i].yi=='a'){
			if(suma<n/2) ans += za; suma++;
			else if(a[i].er=='b'){
				if(sumb<n/2) ans += zb; sumb++;
				else ans += zc; sumc++;
			}
		}else if(a[i].yi=='b'){
			if(sumb<n/2) ans += zb; sumb++;
			else if(s[i].er=='a'){
				if(suma<n/2) ans += za; suma++;
				else ans += zc; sumc++;
			}
		}else{
			if(sumc<n/2) ans += zc; sumc++;
			else if(s[i].er = 'a'){
				if(suma<n/2) ans += za; suma++;
				else ans += zb; sumb++;
			}
		}
	}
	cout<<ans<<'\n';
	
	
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t = 1;
	t = read();
	while(t--){
		solve();
	}
	
	
	return 0;
} 
