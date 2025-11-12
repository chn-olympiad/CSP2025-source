#include<bits/stdc++.h>
using namespace std;
int n,k,q[1000001],cnt,f[600010],l,x,fl,s,st[500010][30],a[600010],i,j,ans,ma;
struct no{
	int x,y;
}tt[500010];
bool cmp(no q,no h){
	return q.x<h.x;
}
void sc(int t,int sum,int lst,int wled){
	int i;
	if(t>cnt){
		ma=max(ma,sum);
		return ;
	}
	if(tt[t].x>tt[wled].y&&q[wled]==0) return ;
	for(i=t;i<=n;i++)
		if(tt[i].x>tt[t].y) break;
	q[t]=0;
	sc(t+1,sum,lst,i);
	q[t]=1;
	if(tt[t].x>lst) sc(t+1,sum+1,tt[t].y,t+1);
}
void did(int x,int y){
	int cnt=0;
	while(x!=0){
		st[y][++cnt]=x%2;
		x/=2;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==1){
		for(i=1;i<=n;i++)
			cin>>x,ans+=((x==1) ? 1 : 0);
		cout<<ans;
		return 0;
	}
	did(k,0);
	for(i=1;i<=n;i++){
		cin>>a[i];did(a[i],i);
		for(j=1;j<=20;j++)
			st[i][j]+=st[i-1][j];
	}
	for(l=1;l<=n;l++)
		for(i=1;i<=n-l+1;i++){
			fl=1;
			for(j=0;j<=19;j++)
				if((st[i+l-1][j]-st[i-1][j])%2!=st[0][j]%2){
					fl=0;
					break;
				}
			if(fl==1) tt[++cnt].x=i,tt[cnt].y=i+l-1;
		}
	sort(tt+1,tt+1+cnt,cmp);
	q[0]=1;
	sc(1,0,0,0);
	cout<<ma;
	return 0;
}

