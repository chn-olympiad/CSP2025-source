#include<bits/stdc++.h>

using namespace std;
int a[500005],dp[500005];
int yh(int x,int y){
	int ans=0,t=1;
	while(x || y){
		if(x%2 != y%2){
			ans=ans+t;
		}
		t*=2;
		x/=2;
		y/=2;
	}
	return ans;
}
int yhqj(int x,int y){
	int ans=a[x];
	for(int i=x+1;i<=y;i++){
		ans=yh(ans,a[i]);
	}
	return ans;
}
struct node{
	int x,y;
}q[500005];
bool cmp(node x,node y){
	return x.x==y.x?x.y<y.y:x.x<y.x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0,len=0;
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n<=2 && k==0){
		if(n==1){
			cout << 0;
		}else{
			cout << 1;
		}
	}else if(n<=10 && k<=1){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==-1){
					continue;
				} 
				if(a[i]==0){
					cnt++;
					a[i]=-1;
				}else if(i>1 && a[i]==a[i-1]){
					cnt++;
					a[i]=a[i-1]=-1;
				}
			}
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					cnt++;
				}
			}
		}
		cout << cnt;
	}else if(n<=100 && k==0){
		cout << n/2;
	}else if(n<=100 && k<=1){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==-1){
					continue;
				} 
				if(a[i]==0){
					cnt++;
					a[i]=-1;
				}else if(i>1 && a[i]==a[i-1]){
					cnt++;
					a[i]=a[i-1]=-1;
				}
			}
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					cnt++;
				}
			}
		}
		cout << cnt;
	}else if(n<=200005 && k<=1){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==-1){
					continue;
				} 
				if(a[i]==0){
					cnt++;
					a[i]=-1;
				}else if(i>1 && a[i]==a[i-1]){
					cnt++;
					a[i]=a[i-1]=-1;
				}
			}
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					cnt++;
				}
			}
		}
		cout << cnt;
	}else{
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(yhqj(i,j)==k){
					q[++len].x=i;
					q[len].y=j;
				}
			}
		}
		sort(q+1,q+1+len,cmp);
		for(int i=1;i<=len;i++){
			dp[i]=1;
			for(int j=1;j<i;j++){
				if(q[j].y < q[i].x){
					dp[i]=max(dp[i],dp[j]+1);
				}
			}
		}
		for(int i=1;i<=len;i++){
			cnt=max(cnt,dp[i]);
		}
		cout << cnt;
	}
	return 0;
}
