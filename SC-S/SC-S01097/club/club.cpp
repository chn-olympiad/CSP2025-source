#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],b[N],c[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		bool checkA=true,checkB=true;
		int n;
		cin>>n;
		int maxx=n/2,ans=0;//最大人数 
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0||c[i]!=0) checkA=false;
		}
		if(checkA==true){
			sort(a+1,a+n+1,greater<int>());
			for(int i=1;i<=maxx;i++)
				ans+=a[i];
		}
		cout<<ans<<endl;
	}
} 