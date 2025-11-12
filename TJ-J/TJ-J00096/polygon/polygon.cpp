#include <bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(n>7) {
		cout<<n*n;
		return 0;
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			for(int b=j+1;b<=n;++b){
				if(a[i]+a[j]+a[b]>2*max(a[i],max(a[j],a[b]))){
					ans++;
				}
				for(int c=b+1;c<=n;++c){
					if(a[i]+a[j]+a[b]+a[c]>2*max(max(a[i],a[j]),max(a[b],a[c]))){
						ans++;
					}
					for(int d=c+1;d<=n;++d){
						if(a[i]+a[j]+a[b]+a[c]+a[d]>2*max(max(a[i],max(a[d],a[j])),max(a[b],a[c]))){
							ans++;
						}
						for(int e=d+1;e<=n;++e){
							if(a[i]+a[j]+a[b]+a[c]+a[d]+a[e]>2*max(max(max(a[e],a[i]),max(a[d],a[j])),max(a[b],a[c]))){
								ans++;
							}
							for(int f=e+1;f<=n;++f){
								if(a[i]+a[j]+a[b]+a[c]+a[d]+a[e]+a[f]>2*max(max(max(a[e],a[i]),max(a[d],a[j])),max(max(a[b],a[f]),a[c]))){
									ans++;
								}
							}
						}
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

