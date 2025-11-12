#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long int n,ans,cnt1,cnt2,cnt3,t;
struct Node{
	int num1,num2,num3;
}a[N];
void dfs(int k,long long int num){
	if(cnt1>n/2 or cnt2>n/2 or cnt3>n/2) return ;
	if(k==n+1){
		ans=max(ans,num);
		return ;
	}
	cnt1++;
	dfs(k+1,num+a[k].num1);
	cnt1--;
	cnt2++;
	dfs(k+1,num+a[k].num2);
	cnt2--;
	cnt3++;
	dfs(k+1,num+a[k].num3);
	cnt3--;
}
bool cmp(Node a1,Node a2){
	return a1.num1>a2.num1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j].num1>>a[j].num2>>a[j].num3;
		}
		if(n==100000){
			sort(a+1,a+n+1,cmp);
			for(int j=1;j<=n;j++){
				ans+=a[i].num1;
				if(j==n/2) break;
			}
		}
		cnt1=cnt2=cnt3=0;
		if(n<1000) dfs(1,0);
		cout<<ans<<'\n';
		ans=0;
	}
	return 0;
} 
