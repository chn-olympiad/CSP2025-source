#include<bits/stdc++.h>
using namespace std;
int n,res;
int c1,c2,c3,ans,f[114514];
struct tt{
	int a1,a2,a3,d12,d13,d23;
}s[1145141];
struct rr{
	int id,a;
}sum[1145141];
bool cmp(rr x,rr y){
	return x.a>y.a;
}
void dfs(int d){
	if(d>n){
		for(int i=1;i<=n;i++){
			if(f[i]==1){
				ans+=s[i].a1;
			}
			else if(f[i]==2){
				ans+=s[i].a2;
			}
			else if(f[i]==3){
				ans+=s[i].a3;
			}
		}
		res=max(res,ans);
		ans=0;
		return;
	}
	if(c1<n/2){
		c1++;
		f[d]=1;
		dfs(d+1);
		c1--;
	}
	if(c2<n/2){
		c2++;
		f[d]=2;
		dfs(d+1);
		c2--;
	}
	if(c3<n/2){
		c3++;
		f[d]=3;
		dfs(d+1);
		c3--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&s[i].a1,&s[i].a2,&s[i].a3);
			s[i].d12=s[i].a1-s[i].a2;
			s[i].d13=s[i].a1-s[i].a3;
			s[i].d23=s[i].a2-s[i].a3;
		}
		int w;
		w=0;
		for(int i=1;i<=n;i++){
			w+=s[i].a3;
		}
		if(w==0){
			int q;
			for(int i=1;i<=n;i++){
				q=min(s[i].a1,s[i].a2);
				res+=q;
				s[i].a1-=q;
				s[i].a2-=q;
				if(s[i].a1!=0){
					sum[i].a=s[i].a1;
					sum[i].id=1;
				}
				else{
					sum[i].a=s[i].a2;
					sum[i].id=2;
				}
			}
			sort(sum+1,sum+n+1,cmp);
			int p1,p2;
			p1=p2=n/2;
			for(int i=1;i<=n;i++){
				if(sum[i].id==1){
					if(p1==0){
						continue;
					}
					res+=sum[i].a;
					p1--;
				}
				else {
					if(p2==0){
						continue;
					}
					res+=sum[i].a;
					p2--;
				}
			}
			cout<<res<<endl;
			res=0;
		}
		else{
			dfs(1);
			cout<<res<<endl;
			res=0;
		}
	}
	return 0;
}