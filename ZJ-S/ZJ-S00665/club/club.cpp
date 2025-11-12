//club
#include<bits/stdc++.h>
using namespace std;
struct st{
	int c,i;
	friend bool operator<(st x,st y){
		return x.c<y.c;
	}
};
priority_queue <st>G;
void cl(){
	while(!G.empty())G.pop();
}
void s(){
	int n;
	cl();
	cin>>n;
	int a[n+5][5]={0},num[5]={0},max_max2[n+5]={0},biggest[n+5]={0},biggest2[n+5]={0};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++)cin>>a[i][j];
		int Max=max(max(a[i][1],a[i][2]),a[i][3]);
		for(int j=1;j<=3;j++)if(a[i][j]==Max){
			biggest[i]=j;
			break;
		}
		int next_biggest=0;
		for(int j=1;j<=3;j++)if(j!=biggest[i]){
			if(next_biggest<=a[i][j]){
			next_biggest=a[i][j];
			biggest2[i]=j;
			}
		}
		max_max2[i]=Max-next_biggest;
		G.push({max_max2[i],i});
	}
	long long ans=0;
	while(!G.empty()){
		if(num[biggest[G.top().i]]<n/2){
			num[biggest[G.top().i]]++;
			ans+=a[G.top().i][biggest[G.top().i]];
			G.pop();
		}
		else {
			ans+=a[G.top().i][biggest2[G.top().i]];
			G.pop();
		}
	}
	cout<<ans;
	cout<<endl;
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
	s();
	}
	return 0;
}
	

	
	
	
	
	
