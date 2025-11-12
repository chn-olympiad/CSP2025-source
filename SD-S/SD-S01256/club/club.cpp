#include<bits/stdc++.h>
using namespace std;
struct peop{
	long long a,b,c,d;
}x[100005];
long long y[5],ans,n,h;
long long t;
bool cmp(peop k,peop l){
	return k.d>l.d;
}
bool cmp2(peop k,peop l){
	return k.a>l.a;
}
bool cmp1(peop k,peop l){
	return k.a-k.b>l.a-l.b; 
}
void dfs(long long xx,long long yy){
	if(y[1]>n/2||y[2]>n/2||y[3]>n/2){
		return;
	}
	if(xx==n+1&&y[1]<=n/2&&y[2]<=n/2&&y[3]<=n/2){
		ans=max(ans,yy);
		return;
	}
	y[1]++;
	dfs(xx+1,yy+x[xx].a);
	y[1]--;
	y[2]++;
	dfs(xx+1,yy+x[xx].b);
	y[2]--;
	y[3]++;
	dfs(xx+1,yy+x[xx].c);
	y[3]--;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		h=0;
		ans=0;
		memset(y,0,sizeof y);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			if(x[i].b==0){
				h++;
			}
			if(x[i].c==0){
				h++;
			}
			int mmin=min(x[i].a,min(x[i].b,x[i].c));
			int mmax=max(x[i].a,max(x[i].b,x[i].c));
			int cha=mmax-mmin;
			x[i].d=cha;
		}
		if(n<=30){
			dfs(1,0);
			cout<<ans<<endl;
			continue;
		}else if(h==2*n){
			sort(x+1,x+n+1,cmp2);
			for(int i=1;i<=n/2;i++){
				ans+=x[i].a;
			}
			cout<<ans<<endl;
			continue;
		}
		//cout<<n/2<<endl;
		else if(h==n){
			sort(x+1,x+n+1,cmp1);
			for(int i=1;i<=n/2;i++){
				ans+=x[i].a;
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=x[i].b;
			}
			cout<<ans<<endl;
			continue;
		}
		sort(x+1,x+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(x[i].a==max(x[i].a,max(x[i].b,x[i].c))&&y[1]<n/2){
				y[1]++;
				//cout<<y[1]<<endl;
				ans+=x[i].a;
			}else if(x[i].b==max(x[i].a,max(x[i].b,x[i].c))&&y[2]<n/2){
				y[2]++;
				//cout<<y[2]<<endl;
				ans+=x[i].b;
			}else if(x[i].c==max(x[i].a,max(x[i].b,x[i].c))&&y[3]<n/2){
				y[3]++;
				//cout<<y[3]<<endl;
				ans+=x[i].c;
			}else if(x[i].a!=max(x[i].a,max(x[i].b,x[i].c))&&x[i].a!=min(x[i].a,min(x[i].b,x[i].c))&&y[1]<n/2){
				y[1]++;
				//cout<<y[1]<<endl;
				ans+=x[i].a;
			}else if(x[i].b!=max(x[i].a,max(x[i].b,x[i].c))&&x[i].b!=min(x[i].a,min(x[i].b,x[i].c))&&y[2]<n/2){
				y[2]++;
				//cout<<y[2]<<endl;
				ans+=x[i].b;
			}else if(x[i].c!=max(x[i].a,max(x[i].b,x[i].c))&&x[i].c!=min(x[i].a,min(x[i].b,x[i].c))&&y[3]<n/2){
				y[3]++;
				//cout<<y[3]<<endl;
				ans+=x[i].c;
			}else if(x[i].a==min(x[i].a,min(x[i].b,x[i].c))&&y[1]<n/2){
				y[1]++;
				//cout<<y[1]<<endl;
				ans+=x[i].a;
			}else if(x[i].b==min(x[i].a,min(x[i].b,x[i].c))&&y[2]<n/2){
				y[2]++;
				//cout<<y[2]<<endl;
				ans+=x[i].b;
			}else{
				y[3]++;
				//cout<<y[3]<<endl;
				ans+=x[i].c;
			}
			//cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
