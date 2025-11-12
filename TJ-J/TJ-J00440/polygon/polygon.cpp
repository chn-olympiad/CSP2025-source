#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[5005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int cnt1,cnt2,cnt3;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				int maxl=max(a[i],max(a[j],a[k]));
				if(a[i]+a[j]+a[k]>2*maxl){
					cnt1++;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				for(int b=k+1;b<n;b++){
					int maxl=max(a[i],max(a[j],max(a[b],a[k])));
				    if(a[i]+a[j]+a[k]+a[b]>2*maxl){
					    cnt2++;
				    }
				}
				
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				for(int b=k+1;b<n;b++){
					for(int c=b+1;c<n;c++){
						int maxl=max(a[i],max(a[j],max(a[b],max(a[k],a[c]))));
				        if(a[i]+a[j]+a[k]>2*maxl){
					        cnt3++;
				        }
					}
				}
				
			}
		}
	}
    if(n==3) cout<<cnt1;
    if(n==4) cout<<cnt1+cnt2;
    if(n==5)
	cout<<cnt1+cnt2+cnt3;
	return 0;
} 
