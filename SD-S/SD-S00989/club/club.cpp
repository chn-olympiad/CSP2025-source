#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct poin{
	ll numb,peop,belo;
}a[100010];
ll n,x,y=1;
ll ans;
bool cmp(poin q,poin p){
	return(q.numb>p.numb);
}
int main( ){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int ii;
	cin>>ii;
	for(int jj=1;jj<=ii;jj++){
		y=1;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>x;
				a[y].numb=x;
				a[y].belo=j;
				a[y].peop=i;
				y++;
			}
		}
		y--;
		sort(a+1,a+y+1,cmp);
		bool f[100010];
		for(int i=1;i<=y;i++){//从第i个开始考虑 
			if(a[i].numb==a[i-1].numb) continue;
			memset(f,0,100005);
			ll o=0,p=0,q=0,l=0;//L统计答案 
			for(int j=1;j<=y;j++){
				if(j==i) continue;
				if(a[j].belo==1) o++;
				if(a[j].belo==2) p++;
				if(a[j].belo==3) q++;
				if(f[a[j].peop]==0&&o<=n/2&&p<=n/2&&q<=n/2){
					l+=a[j].numb;
					f[a[j].peop]=1;
				}else{
					if(a[j].belo==1) o--;
					if(a[j].belo==2) p--;
					if(a[j].belo==3) q--;
				}
			}
			ans=max(ans,l);
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
