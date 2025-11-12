#include<bits/stdc++.h>
using namespace std;
int t,n;
int mx;
bool b,b1;
unsigned long long cnt;
int c1,c2,c3;
struct node{
	int ft;
	int sc;
	int th; 
}a[100005];
bool cmp(node a,node b){
	return a.ft-a.sc>b.ft-b.sc;
}
void dfs(int dep,int sum){
	if(dep==n+1){
		if(sum>cnt)cnt=sum;
		return;
	}
	if(c1<mx){
		c1++;
		dfs(dep+1,sum+a[dep].ft);
		c1--;
	}
	if(c2<mx){
		c2++;
		dfs(dep+1,sum+a[dep].sc);
		c2--;
	}
	if(c3<mx){
		c3++;
		dfs(dep+1,sum+a[dep].th);
		c3--;
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		cnt=0;
		mx=0;
		c1=c2=c3=0;
		b=0;
		b1=0;
		mx=n/2;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i].ft>>a[i].sc>>a[i].th;
			if(a[i].sc!=0||a[i].th!=0)b=1;
			if(a[i].th!=0)b1=1;
		}
		sort(a+1,a+1+n,cmp);
		if(!b){
			for(int i=1;i<=mx;i++){
				cnt+=a[i].ft;
			}
			cout<<cnt<<endl;
			continue;
		}
		if(n==2){
			int cp1=a[1].ft,cp2=a[1].sc,cp3=a[1].th;
			cp1+=max(a[2].sc,a[2].th);
			cp2+=max(a[2].ft,a[2].th);
			cp3+=max(a[2].ft,a[2].sc);
			cnt=max(cp1,max(cp2,cp3));
		}else if(n==4||n==10){
			dfs(1,0);
		}else if(!b1){
			for(int i=1;i<=mx;i++){
				cnt+=a[i].ft;
			}
			for(int i=mx+1;i<=n;i++){
				cnt+=a[i].sc;
			} 
		}else{
			for(int i=1;i<=n;i++){
				cnt=cnt+a[i].ft+a[i].sc+a[i].th;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
