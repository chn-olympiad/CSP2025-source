#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
long long n,ks,f[N],si=0,zero=0,qian[N];
struct l{
	int s,e;
}que[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>ks;
	for(int i=1;i<=n;i++){
		cin>>f[i];
		if(f[i]==1){
			zero++;
		}
	}
	if(zero==n){
		if(ks==0){
		 cout<<n/2;
		}
		else{
			cout<<n;
		}
	}
	else{
		int l=1,r=1,sum=f[1];
		for(int i=1;i<=n;i++){
			qian[i]=qian[i-1]^f[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(int(qian[i]^qian[j-1])==ks){
					que[++si].e=i;
					que[si].s=j;
					/*int s=qian[i]^qian[j-1];
					cout<<s;*/
				}
			}
		}
		int sp=0,ans=0;
		for(int i=1;i<=si;i++){
			if(que[i].s>sp){
				ans++;
				sp=que[i].e;
			}
	}
	cout<<ans<<endl;
	}
	
	return 0;
}
/*4 0
2 1 0 3*/
