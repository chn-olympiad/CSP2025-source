#include<bits/stdc++.h>
using namespace std;
int n,a[6000];
long long cnt;
/*void dfs(int t){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[i]+a[j]+a[k]>2*max(a[i],max(a[j],a[k]))){
					cnt++;
				}
			}
		}
	}
}*/
int ls[6000];
void dfs(int t,int d){
	if(d>t){
		int m=0,s=0;
		for(int i=1;i<t;i++){
			m=max(a[ls[i]],a[ls[i+1]]);
			s+=a[ls[i]];
		}
		s+=a[ls[t]];
		if(s>2*m){
			cnt++;
			/*for(int i=1;i<=t;i++)cout<<ls[i]<<" ";
			cout<<"sum="<<s<<" max="<<m<<endl;*/
		}
		return;
	}
	for(int i=ls[d-1]+1;i<=n;i++){
		ls[d]=i;
		dfs(t,d+1);
		ls[d]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=3;i<=n;i++)dfs(i,1);
	cout<<cnt%998244353;
	return 0;
}
