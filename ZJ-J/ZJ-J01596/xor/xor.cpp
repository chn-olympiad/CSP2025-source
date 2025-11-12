//T3
//8:43~8:54
//9:21 idea
//9:27 AK!
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,V=2e6+5;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,k;
int a[N];
int sum[N];
int f[N];
int b[N];
//b[i]=sum[i]^k
//f[i]=f[j]+(b[j]==sum[i])
vector<int> vec;//b[j]
int c[V];//c[b[j]]
int nowmax;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]^a[i];
	for(int i=0;i<=n;i++)b[i]=sum[i]^k;
	vec.push_back(k);c[k]=1;nowmax=0;
	for(int i=1;i<=n;i++){
		if(c[sum[i]]==1){
			nowmax++;
			for(int j=0;j<vec.size();j++)c[vec[j]]=0;
			vec.clear();
			vec.push_back(b[i]);
			c[b[i]]=1;
		}else{
			vec.push_back(b[i]);
			c[b[i]]=1;
		}
	}
	write(nowmax);
	return 0;
}