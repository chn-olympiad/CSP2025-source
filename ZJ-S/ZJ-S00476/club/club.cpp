#include<bits/stdc++.h>
using namespace std;
struct stu{
	int f,s,t,f1,s1,t1;
}a[100010];
bool cmp(stu x,stu y){
	if(x.f1==y.f1){
		return x.f<y.f;
	}else{
		return x.f1<y.f1;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			int u,v,w;
			cin>>u>>v>>w;
			a[i].f=max(u,max(v,w));
			if(a[i].f==u){
				a[i].f1=1;
				u=-1;
			}
			else if(a[i].f==v){
				a[i].f1=2;
				v=-1;
			}
			else{
				a[i].f1=3;
				w=-1;
			}
			a[i].s=max(u,max(v,w));
			if(a[i].s==u){
				a[i].s1=1;
				u=-1;
			}
			else if(a[i].s==v){
				a[i].s1=2;
				v=-1;
			}
			else{
				a[i].s1=3;
				w=-1;
			}
			a[i].t=max(u,max(v,w));
			if(a[i].t==u){
				a[i].t1=1;
				u=-1;
			}
			else if(a[i].t==v){
				a[i].t1=2;
				v=-1;
			}
			else{
				a[i].t1=3;
				w=-1;
			}
		}
		int c1=0,c2=0,c3=0;
		for(int i=1;i<=n;i++){
			if(a[i].f1==1)	c1++;
			else if(a[i].f1==2)	c2++;
			else c3++;
		}
		while(c1>n/2||c2>n/2||c3>n/2){
			sort(a+1,a+n+1,cmp);
			if(c1>n/2){
				for(int i=1;i<=(c1-n/2);i++){
					swap(a[i].f1,a[i].s1);
					swap(a[i].f,a[i].s);
				}
			}else if(c2>n/2){
				for(int i=c1+1;i<=(c1+(c2-n/2));i++){
					swap(a[i].f1,a[i].s1);
					swap(a[i].f,a[i].s);
				}
			}else{
				for(int i=c1+c2+1;i<=(c1+c2+(c3-n/2));i++){
					swap(a[i].f1,a[i].s1);
					swap(a[i].f,a[i].s);
				}
			}
			c1=0,c2=0,c3=0;
			for(int i=1;i<=n;i++){
				if(a[i].f1==1)	c1++;
				else if(a[i].f1==2)	c2++;
				else c3++;
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			ans+=a[i].f;
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}