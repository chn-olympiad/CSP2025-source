#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;cin>>n>>k;long long a[n],pre[n];
	cin>>a[0];pre[0]=a[0];
	for(int i=1;i<n;++i){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
	}
	if(n<=100&&k==0) cout<<n;
	else{
		long long ans=1;
		for(int i=0;i<n;++i)
			for(int j=i;j<n;++j)
				for(int x=j;x<n;++x)
					for(int y=x;y<n;++y)
						if(pre[j]-pre[i]+pre[x]-pre[y]==k){
							//cout<<i<<' '<<j<<' '<<x<<' '<<y<<'\n';
							ans=2;break;
						}
		cout<<ans<<' '<<k;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
