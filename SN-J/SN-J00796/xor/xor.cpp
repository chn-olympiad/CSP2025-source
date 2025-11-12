#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N];
string b[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for (int i=1;i<=n;i++){
			if (a[i]==1){
				b[i]="01";
			}if (a[i]==0){
				b[i]="00";
			}
	}
	int l=1,r=0,ans=0;
	while(l<n/2){
		r++;
		int res=0;
		if (r>n){
			l++;
			r=l;
		}
		if (r==l){
			res=a[l];
			if (res==k){
				ans++;
			}
		}else{
			for (int i=l;i<=r-1;i++){
				res=0;
				int p=10;
				for (int j=0;j<=1;j++){
					if (b[i][j]==b[i+1][j]){
						res+=0;
					}
					if (b[i][j]!=b[i+1][j]){
						res+=1*p;
					}
					p/=10;
				}
				if (res==k){
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
