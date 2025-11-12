#include<bits/stdc++.h>
using namespace std;
const int N=1e5+6;
struct abc{
	int A,B,C;
	int M,H;
}d[N];
bool cmp(abc a,abc b){
	return a.M>b.M;
}
bool mp(abc a,abc b){
	return a.A>b.A;
}
bool mp3(abc a,abc b){
	return max(a.A,a.B)>max(b.A,b.B);
}
int t,n,m,a,b,c,ans,ts1,ts2;
bool cmpp(abc a,abc b){
	return a.A>b.A;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		m=n/2;
		a=0,b=0,c=0,ans=0;
		for(int i=1;i<=n;i++){
			cin>>d[i].A>>d[i].B>>d[i].C;
			d[i].M=max(d[i].A,max(d[i].B,d[i].C));
			if(d[i].B!=0||d[i].C!=0) ts1=1;
			if(d[i].C!=0) ts2=1;
		}
		if(n==2){
			sort(d+1,d+1+n,cmpp);
			ans=d[1].A+d[2].B;
			cout<<ans<<endl;
			continue;
		}
		if(ts1==0){
			sort(d+1,d+n+1,mp);
			for(int i=1;i<=n/2;i++) ans+=d[i].A;
			cout<<ans<<endl;
		}
		if(ts2==0){
			sort(d+1,d+n+1,mp3);
			int i=1,p1=0,p2=0;
			while(p1<n/2&&p2<n/2){
				if(d[i].A>d[i].B){
					ans+=d[i].A;
					p1++;
				}
				else if(d[i].B>d[i].A){
					ans+=d[i].B;
					p2++;
				}
				else if(p1>p2){
					ans+=d[i].B;
					p2++;
				}
				else if(p1<p2){
					ans+=d[i].B;
					p1++;
				}
			}
			if(p1>=n/2){
				for(int i=p1+p2+1;i<=n;i++){
					ans+=d[i].B;
				}
			}
			else if(p2>=n/2){
				for(int i=p1+p2+1;i<=n;i++){
					ans+=d[i].A;
				}
			}
			cout<<ans<<endl;
		}
		else{
			sort(d+1,d+n+1,cmp);
			for(int i=1;i<=n;i++){
				abc x=d[i];
				int z=x.A+x.B+x.C;
				if(x.A==x.M&&a<m){
					a++;
					ans+=x.A;
				}
				else if(x.B==x.M&&b<m){
					b++;
					ans+=x.B;
				}
				else if(x.C==x.M&&c<m){
					c++;
					ans+=x.C;
				}
				else{
					int y=z-x.M-min(x.A,min(x.B,x.C));
					if(x.A==y) a++;
					if(x.B==y) b++;
					if(x.C==y) c++;
					ans+=y;
				}
			}
			cout<<ans<<endl;
		}
		for(int i=1;i<=n;i++){
			d[i].A=0;d[i].B=0;d[i].C=0;
			d[i].M=0;
		}
	}
	return 0;
}/*
ÃÜÂë£ºRen5Jie4Di4Ling5%
*/
