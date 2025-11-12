#include<bits/stdc++.h>
using namespace std;
int T,n;
const int N=1e5+505;
int a[N][5],b[N][5],c[5];
struct Node{
	int d,id,p,maxn,maxx;
}s[N];
bool cmp(Node x,Node y){
	if(x.d!=y.d) return x.d>y.d;
	return x.maxn>y.maxn;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdin);
	cin>>T;
	while(T--){
		cin>>n;
		memset(c,0,sizeof c);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				b[i][j]=a[i][j];
			}
			sort(b[i]+1,b[i]+4);
			s[i].maxn=b[i][3],s[i].maxx=b[i][2];
			int ma=0;
			for(int j=1;j<=3;j++)
				if(a[i][j]>ma){
					s[i].p=j;
					ma=a[i][j];
				}
		}
		for(int i=1;i<=n;i++)
			s[i].id=i,s[i].d=s[i].maxn-s[i].maxx;
		sort(s+1,s+n+1,cmp);
//		for(int i=1;i<=n;i++)
//			cout<<s[i].maxn<<" "<<s[i].maxx<<" "<<s[i].p<<"\n";
		long long ans=0;
		for(int i=1;i<=n/2;i++){
			ans+=s[i].maxn;
			c[s[i].p]++;
		}
		for(int i=n/2+1;i<=n;i++){
			if(c[s[i].p]<n/2){
				ans+=s[i].maxn;
				c[s[i].p]++;
			}else
				ans+=s[i].maxx;
		}
		cout<<ans<<"\n";
	}
	return 0;
}

