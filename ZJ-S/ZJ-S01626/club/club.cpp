//T1
//14:31 idea
//14:43 code
//14:46 AC
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n;
int a[N][3];
int val[N];
int lns[4];
vector<int> vec[3];
int ans;
int b[N],tot;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		n=read();ans=0;
		for(int i=1;i<=n;i++)
		for(int j=0;j<=2;j++)
			a[i][j]=read();
		for(int i=1;i<=n;i++){
			for(int j=0;j<=2;j++)lns[j]=a[i][j];
			sort(lns,lns+3);val[i]=lns[2]-lns[1];
		}
		for(int i=1;i<=n;i++){
			int Max=0;
			for(int j=0;j<=2;j++)Max=max(Max,a[i][j]);
			for(int j=0;j<=2;j++){
				if(Max==a[i][j]){
					vec[j].push_back(i);
					ans+=Max;break;
				}
			}
		}
		int id=-1;
		for(int j=0;j<=2;j++)if(vec[j].size()>n/2)id=j;
		if(id!=-1){
			tot=0;
			for(int i=0;i<vec[id].size();i++)b[++tot]=val[vec[id][i]];
			sort(b+1,b+1+tot);reverse(b+1,b+1+tot);
			while(tot>n/2)ans-=b[tot--];
		}
		for(int j=0;j<=2;j++)vec[j].clear();
		write(ans);putchar('\n');
	}
	return 0;
}