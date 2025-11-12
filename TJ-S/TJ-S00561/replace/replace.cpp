#include<bits/stdc++.h>
using namespace std;
int n, k;
struct node{
	string a,b;
}t[210000];
long long ans;
int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin >> n >> k;
	string a,b;
	for(int i = 1; i <= n;i++){
		cin >> t[i].a >> t[i].b;
	}
	
	for(int i = 1; i <= k; i++){
		ans = 0;
		cin >> a >> b;
		for(int j = 1; j <= n; j++){
			if(t[j].a == a && t[j].b == b){
				ans++;
			}
		}
		
		for(int j = 1; j <= n; j++){
			int ss = t[j].a.size();
			for(int k = 0; k < a.size();k++){
				string tmp = a.substr(k,a.size());
				int p = tmp.find(t[j].a);
				if(p < tmp.size()){
					string c = a;
					
					c.replace(p,ss,b);
					if(c == b) ans++;
				}
			}
		}
			cout << ans << endl;;
	}
	

	
	return 0;
} 
