#include<bits/stdc++.h>
using namespace std;
#define for1(i,a,b) for(int i=(a);i<=(b);i++)
#define for2(i,a,b) for(int i=(a);i<(b);i++)
#define for3(i,a,b) for(int i=(a);i>=(b);i--)
#define for4(i,a) for(auto &i:(a))
#define puba push_back
#define pii pair<int,int>
#define ll long long
#define mem(a,b) memset((a),(b),sizeof((a)))
#define int long long
const int N=1e5+5;
struct node{
	int x,id;
}a[N][3];
int T,n,t[3],ans,b[N],cnt;
bool cmp(node x,node y){
	return x.x>y.x;
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=cnt=0;
		mem(t,0);
		cin>>n;
		for1(i,1,n){
			for1(j,0,2) cin>>a[i][j].x,a[i][j].id=j;
			sort(a[i],a[i]+3,cmp);
			ans+=a[i][0].x;
			t[a[i][0].id]++;
		}
		int id=-1;
		for1(i,0,2) if(t[i]*2>n) id=i;
		if(id==-1){
			cout<<ans<<"\n";
			continue;
		}
//		cout<<ans<<"\n";
		for1(i,1,n){
			if(a[i][0].id==id){
				b[++cnt]=a[i][0].x-a[i][1].x;
			}
		}
		sort(b+1,b+cnt+1);
		for1(i,n/2+1,cnt) ans-=b[i-n/2];
		cout<<ans<<"\n";
	}
	
	return 0;
}/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/