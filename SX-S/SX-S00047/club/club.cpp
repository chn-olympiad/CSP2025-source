#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2*1e5+3;
struct edge{
	int a,b,c;
	int mmax(){
		return max(a,max(b,c));
	}
}num[N];
int sec,aa,bb,cc,nnum;
inline bool cmp(edge xx,edge yy){
	if(xx.mmax()!=yy.mmax()) return xx.mmax()>yy.mmax();
 	if(xx.b!=yy.b) return xx.b>yy.b;
 	if(xx.a!=yy.a) return xx.a>yy.a;
	return xx.c>yy.c;
}
inline void to_0(){
	memset(num,0,sizeof(num));
	sec=0,aa=0,bb=0,cc=0,nnum=0;
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n;
		k=n/2;
		to_0();
		for(int i=1;i<=n;i++) cin>>num[i].a>>num[i].b>>num[i].c;
		sort(num+1,num+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(num[i].mmax()==num[i].a){
				aa++;
				sec+=num[i].a;
				nnum=num[i].a;
				if(aa>k){
					sec-=num[i].a;
					nnum=max(num[i].b,num[i].c);
					sec+=nnum;
					aa--;
				}
			}
			else if(num[i].mmax()==num[i].b){
				bb++;
				sec+=num[i].b;
				nnum=num[i].b;
				if(bb>k){
					sec-=num[i].b;
					nnum=max(num[i].a,num[i].c);
					sec+=nnum;
					bb--;
				}
			}
			else if(num[i].mmax()==num[i].c){
				cc++;
				sec+=num[i].c;
				nnum=num[i].c;
				if(cc>k){
					sec-=num[i].c;
					nnum=max(num[i].a,num[i].b);
					sec+=nnum;
					cc--;
				}
			}
		}
		cout<<sec<<endl;
	}
	return 0;
}