#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,q;
string s[N][2];
string t1,t2;
int l1,l2;
bool check(int st,int k){
	int cl=s[k][0].length();
	if(st+cl-1>=l1) return 0;
	for(int i=0;i<st;i++){
		if(t1[i]!=t2[i]) return 0;
	}
	for(int i=st+cl;i<l1;i++){
		if(t1[i]!=t2[i]) return 0;
	}
	for(int i=st,j=0;i<=st+cl-1;i++,j++){
		if(t1[i]==s[k][0][j]&&t2[i]==s[k][1][j]) continue;
		return 0;
	}
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> s[i][0] >> s[i][1];
	}
	while(q--){
		cin >> t1 >> t2;
		l1=t1.length();
		l2=t2.length(); 
		if(l1!=l2){
			cout << "0\n";
			continue;
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<l1;j++){
				if(check(j,i)){
//					cout << j << ' ' << i << endl;
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
