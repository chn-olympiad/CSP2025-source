#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=1e5+5;
int t,n,i,j,chao,ans;
int a[N][5],ma[N],zui[N],chamin[N][5],zhi[5],cha[N];
int read(){
	int op=1,x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')op=-1;
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	return op*x;
}
void out(int x){
	if(x<0){
		x=-x;cout<<"-";
	}
	if(x>=10){
		out(x/10);
	}
		cout<<x%10;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();chao=0;ans=0;zhi[1]=0;zhi[2]=0;zhi[3]=0;
		for(i=1;i<=n;i++)for(j=1;j<=3;j++)chamin[i][j]=1000000;
		for(i=1;i<=n;i++){
			a[i][1]=read();a[i][2]=read();a[i][3]=read();
			ma[i]=a[i][1];zui[i]=1;
			if(a[i][2]>ma[i])ma[i]=a[i][2],zui[i]=2;
			if(a[i][3]>ma[i])ma[i]=a[i][3],zui[i]=3;
			ans+=ma[i];
			++zhi[zui[i]];
			for(j=1;j<=3;j++){
				if(j!=zui[i]){
					chamin[i][zui[i]]=min(chamin[i][zui[i]],ma[i]-a[i][j]);
				}
			}
		}
		for(j=1;j<=3;j++){
			if(zhi[j]>n/2)chao=j;
		}
		if(chao==0){
			out(ans);cout<<endl;
		}
		else{
			for(i=1;i<=zhi[chao];i++){
				cha[i]=chamin[i][chao];
			}
			int len=zhi[chao];
			int gai=zhi[chao]-n/2;
			sort(cha+1,cha+len+1);
			for(i=1;i<=gai;i++){
				ans-=cha[i];
			}
			out(ans);cout<<endl;
		}
	}
	return 0;
}
