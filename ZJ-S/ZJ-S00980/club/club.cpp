#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn = 1e5+10;
ll num[maxn][5];
ll t;

ll ans = 0;
void dfs(ll p,ll n,ll sum,ll s1,ll s2,ll s3){
	if(p == n+1){
		ans=max(ans,sum);
		return;
	}
	
	if(s1<n/2) dfs(p+1,n,sum+num[p][1],s1+1,s2,s3);
	if(s2<n/2) dfs(p+1,n,sum+num[p][2],s1,s2+1,s3);
	if(s3<n/2) dfs(p+1,n,sum+num[p][3],s1,s2,s3+1);
}


struct node{
	ll a,b,c;

};
node s[maxn];

bool cmp(node x,node y){
	if( max(x.a,max(x.b,x.c)) == max(y.a,max(y.b,y.c)) ){
		return max( max(min(x.a,x.b),min(x.a,x.c)),min(x.b,x.c) ) > max( max(min(y.a,y.b),min(y.a,y.c)),min(y.b,y.c) );
	} 
	else return max(x.a,max(x.b,x.c)) > max(y.a,max(y.b,y.c));
}

bool cmp2(node x,node y){
	return x.a > y.a;
}

bool cmp3(node x,node y){
	if(x.a == y.a) return x.b > y.b;
	else return x.a > y.a;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		bool fa = 1,fb = 1; 
		for(ll i = 1;i <= n;i++){
			cin >> num[i][1] >> num[i][2] >> num[i][3];	
			s[i].a = num[i][1];
			s[i].b = num[i][2];
			s[i].c = num[i][3];
			if(num[i][2]!=0 || num[i][3] != 0) fa = 0;
			if(num[i][3] != 0) fb = 1;
		}
		
		if(n<=30){
			ans=0;
			dfs(1,n,0, 0,0,0);
			cout << ans << "\n";
		}
		else{
			if(fa){
				sort(s+1,s+n+1,cmp2);
				ans=0;
				for(ll i = 1;i <= n/2;i++){
					ans += s[i].a;
				}
				cout << ans << "\n";
			}
			else if(fb){
				sort(s+1,s+n+1,cmp3);
				ans = 0;
				for(ll i = 1;i <= n/2;i++) ans += s[i].a;
				for(ll i = n/2+1;i <= n;i++) ans += s[i].b;
				cout << ans << "\n";
			}
		}

		
		
	}
	
	
	
	return 0;
}

//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
