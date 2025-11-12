#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+7;
int n,k;
int a[maxn];
int ans;
int f(int a,int b){
	if(a==0)return b;
	if(b==0)return a;
	int n=max(a,b);
	int ans=0,num=0;
	while(n){
		int x=a%2,y=b%2;
		if(x!=y)ans+=pow(2,num);
		num++;
		a/=2;
		b/=2;
		n/=2;
	}
	return ans;//异或运算
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	int start=1,end=n;
	a[n+1]=k;
	for(int i=1;i<=n+1;i++){
		if(i<=n)cin>>a[i];
		if(a[i]==k){//从start到end
			ans++;
			end=i-1;
			//cout<<i<<endl;
			for(int j=start;j<end;j++){
				if(f(a[j],a[j+1])==k){
					ans++;
					j++;
				}
				if(j<=end-2&&f(a[j+1],a[j+2])!=k)a[j+1]=f(a[j],a[j+1]);
			}//如果遇到[2,3]这种就得G
			start=i+1;
		}
	}
	cout<<ans-1;
	return 0;
}