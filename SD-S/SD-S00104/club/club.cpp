#include<bits/stdc++.h>
using namespace std;

//#define int long long
#define PII pair<int,int>
#define fi first
#define se second
const int N = 100005;

int n ,m ;
int T ;
int cnta,cntb,cntc;
int ans = 0,sum=0;
bool vis[N][4];
int a[N][4];

int dfs(int i,int cnta,int cntb,int cntc){
	if(cnta > n/2 || cntb > n/2 || cntc > n/2){
		return 0;
	}
	cout << i << ' ' << cnta << ' ' << cntb << ' ' << cntc << ' ' << ans << "\n";
	if(i == n){
		ans = max(max(ans + a[i][1],ans + a[i][2]),ans + a[i][3]);
		return ans;
	}
	
	for(int j=1;j<=3;j++){
		if(j == 1 && cnta<=n/2){
			sum += a[i][1];
			cnta++;
			dfs(i+1,cnta,cntb,cntc);
			cnta--;
			sum -= a[i][1];
		}
		if(j == 2 && cntb<=n/2){
			sum += a[i][2];
			cntb++;
			dfs(i+1,cnta,cntb,cntc);
			cntb--;
			sum -= a[i][2];
		}
		if(j == 3 && cntc<=n/2){
			sum += a[i][3];
			cntc++;
			dfs(i+1,cnta,cntb,cntc);
			cntc--;
			sum -= a[i][3];
		}
	}
	ans = max(ans,sum);
}

bool cmp1(int a,int b){
	return a > b;
}

bool cmp2(PII a,PII b){
	return a.se > b.se;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin >> T;
	while(T--){
		cin >> n;
		for(int i=1;i<=n;i++){
			a[i][1] = 0;
			a[i][2] = 0;
			a[i][3] = 0;
		}
		ans = 0;
		cnta = 0;
		cntb = 0;
		cntc = 0;
		sum=0;
		int sum2=0;
		int sum3=0;
		for(int i=1;i<=n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			sum2 += a[i][2];
			sum3 += a[i][3];
		}
		
		if(sum2 + sum3 == 0){
			int newa[N];
			for(int i=1;i<=n;i++){
				newa[i] = a[i][1];
			}
			sort(newa+1,newa+1+n,cmp1);
			for(int i=1;i<=n/2;i++){
				ans += newa[i]; 
			}
			cout << ans << "\n";
			continue;
		}
		if(sum3 == 0){
			PII newa[N];
			for(int i=1;i<=n;i++){
				newa[i] = make_pair(i,a[i][1]);
			}
			sort(newa+1,newa+1+n,cmp2);
			PII newb[N];
			for(int i=1;i<=n;i++){
				newb[i] = make_pair(i,a[i][2]);
			}
			sort(newb+1,newb+1+n,cmp2);
			for(int i=1;i<=n/2;i++){
				int cnt=0;
				if(newa[i].fi == newb[i].fi){
					cnt++;
					ans += max(newa[i].se + newb[n/2+cnt].se,newb[i].se + newa[n/2 + cnt].se);
				}
			}
			cout << ans << "\n";
			continue;
		}
		if(n == 2){
			int maxa = max(max(a[1][1],a[1][2]),a[1][3]);
			int ai;
			if(maxa == a[1][1]){
				ai = 1;
			}
			if(maxa == a[1][2]){
				ai = 2;
			}
			if(maxa == a[1][3]){
				ai = 3;
			}
			int maxaa = a[1][1] + a[1][2] + a[1][3] - maxa - min(min(a[1][1],a[1][2]),a[1][3]);
			int maxb = max(max(a[2][1],a[2][2]),a[2][3]);
			int bi;
			if(maxb == a[2][1]){
				bi = 1;
			}
			if(maxb == a[2][2]){
				bi = 2;
			}
			if(maxb == a[2][3]){
				bi = 3;
			}
			int maxbb = a[2][1] + a[2][2] + a[2][3] - maxb - min(min(a[2][1],a[2][2]),a[2][3]);
			if(ai == bi){
				cout << max(maxa + maxbb,maxaa + maxb) << "\n";
				continue;
			}
			else{
				cout << maxa + maxb << "\n";
				continue;
			}
		}
		
//		dfs(1,0,0,0);
		cout << "rp++rp++rp++" << "\n";
	}
	
	

	return 0;
}


