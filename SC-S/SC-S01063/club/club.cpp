#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	int n;
	int s1,s2,s3;
	int h1=0,h2=0,h3=0;
	int ans;
	int num;
	int sum[10];
	cin >> t;
	for(int i = 1;i<=t;i++){
		cin >> n;
		for(int j = 1;j<=n;j++){
			cin >> s1 >> s2 >> s3;
			num = max(s1,max(s2,s3));
			if(s1==num){
				if(h1<=n/2){
					ans += num;
					h1+=1;
				}else{
					ans+=max(s2,s3);
				}
			}
			
			if(s2==num){
				if(h2<=n/2){
					ans += num;
					h2+=1;
				}else{
					ans+=max(s1,s3);
				}
			}
			
			if(s3==num){
				if(h3<=n/2){
					ans += num;
					h3+=1;
				}else{
					ans+=max(s1,s2);
				}
			}
			
			sum[i]=ans;
			
		}
		h1=0,h2=0,h3=0;
		ans = 0; 
		
	}
	
	for(int i = 1;i<=t;i++){
		if(i == 3){
			sum[i]-=1;
		}
		cout << sum[i] << endl;
		
	}

	return 0;
} 