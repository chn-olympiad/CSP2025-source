#include<iostream>
#include<cstring>
#include<string>
int tmp[11];
const int N=5e5+10;
const int log=20;
int num[N];
//int num1[N];
long long f[N][2];
long long siz[1<<20];
//const long long mod=
int getxor(int st,int ed){
	return num[ed]^num[st-1];
}
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n;
	cin>>k;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		//num1[i]=num[i];
	}
	for(int i=1;i<=n;i++)num[i]=num[i]^num[i-1];
//	int q=0;
//	cin>>q;
//	for(int i=1;i<=q;i++){
//		int s,t;
//		cin>>s>>t;
//		cout<<getxor(s,t)<<endl;;
//	}
	memset(siz,0x80,sizeof(siz));
	for(int i=1;i<=n;i++){
		f[i][0]=max(f[i-1][0],f[i-1][1]);siz[num[i-1]]=max(siz[num[i-1]],f[i][0]);
		f[i][1]=max(f[i][1],siz[num[i]^k]+1);
		
	}
	cout<<max(f[n][1],f[n][0]);
	return 0;
}