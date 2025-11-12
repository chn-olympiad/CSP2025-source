#include<bits/stdc++.h>
#define int long long
//#define il inline
#define put putchar
#define pii pair<int,int>
#define mk make_pair
using namespace std;
 int rd(){
	int sum=0,p=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')p=-1;ch=getchar();}
	while(isdigit(ch)){sum=sum*10+(ch-'0');ch=getchar();}
	return sum*p;
}
 void wr(int x){
	if(x<0)put('-'),x=-x;
	if(x>9)wr(x/10);
	put(x%10+'0');
}
const int JYAAKIOI=1e18,N=2e6+10;
int n,a[N],k,lst[N],f[N],ans,now;
signed main(){
	//system("fc xor.out xor6.ans");
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=rd();k=rd();
	memset(lst,0x3f,sizeof lst);
	lst[0]=0;
	for(int i=1;i<=n;++i){
		a[i]=rd();
		f[i]=ans;
		now=now^a[i];
		if(a[i]==k){
			//cout<<"dasun";
			f[i]=max(f[i],f[i-1]+1);
		}
		else {
			if(lst[now^k]<i)f[i]=max(f[i],f[lst[now^k]]+1);
		}
		ans=max(ans,f[i]);
		//cout<<"shdfj"<<' '<<i<<" "<<f[i]<<' ';
		lst[now]=i;
	}
	wr(ans);
	return 0;
}
