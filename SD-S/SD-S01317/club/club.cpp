//club2.0
//17点01分-- 
//crx
/*

记忆化
估计得分:40

*/
#include<bits/stdc++.h>
#define ll long long
#define mkp(a,b) make_pair(a,b)
using namespace std;

const int N=100010;
ll a[N][6],t,n,ans,sum[N],aa[N];
map <pair<ll,pair<ll,pair<ll,pair<ll,ll> > > > ,ll> mp;
bool okey=1,koee=1;
ll sum1,sum2,sum3;
priority_queue <pair<ll,ll> > q[6];
bool bb[100010];

ll dfs(ll x,ll op,ll a1,ll a2,ll a3){
//	cout<<x<<' '<<op<<' '<<a1<<' '<<a2<<' '<<a3<<' '<<a[x][op]<<'\n';////////
	if(a1 > n/2 || a2 > n/2 || a3 > n/2)return 0;
	if(mp.find(mkp(x,mkp(op,mkp(a1,mkp(a2,a3))))) != mp.end()){
		return mp[mkp(x,mkp(op,mkp(a1,mkp(a2,a3))))];
	}
	if(x == n){
		mp[mkp(x,mkp(op,mkp(a1,mkp(a2,a3))))]=a[x][op];
//		cout<<mp[mkp(x,mkp(op,mkp(a1,mkp(a2,a3))))]<<' '<<a[x][op]<<'\n';/////
		return mp[mkp(x,mkp(op,mkp(a1,mkp(a2,a3))))];
	}
	ll tmp=a[x][op];
	if(a1+1 > n/2){
		mp[mkp(x,mkp(op,mkp(a1,mkp(a2,a3))))]=max(tmp+dfs(x+1,2,a1,a2+1,a3),tmp+dfs(x+1,3,a1,a2,a3+1));
		return mp[mkp(x,mkp(op,mkp(a1,mkp(a2,a3))))];
	}
	else if(a2+1 > n/2){
		mp[mkp(x,mkp(op,mkp(a1,mkp(a2,a3))))]=max(tmp+dfs(x+1,1,a1+1,a2,a3),tmp+dfs(x+1,3,a1,a2,a3+1));
//		cout<<x<<' '<<op<<' '<<mp[mkp(x,mkp(op,mkp(a1,mkp(a2,a3))))]<<'\n';/////////
		return mp[mkp(x,mkp(op,mkp(a1,mkp(a2,a3))))];
	}
	else if(a3+1 > n/2){
		mp[mkp(x,mkp(op,mkp(a1,mkp(a2,a3))))]=max(tmp+dfs(x+1,2,a1,a2+1,a3),tmp+dfs(x+1,1,a1+1,a2,a3));
		return mp[mkp(x,mkp(op,mkp(a1,mkp(a2,a3))))];
	}
	mp[mkp(x,mkp(op,mkp(a1,mkp(a2,a3))))]=max(max(tmp+dfs(x+1,2,a1,a2+1,a3),tmp+dfs(x+1,1,a1+1,a2,a3)),tmp+dfs(x+1,3,a1,a2,a3+1));
	return mp[mkp(x,mkp(op,mkp(a1,mkp(a2,a3))))];
}

bool cmp(ll x,ll y){
	return x >= y;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		mp.clear();
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			aa[i] = a[i][1];
			if(a[i][2])okey=0;
			if(a[i][3])koee=0;
					q[1].push(mkp(a[i][1],i));
					q[2].push(mkp(a[i][2],i));
					q[3].push(mkp(a[i][3],i));
//			cout<<i<<" : "<<a[i][1]<<' '<<a[i][2]<<' '<<a[i][3]<<'\n';/////////
		}
		
		if(n<=200){
			ans=max(ans,dfs(0,0,0,0,0));
		}
		else {
			if(okey){
				sort(aa+1,aa+1+n,cmp);
				for(int i=1;i<=n;i++){
					sum[i] = aa[i] + sum[i-1];
				}
				sort(aa+1,aa+1+n,cmp);
				for(int i=1;i<=n;i++){
					sum[i] = aa[i] + sum[i-1];
				}
				ans = sum[n/2];
			}
			else{
				sum1 = sum2 = sum3 = 0;
				for(int i=1;i<=n;i++){
					bb[i] = 0;
				}
				for(int i=1;i<=n;i++){
				}
				
				
				
				for(int i=1;i<=n;i++){
					while(!q[1].empty() && bb[q[1].top().second]){
						q[1].pop();
					}
					while(!q[2].empty() && bb[q[2].top().second]){
						q[2].pop();
					}
					while(!q[3].empty() && bb[q[3].top().second]){
						q[3].pop();
					}
					int a_1 = q[1].top().first,a_2 = q[2].top().first,a_3 = q[3].top().first;
					if(sum1 >= n/2){
						if(a_2 >= a_3){
							sum2++;
							ans += a_2;
							bb[q[2].top().second] = 1;
							q[2].pop();
						}
						else{
							sum3++;
							ans += a_3;
							bb[q[3].top().second] = 1;
							q[3].pop();
						}
					}
					else if(sum2 >= n/2){
						if(a_1 >= a_3){
							sum1++;
							ans += a_1;
							bb[q[1].top().second] = 1;
							q[1].pop();
						}
						else{
							sum3++;
							ans += a_3;
							bb[q[3].top().second] = 1;
							q[3].pop();
						}
					}
					else if(sum3 >= n/2){
						if(a_1 >= a_2){
							sum1++;
							ans += a_1;
							bb[q[1].top().second] = 1;
							q[1].pop();
						}
						else{
							sum2++;
							ans += a_2;
							bb[q[2].top().second] = 1;
							q[2].pop();
						}
					}
					else{
						if(a_1 >= a_2 && a_1 >= a_3){
							sum1++;
							ans += a_1;
							bb[q[1].top().second] = 1;
							q[1].pop();
						}
						else if(a_2 >= a_1 && a_2 >= a_3){
							sum2++;
							ans += a_2;
							bb[q[2].top().second] = 1;
							q[2].pop();
						}
						else{
							sum3++;
							ans += a_3;
							bb[q[3].top().second] = 1;
							q[3].pop();
						}
					}
				}
				
				
				
//				cout<<ans1<<'\n';
				while(!q[1].empty()){
					q[1].pop();
				}
				while(!q[2].empty()){
					q[2].pop();
				}
				while(!q[3].empty()){
					q[3].pop();
				}
					
				}
			}
		cout<<ans<<'\n';
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

