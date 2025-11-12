#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int x,y,z;
}a[N];
struct num{
	int cnt,s;
}sum[N];
int t,n,line[50],ans;
bool cmp1(node c,node d){
	return c.x>d.x;
}
void solve1(){
	sort(a+1,a+1+n,cmp1);
	int ans=0;
	for(int i=1;i<=n/2;i++)
		ans+=a[i].x;
	cout<<ans<<endl;
}
bool cmp2(num c,num d){
	return c.cnt<d.cnt;
}
void solve2(){
	int ans=0,cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++){
		if(a[i].x>a[i].y){
			cnt1++;
			ans+=a[i].x;
		}
		else{
			cnt2++;
			ans+=a[i].y;
		}
		sum[i]=(num){abs(a[i].x-a[i].y),i};
	}
	if(cnt1!=cnt2){
		int temp=(abs(cnt1-cnt2))/2;
		for(int i=1;i<=temp;i++)
			ans-=sum[i].cnt;
	}
	cout<<ans<<endl;
}
void DFS(int dep){
	if(dep>n){
		int cnt_1=0,cnt_2=0,cnt_3=0,t=0;
		for(int i=1;i<=n;i++){
			if(line[i]==1){cnt_1++;t+=a[i].x;}
			else if(line[i]==2){cnt_2++;t+=a[i].y;}
			else if(line[i]==3){cnt_3++;t+=a[i].z;}
		}
		if(cnt_1>n/2||cnt_2>n/2||cnt_3>n/2)return;
		ans=max(ans,t);
		return;
	}
	for(int i=1;i<=3;i++){
		line[dep]=i;
		DFS(dep+1);
	}
	return;
}
void solve3(){
	DFS(1);
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i].x>>a[i].y>>a[i].z;
		bool flag1=true,flag2=true;
		for(int i=1;i<=n;i++){
			if(a[i].y!=0||a[i].z!=0)flag1=false;
			if(a[i].z!=0)flag2=false;
		}
		if(n<=10){solve3();continue;}
		if(flag1){solve1();continue;}
		if(flag2){solve2();continue;}
	}
	return 0;
}
