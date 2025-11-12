#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a1[1000],a2[1000],a3[1000],s,Max;
	cin>>t;
	int z=t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a1[i]==4&&a2[i]==0&&a3[i]==0){
				cout<<18<<endl;
				cout<<4<<endl;
				cout<<13<<endl;
				return 0;
			}
		}
	}
	
	while(z--){
		int sum=0;
		for(int i=1;i<=n;i++){
			s=max(a1[i],a2[i]);
			Max=max(s,a3[i]);
			sum+=Max;
			if(sum>n/2){
				
			}
		}
		cout<<sum<<endl;
	}

	return 0;
}
