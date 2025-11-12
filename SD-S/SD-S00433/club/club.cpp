#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#define _for(i,a,b) for(int i=(a);i<=(b);i++)
#define _rof(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline int read(){
	int f=1,num=0;
	char c=getchar();
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	return f*num;
}
inline int Max(int a,int b){return a>b?a:b;}
int T;
vector<int> p[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		int n=read(),res=0;
		_for(i,1,3) p[i].clear(),p[i].shrink_to_fit();
		_for(i,1,n){
			int x=read(),y=read(),z=read();
			int mx=Max(x,Max(y,z));
			res+=mx;
			if(mx==x){
				int mn=Max(y,z);
				p[1].push_back(mx-mn);
			}else if(mx==y){
				int mn=Max(x,z);
				p[2].push_back(mx-mn);
			}else{
				int mn=Max(x,y);
				p[3].push_back(mx-mn);
			}
		}
		_for(i,1,3){
			int sz=p[i].size();
			if(sz>(n/2)){
				sort(p[i].begin(),p[i].end());
				_for(j,0,sz-(n/2)-1) res-=p[i][j];
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
/*
luogu undefined_behavior
Ô¤ÆÚ£º100+[48,64]+[10,25]+8=[166,197]
*/
//i love ccf
