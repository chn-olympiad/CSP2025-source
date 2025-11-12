#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int T,a[100010][5],ch[100010],n,f[403][403][403];
struct node{
	int id,nch,val,toc; 
}l[100100],r[100100];
bool cmp(node &x,node &y){
	return x.val>y.val;
}
bool cmp1(node &x,node &y){
	return x.toc-x.nch>y.toc-y.nch; 
}
void solve1(){
	int mid=n/2;
	f[0][0][0]=0;
	for(int i=0;i<=mid;i++)
		for(int j=0;j<=mid;j++)
			for(int k=0;k+i+j<=n&&k<=mid;k++)
				f[i][j][k]=0;
	for(int t=1;t<=n;t++)
		for(int j=0;j<=mid&&j<=t;j++)
			for(int k=0;k+j<=t;k++){
				int i=t-j-k;
				if(i>mid)continue;
				if(i!=0) 
				f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[t][1]);
				if(j!=0)
				f[i][j][k]=max(f[i][j][k],f[i][j-1][k]+a[t][2]);
				if(k!=0)
				f[i][j][k]=max(f[i][j][k],f[i][j][k-1]+a[t][3]);
			}
	int ans=0;
	for(int i=0;i<=mid;i++)
		for(int j=0;j<=mid;j++){
			int t=n-i-j;
			if(t>mid)continue;
			ans=max(ans,f[i][j][n-i-j]);
			}
	cout << ans << endl;
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++)
				  scanf("%d",&a[i][j]);
			}
		if(n<=400){
			solve1();
		}
		else {
			
			int mid=n/2;
			for(int i=1;i<=mid;i++){
				l[i].val=a[i][2]-a[i][1];
			l[i].id=i;
			l[i].nch=a[i][1];
			l[i].toc=a[i][3];
		}
		for(int i=mid+1;i<=n;i++){
			r[i-mid].val=a[i][1]-a[i][2];
			r[i-mid].id=i-mid;
			r[i-mid].nch=a[i][2];
			r[i-mid].toc=a[i][3];
		}
		sort(l+1,l+mid+1,cmp);
		sort(r+1,r+mid+1,cmp);
		for(int i=1;i<=mid;i++){
			if(l[i].val+r[i].val>0){
				l[i].nch=l[i].nch+l[i].val;
				r[i].nch=r[i].nch+r[i].val;
			}
			else break;
		}
		sort(l+1,l+mid+1,cmp1);
		sort(r+1,r+mid+1,cmp1);
		int p1=1,p2=mid+1,cnt=0;
		while(cnt!=mid){
			int ch1=l[p1].toc-l[p1].nch;
			int ch2=r[p2].toc-r[p2].nch;
			if(ch1<=0&&ch2<=0)break;
			if(ch1>ch2){
				cnt++;
				l[p1].nch=l[p1].toc;
				p1++;
			}
			else if(ch1<ch2){
				cnt++;
				r[p2].nch=r[p2].toc;
				p2++; 
			}
			else break;
		}
		int ans=0;
		for(int i=1;i<=mid;i++){
			ans+=l[i].nch+r[i].nch;
		}
		cout << ans << "\n";
		}
	}
	return 0;
}

