#include<bits/stdc++.h>
using namespace std;
int n,k;
int ans;
int a[500010];
int e[25];
int z[25];
int z2[25];
int f[500010][25];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	int s=1;
	while(k){
		if(k&1)e[s]=1;
		k>>=1,s++;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int j=1;
	    while(a[i]){
	    	if(a[i]&1)f[i][j]=1;
	    	a[i]>>=1,j++;
		}
	}
	int l=1,r=1;
	while(l<=r&&r<=n){
		for(int i=1;i<=20;i++){
			z[i]^=f[r][i];
		}
		int flag=1;
		for(int i=1;i<=20;i++){
			if(z[i]!=e[i])flag=0;
		}
		if(flag){
			ans++,l=r+1;
			for(int i=1;i<=20;i++)z[i]=0;
		}
		else{
			int l2=l;
			for(int i=1;i<=20;i++){
				z2[i]=z[i];
			}
			while(l2<r){
				for(int i=1;i<=20;i++){
					z2[i]^=f[l2][i];
				}
				int flag1=1;
				for(int i=1;i<=20;i++){
					if(z2[i]!=e[i])flag1=0;
				}
				if(flag1){
					ans++,l=r+1;
					for(int i=1;i<=20;i++)z[i]=0;
					break;
				}
				l2++;
			}
		}
		r++;
	}
	cout<<ans;
	return 0;
}