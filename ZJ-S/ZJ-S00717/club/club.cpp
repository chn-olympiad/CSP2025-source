#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=1e5+10;
int T,n,check[5];
struct nod{
	int x,id;
};
struct node{
	nod v[5];
}a[N];
bool cmp(nod a,nod b){
	return a.x>b.x;
}
bool cmpl(node a,node b){
	return a.v[1].x+b.v[2].x>a.v[2].x+b.v[1].x;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i].v[j].x;
				a[i].v[j].id=j;
			}
			sort(a[i].v+1,a[i].v+3+1,cmp);
		} 
		sort(a+1,a+n+1,cmpl);
		for(int i=1;i<=3;i++) check[i]=n/2;
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(check[a[i].v[j].id]>0){
					ans+=a[i].v[j].x;
					check[a[i].v[j].id]--;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
