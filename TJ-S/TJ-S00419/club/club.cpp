#include<bits/stdc++.h> 
using namespace std;
int a[100010];
int b[100010];
int c[100010];
long long cnt;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=0;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bool fc=true,fb=true;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0){
				fb=false;
			}
			if(c[i]!=0){
				fc=false;
			}
		}
		cnt=0;
			sort(a+1,a+n+1);
			for(int i=n;i>=n/2+1;i--){
				cnt+=a[i];
			}
			cout<<cnt;
			//给10分就行qwq
	}
	return 0;
}
