#include<bits/stdc++.h>
using namespace std;
int a[500050],n,ans;
bool f[500050];
long long d,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int j=i;
		d=0;
		while(j>=1&&f[j]==false){
			d=d^a[j];
			j--;
			if(d==k){
				ans++;
				f[i]=true;
				break;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
