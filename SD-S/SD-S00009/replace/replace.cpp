#include<bits/stdc++.h>
#define FOR(i,l,r) for(int i = l; i<=r; i++)
#define ROF(i,r,l) for(int i = r; i>=l; i--)
#define all(x) x.begin(),x.end()
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
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
const int N = 2e5+10;
string s[N][2], t[N][2];
int sl[N];
typedef unsigned long long ull;
ull hs[N][2],hsh1[N],hsh2[N],p[N];
ull get(ull *hsh, int l, int r){
	return hsh[r]-hsh[l-1]*p[r-l+1]; 
}
int find(string s){
	int len = s.size(),p=0;
	FOR(i,0,len-1){
		if(s[i]=='b'){
			p=i;
			break;
		}
	}
	return p;
}
int tr[5000005],mx,tot,ans[N];
unordered_map<int,int> mp;
struct ask{
	int op, pre,suf,id; 
}; 
vector<ask> vc[N*2];
int lowbit(int x){
	return x&-x;
}
void insert(int x, int v){
	for(int i = x; i<=mx;i+=lowbit(i))tr[i]+=v;
}
int query(int x){
	int sum = 0;
	for(int i = x; i; i-=lowbit(i))sum+=tr[i];
	return sum;
}
bool ED;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n = read(), q = read(),L1=0,L2=0;
	FOR(i,1,n){
		cin>>s[i][0]>>s[i][1];
		L1+=s[i][0].size()+s[i][1].size();
	}
	FOR(i,1,q){
		cin>>t[i][0]>>t[i][1]; 
		L2 += t[i][0].size()+t[i][1].size();
	}
	if(L1<=2000&&L2<=2000){
		p[0] = 1;
		FOR(i,1,2005)p[i] = p[i-1]*3769;
		FOR(i,1,n){
			for(auto c:s[i][0])hs[i][0] = hs[i][0]*3769+c;
			for(auto c:s[i][1])hs[i][1] = hs[i][1]*3769+c;
			sl[i] = s[i][0].size();
		} 
		FOR(x,1,q){
			int len = t[x][0].size(),l,r;
			t[x][0] = " "+t[x][0];
			t[x][1] = " "+t[x][1];
			FOR(i,1,len){
				if(t[x][0][i]!=t[x][1][i]){
					l = i;
					break;
				}
			}
			ROF(i,len,1){
				if(t[x][0][i]!=t[x][1][i]){
					r = i;
					break;
				}
			}
			int cnt=0;
			FOR(i,1,len){
				hsh1[i] = hsh1[i-1]*3769+t[x][0][i];
				hsh2[i] = hsh2[i-1]*3769+t[x][1][i];
				if(i>=r){
					FOR(p,1,n){
						if(i-sl[p]+1<=l){
							cnt += (hs[p][0]==get(hsh1,i-sl[p]+1,i)&&hs[p][1]==get(hsh2,i-sl[p]+1,i));
						}
					}
				}
			}	
			cout<<cnt<<"\n";		
		}
		return 0;
	}
	FOR(i,1,n){
		int p1 = find(s[i][0]), p2 = find(s[i][1]), len = s[i][0].size(), to;
		if(mp.count(p2-p1))to = mp[p2-p1];
		else mp[p2-p1] = to = ++tot;
		vc[to].push_back({1,max(p1,p2)+1, len-min(p1,p2), 1});
		cmax(mx,len-min(p1,p2));
	}
	FOR(i,1,q){
		int p1 = find(t[i][0]), p2 = find(t[i][1]), len = t[i][0].size(),to;
		if(mp.count(p2-p1))to = mp[p2-p1];
		else continue;
		vc[to].push_back({0,p1+1,len-p1,i});
		cmax(mx,len-p1);
	}
	FOR(i,1,tot){
		sort(all(vc[i]),[&](ask a, ask b){
			return a.pre==b.pre?a.suf<b.suf:a.pre<b.pre;
		});
		for(auto p:vc[i]){
			if(p.op){
				insert(p.suf,1);
			}else{
				ans[p.id] = query(p.suf);
			}
		}
		for(auto p:vc[i]){
			if(p.op){
				insert(p.suf,-1);
			}
		}
	}
	FOR(i,1,q)cout<<ans[i]<<"\n";
//	cerr << "\nused: " <<abs(&ST-&ED)/1024/1024<<" MB\n";
	return 0;
}



