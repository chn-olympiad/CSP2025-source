#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+5;
bool bk[N];
struct node{
	int val,num;
	bool operator < (const node &x)const{
		return val<x.val;
	}
};
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,a,b,c,cntq1=0,cntq2=0,cntq3=0,ans=0;
		priority_queue<node,vector<node> > q1,q2,q3;
		memset(bk,0,sizeof bk);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			node t1,t2,t3;
			t1.val=a;t1.num=i;
			t2.val=b;t2.num=i;
			t3.val=c;t3.num=i;
			q1.push(t1);
			q2.push(t2);
			q3.push(t3);
		}
		for(int i=1;i<=n;i++){
			int x,flag=0;
			while(bk[q1.top().num]){q1.pop();}
			while(bk[q2.top().num]){q2.pop();}
			while(bk[q3.top().num]){q3.pop();}
			int t1=q1.top().val;
			int t2=q2.top().val;
			int t3=q3.top().val;
			if(cntq3<<1<n&&cntq2<<1<n){
				x=max(t2,t3);}
			if(cntq3<<1<n&&cntq1<<1<n){
				x=max(t1,t3);}
			if(cntq2<<1<n&&cntq1<<1<n){
				x=max(t1,t2);
			}
			if(cntq3<<1<n&&cntq2<<1<n&&cntq1<<1<n){
				x=max({t1,t2,t3});
			}
			if(cntq1<<1<=n&&x==t1){flag=1;}
			if(cntq2<<1<=n&&x==t2){flag=2;}
			if(cntq3<<1<=n&&x==t3){flag=3;}
			if(flag==1){bk[q1.top().num]=1;q1.pop();cntq1++;}
			if(flag==2){bk[q2.top().num]=1;q2.pop();cntq2++;}
			if(flag==3){bk[q3.top().num]=1;q3.pop();cntq3++;}
			ans+=x;
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
