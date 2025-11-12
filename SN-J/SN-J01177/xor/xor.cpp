#include<bits/stdc++.h>
const int N=500005;
using namespace std;
int n,k,a[N],ans=0,r=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	for(int i=1;i<=n;i++)
	    if(a[i]==1) ans+=1;
	if(k==1){
		int x=0;
		for(int i=1;i<=n;i+=2){
		    x+=ans,ans-=2;
		    if(ans<=0) break;
		}
		cout<<x;
	}else if(k==0) cout<<0;
	return 0;
}
