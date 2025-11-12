#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	for(int i=0;i<t;i++){
		int n,c1=0,c2=0,c3=0;
		int ans=0;
		cin>>n;
		int l[n][3]={0},m[n]={0};
		for(int j=0;j<n;j++){
			cin>>l[j][0]>>l[j][1]>>l[j][2];
			m[j]=max(l[j][0],max(l[j][1],l[j][2]));
		}
		for(int j=0;j<n;j++){
			int b=0,b1=0;
			for(int k=0;k<n;k++){
				if(m[k]>b){
				b=m[k];b1=k;
				}
			}
			if(l[b1][0]==b && c1<=n/2){
				ans+=b;m[b1]=0;c1++;
			}
			else if(l[b1][1]==b && c2<=n/2){
				ans+=b;m[b1]=0;c2++;
			}
			else if(l[b1][2]==b && c3<=n/2){
				ans+=b;m[b1]=0;c3++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
