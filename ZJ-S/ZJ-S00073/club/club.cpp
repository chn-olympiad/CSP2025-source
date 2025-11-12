#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int N=1e5+7;
int n,a[N][3],tmp[N],tot=0;
vector<int>T[4];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int ToT;cin>>ToT;
	while(ToT--){
		int n,res=0;cin>>n;
		for(int i=1;i<=3;i++)T[i].clear();
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int tmp=max(max(a[i][0],a[i][1]),a[i][2]);
			if(tmp==a[i][0]){
				T[1].push_back(i);
			}else if(tmp==a[i][1]){
				T[2].push_back(i);
			}else T[3].push_back(i);
			res+=tmp;
		}
		tot=0;
		if(T[1].size()>n/2){
			for(auto x:T[1])
				tmp[++tot]=a[x][0]+a[x][1]+a[x][2]
				-2*max(max(a[x][0],a[x][1]),a[x][2])
				-min(min(a[x][0],a[x][1]),a[x][2]);
			sort(tmp+1,tmp+1+tot);
			for(int i=tot;i>=n/2+1;i--)res+=tmp[i];
		}
		if(T[2].size()>n/2){
			for(auto x:T[2])
				tmp[++tot]=a[x][0]+a[x][1]+a[x][2]
				-2*max(max(a[x][0],a[x][1]),a[x][2])
				-min(min(a[x][0],a[x][1]),a[x][2]);
			sort(tmp+1,tmp+1+tot);
			for(int i=tot;i>=n/2+1;i--)res+=tmp[i];
		}
		if(T[3].size()>n/2){
			for(auto x:T[3])
								tmp[++tot]=a[x][0]+a[x][1]+a[x][2]
				-2*max(max(a[x][0],a[x][1]),a[x][2])
				-min(min(a[x][0],a[x][1]),a[x][2]);
			sort(tmp+1,tmp+1+tot);
			for(int i=tot;i>=n/2+1;i--)res+=tmp[i];
		}
		cout<<res<<"\n";
			
	}
}
//10
//7 6 9
//18 17 26
//15 20 21
//8 11 2
//16 4 10
//19 23 13
//12 27 24
//22 29 30
//14 5 25
//1 3 28
