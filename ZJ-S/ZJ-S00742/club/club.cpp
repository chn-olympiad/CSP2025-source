#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int t,n,maxn=-1;
struct node{
	int d[4];
}a[N];
void dfs(int k,int ans,int sum1,int sum2,int sum3){
	if(k==n+1){
		maxn=max(maxn,ans);
		return;
	}
	maxn=max(maxn,ans);
	int cnt1=sum1,cnt2=sum2,cnt3=sum3,answ=ans;
	for(int i=1;i<=3;i++){
		if(i==1){
			if(sum1+1<=n/2){
				answ+=a[k].d[i];
				cnt1++;
			}
			else continue;
		}
		if(i==2){
			if(sum2+1<=n/2){
				answ+=a[k].d[i];
				cnt2++;
			}
			else continue;
		}
		if(i==3){
			if(sum3+1<=n/2){
				answ+=a[k].d[i];
				cnt3++;
			}
			else continue;
		}
		dfs(k+1,answ,cnt1,cnt2,cnt3);
		answ-=a[k].d[i];
		if(i==1) cnt1--;
		if(i==2) cnt2--;
		if(i==3) cnt3--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
		    cin>>a[i].d[1]>>a[i].d[2]>>a[i].d[3];
		}
		maxn=-1;
		dfs(1,0,0,0,0);
		cout<<maxn<<endl;
    }
    return 0;
}
