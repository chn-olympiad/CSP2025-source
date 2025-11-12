#include<bits/stdc++.h>

#define int long long

using namespace std;

const int base = 1000;
const int mod = 1000000000000007;

int read(){
	int x = 0,y = 1;
	char ch = getchar();
	while(ch < '0'||ch > '9'){
		if(ch == '-') y = -1;
		ch = getchar();
	}
	while(ch >= '0'&&ch <= '9'){
		x = x*10+ch-'0';
		ch = getchar();
	}
	return x*y;
}

void print(int x){
	char ch = x%10+'0';
	if(x < 10){
		printf("%c",ch);
		return;
	}
	print(x/10);
	printf("%c",ch);
}

int bas[5000005];

int n,q;
string s[200005][2];
int len[200005];
int hash[200005][2];

int clhspt(string s){
	int n = s.length(); 
	int ans = 0;
	for(int i = 0;i < n;++ i)
		ans = (ans*base%mod+s[i])%mod;
	return ans;
}

int clhs(string s,vector<int> &v){
	int n = s.length(); 
	int ans = 0;
	for(int i = 0;i < n;++ i)
		ans = (ans*base%mod+s[i])%mod,v.push_back(ans);
	return ans;
}

string t1,t2;
vector<int> qzht1;

int get(vector<int> v,int l,int r){
	if(l == 0) return v[r];
	int ans = v[r]+mod-v[l-1]*bas[r-l+1]%mod;
	return ans%mod;
}

int getnw(vector<int> v,int l,int r,int thh){
	int ans = 0;
	if(l != 0) ans = get(v,0,l-1)*bas[v.size()-1-l+1];
	ans += thh*bas[v.size()-1-r]%mod;
	if(r != v.size()-1)
		ans += get(v,r+1,v.size()-1)%mod;
	return ans%mod;
}

signed main(){

	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	bas[0] = 1;
	for(int i = 1;i <= 5e6;++ i)
		bas[i] = bas[i-1]*base%mod;

	n = read();q = read();
	for(int i = 1;i <= n;++ i){
		cin >> s[i][1] >> s[i][2];
		hash[i][1] = clhspt(s[i][1]);
		hash[i][2] = clhspt(s[i][2]);
		len[i] = s[i][1].length();
	}
	
	for(int i = 1;i <= q;++ i){
		cin >> t1 >> t2;
		qzht1.clear();
		int ha1 = clhs(t1,qzht1);
		int ha2 = clhspt(t2);
		int nt = t1.length();
		int ans = 0;
		for(int j = 1;j <= n;++ j){
			for(int k = 0;k+len[j]-1 < nt;++ k){
				int hs1 = get(qzht1,k,k+len[j]-1);
				if(hs1 != hash[j][1]) continue;
				int nwha1 = getnw(qzht1,k,k+len[j]-1,hash[j][2]);
				if(nwha1 != ha2) continue;
				ans++; 
				break;
			}
		}
		print(ans);
		printf("\n");
	} 

	return 0;

}

