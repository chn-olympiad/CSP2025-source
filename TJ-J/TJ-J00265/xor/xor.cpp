#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005]; 
bool v[500005];
int ans=0;
int add(int l,int r){
	int cnt=0;
	for(int i=l;i<=r;i++){
		cnt^=a[i];
		if(v[i]) return -100;
	}
	return cnt;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int m=1;m<=n;m++){
		for(int i=1;i+m-1<=n;i++){
			if(add(i,i+m-1)==k){
				ans++;
				for(int j=i;j<=i+m-1;j++){
					v[j]=1;
				}
			}
		}
	}
	cout<<ans;
    return 0;
}
