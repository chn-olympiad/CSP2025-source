#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans;
bool op;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)op=1;
	}
	if(op==0){
		cout<<n/2;
	}else{
		for(int i=1;i<=n;i++){
			int now=a[i];
			bool flag=0;
			for(int j=i-1;j>=1;j--){
				flag=1;
				now^=a[j];
				if(now==k)ans++;
			}
			if(now==k&&flag==0)ans++;
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
}