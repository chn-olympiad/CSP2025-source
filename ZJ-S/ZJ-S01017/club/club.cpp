#include<bits/stdc++.h>
#define min(a,b) (a<b?a:b)
using namespace std;
int T,n,ans,cnt1,cnt2,cnt3;
struct data{
	int a,b,c;
}a[100005];
struct node1{
	int a,b,c;
	bool operator > (const node1 &x)const{
		return min(a-b,a-c)>min(x.a-x.b,x.a-x.c);
	}
};
struct node2{
	int a,b,c;
	bool operator > (const node2 &x)const{
		return min(b-a,b-c)>min(x.b-x.a,x.b-x.c);
	}
};
struct node3{
	int a,b,c;
	bool operator > (const node3 &x)const{
		return min(c-b,c-a)>min(x.c-x.a,x.c-x.b);
	}
};
priority_queue<node1,vector<node1>,greater<node1> >q1;
priority_queue<node2,vector<node2>,greater<node2> >q2;
priority_queue<node3,vector<node3>,greater<node3> >q3;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<48||ch>57){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>=48&&ch<=57){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		ans=0;
		cnt1=0;
		cnt2=0;
		cnt3=0;
		n=read();
		for(int i=1;i<=n;++i){
			a[i].a=read();
			a[i].b=read();
			a[i].c=read();
		}
		for(int i=1;i<=n;++i){
			if(a[i].a>a[i].b){
				if(a[i].a>a[i].c){
					q1.push({a[i].a,a[i].b,a[i].c});
					cnt1++;
				}
				else{
					q3.push({a[i].a,a[i].b,a[i].c});
					cnt3++;
				}
			}
			else{
				if(a[i].b>a[i].c){
					cnt2++;
					q2.push({a[i].a,a[i].b,a[i].c});
				}
				else{
					cnt3++;
					q3.push({a[i].a,a[i].b,a[i].c});
				}
			}
		}
		while(cnt1>n/2){
			node1 p=q1.top();
			q1.pop();
			if(p.b>p.c){
				cnt2++;
				q2.push({p.a,p.b,p.c});
			}
			else{
				cnt3++;
				q3.push({p.a,p.b,p.c});
			}
			cnt1--;
		}
		while(cnt2>n/2){
			node2 p=q2.top();
			q2.pop();
			if(p.a>p.c){
				cnt1++;
				q1.push({p.a,p.b,p.c});
			}
			else{
				cnt3++;
				q3.push({p.a,p.b,p.c});
			}
			cnt2--;
		}
		while(cnt3>n/2){
			node3 p=q3.top();
			q3.pop();
			if(p.b>p.a){
				cnt2++;
				q2.push({p.a,p.b,p.c});
			}
			else{
				cnt1++;
				q1.push({p.a,p.b,p.c});
			}
			cnt3--;
		}
		while(!q1.empty()){
			ans+=q1.top().a;
			q1.pop();
		}
		while(!q2.empty()){
			ans+=q2.top().b;
			q2.pop();
		}
		while(!q3.empty()){
			ans+=q3.top().c;
			q3.pop();
		}
		cout<<ans<<'\n';
	}
	return 0;
}
