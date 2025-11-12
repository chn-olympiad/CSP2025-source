#include<bits/stdc++.h>// 董柏辰 SN-S00625 西安铁一中滨河高级中学 
using namespace std;
#define ll long long
ll t,numa,numb,numc,dbc,re;
ll n,maxn=-1;
struct Node{
	ll a;
	ll b;
	ll c;
}mem[100010];
void dfs(ll num,ll sum){
	if(num>n){
		if(sum>maxn)maxn=sum;
		return;
	}
	if(numa<(n/2)&&(!(sum+mem[num].a<sum+mem[num].c&&sum+mem[num].a<sum+mem[num].b))){
		numa++;
	dfs(num+1,sum+mem[num].a);
	numa--;
	}
	if(numb<(n/2)&&(!(sum+mem[num].b<sum+mem[num].a&&sum+mem[num].b<sum+mem[num].c))){
		numb++;
	dfs(num+1,sum+mem[num].b);
	numb--;
	}
	if(numc<(n/2)&&(!(sum+mem[num].c<sum+mem[num].a&&sum+mem[num].c<sum+mem[num].b))){
		numc++;
	dfs(num+1,sum+mem[num].c);
	numc--;
	}
	return;
}
bool cmp(Node x,Node y){
	return x.a>y.a;
}
int main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;
		for(int i=1;i<=n;i++){
			 cin>>mem[i].a>>mem[i].b>>mem[i].c;
			 if(mem[i].b||mem[i].c)dbc=1;
		}
		   if(!dbc){
		   	sort(mem+1,mem+n+1,cmp);
		   	for(int i=1;i<=n/2;i++)re+=mem[i].a;
		   	cout<<re<<endl;
		   	re=0;
		   }
		else {
		    dfs(1,0);
		    cout<<maxn<<endl;
		    for(int i=1;i<=n;i++)
		    mem[i].a=mem[i].b=mem[i].c=0;
		    numa=numb=numc=0;
		    maxn=0;
		    dbc=0;
		}
    }
	return 0;
}
