#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
int m,n,a[1010],b[1010];
long long ans;
void op(int x,int y){
	if(n-y==x || x==0){
		ans+=1;
		ans%=998244353;
		return;
	}
	if(a[y]-y+(m-x)<0){
		op(x,y+1);
		return;
	}else{
		op(x,y+1);op(x-1,y+1);
	}
	
	
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	ans=0;
	op(m,1);
	cout<<ans;
	return 0;
} 
