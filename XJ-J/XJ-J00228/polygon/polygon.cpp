#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[5005],f[5005],c[5005];
long long qpl(long long end,long long cnt){
	if(cnt==end){
		int sum=0,maxn=0,flag=1;
		for(int i=1;i<=cnt;i++){
			if(c[i]==0){
				flag=0;
				break;
			}
			if(i!=1&&c[i]<c[i-1]){
				flag=0;
				break;
			}
			sum+=c[i];
			maxn=max(maxn,int(c[i]));
		}
		//if(flag==1)for(int i=1;i<=cnt;i++)cout<<i<<" "; 
		//if(flag==1)cout<<endl;
		if(flag==1&&sum>(maxn*2)){
			//cout<<maxn<<endl;
			ans++;
		}
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			f[i]=1;
			cnt++; 
			c[cnt]=a[i];
			qpl(end,cnt);
			f[i]=0;
			c[cnt]=0;
			cnt--; 
		}
	}
} 

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=3;i<=n;i++)qpl(i,0);
	cout<<ans<<endl;
	return 0;
}
