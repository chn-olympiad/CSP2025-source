#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,i,a[200001],flag,f[200001],ans,cnt,sum,b[200001],s,t;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(i=1;i<=n;i++)cin>>a[i];
	if(n==1){
		if(a[1]==k){
			cout<<1;
			return 0;
		}
		else {
			cout<<0;
			return 0;
		}
	}
	for(i=1;i<=n-1;i++)
		if(a[i]!=a[i+1])flag=1;
	if(flag==0){
		if(k==0)cout<<n/2;
		else {
			if(a[1]==k)cout<<n;
			else cout<<0;
		}
	}
	else{
		for(i=1;i<=n;i++)f[a[i]]++;
		if(f[0]+f[1]==n)flag=2;
		if(flag==2){
			if(k==1)cout<<f[1];
			else{
				if(k==0){
					for(i=1;i<=n;i++){
						if(a[i]==0)continue;
						else if(a[i]==1&&a[i+1]==1)ans++,i++;
					}
					cout<<f[0]+ans;
				}
				else{
					cout<<0;
				}
			}
		}
		else{
			for(i=1;i<=n;i++)
				if(a[i]==k)cnt++,b[i]=-2e9;
			for(i=1;i<=n;i++){
				s=0;t=i;
				while(t<=n){
					if(b[t]!=-2e9)s=(s^a[t]);
					else i=t,t=n+1;
					if(s!=k)t++;
					else i=t,t=n+1,sum++;
				}
			}
			cout<<cnt+sum;
		}
	}
}

/*
100 1
1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 
0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 
1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 
1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1
0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1
 
63
#Shang4Shan3Ruo6Shui4
*/
