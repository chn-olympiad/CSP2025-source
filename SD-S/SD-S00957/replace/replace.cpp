#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
using namespace std;
const long long mod1 = 4987;
const long long mod2 = 2999;
const long long mod3 = 4021;
const long long mod4 = 1979;
const long long mod5 = 4969;
int tt[5000][5000][6];
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n , q;
	cin >> n >> q;
	string k , s;
	for(int i = 1 ; i <= n ; i ++){
		char ch=getchar();
		int cnt = 0;
		for(;ch<'a'||ch>'z';ch=getchar());
		for(;ch>='a'&&ch<='z';ch=getchar()){
			k[++cnt]=ch;
		}
		int cnt1 = 0;
		for(;ch<'a'||ch>'z';ch=getchar());
		for(;ch>='a'&&ch<='z';ch=getchar()){
			s[++cnt1]=ch;
		}
		int kk = 1;
		while(s[kk]==k[kk]&&kk<cnt)kk++;
		int kkk = cnt;
		while(s[kkk]==k[kkk]&&kkk>1) kkk--;
		if(kk==cnt&&kkk==1) continue;
		long long sumk1=0 , sumk2=0 , sumk3=0,sumk4=0,sumk5=0;
		long long sums1=0 , sums2=0 , sums3=0,sums4=0,sums5=0;
		for(int i = kk ; i <= kkk ; i ++){
			long long fu = k[i]-'a'+1;
			long long ck = s[i]-'a'+1;
			sumk1 = (sumk1*27+fu)%mod1;
			sumk2 = (sumk2*27+fu)%mod2;
			sumk3 = (sumk3*27+fu)%mod3;
			sumk4 = (sumk4*27+fu)%mod4;
			sumk5 = (sumk5*27+fu)%mod5;
			sums1 = (sums1*27+ck)%mod1;
			sums2 = (sums2*27+ck)%mod2;
			sums3 = (sums3*27+ck)%mod3;
			sums4 = (sums4*27+ck)%mod4;
			sums5 = (sums5*27+ck)%mod5;
		}
		tt[sumk1][sums1][1]++;
		tt[sumk2][sums2][2]++;
		tt[sumk3][sums3][3]++;
		tt[sumk4][sums4][4]++;
		tt[sumk5][sums5][5]++;
	}
	for(int i = 1 ; i <= q ; i ++){
		char ch=getchar();
		int cnt = 0;
		for(;ch<'a'||ch>'z';ch=getchar());
		for(;ch>='a'&&ch<='z';ch=getchar()){
			k[++cnt]=ch;
		}
		int cnt1 = 0;bool flag = 0;
		for(;ch<'a'||ch>'z';ch=getchar());
		for(;ch>='a'&&ch<='z';ch=getchar()){
			s[++cnt1]=ch;
		}
		int kk = 1;
		while(s[kk]==k[kk]&&kk<cnt)kk++;
		int kkk = cnt;
		while(s[kkk]==k[kkk]&&kkk>1) kkk--;
		if(kk==cnt&&kkk==1) continue;
		long long sumk1=0 , sumk2=0 , sumk3=0,sumk4=0,sumk5=0;
		long long sums1=0 , sums2=0 , sums3=0,sums4=0,sums5=0;
		for(int i = kk ; i <= kkk ; i ++){
			long long fu = k[i]-'a'+1;
			long long ck = s[i]-'a'+1;
			sumk1 = (sumk1*27+fu)%mod1;
			sumk2 = (sumk2*27+fu)%mod2;
			sumk3 = (sumk3*27+fu)%mod3;
			sumk4 = (sumk4*27+fu)%mod4;
			sumk5 = (sumk5*27+fu)%mod5;
			sums1 = (sums1*27+ck)%mod1;
			sums2 = (sums2*27+ck)%mod2;
			sums3 = (sums3*27+ck)%mod3;
			sums4 = (sums4*27+ck)%mod4;
			sums5 = (sums5*27+ck)%mod5;
		}
//		cout<<tt[sumk1][sums1][1]<<" ";
//		cout<<tt[sumk2][sums2][2]<<" ";
//		cout<<tt[sumk3][sums3][3]<<" ";
//		cout<<tt[sumk4][sums4][4]<<" ";
//		cout<<tt[sumk5][sums5][5]<<" ";
		int ans = min(min(tt[sumk1][sums1][1],tt[sumk2][sums2][2]),min(tt[sumk5][sums5][5],min(tt[sumk3][sums3][3],tt[sumk4][sums4][4])));

		cout<<ans<<"\n";
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
