#include <bits/stdc++.h>
using namespace std;
int t,n,m[5];
int a[100005][10];
struct st{
	int a,b,c,mi,ma,mid,pd,mai,midi;
}f[100005];
bool cmp(st x,st y){
	if(x.ma>y.ma){
		return x.ma>y.ma;
	} 
	else if(x.ma==y.ma){
		if(x.mid==y.mid){
			return x.mi>y.mi;
		}
		return x.mid>y.mid;
	}
	return x.ma>y.ma;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(f,0,sizeof(f));
		memset(m,0,sizeof(m));
		cin>>n;
		long long ans=0,tp=0,tp2=0;
		for(int i=1;i<=n;i++){
			cin>>f[i].a>>f[i].b>>f[i].c;
			if(f[i].b==0&&f[i].c==0) tp++;
			if(f[i].c==0) tp2++;
			f[i].ma=max(f[i].a,max(f[i].b,f[i].c));
			f[i].mi=min(f[i].a,min(f[i].b,f[i].c));
			f[i].mid=f[i].a+f[i].b+f[i].c-f[i].ma-f[i].mi;
			if(f[i].a>f[i].b){
				if(f[i].b>f[i].c) f[i].mai=1;
				else if(f[i].a>f[i].c) f[i].mai=1;
				else f[i].mai=3;
			}else if(f[i].b<f[i].c) f[i].mai=3;
			else f[i].mai=2;
			if(f[i].a>f[i].b){
				if(f[i].b>f[i].c) f[i].midi=2;
				else if(f[i].a>f[i].c) f[i].midi=3;
				else f[i].midi=1;
			}else if(f[i].b<f[i].c){
				f[i].midi=2;
			}else if(f[i].a>f[i].c){
				f[i].midi=1;
			}else f[i].midi=3;
		}
		sort(f+1,f+1+n,cmp);
		long long ans1=0,ans4=0;
		if(tp>=n/2){
			for(int i=1;i<=(n/2);i++){
				if(f[i].pd==0){
					if(m[f[i].midi]<(n/2)){
						ans1+=f[i].mid;
						f[i].pd=1;
						m[f[i].midi]++;
					}
					else if(m[f[i].mai]<(n/2)){
						ans1+=f[i].ma;
						f[i].pd=1;
						m[f[i].mai]++;
					}else{
						ans1+=f[i].mi;
						f[i].pd=1;
					}
				}
			}
			long long ans3=0;
			for(int i=(n/2);i<=n;i++){
				if(f[i].pd==0){
					if(m[f[i].mai]<(n/2)){
						ans3+=f[i].ma;
						f[i].pd=1;
						m[f[i].mai]++;
					}else if(m[f[i].midi]<(n/2)){
						ans3+=f[i].mid;
						f[i].pd=1;
						m[f[i].midi]++;
					}else{
						ans3+=f[i].mi;
						f[i].pd=1;
					}
				}
			}
			ans1+=ans3;
		}else if(tp2==n){
			for(int i=1;i<=n;i++){
				if(i<=n/2){
					ans4+=f[i].ma;
				}else{
					ans4+=f[i].mid;
				}
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(f[i].pd==0){
					if(m[f[i].mai]<(n/2)){
						ans+=f[i].ma;
						f[i].pd=1;
						m[f[i].mai]++;
					}else if(m[f[i].midi]<(n/2)){
						ans+=f[i].mid;
						f[i].pd=1;
						m[f[i].midi]++;
					}else{
						ans+=f[i].mi;
						f[i].pd=1;
					}
				}
			}
		}
		ans=max(ans,max(ans1,ans4));
		cout<<ans<<"\n";
	}
	return 0;
}
