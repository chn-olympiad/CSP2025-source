#include<bits/stdc++.h>
using namespace std;
int ans,t,n,a1[100005],a2[100005],a3[100005],a11,a22,a33;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		for(int i=1;i<=n;i++){
			if(max(a3[i],max(a1[i],a2[i]))==a1[i]&&a11<n/2){
				ans+=a1[i];
				a11++;
			}
				else if(max(a3[i],max(a1[i],a2[i]))==a2[i]&&a22<n/2){
				ans+=a2[i];
				a22++;
			}
				else if(max(a3[i],max(a1[i],a2[i]))==a3[i]&&a33<n/2){
				ans+=a3[i];
				a33++;
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 