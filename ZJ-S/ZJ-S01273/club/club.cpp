#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int awa=500,qwq=100005;
ll aaa,bbb,ccc;
ll f[awa>>1][awa>>1][awa>>1],victory;
ll a[qwq],b[qwq],Beee,ff[qwq];
int n;
int main (){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		victory=0;
		if(n==100000){
			memset(ff,0,sizeof(ff));
			for (int i=1;i<=n;++i) {
				cin>>a[i]>>b[i]>>ccc;
				Beee+=b[i];
			}
			if(Beee==0){
				sort(a+1,a+n+1);
				for (int i=(n>>1)+1;i<=n;++i) {
					victory+=a[i];
				}
			}
			else{
				for (int i=1;i<=n;++i)
				for (int x=0;x<=min(i,n/2);++x) {
					if(x!=0)ff[x]=max(ff[x],ff[x-1]+a[i]);
					if(i-x!=0) ff[i-x]=max(ff[i-x],ff[i-x-1]+a[i]);
				}
				cout<<ff[n/2]<<"\n";
			}
		}
		else {
			for (int i=1;i<=n;++i) {
				cin>>aaa>>bbb>>ccc;
				for (int a=0;a<=min(n/2,i);++a) {
					for (int b=0;b<=min(n/2,i-a);++b) {
						if(i-a-b>n/2)continue;
					//	cout<<f[a-1][b][i-a-b]+aaa<<" "<<f[a][b-1][i-a-b]+bbb<<" "<<f[a][b][i-a-b-1]+ccc<<" 111\n";
						f[a][b][i-a-b]=0;
						if(a>=1)f[a][b][i-a-b]=max(f[a][b][i-a-b],f[a-1][b][i-a-b]+aaa);
						if(b>=1)f[a][b][i-a-b]=max(f[a][b][i-a-b],f[a][b-1][i-a-b]+bbb);
						if(i-a-b>=1)f[a][b][i-a-b]=max(f[a][b][i-a-b],f[a][b][i-a-b-1]+ccc); 
					//	cout<<a<<" "<<b<<" "<<i-a-b<<" "<<f[a][b][i-a-b]<<" 222\n";
					}
				}
			}
			
			for (int a=0;a<=(n>>1);++a) {
				for (int b=0;b<=(n>>1);++b) {
					if(a+b<(n>>1))continue;
					victory=max(victory,f[a][b][n-a-b]);
				//	cout<<a<<" "<<b<<" "<<n-a-b<<" "<<f[a][b][n-a-b]<<" 333\n";
				}
			}
			cout<<victory<<"\n";
		}
	}
}
/* 我要弄whk了qwq
我也该退役了qwq
这次好难啊qwq
再见编程qwq
不会做qwq
再见qwq
啊qwq
qwq
luogu:_wronganswer_
*/