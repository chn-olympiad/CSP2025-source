#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans;
bool flag=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=false;
	}
	if(k==0&&flag){
		cout<<n/2;
		return 0;
	}
	int t=0,l=1,r=1;
	while(l<=n){
		while(r<=n){
			t^=a[r];
			if(t==k){
				ans++;
				t=0;
				break;
			}
			r++;
		}
		l=r+1;
		r=l;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
