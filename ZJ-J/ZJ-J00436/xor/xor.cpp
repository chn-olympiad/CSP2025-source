#include<bits/stdc++.h>
#define ll long long
using namespace std;
void fre(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
}
int _xor[2097152],ans[500010],n,now,x,k;
int main(){
	fre();
	cin>>n>>k;
	_xor[0]=1;
	for(int i=2;i<=n+1;i++){
		cin>>x;
		now=now^x;
		ans[i]=ans[i-1];
		if(_xor[now^k]!=0)ans[i]=max(ans[i],ans[_xor[now^k]]+1);
		//cout<<i<<" "<<ans[i]<<" "<<now<<" "<<_xor[now^k]<<endl;
		_xor[now]=i;
		//cout<<now<<" "<<(now^k)<<" "<<_xor[now^k]<<endl;
	}
	cout<<ans[n+1];
	return 0;
}
