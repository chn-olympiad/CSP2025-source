#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,sum1=0,sum2=0,sum3=0,ans=0;
		vector<int> v1,v2,v3;
		cin>>n;
		for(int i=1;i<=n;i++){
			int x,y,z,maxn;
			cin>>x>>y>>z;
			maxn=max(x,max(y,z));
			ans+=maxn;
			if(x==maxn){
				sum1++,v1.push_back(x-max(y,z));
			}
			else if(y==maxn){
				sum2++,v2.push_back(y-max(x,z));
			}
			else{
				sum3++,v3.push_back(z-max(x,y));
			}
		}
		if(sum1*2>n){
			sort(v1.begin(),v1.end());
			int len=sum1-n/2;
			for(int i=0;i<len;i++){
				ans-=v1[i];
			}
		}
		if(sum2*2>n){
			sort(v2.begin(),v2.end());
			int len=sum2-n/2;
			for(int i=0;i<len;i++){
				ans-=v2[i];
			}
		}
		if(sum3*2>n){
			sort(v3.begin(),v3.end());
			int len=sum3-n/2;
			for(int i=0;i<len;i++){
				ans-=v3[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}