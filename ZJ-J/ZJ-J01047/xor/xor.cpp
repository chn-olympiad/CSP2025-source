#include<bits/stdc++.h>
using namespace std;
#define int long long
bool st;
int n,m;
int a[500005];
int b[500005];
const int N=(1048576+5);
int book[N];
int sbook[N];
int fuckbook[N];
int ans;
bool ed;
signed main(){
//	cout<<(&st-&ed)/1024.0/1024.0<<endl;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1,j;i<=n;i++){
		cin>>a[i];
		b[i]=(b[i-1]^a[i]);
	}
	memset(fuckbook,~0x3f,sizeof(fuckbook));
	fuckbook[0]=0;
	for(int i=1;i<=n;i++){
		book[i]=0;
		int j=fuckbook[(b[i]^m)]+1;
		if(j>=1){
			book[i]=sbook[j-1]+1;
		}
//		for(int j=i;j>=1;j--){
//			if((b[i]^b[j-1])==m){
//				cout<<j<<"("<<b[j-1]<<","<<b[i]<<"^"<<m<<" "<<(m^b[i]);
//				book[i]=max(book[i],sbook[j-1]+1);
//				break;
//			}
//		}
		fuckbook[b[i]]=i;
		sbook[i]=max(sbook[i-1],book[i]);
	}
	cout<<sbook[n];
}
