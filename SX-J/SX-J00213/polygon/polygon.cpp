#include <bits/stdc++.h>
using namespace std;

const int MAX=5e3+5;

int n;
int a[MAX];
int f[MAX],m[MAX];
int num=0,mod=998244353;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	ios::sync_with_stdio(0);

    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
    	f[i]=f[i-1]+a[i];
	}

    for(int i=2;i<=n;i++){
    	for(int j=i;j<=n;j++){
    		for(int p=1;p<=n;p++){
    			if(p>=j-i&&p<=j) continue;
    			int mm=max(a[p],a[j]);
               if(f[j]-f[j-i]+a[p]>2*mm){
               	num++;
               	num%=mod;
//               	cout<<j-i<<" "<<j<<" "<<p<<endl;
			   }
			}
		}
	}
//	cout<<f[n];
	if(f[n]>2*a[n]) num++;
	cout<<num%mod;
	return 0;
}
