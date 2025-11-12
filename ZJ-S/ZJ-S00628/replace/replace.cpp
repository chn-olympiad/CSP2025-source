#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N=2e5+10,B=13331;
int n,m,l,ly,ans,p,po[N*30],s[2][N*30];
string x,y;
struct node{
	int la,va,lb,vb;
	bool operator<(const node&a)const{
		return la==a.la?lb<a.lb:la<a.la;
	}
}a[N];
int get(int k,int l,int r){
	return s[k][r]-(l==0?0:s[k][l-1]*po[r-l+1]);
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	po[0]=1;
	for(int i=1;i<=5e6;i++)
		po[i]=po[i-1]*B;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		a[i].la=x.length();
		a[i].lb=y.length();
		for(int j=0;x[j];j++)
			a[i].va=a[i].va*B+x[j];
		for(int j=0;y[j];j++)
			a[i].vb=a[i].vb*B+y[j];
	}
	sort(a+1,a+1+n);
	while(m--){
		cin>>x>>y;
		l=x.length();
		ly=y.length();
		x=" "+x;
		y=" "+y;
		ans=0;
		for(int i=1;i<=l;i++)
			s[0][i]=s[0][i-1]*B+x[i];
		for(int i=1;i<=ly;i++)
			s[1][i]=s[1][i-1]*B+y[i];
		for(int i=1;i<=min(l,ly);i++)
			if(x[i]!=y[i]){
				p=i-1;
				break;
			}
		for(int i=l,q;i>=0;i--){
			node w={i-p,0,0,0};
			q=lower_bound(a+1,a+1+n,w)-a;
			for(int j=q;j<=n&&a[j].la<=i;j++){
				if(get(0,i-a[j].la+1,i)==a[j].va&&i-a[j].la+a[j].lb<=ly&&get(1,i-a[j].la+1,i-a[j].la+a[j].lb)==a[j].vb)
					ans++;
			}
			if(y[ly-l+i]!=x[i])
				break;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

