#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=105;
int n,m,a[N],x,s_1,s_2;
inline int read(){
	int t=1,tot=0;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') t=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		tot=tot*10+ch-'0';
		ch=getchar();
	}
	return tot*t;
}
inline int cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(); m=read();
	for(int i=1;i<=n*m;i++) a[i]=read();
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			x=i;
			break;
		}
	}
	if(x%n!=0) s_1=x/n+1;
	else s_1=x/n;
	if(s_1&1){
		if(x%n!=0) s_2=x%n;
		else s_2=n;
	}
	else{
		if(x%n!=0) s_2=n-(x%n)+1;
		else s_2=1;
	}
	cout<<s_1<<" "<<s_2<<endl;
	return 0;
}
/*#Shang4Shan3Ruo6Shui4*/
