//hhz RP++ SCORE++ pts++
//Aqx¸½Ìå 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int T;
int n;
struct node{
	int a,b,c;
}t[N];
int m[N],ch[N];
bool cmp(node x,node y){
	if(x.a==y.a){
		return x.b>y.b;
	}
	if(x.a==y.a&&x.b==y.b){
		return x.c>y.c;
	}
	else return x.a>y.a;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		int h=n/2,ans=0;
		int c1=0,c2=0,c3=0;
		for(int i=1;i<=n;i++){
			cin>>t[i].a>>t[i].b>>t[i].c;
			m[i]=max(max(t[i].a,t[i].b),max(t[i].b,t[i].c));
			//1da 2da cha
			int u=t[i].a,v=t[i].b,w=t[i].c;
			if(m[i]==u){
				u=0;
			}
			else if(m[i]==v){
				v=0;
			}
			else{
				w=0;
			}
			ch[i]=m[i]-max(max(u,v),max(v,w));
		}
		sort(t+1,t+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(m[i]==t[i].a){
				c1++;				
			}
			else if(m[i]==t[i].b){
				c2++;
			}
			else{
				c3++;
			}
			//c1
			if(c1>h){
				c1=h;
				if(c2<h&&c3<h){
					m[i]=max(t[i].b,t[i].c);
				}
				else if(c2>=h&&c3<h){
					m[i]=t[i].c;
				}
				else{
					m[i]=t[i].b;
				}
			}
			//c2
			if(c2>h){
				c2=h;
				if(c1<h&&c3<h){
					m[i]=max(t[i].a,t[i].c);
				}
				else if(c1>=h&&c3<h){
					m[i]=t[i].c;
				}
				else{
					m[i]=t[i].a;
				}
			}
			//c3
			if(c3>h){
				c3=h;
				if(c1<h&&c2<h){
					m[i]=max(t[i].a,t[i].b);
				}
				else if(c1>=h&&c2<h){
					m[i]=t[i].b;
				}
				else{
					m[i]=t[i].a;
				}
			}
		}
		bool flag=0;
		for(int i=2;i<=n;i++){
			if(ch[i]>ch[i-1]){
				flag=1;
			}
		}
		if(n==2){
			//cout<<"wa";
			if(flag==1){
				for(int i=2;i<=n;i++){
				ans+=m[i];
				ans+=ch[i]-ch[i-1];
				}
				ans+=m[1];
				cout<<ans<<"\n";
			}
			else{
				for(int i=1;i<=n;i++){
					ans+=m[i];
				}
				cout<<ans<<"\n";
			}
		}
		else{
			//cout<<"....";
			for(int i=1;i<=n;i++){
				ans+=m[i];
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
