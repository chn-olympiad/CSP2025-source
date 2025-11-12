#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&-(x))
#define endl "\n"
using namespace std;
const int N=1e5+10;
int t,n,a[N][4],ma[N],oth[N],num[4],p[N],tot;
bool cmp(int x,int y){
	return a[x][ma[x]]-oth[x]>a[y][ma[y]]-oth[y];
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;int res=0;
		for(int i=1;i<=3;i++)num[i]=0;
		for(int i=1;i<=n;i++){
			ma[i]=0;oth[i]=0;
			for(int k=1;k<=3;k++){
				cin>>a[i][k];
				if(a[i][k]>a[i][ma[i]])ma[i]=k;
			}
			for(int k=1;k<=3;k++){
				if(k!=ma[i])oth[i]=max(oth[i],a[i][k]);
			}
			res+=a[i][ma[i]];num[ma[i]]++;
		}
		int bo=0,tp=0;
		for(int i=1;i<=3;i++){
			if(num[i]>n/2){
				bo=1;tp=i;
			}
		}
		if(!bo){
			cout<<res<<endl;continue;
		}tot=0;
		for(int i=1;i<=n;i++){
			if(ma[i]==tp)p[++tot]=i;
		}
		sort(p+1,p+1+tot,cmp);
		for(int i=n/2+1;i<=tot;i++){
			res-=(a[p[i]][tp]-oth[p[i]]);
		}
		cout<<res<<endl;
	}
	return 0;
}
