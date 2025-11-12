#include<bits/stdc++.h>
using namespace std;
inline int in(){
	int s=1,k=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') s=-1;c=getchar();}
	while('0'<=c&&c<='9'){k=(k<<1)+(k<<3)+(c^48);c=getchar();}
	return k*s;
}
void out(int x){
	if(x<0) x=-x,putchar('-');
	if(x>9) out(x/10);
	putchar(x%10^48);
}
const int MAXN=200+7;
int f[107][107][107];
int w1[MAXN],w2[MAXN],w3[MAXN];
struct node{
	int val1,val2,val3;
}w[100010];
inline void init(int len){
	for(int i=0;i<=len;i++) for(int j=0;j<=len;j++) for(int k=0;k<=len;k++) f[i][j][k]=0;
}
bool cmp(node x,node y){
	return x.val1>y.val1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int q=in();
	while(q--){
		int n=in();
		int V=n>>1;
		if(n<=200){
			init(V);
			bool isB=true;
			for(int i=1;i<=n;i++){
				w1[i]=in();
				w2[i]=in();
				w3[i]=in();
				if(w3[i]!=0) isB=false;
			}	
			if(isB){
				for(int z=1;z<=n;z++){
					for(int i=V;i>=0;i--){
						for(int j=V;j>=0;j--){
								if(i>=1) f[i][j][0]=max(f[i][j][0],f[i-1][j][0]+w1[z]);
								if(j>=1) f[i][j][0]=max(f[i][j][0],f[i][j-1][0]+w2[z]);
						}
					}	
				}
				out(f[V][V][0]); puts("");
			}
			else{
				for(int z=1;z<=n;z++){
					for(int i=V;i>=0;i--){
						for(int j=V;j>=0;j--){
							for(int k=V;k>=0;k--){
								if(i>=1) f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+w1[z]);
								if(j>=1) f[i][j][k]=max(f[i][j][k],f[i][j-1][k]+w2[z]);
								if(k>=1) f[i][j][k]=max(f[i][j][k],f[i][j][k-1]+w3[z]);
							}
						}
					}	
				}
				out(f[V][V][V]); puts("");
			}
		}
		else{
			bool isA=true;
			for(int i=1,a,b,c;i<=n;i++){
				a=in(); b=in(); c=in();
				if(b!=0||c!=0) isA=false;
				w[i]={a,b,c};
			}
			int ans=0;
			if(isA){
				sort(w+1,w+1+n,cmp);
				for(int i=1;i<=V;i++) ans+=w[i].val1;
				out(ans); puts("");
			}
			else{
				for(int i=1;i<=n;i++){
					int a=w[i].val1,b=w[i].val2,c=w[i].val3;
					int cnt1=0,cnt2=0,cnt3=0;
					if(a>=b&&a>=c){
						if(cnt1<V) ans+=a,cnt1++;
						else{
							if(b>=c){
								if(cnt2<V) ans+=b,cnt2++;
								else{
									if(cnt3<V) ans+=c,cnt3++;
								}
							}
						}
					}
					else if(b>=a&&b>=c){
						if(cnt2<V) ans+=b,cnt2++;
						else{
							if(a>=c){
								if(cnt1<V) ans+=a,cnt1++;
								else{
									if(cnt3<V) ans+=c,cnt3++;
								}
							}
						}
					}
					else{
						if(cnt3<V) ans+=c,cnt3++;
						else{
							if(b>=a){
								if(cnt2<V) ans+=b,cnt2++;
								else{
									if(cnt1<V) ans+=a,cnt1++;
								}
							}
						}
					}
				}
				out(ans); puts("");
			}
		}
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
