#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans,num[500005],num0,num1,vis[500005];
long long fun(long long x,long long y){
	int ax[30],ay[30];
	long long rx=x,ry=y;
	int lenx=0,leny=0;
	memset(ax,0,sizeof(ax));
	memset(ay,0,sizeof(ay));
	while(rx>0){
		lenx++;
		ax[lenx]=rx%2;
		rx/=2;
	}
	while(ry>0){
		leny++;
		ay[leny]=ry%2;
		ry/=2;
	}
	long long j=1,w=0;
	for(int i=1;i<=max(lenx,leny);i++){
		if(ax[i]!=ay[i]) w+=j;
		j*=2;
	}
	return w;
}
map<int,int>mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]==0) num0++;
		if(a[i]==1) num1++;
	}
	if(num1==n){
		cout<<n/2;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(num1+num0==n){
		ans=0;
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans++;
				}else{
					if(a[i+1]==0){
						ans++;
						i++;
					}
				}
			} 
			cout<<ans;
		} else{
			cout<<num1;
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<=n-i;j++){
			if(mp[j+i]==1){
				vis[j]=1;
				continue;
			}
			if(vis[j]==1) continue;
			num[j]=fun(num[j],a[j+i]);
			if(num[j]==k){
				ans++;
				for(int kk=j;kk<=j+i;kk++){
					vis[kk]=1;
					mp[kk]=1;
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
