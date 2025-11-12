#include <bits/stdc++.h>
using namespace std;
struct node{
	int a1,a2,a3;
}a[100005];
int mx=-100000;
int club1=0,club2=0,club3=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int sum=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;	
			mx=max(a[i].a1,a[i].a2);
			mx=max(mx,a[i].a3);
			if(mx==a[i].a1){
				club1++;
			}else if(mx==a[i].a2){
				club2++;
			}else if(mx==a[i].a3){
				club3++;
			}
			sum+=mx;
		}
		cout<<sum;
		mx=-10000;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

