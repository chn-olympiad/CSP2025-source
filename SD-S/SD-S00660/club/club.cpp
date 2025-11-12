#include <bits/stdc++.h>
#define ll long long 
#define rep(i,a,n) for(int i = (a);i<=(n);++i)
#define endl '\n'
#define _x putchar('\n')
using namespace std;

template<typename T>inline void read(T &x){
	char c = getchar();
	short int t = 1;x = 0;
	for(;!isdigit(c);c = getchar())if(c == '-')t=-1;
	for(;isdigit(c);c = getchar())x = (x<<1) + (x<<3) + (c^48);
	x*=t;
}

const int N = 1e5+10;

struct node{
	int a,b,c,maxx,id;
	node(int x = 0,int y = 0,int z = 0){
		a = x;b = y;c = z;
	}
}x[N];
bool cmp1(node t1,node t2){
	return t1.a>t2.a;
}
bool cmp2(node t1,node t2){
	return t1.a+t2.b>t1.b+t2.a;
}
bool cmp3(node t1,node t2){
	return t1.maxx>t2.maxx;
}
int T = 0,n = 0,a[N],b[N],c[N];
ll sum = 0,ans = 0;
void dfs(int pos,int lena,int lenb,int lenc){
	if(pos == n+1){
		for(int i = 1;i<=lena;++i){
			sum += x[a[i]].a;
		} 
		for(int i = 1;i<=lenb;++i){
			sum += x[b[i]].b;
		}
		for(int i = 1;i<=lenc;++i){
			sum += x[c[i]].c;
		}
		ans = max(ans,sum);
		sum = 0;
		return ;
	}	
	if(lena<=n/2){
		a[lena] = pos;
		dfs(pos+1,lena+1,lenb,lenc);
		a[lena] = 0;
	}
	if(lenb<=n/2){
		b[lenb] = pos;
		dfs(pos+1,lena,lenb+1,lenc);
		b[lenb] = 0;
	}
	if(lenc<=n/2){
		c[lenc] = pos;
		dfs(pos+1,lena,lenb,lenc+1);
		c[lenc] = 0;
	}
	
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(T);
	while(T--){
		read(n);
		bool flag1 = 1,flag2 = 1;
		rep(i,1,n){
			read(x[i].a);read(x[i].b);read(x[i].c);
			if(x[i].b != 0||x[i].c!=0){
				flag1 = 0;
			}
			if(x[i].c!=0){
				flag2 = 0;
			}
			x[i].id = i;
		}
		ans = 0;
		if(n<=30){
			dfs(1,1,1,1);
			cout <<ans<<endl;
			continue;
		}	
		if(flag1){
			sort(x+1,x+1+n,cmp1);
			for(int i = 1;i<=n/2;++i){
				ans+=x[i].a;
			}
			cout <<ans<<endl;
			continue;
		}else if(flag2){
			sort(x+1,x+1+n,cmp2);
			for(int i = 1;i<=n/2;++i){
				ans += x[i].a;
			}
			for(int i = n/2+1;i<=n;++i){
				ans += x[i].b; 
			}
			cout <<ans<<endl;
			continue;
		}else{
			sort(x+1,x+1+n,cmp3);
			int c1 = 0,c2 = 0,c3 = 0;
			for(int i = 1;i<=n;++i){
				x[i].maxx = max(x[i].a,max(x[i].b,x[i].c));	
				
				if(x[i].maxx == x[i].a){
					if(c1<n/2){
						++c1;
						ans+=x[i].a;						
					}else{
						int maxn = max(x[i].b,x[i].c);
						if(maxn == x[i].b){
							if(c2 < n/2){
								++c2;
								ans+=x[i].b;
							}else{
								++c3;
								ans += x[i].c;
							}
						}else{
							++c3;
							ans += x[i].c;
						}
					}
				}else if(x[i].maxx == x[i].b){
					if(c2<n/2){
						++c2;
						ans += x[i].b; 
					}else{
						++c3;
						ans += x[i].c;
					}
				}else{
					++c3;
					ans += x[i].c;
				} 
			}
			cout <<ans<<endl;
			
			
		}
		
		
		
	}
	return 0;
}


 
