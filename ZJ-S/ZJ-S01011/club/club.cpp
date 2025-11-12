#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdout);
	cin>>t;
	while(t--){
		int n;
		long long ans=0;
		cin>>n;
		vector<int>a;
		vector<int>b;
		vector<int>c;
		int k[3];
		for(int i=0;i<n;i++){
			cin>>k[0]>>k[1]>>k[2];			
			if(k[0]>=k[1]&&k[0]>=k[2]){
				a.push_back(min(k[0]-k[1],k[0]-k[2]));
				ans+=k[0];
			}else if(k[1]>=k[0]&&k[1]>=k[2]){
				b.push_back(min(k[1]-k[0],k[1]-k[2]));
				ans+=k[1];
			}else{
				c.push_back(min(k[2]-k[0],k[2]-k[1]));
				ans+=k[2];
			}			
		}int aa=a.size(),bb=b.size(),cc=c.size();
		sort(&a[0],&a[aa]);
		sort(&b[0],&b[bb]);
		sort(&c[0],&c[cc]);
		for(int i=0;i<aa-n/2;i++){
			ans-=a[i];
		}for(int i=0;i<bb-n/2;i++){
			ans-=b[i];
		}for(int i=0;i<cc-n/2;i++){
			ans-=c[i];
		}cout<<ans<<'\n';
	}
	return 0;
}
