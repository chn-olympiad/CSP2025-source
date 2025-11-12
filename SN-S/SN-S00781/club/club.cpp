//SN-S00781 ¬нич–щ 
#include <bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}p[100010];
int d[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> p[i].a >> p[i].b >> p[i].c;
		}
		int m=pow(4,n),mx=0;
		for(int i=1;i<=m;i++){
			int cnt_a=0,cnt_b=0,cnt_c=0,sum=0;
			for(int j=0;j<=n;j++){
				int mod=pow(4,j);
				if(i%mod==0){
					d[j+1]=(d[j+1]+1)%4;
				}
				if(d[j+1]==1){
					sum+=p[j+1].a;
					cnt_a++;
				}else if(d[j+1]==2){
					sum+=p[j+1].b;
					cnt_b++;
				}else if(d[j+1]==3){
					sum+=p[j+1].c;
					cnt_c++;
				}
			}
			//cout << sum << endl;
			if(cnt_a<=n/2 && cnt_b<=n/2 && cnt_c<=n/2) mx=max(mx,sum);
		}
		cout << mx << endl;
	}
	return 0;
}
