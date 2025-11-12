#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cassert>
int n,q;
const int maxn=2e5+5,maxq=2e5+5,maxl=5e6+5;
char tmp1[maxl],tmp2[maxl];
std::string a[maxn],b[maxn];
std::string x,y;
namespace Force{
	void solve(){
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<(int)x.size()-(int)a[i].size()+1;j++){
				bool flag=true;
				for(int k=j;k<=j+(int)a[i].size()-1;k++) if(x[k]!=a[i][k-j]) flag=false;
				if(flag){
					std::string str=x;
					for(int k=j;k<=j+(int)a[i].size()-1;k++) str[k]=b[i][k-j];
					if(str==y) cnt++;
				}
			}
		}
		printf("%d\n",cnt);
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",&tmp1[1],&tmp2[1]);
		a[i]=&tmp1[1],b[i]=&tmp2[1];
	}
	while(q--){
		scanf("%s%s",&tmp1[1],&tmp2[1]);
		x=&tmp1[1],y=&tmp2[1];
		Force::solve();
	}
	return 0;
}
