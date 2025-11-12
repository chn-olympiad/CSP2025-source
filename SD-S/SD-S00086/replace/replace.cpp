#include<bits/stdc++.h>
#define ll long long
#define V vector
#define pi pair <int,int>
#define fi first
#define se second
using namespace std;

const int N = 2e5+5;

string s[N][3];
int n,q,ans=0;
string s1,s2;
bool check(string a,string b){
	if(a.size()!=b.size()) return false;
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]) return false;
	}
	return true;
}

void dfs(int id,string now_s){
//	cout << id << " " << now_s << '\n';
	if(id==s1.size()){
		if(now_s==s2) ans++;//,cout << " ans : " << ans << '\n';
		return ;
	}
	string a1,a2;
	int i;
	for(i=id;i<now_s.size();i++) a1+=now_s[i],a2+=s2[i];
	for(i;i<id+s[id+1][1].size();i++) a1+=s1[i],a2+=s2[i];  
	if(check(a1,s[id+1][1])){
		if(check(s[id+1][2],a2)){
			string new_s="";
			for(i=0;i<id;i++) new_s+=now_s[i];
			new_s+=a2;
			dfs(id+1,new_s);
		}
	}
	if(now_s.size()>id) dfs(id+1,now_s);
	else if(s1[id]==s2[id]) dfs(id+1,now_s+s1[id]);
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for(int i=1;i<=n;i++) cin >> s[i][1] >> s[i][2];
	while(q--){
		cin >> s1 >> s2;
		ans=0;
		string h="";
		h+=s1[0];
		dfs(0,"");
		cout << ans << '\n';
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

