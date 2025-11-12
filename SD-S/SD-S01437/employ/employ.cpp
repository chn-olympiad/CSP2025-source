#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;
const int N = 510;
const int mod = 998244353;

int n,m;
char cs[N];
int c[N];
int ans;
int chs[N];
string s;
int jz;



bool check()  //µ±Ç°s 
{
	int res = 0;
	int kkkk[N] = {0};
	for(int i = 1 ; i <= n ;i++) //s[i-1];
	{
	//	cout << chs[i] << " " << c[s[i-1]] << " " << cs[i] << '\n';
		int hh = s[i-1]-'0';
		if(hh<=jz){
			hh = (jz-hh)+jz;
		}
		else {
			hh = jz - (hh-jz);
		}
		int j = i;
		if(j<=jz){
			j = (jz-j)+jz;
		}
		else {
			j = jz - (j-jz);
		}
		kkkk[j] = hh;
	}
	
	for(int i = 1 ; i <= n; i++){
		if(chs[i]<c[kkkk[i]]&&cs[i]=='1') res++;
	}
	
	return res>=m;
}



int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	cin >> cs+1;
	int res = 0;
	if(n%2==0) jz = n/2;
	else jz = (n/2)+1;
	for(int i = 1 ; i<=n;i++)
	{
		chs[i] = res;
		if(cs[i]=='0') res++;
	}
	
	for(int i = 1 ; i <= n; i++) cin >> c[i];
	
	for(int i = 1; i <= n;i++)
	{
		int l = i;
		char ll = l+'0';
		s+=ll;
	}
	
	sort(c+1,c+1+n);
	
	
	do{
		if(check()){
			ans++;
			if(ans>=mod) ans-=mod;
		}
	}while(next_permutation(s.begin(),s.end()));
	
	cout << ans;
	return 0; 
}
