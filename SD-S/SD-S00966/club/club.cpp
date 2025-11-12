#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int N=1e3+10;
struct node{
	int id,w;
}b[N];
int T,n;
int a[N][4],ans,cnt=0,cnt1,cnt2,cnt3;
void dfs(int x,int sum,int id){
	if(x==n){
		cnt++;
		//cout<<cnt<<"\n";
		ans=max(ans,sum);
		return;
	}
	if((cnt1+1)*2<=n){
		cnt1++;
		//cout<<"1: "<<id<<"\n";
		dfs(x+1,sum+a[id][1],id+1);
		cnt1--;
	}
	if((cnt2+1)*2<=n){
		//cout<<"2: "<<id<<"\n";
		cnt2++;
		dfs(x+1,sum+a[id][2],id+1);
		cnt2--;
	}
	if((cnt3+1)*2<=n){
		//cout<<"3: "<<id<<"\n";
		cnt3++;
		dfs(x+1,sum+a[id][3],id+1);
		cnt3--;
	}
}
bool cmp(node a,node b){
	return a.w>b.w;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		ans=0;
		cnt=0;
		int f=1,f1=1;
		for(int i=1;i<=n;i++){
			a[i][1]=read();
			a[i][2]=read();
			a[i][3]=read();
			if(a[i][2]!=0||a[i][3]!=0)f=0;
			if(a[i][3]!=0)f1=0;
		}
		if(f){
			for(int i=1;i<=n;i++){
				b[i].id=i;
				b[i].w=a[i][1];
			}
			sort(b+1,b+n+1,cmp);
			for(int i=1;i*2<=n;i++){
				ans+=b[i].w;
			}
			cout<<ans<<"\n";
			continue;
		}
		dfs(0,0,1);
		cout<<ans<<"\n";
	}
	return 0;
} 
