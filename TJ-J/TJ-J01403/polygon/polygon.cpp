#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt;
int l,r;
int a[5040];
bool v[5040];
int s(int l,int r){
	int sum=0;
	for(int i=l;i<=r;i++){
		sum+=a[i];
	}
	return sum;
}
int dlt(int l,int r){
	int zdz=0;
	for(int i=l;i<=r;i++){
		zdz=max(zdz,a[i]);
	}
	return zdz;
} 
void dfs(int step,int mudi,int sumly,int zd){
	if(step>mudi) return ;
	if(step==mudi){
		if(sumly>=zd*2){
			cnt++;
			cnt%998244353;
			return;
		}
	}
	if(step<mudi){
		for(int i=1;i<=n;i++) {
			if(v[i]==0){
				v[i]=1;
				dfs(step+1,mudi,sumly+a[i],max(zd,a[i]));
				v[i]=0;
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=3;i<=n;i++){
		dfs(1,i,0,0);
	}
	cout<<cnt;
	return 0;
} 
