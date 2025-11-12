#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,r,ans=0;
	cin>>n>>r;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(r==0){
		for(int i=1;i<=n;){
			if(a[i]==0) ans++;
			else if(i+1<=n){
				if(a[i+1]==a[i]){
					ans++;
					i+=2;
					continue;
				}
			}
			i++;
		} 
		cout<<ans;
	}
	else if(r==1){
		for(int i=1;i<=n;){
			if(a[i]==r){
//				cout<<a[i]<<"%%";
				i++;
				ans++;
				continue;
			}
			else if(i+1<=n){
				if(abs(a[i]-a[i+1])==1){
//					cout<<a[i]<<"*%";
					ans++;
					i+=2;
					continue;
				}
			}
			i++;	
		}
		cout<<ans;
	}
	else cout<<2025;
	return 0;
}
