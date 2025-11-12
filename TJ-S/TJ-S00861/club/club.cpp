#include<bits/stdc++.h>
using namespace std;
int T,n;
struct S{
	int a,b,c;
}a[100010];
int qx(int d){
	if(a[d].a>=a[d].b and a[d].a>=a[d].c) return 1;
	if(a[d].b>=a[d].a and a[d].b>=a[d].c) return 2;
	if(a[d].c>=a[d].a and a[d].c>=a[d].b) return 3;
}
struct St{
	int hgd,renshu;	
}t[100];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		for(int i=1;i<=100010;i++) a[i].a=a[i].b=a[i].c=0;
		for(int i=1;i<=100;i++) t[i].hgd =t[i].renshu=0;
		cin>>n;
		for(int i=1;i<=n;i++)	cin>>a[i].a>>a[i].b>>a[i].c;
		for(int i=1;i<=n;i++){
			int w=qx(i);
			if(t[w].renshu+1 <= n/2){
				t[w].renshu++;
				if(w==1) t[w].hgd += a[i].a;
				else if(w==2) t[w].hgd += a[i].b;
				else if(w==3) t[w].hgd += a[i].c;
			}
		} 
		long long ans=t[1].hgd+t[2].hgd+t[3].hgd;
		cout<<ans<<endl;
	}
	return 0;
} 
