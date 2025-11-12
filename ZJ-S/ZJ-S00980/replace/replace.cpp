#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,q; 
//map<string,string>mp;
string s[10000+10][3];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> q;
	for(ll i = 1;i <= n;i++){
		string a,b;
		cin >> a >> b;
//		mp[a] = b;
		s[i][1] = a;
		s[i][2] = b;
	}
	
	while(q--){
		string x,y;
		cin >> x >> y;
		ll head = -1,tail = x.size();
		while(x[head+1]==y[head+1]) head++;
		while(x[tail-1]==y[tail-1]) tail--;
		
		//cout << "head:" << head << " tail:" << tail << "\n";
		
		// x,y完全不同 
		ll ans = 0;
		if(head==-1&&tail==x.size()){
			for(ll i = 1;i <= n;i++){
				if(s[i][1]==x && s[i][2] == y) ans++;
			}
			cout << ans << "\n";
			continue;
		}
		// 右侧有相同字符 
		else if(head==-1){
			for(ll i = tail-1;i <= x.size()-1;i++){
				string p1 = "",p2 = "";
				for(ll j = 0;j <= i;j++){
					p1 = p1 + x[j];
					p2 = p2 + y[j];
				} 
				for(ll j = 1;j <= n;j++){
					if(s[j][1] == p1 && s[j][2] == p2) ans++;
				}
			}
		}
		// 左侧有相同字符 
		else if(tail == x.size()){
			for(ll i = 0;i <= head+1;i++){
				string p1 = "",p2 = "";
				for(ll j = i;j <= x.size()-1;j++){
					p1 = p1 + x[j];
					p2 = p2 + y[j];
				}
				for(ll j = 1;j <= n;j++){
					if(s[j][1] == p1 && s[j][2] == p2) ans++;
				}
			}
		}
		// 两侧都有相同字符 
		else{
			for(ll i = 0;i <= head+1;i++){
				for(ll j = tail-1;j <= x.size()-1;j++){
					string p1 = "",p2 = "";
					for(ll k = i;k <= j;k++){
						p1 = p1 + x[k];
						p2 = p2 + y[k];
					}
					for(ll k = 1;k <= n;k++){
						if(s[k][1] == p1 && s[k][2] == p2) ans++;
					}
				}
			}
		}
		
		cout << ans << "\n";
	}
	
	
	return 0;
}


