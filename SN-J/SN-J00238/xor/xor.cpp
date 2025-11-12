#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long cnt,yh;
long long l = 1,r = 1;
long long a[5000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i = 1;i<=n;i++){
		cin>>a[i];
	}
	while(l < (n+1)){
		for(long long i = l;i<=r;i++){
			yh = yh^a[i];
		}
		if(yh == k){
			cnt++;
			r++;
			l = r;
			yh = 0;
		}
		else{
			if(r == n){
				l++;
				r = l;
				yh = 0;
			}
			else{
				r++;
			}
		}
	}
	cout<<cnt;
}
