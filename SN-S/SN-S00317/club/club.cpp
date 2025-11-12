#include<bits/stdc++.h>
using namespace std;
int t,ad=0,a=0,b=0,c=0;

long long as[100005][15];
long long dp[100005][15];
vector <int> vt1;
vector <int> vt2;
vector <int> vt3;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>as[j][1]>>as[j][2]>>as[j][3];
			int ass;
			if(a>=n/2+1){
				ass=max(as[j][2],as[j][3]);
			}else if(b>=n/2+1){
				ass=max(as[j][1],as[j][3]);
			}else if(c>=n/2+1){
				ass=max(as[j][1],as[j][2]);
			}else{
				ass=max(as[j][1],max(as[j][2],as[j][3]));
			}
		
			if(ass==as[j][1]){
				
				a++;
			}else if(ass==as[j][2]){
				
				b++;
			}else if(ass==as[j][2]){
				
				c++;
			}
			ad+=ass;
		}
		}
		cout<<ad;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
