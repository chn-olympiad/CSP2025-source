#include<bits/stdc++.h>
using namespace std;
int a[500005],sum[500005];
struct qj{
	int x,y;
}g[500005];
int tp(int n){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0) cnt++;
	}
	return cnt;
}
bool cmp(qj a,qj b){
	if(a.x-a.y!=b.x-b.y){
		if(a.x-a.y<b.x-b.y) return 1;
		else return 0;
	}else{
		return a.x<b.x;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,c1=0,cnt1=0;
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=(sum[i-1]^a[i]);
	}
	if((n>1000&&k==0)||(n>1000&&k==1)){
		if(k=0){
			cout<<tp(n);
			return 0;
		}else{
			cout<<n-tp(n);
			return 0;
		}
	}
	for(long long  i=1;i<=n;i++){
		for(long long j=i;j>=1;j--)
		if((sum[i]^sum[j-1])==k){
			g[++c1].x=i,g[c1].y=j;
			break;
		}
	}
	sort(g+1,g+c1+1,cmp);
	for(int i=1;i<=c1;i++){
		if(g[i].x!=-1){
			cnt1++;
			for(int j=i+1;j<=c1;j++){
				if(!(g[i].y>g[j].x)&&!(g[i].x<g[j].y)){
					g[j].x=-1;
				}
			}
		}
		
	}
	cout<<cnt1;
	return 0;
}

