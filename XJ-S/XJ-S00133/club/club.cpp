#include <bits/stdc++.h>
using namespace std;
int d[100010];
int diff[100010];
int n;
int ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans+=1;
			if(ans==n/2){
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans+=1;
			if(ans==n/2){
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans+=1;
			if(ans==n/2){
				break;
			}
		}
	}
	cout<<ans<<endl; 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
