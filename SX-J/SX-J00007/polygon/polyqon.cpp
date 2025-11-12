#include<bits/stdc++.h>
using namespace std;
int n,m,r,s;
int a[1005],ax[1005],b[15][15];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-2;i++)
		for(int j=i+1;j<=n-1;j++)
			for(int k=j+1;k<=n;k++)
				if((a[i]+a[j]+a[k])/a[k]==2&&(a[i]+a[j]+a[k])%a[k]>0)
					s++;
	for(int p=1;p<=n-3;p++)
		for(int i=p+1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++)
					if((a[p]+a[i]+a[j]+a[k])/a[k]==2&&(a[p]+a[i]+a[j]+a[k])%a[k]>0)
						s++;
	for(int q=1;q<=n-4;q++)
		for(int p=q+1;p<=n-3;p++)
			for(int i=p+1;i<=n-2;i++)
				for(int j=i+1;j<=n-1;j++)
					for(int k=j+1;k<=n;k++)
						if((a[q]+a[p]+a[i]+a[j]+a[k])/a[k]==2&&(a[q]+a[p]+a[i]+a[j]+a[k])%a[k]>0)
							s++;
	for(int x=1;x<=n-5;x++)
		for(int q=x+1;q<=n-4;q++)
			for(int p=q+1;p<=n-3;p++)
				for(int i=p+1;i<=n-2;i++)
					for(int j=i+1;j<=n-1;j++)
						for(int k=j+1;k<=n;k++)
							if((a[x]+a[q]+a[p]+a[i]+a[j]+a[k])/a[k]==2&&(a[x]+a[q]+a[p]+a[i]+a[j]+a[k])%a[k]>0)
								s++;
	cout<<s;
    return 0;
}