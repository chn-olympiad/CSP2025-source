#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = (a);i <= (b);i ++)
#define lop(i,a,b) for(int i = (a);i <  (b);i ++)
#define dwn(i,a,b) for(int i = (a);i >= (b);i --)
#define lnt long long
#define f32 float
#define f64 double
#define f80 long double
#define pb push_back
#define pp pop_back
#define lb lower_bound
#define ub upper_bound
#define TCSmain signed main()
#define ret return
#define If ((
#define Then )?(
#define Else ):(
#define Eif ))
#define IOSFST std::ios::sync_with_stdio(0)
#define TCSdbg(x) std::cerr << #x << " : " << (x) << "\n";
#define fn void
#define FaILurEg(s) std::freopen(s ".in", "r", stdin);std::freopen(s ".out", "w", stdout)
#define AKIOI 998244353
#define Loop1st %
#define Loop2nd %=
using std::cin;using std::cout;
lnt n, a[5005], DP[10005];
TCSmain {
   FaILurEg("polygon");
   IOSFST;cin.tie(0);
   cin >> n;rep(i, 1, n) cin >> a[i];
   std::sort(a + 1, a + 1 + n);
   DP[0] = 1;lnt ans = 0;
   rep(i, 1, n) {
      rep(j, a[i] + 1, 10001) ans = (ans + DP[j]) Loop1st AKIOI;
      dwn(j, 10001, 0)
         DP[std::min(j + a[i], 10001ll)] += DP[j],
         DP[std::min(j + a[i], 10001ll)] Loop2nd AKIOI;}
   cout << ans << "\n";
   //std::cerr << clock() << "\n";
   ret 0;
}
/*
The End.
This T4 << Last Year (Maybe I have T/Wa ?)

I've 2 hours to sleep!

LuoGu ID : 808180 HDS_*****

Loop1st : Gau Zhung Li Ke Yi Ge Yue Ju Neng Shue Wan
sto orz

Loop2nd : Wo Yi Lai YWHS Ju Ting Ke
sto orz

Loop3rd : Bu Da Sheng Dwi Ni Da Shen Me OI A
sto orz

GDB Edition Shii Jie 9.1

Kards

Hwi Jia Di Yi Jan She
Da Kai Kards JJC
150 Jin Bi Yi Tse
Wo She Fen Dyan Kuang
De GWo Ju Gwo Fa Gwo Mung Gwo
San Jang Che Tui Tan Ke
Hai You Fu Chung Meng Bi Ge
Shei Neng Ru He Wo
Shyan Tzai Shyun Jau Di Ren
** **
She ** De Mei Fen
Chi Shou 131 Fu Ji
Zhe Ba Ye Shyu You De Ban
Shii Wang Dwi Myan Shou Pai Lan
Shen Me  T26 466 Hai You Lan hwi She
Yin Tou Pi Jiao Hwan Cheng Hou Chi
Wo Hai You PSM Dou Di
Shen Me Cheng Jie Tau Li Jan Sha Shyan
** De Ji Nu
** De Mei Fen ** De Bin Dau Ren
1939 Gung Tzuo She  Kwai Rang Mei Fen 414
Bu Ran Wo Jiu Manhattan     Ni De Gung Tzuo She
............



The Last Year of CSP-J     AK is a dream

AFO.
*/