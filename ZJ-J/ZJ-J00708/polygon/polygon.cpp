#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,k,a[1000010],f1,f10,g=1;
int f(int c,int d,int ma,int zh,int sl){
	if(sl>c){
		if(zh>ma*2)return 1;
		else return 0;
	}int sum=0;
	for(int i=d+1;i<=n;i++){
		sum+=f(c,i,max(ma,a[i]),zh+a[i],sl+1);
	}
	return sum;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f1=1;
	}
	if(!f1){
		int s=0,r=1;
		for(int i=3;i<=n;i++){
			for(int j=1;j<=i;j++){
				r*=(n-j+1);
				r/=j;
			}
			s+=r;
			r=1;
		}
		cout<<s;
	}else if(n==3){
		if(max(a[1],max(a[2],a[3]))*2<a[1]+a[2]+a[3])cout<<1;
		else cout<<0;
	}else{
		int s=0;
		for(int i=3;i<=n;i++){
			s+=f(i,0,0,0,1);
		}
		cout<<s;
	}
	return 0;
}
