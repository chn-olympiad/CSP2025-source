#include<bits/stdc++.h>
using namespace std;

//#define int long long
const int N = 50005;

int n ,q ;
pair<string,string> a[200005];
int l[200005];
string s;
pair<string ,string> cha(string a,string b){
	string res1,res2;
	for(int i=1;i<=a.size();i++){
		if(a[i] != b[i]){
			res1 += a[i]; 
			res2 += b[i];
		}
	}
	return make_pair(res1,res2);
}
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		string x,y;
		cin >> x >> y;
		a[i] = cha(x,y);
		l[i] = a[i].first.size();
	}
	while(q--){
		int ans=0;
		string x,y;
		cin >> x >> y;
		string nowa,nowb;
		for(int j=1;j<=n;j++){
			for(int i=0;i<x.size();i++){
				nowa += x[i];
				nowb += y[i];
			}
			if(nowa.size() == l[j] && nowa == a[j].first && nowb == a[j].second){
				ans++;
			}
		}
		cout << ans << "\n";
	}
	for(int i=1;i<=n;i++){
		cout << a[i].first << ' ' << a[i].second << "\n";
	}
	return 0;
}


