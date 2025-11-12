#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,cnt;
string s[200005][3],t[200005][3];
signed main(){
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;i++) cin >> s[i][1] >> s[i][2];
	for(int i = 1;i <= q;i++) cin >> t[i][1] >> t[i][2];
	//if(q==1){
		
	//}
	//else{
		/*for(int i = 1;i <= q;i++){
			cnt=0;
			for(int j = 1;j <= n;j++){
				int len = s[j][1].size(),len1=t[i][1].size();
				for(int k = 0;k <= len1-len;k++){
					string u="";
					string a=t[i][1];
					//for(int l = k;l <= k+len-1;k++) u=u+a[l];
					u=a.substr(k,k+len-1);
					//cout << u << " ";
					if(u==s[j][1]){
						string p=t[i][1];
						p.replace(k,k+len,s[j][2]);
						if(p==t[i][2]) cnt++;
					}
				}
			}
			cout << cnt << "\n";
		}*/
	//}
	for(int i = 1;i <= q;i++){
		string a = t[i][1],b=t[i][2];
		int u = a.find('b'),l=a.size(),v=b.find('b');
		for(int j = 1;j <= n;j++){
			string a1=s[j][1],y=s[j][2];
			int u1=a1.find('b');
			//int v1=y.find('b');
			int l1=a1.size();
			int pre=u-u1+1,nxt=l1-u1+u;
			if(pre>=0&&pre<=v&&nxt<=l-1&&nxt<=v) cnt++;
		}
	}
	cout << cnt << "\n";
	return 0;
}
