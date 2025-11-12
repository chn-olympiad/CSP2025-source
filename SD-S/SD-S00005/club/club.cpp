#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct NODE{
	int a1,a2,f1,f2,c;
}a[N];
struct node{
	int x,id;
}b[3]; 
int read(){
	int s=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*f;
}
bool cmp (node x,node y){
	return x.x>=y.x;
}
bool cmp2 (NODE x,NODE y){
	return x.c>x.c;
}
int t[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		memset(t,0,sizeof(t));
		long long ans=0;
		int n=read();
//		cout<<n;
		for(int i=1;i<=n;i++){
//			int b[3];
			b[0].x=read(),b[1].x=read(),b[2].x=read();
			b[0].id=0,b[1].id=1,b[2].id=2;
			sort(b,b+3,cmp);
			a[i].a1=b[0].x,a[i].a2=b[1].x;
			a[i].c=a[i].a1-a[i].a2;
			a[i].f1=b[0].id,a[i].f2=b[1].id;
//			cout<<a[i].a1<<' '<<a[i].a2<<endl;
//			cout<<b[0].x<<' '<<b[1].x<<endl;
		}
		sort(a+1,a+1+n,cmp2);
//		for(int i=1;i<=n;i++){
//			cout<<a[i].a1<<' '<<a[i].a2<<endl;
//		}
		for(int i=1;i<=n;i++){
			if(t[a[i].f1]<n/2){
				t[a[i].f1]++;
				ans+=a[i].a1;
			}
			else {
				t[a[i].f2]++;
				ans+=a[i].a2;
			}
			
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

