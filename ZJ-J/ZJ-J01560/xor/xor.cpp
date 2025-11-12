#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,a[500050],cct,jl;
bool flag=0;
//不会用dp啊！！！ 
//太难了！！！:( 
//明年能不能出简单点:)嘻嘻 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		ll numr=a[i];
		if(a[i]==k){
			cct++;
			//cout<<cct<<" ";
			continue;
		}
		for(ll j=i+1;j<=n;j++){
			numr=numr^a[j];
			if(numr==k){
				jl=j,flag=1;
				cct++;
				//cout<<cct<<"ada ";
				break;
			}
		}
		if(flag){
			i=jl;
			flag=0;
		}
	}
	cout<<cct;
	
	return 0;
}
