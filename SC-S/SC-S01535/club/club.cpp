#include <bits/stdc++.h>
using namespace std;
long long t;
struct pp{
	long long a,b,c;
	bool d;
	long long cz;
};
bool cmp(pp z,pp y){
	return z.cz>y.cz;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		pp A[200000];
		long long cnt=0;
		bool x=1;
		bool c=1;
		long long mx=-1e9;
		for(int i=1;i<=n;i++){
			cin>>A[i].a>>A[i].b>>A[i].c;
			A[i].cz=A[i].a-A[i].b;
			mx=max(mx,A[i].a);
			if(A[i].b!=0){
				x=0;
			}else if(A[i].c!=0){
				x=0,c=0;
			}
		}
		if(x){
			cout<<mx<<endl;;
			continue;
		}
		cout<<0<<endl;
		
	}
	fclose(stdin);
	fclose(stdout);


	return 0;
}
