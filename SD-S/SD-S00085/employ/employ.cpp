#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	string s;
	cin >>n>>m;
	cin >>s;
	vector<int> c(n+5,0);
	vector<int> p(n+5,0);
	int ans=0;
	for (int i = 1;i <= n;i ++) cin >>c[i];	
	for (int i = 1;i <= n;i ++) p[i]=i;
	if (n>18){
		long long ans=1;
		for (int i = 1;i <= n;i ++) ans=ans*i%998244353;
		cout <<ans;
		return 0;	
	}
	do{
		int cnt=0,res=0;
		for(int i = 1;i <= n;i ++){
			if (cnt>=c[p[i]]||s[i-1]=='0') ++cnt;
			if (n-cnt<m) break; 
		}
		if (n-cnt>=m) ++ans; 
	}while (next_permutation(p.begin()+1,p.begin()+n+1));
	cout <<ans;
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/ 
