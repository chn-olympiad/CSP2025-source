#include<bits/stdc++.h>
using namespace std;
int m,n,k,lg[500005],dp[500005][21],p[500005];
struct node{
	int st;
	int ed;
}a[1000005];
bool cmp(node x,node y){
	if(x.ed<y.ed)return 1;
	else if(x.ed==y.ed&&x.st>y.st)return 1;
	else return 0;
}int check(int i,int j){
	int zs=lg[j-i+1],r=j-i+1,now=i,res=0;
	while(r){
		if(r>=(1<<zs)){
			res=res^dp[now][zs];
			r-=(1<<zs);
			now+=(1<<zs);
		}zs--;
	}return res;
}int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	if(n<=1000){
		lg[0]=-1;
		for(int i=1,a; i<=n; i++){
			cin>>a;
			lg[i]=lg[i/2]+1;
			dp[i][0]=a;
		}for(int i=1; i<=20; i++){
			for(int j=1; j+(1<<i)<=n; j++){
				dp[j][i]=dp[j][i-1]^dp[j+(1<<i-1)][i-1];
			}
		}for(int i=1; i<=n; i++){
			for(int j=i; j<=n; j++){
				if(check(i,j)==k){
					a[++m].st=i;
					a[m].ed=j;
				}
			}
		}sort(a+1,a+1+m,cmp);
		int lst=-1,sum=0;
		for(int i=1; i<=m; i++){
			if(a[i].st>lst){
				sum++;
				lst=a[i].ed;
			}
		}cout<<sum;
	}else{
		int sum=0,ans=0;
		for(int i=1; i<=n; i++)cin>>p[i];
		for(int i=1; i<=n; i++){
			if(p[i]==1)sum++;
		}for(int i=1; i<n; i++){
			if(p[i]==0)ans++;
			if(p[i]==1&&p[i+1]==1){
				ans++;
				i++;
			}
		}if(p[n]==0)ans++;
		if(k==1)cout<<sum;
		else cout<<ans;
	}
	return 0;
}
//xor