#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define fir first
#define sec second
#define endl '\n'
const int N=5e6+5,M=5e3+5;

string s[N],t[N];
int bpow[N];
int bpow2[N];
vector<int> hs[N],ht[N];
int n,q;
const int P=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;

void hsh(string &s,vector<int> &v){
	int num=0;
	for(int i=0;i<s.length();i++){
		num*=131;
		num+=s[i];
		num%=P;
		v.push_back(num);
	}
}

int fpm(int x,int y){
	int res=1;
	while(y){
		if(y&1)res*=x;
		res%=P;
		x*=x;
		x%=P;
		y>>=1;
	}
	return res;
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> q;
	bpow[1]=fpm(131,P-2);
	bpow2[1]=131;
	for(int i=2;i<=100000;i++){
		bpow[i]=bpow[i-1]*bpow[1]%P;
		bpow2[i]=bpow2[i-1]*131;
	}
//	for(int i=1;i<=4;i++){
//		cout << bpow[i] << ' ' << 131*bpow[i]%P << endl;
//	}
//	cout << endl;
	for(int i=1;i<=n;i++){
		cin >> s[i] >> t[i];
		hsh(s[i],hs[i]);
		hsh(t[i],ht[i]);
//		for(auto e:hs[i]){
//			cout << e << ' ';
//		}
//		cout << endl;
	}
	while(q--){
		string a,b;
		cin >> a >> b;
		if(a.size()!=b.size()){
			cout << 0 << endl;
			continue;
		}
		int difl=-INF,difr=0;
		for(int i=0;i<a.length();i++){
			if(a[i]!=b[i]){
				if(-INF==difl)difl=i;
				difr=i;
			}
		}
		int res=0;
		vector<int> ha,hb;
		hsh(a,ha);
		hsh(b,hb);
//		for(auto e:ha){
//			cout << e << ' ';
//		}
//		cout << endl;
//		cout << ha[3] << ' ' << ha[1] << ' ' << (ha[3]-ha[1]*bpow2[2]) << ' ' << (ha[3]-ha[1]*bpow2[2]) << endl;
		for(int i=1;i<=n;i++){
			for(int j=0;j<a.length();j++){
				int r=j+s[i].length()-1;
				if(r>=a.length())break;
				if(j<=difl && r>=difr && hs[i][s[i].length()-1]==(j!=0 ? ((ha[r]-ha[j-1]*bpow2[r-j+1]%P+P)%P) : (ha[r])) && ht[i][t[i].length()-1]==(j!=0 ? ((hb[r]-hb[j-1]*bpow2[r-j+1]%P+P)%P) : (hb[r]))){
					res++;
//					cout << i << ' ' << j << ' ' << r << endl;
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}






//*Some strong music rings...
/*
Today is 20251101.
The code is by XYM!!!

buhao,300-

3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
//We are strange to love.
//You know the rules and so do I~
//
//Never gonna give you up.
//Never gonna let you down.
//Never gonna run around and hurt you.
//Never gonna make you cry.
//Never gonna say goodbye.
//Never gonna run around and hurt you.
//
//luogu UID 1433474,luogu name Meng_Xiangyu
//I AKed CSP-J this morning.

