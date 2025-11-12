#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5050],sum,n,e,b[5050],u[5050],lk=1;
int q[5001][5001];
bool cmp(int x,int y){
	return x>y;
}
void dfs(int d){
	if(d==e+1){
		sort(u+1,u+d,cmp);
		int ans=0,maxn=-1;
		for(int i=1;i<d;i++){
			ans+=a[u[i]];
			maxn=max(maxn,a[u[i]]);
		}
		if(ans>maxn*2){
//			cout<<ans<<' '<<maxn<<' ';
			int c,l=0;
			for(int i=1;i<lk;i++){
				c=0;
				for(int j=1;j<d;j++){
					if(a[u[j]]==q[i][j]){
						c++;
					}
				}
				for(int j=1;j<d;j++){
					if(a[u[j]]==a[u[j-1]]){
						l=1;
						break;
					}
				}
				if(c==d-1){
					l=1;
					break;
				}
			}
			if(l==0){
				sum++;
				for(int i=1;i<d;i++){
					q[lk][i]=a[u[i]];
				}
				for(int i=1;i<d;i++){
					cout<<u[i]<<' ';
				}
				cout<<'\n';
				lk++;
			}
			
		}
		
		return ;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			u[d]=i;
			b[i]=1;
			dfs(d+1);
			b[i]=0;
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxm=-1,al=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxm=max(maxm,a[i]);
		al+=a[i];
	}
	if(n<3){
		cout<<0;
	}
	if(n==3){
		if(al>maxm/2){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	if(maxm==1){
		cout<<1;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=3;i<=n;i++){
		e=i;
		dfs(1);
	}
	cout<<sum;
	
	return 0;
}
