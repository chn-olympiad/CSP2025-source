#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;

struct ord{
	int fir,sec,end;
	char or1,or2,or3;
}m[MAXN];

int T,n;
int vis[MAXN];
int a[MAXN],b[MAXN],c[MAXN];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			m[i].fir=a[i];
			m[i].sec=b[i];
			m[i].end=c[i];
			if(a[i]>=b[i]&&b[i]>=c[i])
				m[i].or1='a',m[i].or2='b',m[i].or3='c';
			else if(a[i]>=c[i]&&c[i]>=b[i])
				m[i].or1='a',m[i].or2='c',m[i].or3='b';
			else if(c[i]>=b[i]&&b[i]>=a[i])
				m[i].or1='c',m[i].or2='b',m[i].or3='a';
			else if(b[i]>=c[i]&&c[i]>=a[i])
				m[i].or1='b',m[i].or2='c',m[i].or3='a';
			else if(b[i]>=a[i]&&a[i]>=c[i])
				m[i].or1='b',m[i].or2='a',m[i].or3='c';
			else
				m[i].or1='c',m[i].or2='a',m[i].or3='b';
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		sort(c+1,c+1+n,cmp);
	
		ll ans=0,numa=0,numb=0,numc=0;
	
		for(int i=1;i<=n;i++){
			bool temp=false;
			if(m[i].or1=='a'&&a[n/2]<=m[i].fir&&numa<=n/2){
				ans+=m[i].fir;
				numa++;
				temp=true;
			}
			else if(m[i].or1=='b'&&b[n/2]<=m[i].sec&&numb<=n/2){
				ans+=m[i].sec;
				numb++;
				temp=true;
			}
			else if(m[i].or1=='c'&&c[n/2]<=m[i].end&&numc<=n/2){
				ans+=m[i].end;
				numc++;
				temp=true;
			}	
			if(!temp){
				if(m[i].or2=='a'&&a[n/2]<=m[i].fir&&numa<=n/2){
					ans+=m[i].fir;
					numa++;
					temp=true;
				}
				else if(m[i].or2=='b'&&b[n/2]<=m[i].sec&&numb<=n/2){
					ans+=m[i].sec;
					numb++;
					temp=true;
				}
				else if(m[i].or2=='c'&&c[n/2]<=m[i].end&&numc<=n/2){
					ans+=m[i].end;
					numc++;
					temp=true;
				}	
			}
			if(!temp){
				if(m[i].or3=='a'&&a[n/2]<=m[i].fir&&numa<=n/2){
					ans+=m[i].fir;
					numa++;
					temp=true;
				}
				else if(m[i].or3=='b'&&b[n/2]<=m[i].sec&&numb<=n/2){
					ans+=m[i].sec;
					numb++;
					temp=true;
				}
				else if(m[i].or3=='c'&&c[n/2]<=m[i].end&&numc<=n/2){
					ans+=m[i].end;
					numc++;
					temp=true;
				}	
			}
		}
		cout<<ans<<"\n";
	}
	


	return 0;
}