#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t;
struct node{
	int a,b,c;
}club[N];
bool cmp1(node x,node y){
	return x.a>y.a;
}
int ans,n,num1,num2,num3;
void dfs(int step,int sum){
	if(step>n){
		ans=max(ans,sum);
		return;
	}
	if(num1<(n/2)){
		num1++;
		dfs(step+1,sum+club[step].a);
		num1--;
	}
	if(num2<(n/2)){
		num2++;
		dfs(step+1,sum+club[step].b);
		num2--;
	}
	if(num3<(n/2)){
		num3++;
		dfs(step+1,sum+club[step].c);
		num3--;
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0,num1=0,num2=0,num3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>club[i].a>>club[i].b>>club[i].c;
		}
		dfs(1,0);
		cout<<ans<<"\n";
	}
}
