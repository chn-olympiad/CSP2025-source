#include<bits/stdc++.h>
using namespace std;
int n;
const int N=1e5+10;
struct node{
	int a,b,c;
}p[N];
bool cmp(int a,int b){
	return a>b;
}
struct node2{
	int num,index;
}mxn[N];
void solve(){
	int a[N],b[N],c[N];
	int ga[N/2],gb[N/2],gc[N/2];
	for(int i=1;i<=n;i++){
		a[i]=p[i].a;
		b[i]=p[i].b;
		c[i]=p[i].c;
	}
	int man=n/2;
	for(int i=1;i<=n;i++){
		if(a[i]>=b[i]){
			mxn[i].num=a[i];
			mxn[i].index=1;
		}else if(a[i]<b[i]){
			mxn[i].num=b[i];
			mxn[i].index=2;
		}
		if(mxn[i].num<c[i]){
			mxn[i].num=c[i];
			mxn[i].index=3;
		}
		if(a[i]==b[i]&&a[i]==c[i]){
			mxn[i].index=4;
		}
		
	}
	int p=1,pp=1,ppp=1;
	for(int i=1;i<=n;i++){
		if(mxn[i].index==1){
			ga[p]=mxn[i].num;
			p++;
		}else if(mxn[i].index==2){
			gb[pp]=mxn[i].num;
			pp++;
		}else if(mxn[i].index==3){
			gc[ppp]=mxn[i].num;
			ppp++;
		}
	}
	sort(ga+1,ga+1+p,cmp);
	sort(gb+1,gb+1+pp,cmp);
	sort(gc+1,gc+1+ppp,cmp);
	int sum2=0;
	for(int i=1;i<=man;i++){
		sum2+=ga[i]+gb[i]+gc[i];
	}
	cout<<sum2<<endl;
}
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int t;
cin>>t;
while(t--){
	cin>>n;
	bool a=1,b=1;
	for(int i=1;i<=n;i++){
		cin>>p[i].a>>p[i].b>>p[i].c;
		if(p[i].c!=0){
			a=0;
			b=0;
		}else if(p[i].b!=0){
			a=0;
		}
	}
	if(a==1){
		int sum=0;
		int a[N];
		for(int i=1;i<=n;i++)a[i]=p[i].a;
		sort(a+1,a+1+n,cmp); 
		for(int i=1;i<=n/2;i++){
			sum+=a[i];
		}
		cout<<sum<<endl;
	}else if(b==1){
		int sum=0;
		int a[N];
		int b[N];
		for(int i=1;i<=n;i++){
			a[i]=p[i].a;
			b[i]=p[i].b;
		}
		sort(a+1,a+1+n,cmp); 
		sort(b+1,b+1+n,cmp);
		for(int i=1;i<=n/2;i++){
			if(a[i]>=b[i]){
				sum+=a[i];
			}else{
				sum+=b[i];
			}
		}
		cout<<sum<<endl;
	}else{
		solve();
	}

}

fclose(stdin);
fclose(stdout);
	return 0;
}