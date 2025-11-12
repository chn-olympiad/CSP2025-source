#include <bits/stdc++.h>
using namespace std;
struct ww{
	int r;
	int q,w,e;
}a[100005];
int n,t,b,ja[4],dd[4][100005][3];
long long sum;
bool bx[100005];
bool cmp(ww x,ww y){
	return x.q>y.q;
}
bool cm(ww x,ww y){
	return x.w>y.w;
}
bool cp(ww x,ww y){
	return x.e>y.e;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(dd,0,sizeof(dd));
		memset(bx,0,sizeof(bx));
		cin>>n;
		sum=0;
		for(int i = 1;i<= n;i++){
			for(int j = 1;j<= 3;j++){
				cin>>a[i].q>>a[i].w>>a[i].e;
				a[i].r=i;
			}
		}
		b=n/2;
		int m =0;
		sort(a+1,a+n+1,cmp);
		for(int i = 1;i<=n;i++){
			dd[1][i][1]=a[i].q;
			dd[1][i][2]=a[i].r;
		}
		sort(a+1,a+n+1,cm);
		for(int i = 1;i<=n;i++){
			dd[2][i][1]=a[i].w;
			dd[2][i][2]=a[i].r;
		}
		sort(a+1,a+n+1,cp);
		for(int i = 1;i<=n;i++){
			dd[3][i][1]=a[i].e;
			dd[3][i][2]=a[i].r;
		}
		ja[1]=1;
		ja[2]=1;
		ja[3]=1;
		for(int i = 1;i<=b;i++){
			for(int j = ja[1];j<=n;j++){
				if(bx[dd[1][j][2]]==1){
					ja[1]++;
				}
				else
				{
					break;
				}
			}
			for(int j = ja[2];j<=n;j++){
				if(bx[dd[2][j][2]]==1){
					ja[2]++;
				}
				else
				{
					break;
				}
			}
			for(int j = ja[3];j<=n;j++){
				if(bx[dd[3][j][2]]==1){
					ja[3]++;
				}
				else
				{
					break;
				}
			}
			if(dd[1][ja[1]][1]>=dd[2][ja[2]][1]&&dd[1][ja[1]][1]>=dd[3][ja[3]][1])
			{
				sum+=dd[1][ja[1]][1];
				bx[dd[1][ja[1]][2]]=1;
				ja[1]++;
			}
			else if(dd[2][ja[2]][1]>=dd[1][ja[1]][1]&&dd[2][ja[2]][1]>=dd[3][ja[3]][1])
			{
				sum+=dd[2][ja[2]][1];
				bx[dd[2][ja[2]][2]]=1;
				ja[2]++;
			}
			else if(dd[3][ja[3]][1]>=dd[1][ja[1]][1]&&dd[3][ja[3]][1]>=dd[2][ja[2]][1])
			{
				sum+=dd[3][ja[3]][1];
				bx[dd[3][ja[3]][2]]=1;
				ja[3]++;
			}
		}
		cout<<sum<<endl;
	}
	
	return 0;
} 

