#include<bits/stdc++.h>
using namespace std;

const int maxn=500005;
int n,k;
int a[maxn];
int sum,ans;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int op=0,oo=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)op=1;
		if(a[i]!=1&&a[i]!=0)oo=1;
	}
	if(!op){
		cout<<n/2;
		return 0;
	}
	if(!oo){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0)ans++;
				else{
					if(a[i+1]==1){
						ans++;
						i++;
					}
				}
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==1)ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	
	return 0;
}
