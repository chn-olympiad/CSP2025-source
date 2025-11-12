#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int b[500010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]^b[i-1];
	}
	int i=1,j=1,ans=0,la=1;
	while(i<=n&&j<=n){
		int h=b[j]^b[i-1];
		if(h==k){
			ans++;
			i=j+1;
			j+=1;
			la=i;
			
		}
		else if(i==j){
			j++;
			i=la;
		}
		else{
			i++;
		}
		
	}
	cout<<ans;
	return 0;
}

