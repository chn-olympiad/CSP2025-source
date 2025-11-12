#include<bits/stdc++.h>
#include<iostream>
using namespace std;
struct cy{
	int bm1,bm2,bm3;
};
const int N=1e5+10;
cy arr[N];
bool cmp(cy x,cy y){
	return x.bm1>y.bm1;
}
int ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int a=1;a<=n;a++)
			cin>>arr[a].bm1>>arr[a].bm2>>arr[a].bm3;
		if(n==2){
			int mm1=max(arr[1].bm1+arr[2].bm2,arr[1].bm1+arr[2].bm3);
			int mm2=max(arr[1].bm2+arr[2].bm1,arr[1].bm1+arr[2].bm3);
			int mm3=max(arr[1].bm3+arr[2].bm2,arr[1].bm1+arr[2].bm1);
			cout<<max(mm1,max(mm2,mm3));
			return 0;
		}
		for(int a=1;a<=n;a++){
			if(arr[a].bm2||arr[a].bm3){
				break;
			}
			else{
				sort(arr+1,arr+n+1,cmp);
				for(int a=1;a<=n/2;a++)
					ans+=arr[a].bm1;
				cout<<ans;
				
			}
				
		}	
			
	} 
	return 0;
} 
