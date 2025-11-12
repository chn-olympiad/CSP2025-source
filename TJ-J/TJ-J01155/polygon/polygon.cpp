#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N],ans,b[N];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==3){
		if(a[3]<a[2]+a[1]){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(int i=n;i>=2;i--){
		for(int j=i-1;j>=1;j--){
			if(b[j]>a[i]){
				ans++;
				for(int k=i;k>=2;k--){
					if(b[j]-a[k]>a[i]){
						ans++;
					}
					for(int w=1;w<=k-2;w++)
						if(b[j]-b[k-1]+b[w]>a[i]){
							ans++;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
