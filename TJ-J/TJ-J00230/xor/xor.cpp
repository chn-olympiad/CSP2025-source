#include <bits/stdc++.h>
using namespace std;
int n,k,ans,a[500005];
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cin>>n>>k;
for(int i=1;i<=n;i++){
	cin>>a[i];
	if(a[i]==k){
		ans++;
		a[i]=-1;
	}
}
int x=1,y=0,i=1;
while(true){
	if(x>n or i+x>n){
		break;
	}
	if(a[i]<0){
		i++;
		continue;
	}
	int s=a[i];
	y=i+x;
	for(int j=i+1;j<=y;j++){
		if(a[j]==-1){
			i=j;
			x=0;
			break;
		}
		s=s^a[j];
		if(s==k){
			a[j]=-1;
			i=j;
			ans++;
			break;
		}
	}
	x++;
}
cout<<ans;
return 0;
}
