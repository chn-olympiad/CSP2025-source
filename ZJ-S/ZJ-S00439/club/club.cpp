#include<bits/stdc++.h>
using namespace std;
const int xn=1e5+5;int T,s,a[xn][3],b[3],c[xn],u[xn],l[xn],o;
template<typename T>inline void read(T &n){
	T w=1;n=0;char ch=getchar();
	while(!isdigit(ch)&&ch!=EOF){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)&&ch!=EOF)n=(n<<1)+(n<<3)+(ch&15),ch=getchar();
	n*=w;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(T);
	while(T--){
		read(s);for(int g=1;g<=s;g++)for(int v=0;v<3;v++)read(a[g][v]);int kk=0;
		for(int g=1;g<=s;g++){
			for(int v=0;v<3;v++)b[v]=a[g][v];sort(b,b+3),c[g]=b[2]-b[1];
			int k1=-1,k2=0;for(int v=0;v<3;v++)if(a[g][v]>k1)k1=a[g][v],k2=v;kk+=k1,u[g]=k2;
		}
		for(int v=0;v<3;v++)b[v]=0;
		for(int g=1;g<=s;g++)b[u[g]]++;
		for(int v=0;v<3;v++)if(b[v]>s/2){
			o=0;for(int g=1;g<=s;g++)if(u[g]==v)l[++o]=c[g];
			sort(l+1,l+1+o);
			for(int g=1;g<=b[v]-s/2;g++)kk-=l[g];
		}
		cout<<kk<<'\n';
	}
	return 0;
}
