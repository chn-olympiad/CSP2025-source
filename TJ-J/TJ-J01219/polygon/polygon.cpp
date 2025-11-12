#include<bits/stdc++.h>
#define ll long long
ll n,a[5005]={},cnt=0,box[5005]={};
void pai(ll num,ll xia){
	
	if(num>3)
	{
		if(box[num-1]>(box[num-1]-box[num-2])*2){
			cnt++;
		}
	}
	if(num>n) return ;
	for(ll i=xia;i<=n;i++){
		box[num]=a[i]+box[num-1];
		pai(num+1,i+1);	
	}return;
	
}
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	pai(1,1);
	cout<<cnt%998244353;
	return 0;
}
