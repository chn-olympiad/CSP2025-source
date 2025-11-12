#include<bits/stdc++.h>
using namespace std;
#define N 500005
#define int long long 
int n,k;
int a[N],sum[N],cnt;
struct node{
	int s;
	int e;
}b[N];

bool cmp(node x,node y){
	if(x.s==y.s) return x.e<y.e;
	else return x.s<y.s;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>k;
	sum[1]=0;
	int flag=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]!=1){
			flag=1;
		}
		if(i>1){
			sum[i]=sum[i-1]^a[i];
		}
	}
	if(flag==0){
		if(k==1){
			cout<<n;
			return 0;
		}
		if(k==0){
			cout<<n/2;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			int d=sum[j]^sum[i-1];
			if(d==k){
				cnt++;
				b[cnt].s=i;
				b[cnt].e=j;	
				break;		
			}
		}
	}
	b[0].s=1000000;
	b[0].e=1000000;
	int ans=0;
	sort(b+1,b+1+cnt,cmp);
	for(int i=1;i<=cnt;++i){
		if(b[i-1].s==b[i].s||b[i-1].e==b[i].s){
			ans++;
			b[i].s=1000000;
			b[i].e=1000000;
		}
	}
	cout<<cnt-ans;
	return 0;
}
