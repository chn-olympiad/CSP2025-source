#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N=5e3+5,mod=998244353;
struct node{
	int sum,cnt,maxn;
}f[N*N];
int n,a[N],ans,tot;
bool cmp(node p,node q){
	return p.sum<q.sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	sort(a+1,a+n+1);
	f[++tot]=(node){0,0,0};
	for(int i=1;i<=n;i++){
		int maxn=tot;
		for(int j=1;j<=maxn;j++)
			f[++tot]=(node){f[j].sum+a[i],f[j].cnt+1,a[i]};
		
	}
    for(int i=2;i<=tot;i++){
    	if(f[i].cnt>=3&&f[i].sum>f[i].maxn*2) ans++;
    	ans%=mod;
	}
	cout<<ans; 
	return 0;
} 

