#include<bits/stdc++.h>
using namespace std;
typedef long long lint;

const int N=1e5+7;

struct saty{
	int s1,s2,s3;
}a[N];

int n,sum1=0,sum2=0,sum3=0;
int m[5]={},vis[N]={},mx=0;

void dfs(int s){
	if(s>n){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==1){
				cnt+=a[i].s1;
			}
			if(vis[i]==2){
				cnt+=a[i].s2;
			}
			if(vis[i]==3){
				cnt+=a[i].s3;
			}
		}
		mx=max(cnt,mx);
	}
	
	if(sum1&&m[1]<n/2){
		m[1]++;
		vis[s]=1;
		dfs(s+1);
		m[1]--;
	}
	if(sum2&&m[2]<n/2){
		m[2]++;
		vis[s]=2;
		dfs(s+1);
		m[2]--;
	}
	if(sum3&&m[3]<n/2){
		m[3]++;
		vis[s]=3;
		dfs(s+1);
		m[3]--;
	}
	
}

bool cmp1(saty p,saty q){
	return p.s1>q.s1;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin>>t;
	while(t--){
		cin>>n;
		sum2=sum3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].s1>>a[i].s2>>a[i].s3;
			sum1+=a[i].s1;
			sum2+=a[i].s2;
			sum3+=a[i].s3;
		}
		if(n<=10){
//			-----------
			mx=0;
			dfs(1);
			cout<<mx<<"\n";
			continue;
		}
		if(!sum3){
			if(!sum2){
				int ans=0;
				sort(a+1,a+1+n,cmp1);
				for(int i=1;i<=n/2;i++){
					ans+=a[i].s1;
				}
				cout<<ans<<"\n";
				continue;
			}
			
//			--------------
			
		}
		
	}
	
	
	return 0;
}