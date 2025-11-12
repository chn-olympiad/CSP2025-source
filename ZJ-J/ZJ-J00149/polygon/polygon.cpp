#include<bits/stdc++.h>
using namespace std;
int a[5005],ans,n,maxn,num;
bool b[5005];
void f(int x,int y,int z){
	for(int j=z;j<=x;j++){
		if(b[j]==0){
			b[j]=1;
			f(x,y-1,z+1);
		}
		if(x==y){
			maxn=-1,num=0;
			for(int k=1;k<=x;k++){
				if(b[k]==1){
					maxn=max(maxn,a[k]);
					num+=a[k];
					b[k]=0;
				}	
			}
			if(num>2*maxn)ans++;	
			if(ans>=998244353)ans%=998244353;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	freopen("ans.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		f(i,i,1);
	}
	cout<<ans;
	return 0;
}