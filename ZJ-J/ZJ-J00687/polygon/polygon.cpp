#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int ans;
int a[1000001];
void f(int cnt,int mx,int k,int num,int flag[]){
	if(k==n){
		if(num>=3){
			if(cnt>mx*2){
				ans++;
//				cout<<num<<endl;
//				for(int i=0;i<n;i++){
//					cout<<flag[i]<<' ';
//				}
//				cout<<endl;
			}
		}
		return;
	}
	if(k==n){
		return;
	}
	flag[k]=1;
	f(cnt+a[k],max(a[k],mx),k+1,num+1,flag);
	flag[k]=0;
	f(cnt,mx,k+1,num,flag);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	int q[10001]={0};
	f(0,0,0,0,q);
	printf("%lld\n",ans%998244353);
	
	
	return 0;
}
