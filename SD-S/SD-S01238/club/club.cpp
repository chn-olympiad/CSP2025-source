#include<bits/stdc++.h>
using namespace std;
inline long long _(){
	long long f=1,x=0;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-f;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c-'0');
		c=getchar();
	}
	return f*x;
}
inline void __(long long x,int opt){
	int top=0;
	char st[85];
	if(x<0)putchar('-'),x=-x;
	do{
		st[++top]=x%10;x/=10;
	}while(x);
	for(int i=top;i>=1;i--)putchar(st[i]+'0');
	if(opt==0)return;
	if(opt==1)putchar(' ');
	else putchar('\n');
}
int t;
int n;
int a[100005][4];
int bel[100005];
int cnt[4];
priority_queue<int>pq;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=_();
	while(t--){
		n=_();
		long long ans=0;
		for(int i=1;i<=n;i++){
			a[i][1]=_();
			a[i][2]=_();
			a[i][3]=_();
			if(a[i][1]==max({a[i][1],a[i][2],a[i][3]})){
				bel[i]=1;
				cnt[1]++;
				ans+=a[i][1];
			}
			else if(a[i][2]==max({a[i][1],a[i][2],a[i][3]})){
				bel[i]=2;
				cnt[2]++;
				ans+=a[i][2];
			}
			else{
				bel[i]=3;
				cnt[3]++;
				ans+=a[i][3];
			}
		}
		if(cnt[1]>n/2){
			for(int i=1;i<=n;i++){
				if(bel[i]==1){
					pq.push(-a[i][1]+max(a[i][2],a[i][3]));
				}
			}
			for(int i=1;i<=cnt[1]-n/2;i++)ans+=pq.top(),pq.pop();
		}
		if(cnt[2]>n/2){
			for(int i=1;i<=n;i++){
				if(bel[i]==2){
					pq.push(-a[i][2]+max(a[i][1],a[i][3]));
				}
			}
			for(int i=1;i<=cnt[2]-n/2;i++)ans+=pq.top(),pq.pop();
		}
		if(cnt[3]>n/2){
			for(int i=1;i<=n;i++){
				if(bel[i]==3){
					pq.push(-a[i][3]+max(a[i][1],a[i][2]));
				}
			}
			for(int i=1;i<=cnt[3]-n/2;i++)ans+=pq.top(),pq.pop();
		}
		__(ans,2);
		for(int i=1;i<=n;i++)bel[i]=0,a[i][1]=0,a[i][2]=0,a[i][3]=0;
		ans=0;
		while(!pq.empty())pq.pop();
		for(int i=1;i<=3;i++)cnt[i]=0;
	}
} 
