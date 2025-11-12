#include<bits\stdc++.h>
using namespace std;
const int N=5e5+10;
int q[N];
int isyihuo(int a,int b){
	if(a==b)return a;
	int c=a^b;
	return c;
}
int isqujian(int l,int r){
	int a,b,c;
	c=q[l];
	for(int i=l+1;i<=r;i++){
		a=c;
		b=q[i];
		c=isyihuo(a,b);
	}
	return c;
}
int n,k;
int main(){
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	cin>>n>>k;
	int ans=0;
	for(int i=1;i<=n;i++)
		cin>>q[i];
	int lt=1,rt;
	while(lt<=n){
		rt=lt;
		int flag=0;
		while(rt<=n){
			if(isqujian(lt,rt)==k){
				ans++;
				flag=1;
				lt=rt+1;
				break;
			}
			rt++;
		}
		if(flag==0)lt++;
	}
	cout<<ans;
	return 0;
}
/*
10 55
190 149 51 20 174 185 40 20 48 189
*/
