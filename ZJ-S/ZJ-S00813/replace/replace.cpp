#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = (a);i <= (b);i ++)
#define lop(i,a,b) for(int i = (a);i <  (b);i ++)
#define dwn(i,a,b) for(int i = (a);i >= (b);i --)
#define lnt long long
#define f32 float
#define f64 double
#define f80 long double
#define snt short
#define hnt char
#define fn void
#define lb lower_bound
#define ub upper_bound
#define TCSmain signed main()
#define ret return
#define If ((
#define Then )?(
#define Else ):(
#define Eif ))
#define pb push_back
#define pp pop_back
#define elif else if
#define i64 1ll
#define TCSdbg(x) cout << #x << " " << (x) << "\n";
#define IOSFST std::ios::sync_with_stdio(0)
#define FaILurEg(s) freopen(s ".in", "r", stdin);freopen(s ".out", "w", stdout);
using std::cin;using std::cout;
struct ACAM {
   int E[5000005][26], dep[5000005], fail[5000005], top, fa[5000005], nd[200005];
   hnt c[5000005];int cnt[5000005], d, FF[5000005];// F[5000005][25];
   //std::vector<int> G[5000005];
   int h[5000005], nxt[5000005], cE, to[5000005], DD[5000005];
   bool FFFF[5000005];
   int ins(std::string &s, int num) {
      int now = 0;
      lop(i, 0, s.size()){
         //sz[now] ++;
         if(!E[now][s[i] - 'a'])
            E[now][s[i] - 'a'] = ++ top, dep[top] = dep[now] + 1, c[top] = s[i] - 'a', fa[top] = now;
         now = E[now][s[i] - 'a'];
      }
      //sz[now] ++;
      //Lf[now] = num;
      nd[num] = now;
      cnt[now] ++;FFFF[now] = 1;
      ret now;
   }
   void BuildFail() {
      std::queue<int> Q;Q.push(0);
      while(!Q.empty()) {
         int f = Q.front();Q.pop();
         if(fa[f]) fail[f] = E[fail[fa[f]]][c[f]];
         //if(!Lf[f]) Lf[f] = Lf[fail[f]];
         if(f) cE ++, nxt[cE] = h[fail[f]], h[fail[f]] = cE, to[cE] = f; 
         cnt[f] += cnt[fail[f]];
         FF[f] = If FFFF[fail[f]] Then fail[f] Else FF[fail[f]] Eif;
         rep(I, 0, 25)
            if(E[f][I]) Q.push(E[f][I]);
            else E[f][I] = E[fail[f]][I];
      }
   }
   void DFS(int u) {
      int now = h[u];
      while(now) {
         DD[to[now]] = DD[u] + 1;
         DFS(to[now]);
         now = nxt[now];
      }
   }  
} X, Y;
bool Same[5000005], Sfsm[5000005];
TCSmain {
   FaILurEg("replace");
   IOSFST;cin.tie(0);
   std::cerr << (sizeof X) * 2.0 / 1048576 << "GiB\n";
//   system("pause");
   int n, q;cin >> n >> q;
   std::map<std::pair<int, int>, int>mp;
   rep(i, 1, n) {
      std::string s, t;cin >> s >> t;
      mp[{X.ins(s, i),Y.ins(t, i)}] ++;
   }
   X.BuildFail();Y.BuildFail();X.DFS(0);Y.DFS(0);
   //cout << "DICK";
   rep(i, 1, q) {
      std::string s, t;cin >> s >> t;
      if(s.size() != t.size()) {cout << "0\n";continue;}
      Same[0] = true;int GGGG;int ans = 0;
      rep(i, 1, s.size())
         Same[i] = (Same[i - 1] & (s[i - 1] == t[i - 1]));
      rep(i, 1, s.size())if(!Same[i]) {GGGG = i;break;}
      Sfsm[s.size() + 1] = true;
      dwn(i, s.size(), 1)
         Sfsm[i] = (Sfsm[i + 1] & (s[i - 1] == t[i - 1]));
      int U1 = 0, U2 = 0;
      int I;
      rep(i, 1, s.size()) if(!Sfsm[i]) {
         U1 = X.E[U1][s[i - 1] - 'a'];
         U2 = Y.E[U2][t[i - 1] - 'a'];I = i;
         //cout << U1 << " " << U2 << "\n";
      }else break;
      rep(i, I, s.size()) {
         // log get LCA
         int Uu1 = U1, Uu2 = U2;
         while(Uu1 && Uu2){
         while(Uu1 && Uu2 &&!mp[{Uu1, Uu2}]) {
            if(X.dep[Uu1] > Y.dep[Uu2])
               Uu1 = X.FF[Uu1];
            elif(X.dep[Uu1] < Y.dep[Uu2]) Uu2 = Y.FF[Uu2];
            else Uu1 = X.FF[Uu1], Uu2 = Y.FF[Uu2];
         } 
         if(X.dep[Uu1] >= i - GGGG + 1)
            ans += mp[{Uu1, Uu2}];
         Uu1 = X.FF[Uu1], Uu2 = Y.FF[Uu2];
         }
         if(i != s.size())
         U1 = X.E[U1][s[i] - 'a'],
         U2 = Y.E[U2][t[i] - 'a'];
         //cout << ans << " " << U1 << " " << U2 << "\n";
      }
      cout << ans << "\n";
      // rep(i, 1, s.size()) {
      //    if(Sfsm[i] && X.Lf[U1] && Y.Lf[U2]) {
      //       int Uu1 = U1, Uu2 = U2;
      //       while(X.Lf[Uu1] != Y.Lf[Uu2])
      //          if(X.DD[Uu1] > Y.DD[Uu2])
      //             Uu1 = X.fail[Uu1];
      //          elif(X.DD[Uu1] < Y.DD[Uu2])
      //             Uu2 = Y.fail[Uu2];
      //          else
      //    }
      //    U1 = X.E[U1][s[i - 1] - 'a'];
      //    U2 = Y.E[U2][t[i - 1] - 'a'];
      // }   

   }
   std::cerr << clock() << "ms\n";
}