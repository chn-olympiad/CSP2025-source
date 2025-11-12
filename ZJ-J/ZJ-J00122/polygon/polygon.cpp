#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+10;
ll n,cnt,a[N],pre[N],d[N],f;
void dfs(ll x,ll y,ll z){
	if(x==n+1){
		if(z<3) return ;
		ll p=0;
		for(int i=n;i>0;i--){
			if(d[i]){
				p=i;
				break;
			}
		}if(a[p]<(y-a[p])) cnt++;//cout<<p<<endl;
		//cout<<p<<endl;
		return ;
	}
	dfs(x+1,y,z);
	d[x]=1;
	dfs(x+1,y+a[x],z+1);
	d[x]=0;
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
		if(a[i]!=1) f=1;
	}if(!f){
		for(int i=3;i<=n;i++){
			ll bb=1,cc=1;
			for(int j=n;j>=(n-i+1);j--){
				bb*=j;
				cc*=(n-j+1);
			}cnt+=(bb/cc);
			cout<<bb<<" "<<cc<<endl;
			cout<<cnt<<endl;
		}cout<<cnt;
		return 0;
	}
	if(n<=26){
		dfs(1,0,0);
		cout<<cnt;
		return 0;
		
	}
	for(int i=3;i<=n;i++){
		for(int r=1;r<i;r++){
			for(int l=1;l<r;l++){
				
				if(pre[r]-pre[l-1]>a[i]) cnt++;
				cout<<pre[r]-pre[l-1]<<" "<<i<<endl;
			}
		}
	
	}cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
