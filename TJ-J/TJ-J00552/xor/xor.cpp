#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
		if(a[i]^a[j]==k){
			ans++;
		}
		else if(a[i]==k){
			ans++;
		}
		else if(a[i]^a[j]^a[j+1]==k){
			ans++;
		}
		else if(a[i]^a[j]^a[j+1]^a[j+2]==k){
			ans++;
		}
		else if(a[i]^a[j]^a[j+1]^a[j+2]^a[j+3]==k){
			ans++;
		}
	}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
