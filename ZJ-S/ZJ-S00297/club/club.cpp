#include<bits/stdc++.h>
using namespace std;
struct s{
	int a1;
	int a2;
	int a3;
}b[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		long long cnt=0;
		memset(b,0,sizeof(b));
		int n,sum1=0,sum2=0,sum3=0;
		cin>>n;
		int r=n/2;
		for(int i=1;i<=n;i++) cin>>b[i].a1>>b[i].a2>>b[i].a3;
		for(int i=1;i<=n;i++){
			if(b[i].a1!=b[i].a2&&b[i].a2!=b[i].a3){
				if(b[i].a1==max(b[i].a1,max(b[i].a2,b[i].a3))&&sum1<r){
				    cnt+=b[i].a1;
				    sum1++;
			    }
			    if(b[i].a2==max(b[i].a1,max(b[i].a2,b[i].a3))&&sum2<r){
				    cnt+=b[i].a2;
				    sum2++;
			    }
			    if(b[i].a3==max(b[i].a1,max(b[i].a2,b[i].a3))&&sum3<r){
				    cnt+=b[i].a3;
				    sum3++;
			    }
			}
			
	    }
	    cout<<cnt<<endl;
	}
	return 0;
}
