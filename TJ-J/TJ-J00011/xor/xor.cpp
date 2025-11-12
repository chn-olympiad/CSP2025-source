#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6;
int n,k,num;
ll a[N],b[N],c[N],d[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			num++;
			b[i]=1;
		}c[i]=a[i];
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			if(b[j+i-1]||c[j]==-1||b[j]){
				c[j]=-1;
				continue;
			}
			c[j]=c[j]^a[j+i-1];
			if(c[j]==k){
				num++;
				for(int kk=0;kk<=j;kk++){
					b[j-i+1+kk]=1;
					b[j+kk]=1;
					b[j+i-1+kk]=1;
					c[j-i+1+kk]=-1;
					c[j+kk]=-1;
					c[j+i-1+kk]=-1;
				}
			}
		}
	}cout<<num;
	return 0;
}
