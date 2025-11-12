#include<iostream>
#include<cstring>
using namespace std;
const int N=1e4+1;
const int M=3;
int s[N+1][M+1];
int f[N/2+1][N/2+1];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=M;j++){
				cin>>s[i][j];
			}
		}
		memset(f,0x80,sizeof(f));
		f[0][0]=0;
		for(int i=1;i<=n;i++){
			for(int a=min(i,n/2);a>=0;a--){
				for(int b=min(i-a,n/2);b>=max(0,i-a-n/2);b--){
					int c=i-a-b;
					int mx=0x8f8f8f8f;
//					if(a>0)mx=max(mx,f[a-1][b]+s[i][1]);
//					if(b>0)mx=max(mx,f[a][b-1]+s[i][2]);
//					if(c>0)mx=max(mx,f[a][b]+s[i][3]);
//					f[a][b]=max(f[a][b],mx);
					f[a][b]+=s[i][3];
					f[a][b]=max(f[a][b],max(f[a-1][b]+s[i][1],f[a][b-1]+s[i][2]));
				}
			}
		}
		int mx=0x8f8f8f8f;
		for(int a=0;a<=n/2;a++){
			for(int b=1;b<=n/2;b++){
				mx=max(mx,f[a][b]);
			}
		}
		cout<<mx<<endl;
	}
}
