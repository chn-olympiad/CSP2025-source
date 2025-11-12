#include<bits/stdc++.h>
#define FOR(i,l,r) for(int i = l; i<=r; i++)
#define ROF(i,r,l) for(int i = r; i>=l; i--)
#define all(x) x.begin(),x.end()
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
#define fi first
#define se second
using namespace std;
inline int read(){
	char ch=getchar();
	int x=0,f=1;
    while(!isdigit(ch)) {
    	if(ch=='-') f=-1;
    	ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
bool ST;
typedef pair<int,int> pii;
const int N = 1e5+10;
vector<pii> vc[N];
vector<int> tmp;
int cnt[4];
bool ED;
void solve(){
	int n = read(),x,sum=0;
	// clear
	tmp.clear();cnt[1]=cnt[2]=cnt[3] = 0;
	FOR(i,1,n)vc[i].clear();
	
	FOR(i,1,n){
		FOR(j,1,3){
			x=read();
			vc[i].push_back({x,j});
		}
		sort(all(vc[i]));
		sum += vc[i][2].fi;
		cnt[vc[i][2].se]++; 
	}
	int id = 0;
	FOR(i,1,3)if(cnt[i]>n/2)id = i;
	if(id){
		FOR(i,1,n){
			if(vc[i][2].se==id)tmp.push_back(vc[i][2].fi-vc[i][1].fi); 
		}
		sort(all(tmp));
		FOR(j,1,cnt[id]-n/2)sum -= tmp[j-1];
	} 
	cout << sum<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t = read();
	while(t--)solve();
//	cerr << "\nused: " <<abs(&ST-&ED)/1024/1024<<" MB\n";
	return 0;
}



