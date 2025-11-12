#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	short t=0;
	cin>>t;
	for(int i=0;i<t;i++){
		short n=0;cin>>n;
		short m1[n],m2[n],p[n];
		short timely=0;
		int ans=0;
		for(int j=0;j<n;j++){
			cin>>m1[j]>>m2[j]>>p[j];
		}
		for(int j=0;j<n-1;j++){
			if (m1[j]>m1[j+1]){
				timely=m1[j+1];m1[j+1]=m1[j];m1[j]=timely;
			}
		}
			for(int j=n-1;j>=n/2;j--){
				ans+=m1[j];
				}
			cout<<ans<<endl;
	}
	return 0;
}
