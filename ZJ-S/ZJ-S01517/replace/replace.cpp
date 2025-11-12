#include <iostream>
#include <cstring>
using namespace std;

const int MAXN=2e5+10;

int n,Q;
string s[MAXN][2];
string q[MAXN][2];
int sdif[MAXN];
int qdif[MAXN];
int ans=0;

bool cbr(int a,int b){
	int al=s[a][0].size();
	int bl=q[b][0].size();
	if (al>bl) return false; // too big
	if (sdif[a]!=qdif[b]) return false;
	bool flag=true;
	for (int i=0;i<bl-al+1;i++){
		flag=true;
		for (int j=0;j<al;j++){
			if (!(s[a][0][j]==q[b][0][i+j] && s[a][1][j]==q[b][1][i+j])){
				flag=false;
				break;
			}
		}
		if (flag){
			return true;
		}
	}
	return false;
}

int main(){
//	freopen("replace1.in","r",stdin);
//	freopen("replace3.out","w",stdout);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> Q;
	for (int i=0;i<n;i++){
		cin >> s[i][0] >> s[i][1];
		for (int j=0;j<s[i][0].size();j++){
			if (s[i][0][j]!=s[i][1][j]){
				sdif[i]++;
			}
		}
	}
	for (int i=0;i<Q;i++){
		ans=0;
		cin >> q[i][0] >> q[i][1];
		if (q[i][0].size()!=q[i][1].size()){
			cout << 0 << '\n';
			continue; // len isn't equal
		}
		else for (int j=0;j<q[i][0].size();j++){
			if (q[i][0][j]!=q[i][1][j]){
				qdif[i]++;
			}
		}
		for (int j=0;j<n;j++){
			if (cbr(j,i)){
				ans++;
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}
