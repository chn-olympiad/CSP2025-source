#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5; 
int read(){
	int x=0,f=1;char ch=getchar();
	while('0'>ch||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,num[5],ans;
pair<int,int>a[N][5];
priority_queue<int>q;
void solve(int mx=0){
	n=read();ans=0;
	num[1]=num[2]=num[3]=0;
	while(!q.empty())q.pop();
	for(int i=1;i<=n;i++){
		a[i][1]={read(),1};
		a[i][2]={read(),2};
		a[i][3]={read(),3};
		sort(a[i]+1,a[i]+4);
		num[a[i][3].second]++;
		ans+=a[i][3].first;
	}
	if(num[1]*2>n)mx=1;
	if(num[2]*2>n)mx=2;
	if(num[3]*2>n)mx=3;
	if(mx){
		for(int i=1;i<=n;i++)
			if(a[i][3].second==mx)
				q.push(a[i][2].first-a[i][3].first);
		while(num[mx]*2>n){
			ans+=q.top();q.pop();
			num[mx]--;
		}
	}
	printf("%d\n",ans);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=read();
	while(t--)solve();
	return 0;
}