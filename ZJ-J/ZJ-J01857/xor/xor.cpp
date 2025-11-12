#include<bits/stdc++.h>
using namespace std;
long long a[500010],b[500010];
int n;
long long k,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cin>>a[1];
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]^b[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int t=0;
			if(i==1){
				t=b[j];
			}
			else{
				t=b[i-1]^b[j];
			}
			if(t==k){
				ans++;
				cout<<i<<" "<<j<<" "<<t<<endl;
				i=j+1;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
