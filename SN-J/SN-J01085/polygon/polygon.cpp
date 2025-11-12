//SN-J01085  闫卜予  西安高新一中沣东中学初中校区 

#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

ll a[5140];
ll n;
ll ans;
int c[5555],cnt;
void fun(int k,int las,ll sum,int t){
	
	if(t==k){
		if(sum>2*a[las]){
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int i=las+1;i<=n;i++){
		c[++cnt]=a[i];
		fun(k,i,sum+a[i],t+1);
		cnt--;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		fun(i,0,0,0);
		cnt=0;
	}
	cout<<ans;
	return 0;
}
