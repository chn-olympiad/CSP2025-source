#include<bits/stdc++.h>//< £¤¡Ñ
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define OpenFile(_) freopen(#_ ".in","r",stdin);freopen(#_ ".out","w",stdout)
typedef long long Int;

Int n,k,a,sum=0,lst[2000005],ans=0,pos=0;

int main(){
	IOS;OpenFile(xor);

	cin>>n>>k;
	memset(lst,-1,sizeof lst);
	lst[0]=0;
	for(Int i=1;i<=n;i++){
		cin>>a;
		sum^=a;
		if(lst[sum^k]>=pos)pos=i,++ans;
		lst[sum]=i;
	}
	cout<<ans<<endl;

	return 0;
}

