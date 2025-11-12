#include<bits/stdc++.h>

using namespace std;


long long bmx[100010],bmy[100010],bmz[100010];
int ans=0;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	while(t--){
		ans=0;
		long long n,a1,a2,a3;
		cin>>n;
		int f1=0,f2=0,f3=0;
		if(n%2!=0){
			continue;
		}
		if(n%2==0){
			for(long long i=1;i<=n;i++){
				cin>>a1>>a2>>a3;
				if(f1!=2&&f2!=2&&f3!=2){
					ans+=max(max(a1,a2),a3);
					if(max(max(a1,a2),a3)==a1) f1++;
					if(max(max(a1,a2),a3)==a2) f2++;
					if(max(max(a1,a2),a3)==a3) f3++;
				}
				if(f1==2&&f2!=2&&f3!=2){
					ans+=max(a2,a3);
					if(max(a2,a3)==a2) f2++;
					if(max(a2,a3)==a3) f3++;
				}
				if(f1!=2&&f2==2&&f3!=2){
					ans+=max(a1,a3);
					if(max(a1,a3)==a1) f1++; 
					if(max(a1,a3)==a3) f3++; 
				}
				if(f1!=2&&f2!=2&&f3==2){
					ans+=max(a2,a1);
					if(max(a2,a1)==a2) f2++;
					if(max(a2,a1)==a1) f1++;
				}
				if(f1==2&&f2==2&&f3!=2){
					ans+=a3;
					f3++;
				}
				if(f1==2&&f2!=2&&f3==2){
					ans+=a2;
					f2++;
				}
				if(f1!=2&&f2==2&&f3==2){
					ans+=a1;
					f1++;
				}
				f1=0,f2=0,f3=0;
			}
		}cout<<ans<<endl;
	}
	return 0;
}
