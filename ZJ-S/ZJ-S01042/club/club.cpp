#include <bits/stdc++.h>
typedef long long lld;
using namespace std;
const int N=1e5+5;
const int MX=2e9;

int alike[N];
int blike[N];
int clike[N];
int n;
int ans;
struct Node{
	int a,b,c;
}members[N];
lld cnta=0;
lld cntb=0;
lld cntc=0;
lld ca=0;
lld cb=0;
lld cc=0;
bool cmp(Node x,Node y){
	return max(max(x.a,x.b),x.c)>max(max(y.a,y.b),y.c);
}
void dfs(int d,int sum,int a,int b,int c){
	if(d==n+1){
		ans=max(ans,sum);
		return;
	}
	if(a+1<=(n/2)){
		dfs(d+1,sum+alike[d],a+1,b,c);
	}
	if(b+1<=(n/2)){
		dfs(d+1,sum+blike[d],a,b+1,c);
	}
	if(c+1<=(n/2)){
		dfs(d+1,sum+clike[d],a,b,c+1);
	}
}

void dfs2(int d,int sum,int a,int b){
	if(d==n+1){
		ans=max(ans,sum);
		return;
	}
	if(a+1<=(n/2)){
		dfs2(d+1,sum+alike[d],a+1,b);
	}
	if(b+1<=(n/2)){
		dfs2(d+1,sum+blike[d],a,b+1);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		
		cin>>n;
		int f=0;
		ans=0;
		int lim=n/2;
		for(int i=1;i<=n;i++){
			cin>>alike[i]>>blike[i]>>clike[i];
			members[i].a=alike[i];
			members[i].b=blike[i];
			members[i].c=clike[i];
			sort(members+1,members+1+n,cmp);
			if(n<=17){
				continue;
			}
			if(blike[i]==0&&f==0){
				f=1;
			}
			else if(clike[i]==0&&f==0){
				f=2;
			}
			if(blike[i]==0){
				f=1;
			}
			if(blike[i]!=0||clike[i]!=0){
				f=-1;
			}
			if(f==1){
				if(i>n/2){
					continue;
				}
				ans+=alike[i];
			}
		}
		if(f==-1){
			f=0;
		}
		if(f==1){
			cout<<ans<<endl;
			continue;
		}
		else if(f==2){
			if(n<=17){
				dfs2(1,0,0,0);
			}
			else{
				for(int i=1;i<=n;i++){
					lld a=members[i].a;
					lld b=members[i].b;
					lld c=members[i].c;
					lld mx=max(max(a,b),c);
					//a最大 且 a在限制内 -> 取a 
					if(mx==a&&mx!=b&&mx!=c&&ca+1<=lim){
						cnta+=a;
						ca++;
					}
					else if(mx==a&&mx!=b&&mx!=c&&ca+1>lim&&b>c&&cb+1<=lim){
						cntb+=b;
						cb++;
					}
					else if(mx==a&&mx!=b&&mx!=c&&ca+1>lim&&b<c&&cc+1<=lim){
						cntc+=c;
						cc++;
					}
					else if(mx==a&&mx!=b&&mx!=c&&ca+1>lim&&cb+1<=lim){
						cntb+=b;
						cb++;
					}
					else if(mx==a&&mx!=b&&mx!=c&&ca+1>lim&&cc+1<=lim){
						cntc+=c;
						cc++;
					}
					//b最大 且 b在限制内 -> 取b 
					else if(mx!=a&&mx==b&&mx!=c&&cb+1<=lim){
						cntb+=b;
						cb++;
					}
					else if(mx!=a&&mx==b&&mx!=c&&a>c&&ca+1<=lim){
						cnta+=a;
						ca++;
					}
					else if(mx!=a&&mx==b&&mx!=c&&a<c&&cc+1<=lim){
						cntc+=c;
						cc++;
					}
					else if(mx!=a&&mx==b&&mx!=c&&ca+1<=lim){
						cnta+=a;
						ca++;
					}
					else if(mx!=a&&mx==b&&mx!=c&&cc+1<=lim){
						cntc+=c;
						cc++;
					}
					//c最大 且 c在限制内 -> 取c 
					else if(mx!=a&&mx!=b&&mx==c&&cc+1<=lim){
						cntc+=c;
						cc++;
					}
					else if(mx!=a&&mx!=b&&mx==c&&a>b&&ca+1<=lim){
						cnta+=a;
						ca++;
					}
					else if(mx!=a&&mx!=b&&mx==c&&a<b&&cb+1<=lim){
						cntb+=b;
						cb++;
					}
					else if(mx!=a&&mx!=b&&mx==c&&ca+1<=lim){
						cnta+=a;
						ca++;
					}
					else if(mx!=a&&mx!=b&&mx==c&&cb+1<=lim){
						cntb+=b;
						cb++;
					}
					//a,b最大 且 a人数少于b人数 且 a在限制内 -> 取a 
					else if(mx==a&&mx==b&&mx!=c&&ca<cb&&ca+1<=lim){
						cnta+=a;
						ca++;
					}
					//a,b最大 且 b人数少于a人数 且 b在限制内 -> 取b 
					else if(mx==a&&mx==b&&mx!=c&&ca>cb&&cb+1<=lim){
						cntb+=b;
						cb++;
					}
					//a,b最大 且 a人数等于b人数 且 a在限制内 -> 取a
					else if(mx==a&&mx==b&&mx!=c&&ca==cb&&ca+1<=lim){
						cnta+=a;
						ca++;
					}
					//a,b最大 且 a人数等于b人数 且 b在限制内 -> 取b
					else if(mx==a&&mx==b&&mx!=c&&ca==cb&&cb+1<=lim){
						cntb+=b;
						cb++;
					}
					//a,c最大 且 a人数少于c人数 且 a在限制内 -> 取a
					else if(mx==a&&mx!=b&&mx==c&&ca<cc&&ca+1<=lim){
						cnta+=a;
						ca++;
					}
					//a,c最大 且 c人数少于a人数 且 c在限制内 -> 取c
					else if(mx==a&&mx!=b&&mx==c&&ca>cc&&cc+1<=lim){
						cntc+=c;
						cc++;
					}
					//a,c最大 且 a人数等于c人数 且 a在限制内 -> 取a
					else if(mx==a&&mx!=b&&mx==c&&ca==cc&&ca+1<=lim){
						cnta+=a;
						ca++;
					}
					//a,c最大 且 a人数等于c人数 且 c在限制内 -> 取c
					else if(mx==a&&mx!=b&&mx==c&&ca==cc&&cc+1<=lim){
						cntc+=c;
						cc++;
					}
					//b,c最大 且 b人数少于c人数 且 b在限制内 -> 取b
					else if(mx!=a&&mx==b&&mx==c&&cb<cc&&cb+1<=lim){
						cntb+=b;
						cb++;
					}
					//b,c最大 且 c人数少于b人数 且 c在限制内 -> 取c
					else if(mx!=a&&mx==b&&mx==c&&cb>cc&&cc+1<=lim){
						cntc+=c;
						cc++;
					}
					//b,c最大 且 b人数等于c人数 且 b在限制内 -> 取b
					else if(mx!=a&&mx==b&&mx==c&&cb==cc&&cb+1<=lim){
						cntb+=b;
						cb++;
					}
					//b,c最大 且 b人数等于c人数 且 c在限制内 -> 取c
					else if(mx!=a&&mx==b&&mx==c&&cb==cc&&cc+1<=lim){
						cntc+=c;
						cc++;
					}
					//a,b,c最大 且 a在限制内 ->取a
					else if(mx==a&&mx==b&&mx==c&&ca+1<=lim){
						cnta+=a;
						ca++;
					}
					//a,b,c最大 且 b在限制内 ->取b
					else if(mx==a&&mx==b&&mx==c&&cb+1<=lim){
						cntb+=b;
						cb++;
					}
					//a,b,c最大 且 c在限制内 ->取c
					else if(mx==a&&mx==b&&mx==c&&cc+1<=lim){
						cntc+=c;
						cc++;
					}
				}
				cout<<cnta+cntb+cntc<<endl;
			}
			continue;
		}
		else{
			if(n<=17){
				dfs(1,0,0,0,0);
			}
			else{
				for(int i=1;i<=n;i++){
					lld a=members[i].a;
					lld b=members[i].b;
					lld c=members[i].c;
					lld mx=max(max(a,b),c);
					//a最大 且 a在限制内 -> 取a 
					if(mx==a&&mx!=b&&mx!=c&&ca+1<=lim){
						cnta+=a;
						ca++;
					}
					else if(mx==a&&mx!=b&&mx!=c&&ca+1>lim&&b>c&&cb+1<=lim){
						cntb+=b;
						cb++;
					}
					else if(mx==a&&mx!=b&&mx!=c&&ca+1>lim&&b<c&&cc+1<=lim){
						cntc+=c;
						cc++;
					}
					else if(mx==a&&mx!=b&&mx!=c&&ca+1>lim&&cb+1<=lim){
						cntb+=b;
						cb++;
					}
					else if(mx==a&&mx!=b&&mx!=c&&ca+1>lim&&cc+1<=lim){
						cntc+=c;
						cc++;
					}
					//b最大 且 b在限制内 -> 取b 
					else if(mx!=a&&mx==b&&mx!=c&&cb+1<=lim){
						cntb+=b;
						cb++;
					}
					else if(mx!=a&&mx==b&&mx!=c&&a>c&&ca+1<=lim){
						cnta+=a;
						ca++;
					}
					else if(mx!=a&&mx==b&&mx!=c&&a<c&&cc+1<=lim){
						cntc+=c;
						cc++;
					}
					else if(mx!=a&&mx==b&&mx!=c&&ca+1<=lim){
						cnta+=a;
						ca++;
					}
					else if(mx!=a&&mx==b&&mx!=c&&cc+1<=lim){
						cntc+=c;
						cc++;
					}
					//c最大 且 c在限制内 -> 取c 
					else if(mx!=a&&mx!=b&&mx==c&&cc+1<=lim){
						cntc+=c;
						cc++;
					}
					else if(mx!=a&&mx!=b&&mx==c&&a>b&&ca+1<=lim){
						cnta+=a;
						ca++;
					}
					else if(mx!=a&&mx!=b&&mx==c&&a<b&&cb+1<=lim){
						cntb+=b;
						cb++;
					}
					else if(mx!=a&&mx!=b&&mx==c&&ca+1<=lim){
						cnta+=a;
						ca++;
					}
					else if(mx!=a&&mx!=b&&mx==c&&cb+1<=lim){
						cntb+=b;
						cb++;
					}
					//a,b最大 且 a人数少于b人数 且 a在限制内 -> 取a 
					else if(mx==a&&mx==b&&mx!=c&&ca<cb&&ca+1<=lim){
						cnta+=a;
						ca++;
					}
					//a,b最大 且 b人数少于a人数 且 b在限制内 -> 取b 
					else if(mx==a&&mx==b&&mx!=c&&ca>cb&&cb+1<=lim){
						cntb+=b;
						cb++;
					}
					//a,b最大 且 a人数等于b人数 且 a在限制内 -> 取a
					else if(mx==a&&mx==b&&mx!=c&&ca==cb&&ca+1<=lim){
						cnta+=a;
						ca++;
					}
					//a,b最大 且 a人数等于b人数 且 b在限制内 -> 取b
					else if(mx==a&&mx==b&&mx!=c&&ca==cb&&cb+1<=lim){
						cntb+=b;
						cb++;
					}
					//a,c最大 且 a人数少于c人数 且 a在限制内 -> 取a
					else if(mx==a&&mx!=b&&mx==c&&ca<cc&&ca+1<=lim){
						cnta+=a;
						ca++;
					}
					//a,c最大 且 c人数少于a人数 且 c在限制内 -> 取c
					else if(mx==a&&mx!=b&&mx==c&&ca>cc&&cc+1<=lim){
						cntc+=c;
						cc++;
					}
					//a,c最大 且 a人数等于c人数 且 a在限制内 -> 取a
					else if(mx==a&&mx!=b&&mx==c&&ca==cc&&ca+1<=lim){
						cnta+=a;
						ca++;
					}
					//a,c最大 且 a人数等于c人数 且 c在限制内 -> 取c
					else if(mx==a&&mx!=b&&mx==c&&ca==cc&&cc+1<=lim){
						cntc+=c;
						cc++;
					}
					//b,c最大 且 b人数少于c人数 且 b在限制内 -> 取b
					else if(mx!=a&&mx==b&&mx==c&&cb<cc&&cb+1<=lim){
						cntb+=b;
						cb++;
					}
					//b,c最大 且 c人数少于b人数 且 c在限制内 -> 取c
					else if(mx!=a&&mx==b&&mx==c&&cb>cc&&cc+1<=lim){
						cntc+=c;
						cc++;
					}
					//b,c最大 且 b人数等于c人数 且 b在限制内 -> 取b
					else if(mx!=a&&mx==b&&mx==c&&cb==cc&&cb+1<=lim){
						cntb+=b;
						cb++;
					}
					//b,c最大 且 b人数等于c人数 且 c在限制内 -> 取c
					else if(mx!=a&&mx==b&&mx==c&&cb==cc&&cc+1<=lim){
						cntc+=c;
						cc++;
					}
					//a,b,c最大 且 a在限制内 ->取a
					else if(mx==a&&mx==b&&mx==c&&ca+1<=lim){
						cnta+=a;
						ca++;
					}
					//a,b,c最大 且 b在限制内 ->取b
					else if(mx==a&&mx==b&&mx==c&&cb+1<=lim){
						cntb+=b;
						cb++;
					}
					//a,b,c最大 且 c在限制内 ->取c
					else if(mx==a&&mx==b&&mx==c&&cc+1<=lim){
						cntc+=c;
						cc++;
					}
				}
				cout<<cnta+cntb+cntc<<endl;
			}
			continue;
		}
		cout<<ans<<endl;
	}
	return 0;
}


