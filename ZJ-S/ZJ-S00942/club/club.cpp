#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define N 100050
typedef long long ll;
typedef pair<ll,ll> pii;
#define val first 
#define pos second

ll n,t,len;
ll tmp;
ll sum;
struct node{
	pii p[4]; //val,pos
	ll dis;
}a[N],b[4][N];
int cnt[4];

bool cmp(node a,node b){
	return a.dis<b.dis;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>t;
	while(t--){
		cin>>n;
		sum=0;
		for(int i=1; i<=3; i++) {
			cnt[i]=0;
		}
		for(int i=1; i<=n; i++){
			for(int j=1; j<=3; j++){
				cin>>a[i].p[j].val;
				a[i].p[j].pos=j;
			}
			sort(a[i].p+1,a[i].p+4);
			a[i].dis=a[i].p[3].val-a[i].p[2].val;
			b[a[i].p[3].pos][++cnt[a[i].p[3].pos]]=a[i];
		}

		for(int i=1; i<=3; i++){
			for(int j=1; j<=cnt[i]; j++)
				sum+=b[i][j].p[3].val;
			if(cnt[i]>n/2){
				sort(b[i]+1,b[i]+cnt[i]+1,cmp);
				for(int j=1; j<=cnt[i]-n/2; j++)
					sum-=b[i][j].dis;
			}
		}
		cout<<sum<<endl;
	}
	
	return 0;
}
