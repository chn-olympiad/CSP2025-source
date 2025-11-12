#include<bits/stdc++.h>
using namespace std;
const int MAX=500010;
long long q[MAX],n,k,a[MAX],ans,mxr;
int main(){
	cin.tie(0);
	cout.tie(0); 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q[i]=q[i-1]^a[i];
	}
	for(long long  i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			long long flag=q[j]^q[i-1];
			if(k==flag){
				if(i>mxr){
					ans++;	
					mxr=j;
				}else{
					mxr=min(mxr,j);
				}
				
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
