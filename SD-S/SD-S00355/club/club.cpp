#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')f=-1,ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch-'0'),ch=getchar();
	return x*f;
}
const int N=1e5+10;
int linc[10];
struct node{
	int a,b,c,maxd,maxid;
}e[N];
bool cmp(node a,node b){
	if(a.maxid==b.maxid)return a.maxd>b.maxd; 
	return a.maxid<b.maxid;
}
int cnt,la;
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=read();
	while(t--){
		int n=read();
		for(int i=1;i<=n;i++){
//			e[i].a=read(),e[i].b=read(),e[i].c=read();
			linc[1]=read(),linc[2]=read(),linc[3]=read();
			e[i].a=linc[1];
			e[i].b=linc[2];
			e[i].c=linc[3];
			
			sort(linc+1,linc+4);
//			for(int j=1;j<=3;j++)cout<<linc[j]<<' ';cout<<endl;
			e[i].maxd=linc[3]-linc[2];
			if(linc[3]==e[i].a)e[i].maxid=1;
			if(linc[3]==e[i].b)e[i].maxid=2;
			if(linc[3]==e[i].c)e[i].maxid=3;
		}
		sort(e+1,e+1+n,cmp);
//		for(int i=1;i<=n;i++)cout<<e[i].maxid<<' '<<e[i].maxd<<endl;
		cnt=0,ans=0;
		for(int i=1;i<=n;i++){
			ans+=max(e[i].a,max(e[i].b,e[i].c)); 
			cnt++;
//			cout<<ans<<' '<<cnt<<endl;
			if(e[i].maxid!=e[i-1].maxid){
				cnt--;
				if(cnt<=n/2)cnt=1;
				else{
					for(int j=1;j<=cnt-n/2;j++){
						la=i-j;
						ans-=e[la].maxd;
//						cout<<ans<<endl;
					} 
					cnt=1;
				}
			}
//			cout<<cnt<<' '<<ans<<endl;
		}
		if(cnt>n/2){
			for(int i=1;i<=cnt-n/2;i++){
				la=n-i+1;
				ans-=e[la].maxd;
//				cout<<ans<<' ';
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
