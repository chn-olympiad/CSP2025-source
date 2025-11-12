#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,ans,a[N];
bool vis[N];//标记 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k) ans++,vis[i]=1;
	}
	
	for(int i=1;i<n;i++){
		int s=a[i];
		vis[i]=1; //有没有都要标记，不来了 
		for(int j=i+1;j<=n;j++){
			if(vis[j]) break;
			s^=a[j];
			if(s==k){
//				cout<<i<<" "<<j<<"\n";
				i=j;
				for(int k=i+1;k<=j;k++) vis[k]=1;//已经来过 
				ans++;
				break;
			}
		}
	}
	cout<<ans<<"\n";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
