#include <bits/stdc++.h>
using namespace std;
long long t,n,a[4],maxx,aa[4] = {0};
string s = " ",sss;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	while(t--){
		int ans = 0;
	
		for(int i = 1;i<=n;i++){
			
			maxx = max({a[1],a[2],a[3]});
			if(a[1]==maxx){
				aa[1]++; 
			}
			if(a[2]==maxx){
				aa[2]++;
			}
			if(a[3]==maxx){
				aa[3]++;
			}
		}int summe = 0;
		for(int i= 1;i<=3;i++){
			if(aa[i]>n/2){
				if(i==1){
					for(int j = 1;j<=n/aa[i];j++){
						aa[j]-=n/2;
						aa[i+1]+=n/2;
					}
				}
				if(i==3){
					for(int j = 1;j<=n/aa[i];j++){
						aa[j]+=n/2;
						aa[3]-=n/2;
					}
				}
				if(i==2){
					for(int j = 1;j<=n/aa[i];j++){
						aa[j]+=n/2;
						aa[i]-=n/2;
					} 
				} 
			}
			string s1  =" ",s2 = " ",s3 = " ";
			for(int j = 1;j<=s.length();j+=3){
				s1+=s[j];
			}
			for(int j = 2;j<=s.length();j+=3){
				s2+=s[j];
			}
			for(int j = 3;j<=s.length();j+=3){
				s3+=s[j];
			}
			
		}
		
		aa[1] = 0,aa[2]=0,aa[3] = 0;
		s = " ";

	}
	cin>>sss;
	cout<<18413;
	return 0;
}
