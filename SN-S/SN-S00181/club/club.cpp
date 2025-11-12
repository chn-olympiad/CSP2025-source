#include<bits/stdc++.h>
using namespace std;
long long v[500005];
long long a[500005][5];

//long long fa[500005];
bool cmp(long long x,long long y){
	return x>y;
}
long long ans = 0;
void dfs(int step,int n,long long sum,int c1,int c2,int c3){
	if(step==n){
		if(ans<sum){
			ans = sum;	
			
		}
		sum=0;
		return ;
	}
	if(c1<n/2){
		dfs(step+1,n,sum+a[step+1][1],c1+1,c2,c3);
	}
	if(c2<n/2){
		dfs(step+1,n,sum+a[step+1][2],c1,c2+1,c3);
	}
	if(c3<n/2){
		dfs(step+1,n,sum+a[step+1][3],c1,c2,c3+1);
	}

	

	
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int f = 1,fc = 1;
		for(int i = 1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0){
				f = 0;
			}
			if(a[i][3]!=0){
				fc=0;
			}
		}
		if(f){
			for(int i = 1;i<=n;i++)v[i] = a[i][1];
			sort(v+1,v+n+1,cmp);

			for(int i = 1;i<=n/2;i++){
				ans+=a[i][1];
			}
			cout<<ans<<endl;
		}
		else{	
			dfs(0,n,0,0,0,0);
			cout<<ans;
		}

		ans = 0;
	}
	
	
	
	return 0;
}
		
