#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
bool Men;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-') f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

int a[505],n,m;

bool cmp(int a,int b){
	return a>b;
}

bool Mbe;
signed main(){
//	printf("%.8lfMB\n",(&Mbe-&Men)/1000000.0);
//	freopen("seat3.in","r",stdin);
//	freopen("test.ans","w",stdout);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	int tot=n*m;
	for(int i=1;i<=tot;i++){
		a[i]=read();
	}
	int num=a[1];
	sort(a+1,a+1+tot,cmp);
	int nowat=0;
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				if(a[++nowat]==num){
					cout<<i<<' '<<j<<endl;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(a[++nowat]==num){
					cout<<i<<' '<<j<<endl;
					return 0;
				}
			}
		}
	}
	
	return 0;
} 
