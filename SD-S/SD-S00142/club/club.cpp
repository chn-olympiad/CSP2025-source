#include<bits/stdc++.h>
#define int long long
const int M=1e5+500;
using namespace std;
int T,maxid[M];
struct node{
	int a,b,c,maxx;
}x[M];
int bb[M],cnt;
int cmp(node a,node b){
	return a.a>b.a;
}
int cmp2(node a,node b){
	return  a.maxx>b.maxx;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		int m;
		cin>>m;
		if(m==2){
			int a,b,c,d,e,f;
			cin>>a>>b>>c;
			cin>>d>>e>>f;
			cout<<max(max(max(a+e,a+f),max(b+d,b+f)),max(c+d,c+e))<<endl;
		}
		for(int i=1;i<=m;i++) cin>>x[i].a>>x[i].b>>x[i].c;
		int sum=0,ans=0;
		for(int i=1;i<=m;i++) if(x[i].b==0&&x[i].c==0) sum++;
		if(sum==m){
			sort(x+1,x+m+1,cmp);
			for(int i=1;i<=m/2;i++) ans+=x[i].a;
			cout<<ans<<endl;
			ans=0;
		}
		else{
			for(int i=1;i<=m;i++) {
				int a=x[i].a,b=x[i].b,c=x[i].c;
				if(a>=b&&a>=c) maxid[i]=1;
				if(b>=a&&b>=c) maxid[i]=2;
				if(c>=a&&c>=b) maxid[i]=3;
			}
			sort(x+1,x+m+1,cmp2);
			for(int i=1;i<=m;i++){
				if(maxid[i]==1) ans+=x[i].a;
				if(maxid[i]==2) ans+=x[i].b;
				if(maxid[i]==3) ans+=x[i].c;
			}
			cout<<ans<<endl;
		}
		
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
