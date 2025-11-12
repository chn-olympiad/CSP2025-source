#include <bits/stdc++.h>
#define For(i,x,y) for(int (i)=(x);(i)<=(y);(i)++)
using namespace std;
const int N=1e5+5,M=2e4+5;
int t,n,ans,maxx,cho[N],num[4],cun[N],ove,v[M],k[4],bes;
int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x;
}
void write(int x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		For(i,1,n){
			k[1]=read(),k[2]=read(),k[3]=read();
			if(k[1]>=k[2]&&k[1]>=k[3]) bes=1;
			else if(k[2]>=k[3]&&k[2]>=k[1]) bes=2;
			else bes=3;
			ans+=k[bes];
			num[bes]++;
			cho[i]=bes;
			sort(k+1,k+4);
			cun[i]=k[3]-k[2];
			maxx=max(maxx,cun[i]);
		}
		if(num[1]>n/2) ove=1;
		else if(num[2]>n/2) ove=2;
		else if(num[3]>n/2) ove=3;
		if(ove){
			For(i,1,n) if(cho[i]==ove) v[cun[i]]++;
			For(i,0,maxx) while(v[i]&&num[ove]>n/2){
				ans-=i;
				v[i]--;
				num[ove]--;
			}
			For(i,0,maxx) v[i]=0;
		}
		write(ans);
		putchar(10);
		ans=maxx=num[1]=num[2]=num[3]=ove=0;
	}
	return 0;
}
