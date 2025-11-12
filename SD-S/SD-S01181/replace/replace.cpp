#include<bits/stdc++.h>

#define int long long

#define maxn 200005

#define INF (int)(1e18)

#define double long double

using namespace std;

int n,q;

struct node{
	
	string s1,s2;
	
}a[maxn];

map<string,vector<string> > m;

signed main(){

	ios::sync_with_stdio(0);
	
	cin.tie(0);
	
	cout.tie(0);
	
	freopen("replace.in","r",stdin);
	
	freopen("replace.out","w",stdout);
	
	cin >> n >> q;
	
	for(int i = 1;i <= n;++ i) cin >> a[i].s1 >> a[i].s2,m[a[i].s1].push_back(a[i].s2);
	
//	sort(a + 1,a + n + 1,cmp);
	
	while(q --){
		
		string t1,t2;
		
		cin >> t1 >> t2;
		
		if(t1.length() != t2.length()){
			
			cout << 0 << "\n";
			
			continue;
			
		}
		
		int len = t1.length();
		
		int klo = len;
		
		for(int i = len - 1;i >= 0;-- i){
			
			if(t1[i] != t2[i]){
				
				klo = i;
				
				break;
				
			}
			
		}
		
		int ans = 0;
		
		for(int i = 0;i < len;++ i){
			
			if(i > 0){
				
				if(t1[i - 1] != t2[i - 1]) break;
				
			}
			
			node cnt;
			
			cnt.s1.clear();
			
			cnt.s2.clear();
			
			for(int j = i;j < len;++ j){
				
				cnt.s1 += t1[j];
				
				cnt.s2 += t2[j];
				
				if(j < klo) continue;
				
				for(string bec : m[cnt.s1]){
					
//					cout << bec << "\n";
					
					if(bec == cnt.s2) ++ ans;
					
				}
				
			}
			
		}
		
		cout << ans << "\n";
		
	}
	
	return 0;

}

