#include <bits/stdc++.h>
using namespace std;
const int N=100020;
struct clb{
	int w,id;
}cc[10];
bool cmp(clb x,clb y){
	return x.w>y.w;
}
int tot[5],s[5][N],p[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,a,b,c,ans=0;tot[1]=tot[2]=tot[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			cc[1]={a,1},cc[2]={b,2},cc[3]={c,3};
			sort(cc+1,cc+4,cmp);
			s[cc[1].id][++tot[cc[1].id]]=cc[1].w-cc[2].w;
			ans+=cc[1].w;
		}
		for(int i=1;i<=3;i++){
			if(tot[i]>n/2){
				for(int j=1;j<=tot[i];j++) p[j]=s[i][j];
				sort(p+1,p+tot[i]+1);
				for(int j=1;j<=tot[i]-n/2;j++) ans-=p[j];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//14:57 finish 100
//fyc 保佑我这题不挂分！