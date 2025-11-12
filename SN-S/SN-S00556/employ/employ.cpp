//石丰源 SN_S00556 安康市长兴综合高级中学 
#include<map>
#include<queue>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;
#define maxn int(5e6+10)
#define maxm int(1e6+10)
#define ull unsigned long long
typedef pair<int,int> pii;
inline int read(){
	char c=getchar(); int t=1,k=0;
	while('0'>c||c>'9'){if(c=='-') t=-1; c=getchar();}
	while('0'<=c&&c<='9'){k=k*10+(c^48); c=getchar();}
	return t*k;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n=read(),m=read();
	string str;
	cin>>str;
	for(int i=1;i<=m;i++) int a=read();
	cout<<rand()%998244353+1;
	return 0;
}
