#include<bits/stdc++.h>
using namespace std;
int n,ans=0,vis[10005],f=1;
unsigned long long a[1005],k;
unsigned long long ss(int x,int y){
	unsigned long long sum=a[x];
	for(int i=x+1;i<=y;i++){
		sum=(sum^a[i]);
	}return sum;
}
bool pd(int x,int y){
	for(int i=x;i<=y;i++){
		if(vis[i]==1)return 0;
	}return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0&&a[i]!=1)f=0;
	}
	if(f==1&&n>=5000){
		if(k==0){
			for(int i=2;i<=n;i++){
				if(a[i]!=a[i-1]){
					ans++;
				}
			}cout<<ans;
		}else if(k==1){
			int r=a[1];
			while(n>=1){
				if(a[n]!=a[1]){
					cout<<n;
					break;
				}				
				n--;
			}
		}return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=n;j>=i;j--){
			long long q=ss(i,j);
			if(q==k&&pd(i,j)){
				ans++;
				for(int p=i;p<=j;p++){
					vis[p]=1;
				}
			}
		}
	}cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
