#include<bits/stdc++.h>
using namespace std;
struct ciallo{
	int nam;
	int a1,a2,a3;
	int wan;
}a[114514];
int t;
int n,ans,tmp;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	for(int j=0;j<t;j++){
		cin>>n;
		int peo1[n/2+1]={0},peo2[n/2+1]={0},peo3[n/2+1]={0};
		for(int i=1;i<=n;i++){
			a[i].nam=i;
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a1>a[i].a2){
				if(a[i].a1>a[i].a3){
					a[i].wan=1;
					peo1[0]++;
				}
				else{
					a[i].wan=3;
					peo3[0]++;
				} 
			}else {
				if(a[i].a2>a[i].a3){
					a[i].wan=2;
					peo2[0]++;
				}
				else {
					a[i].wan=3;
					peo3[0]++;
				}
			}
			tmp=max(max(peo1[0],peo2[0]),peo3[0]);
			ans+=max(max(a[i].a1,a[i].a2),a[i].a3);
		}
		cout<<ans<<endl;
	}
	return 0;
} 
