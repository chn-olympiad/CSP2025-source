#include<bits/stdc++.h>
#define m_n(a,b) (a<b?a:b)
using namespace std;
const int N=1e5+5;
struct ppp{
	int a,b,c;
	int i;
}x[N],a[N],b[N],c[N];
bool amp(ppp a,ppp b){
	return m_n(a.a-a.b,a.a-a.c)>m_n(b.a-b.b,b.a-b.c);
}
bool bmp(ppp a,ppp b){
	return m_n(a.b-a.a,a.b-a.c)>m_n(b.b-b.a,b.b-b.c);
}
bool cmp(ppp a,ppp b){
	return m_n(a.c-a.b,a.c-a.a)>m_n(b.c-b.b,b.c-b.a);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//有显然n^3dp
	//性质AB可O(n^2)
	//推广后发现可以根据每个大小初始分配 
	//然而如果一个club超过n/2则其他不会 
	//所以我们要做的只有止损，即按差排序 
	//好题，看似张牙舞爪实则签到，不愧是T1 
	int t,n,m,sa,sb,sc,ans;
	cin>>t;
	while(t--){
		cin>>n;
		m=n/2;
		ans=sa=sb=sc=0;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			x[i].i=i;
			if(x[i].a>x[i].b){
				if(x[i].a>x[i].c)a[++sa]=x[i];
				else c[++sc]=x[i];
			}else{
				if(x[i].b>x[i].c)b[++sb]=x[i];
				else c[++sc]=x[i];
			}
		}
		if(sa>m){
			sort(a+1,a+sa+1,amp);
			while(sa>m){
				if(a[sa].a-a[sa].b<a[sa].a-a[sa].c)b[++sb]=a[sa];
				else c[++sc]=a[sa];
				sa--;
			}
		}else if(sb>m){
			sort(b+1,b+sb+1,bmp);
			while(sb>m){
				if(b[sb].b-b[sb].a<b[sb].b-b[sb].c)a[++sa]=b[sb];
				else c[++sc]=b[sb];
				sb--;
			}
		}else if(sc>m){
			sort(c+1,c+sc+1,cmp);
			while(sc>m){
				if(c[sc].c-c[sc].b<c[sc].c-c[sc].a)b[++sb]=c[sc];
				else a[++sa]=c[sc];
				sc--;
			}
		}
//		cerr<<"\nA\n";
		for(int i=1;i<=sa;i++)ans+=a[i].a;//cerr<<a[i].i<<' ';
//		cerr<<"\nB\n";
		for(int i=1;i<=sb;i++)ans+=b[i].b;//cerr<<b[i].i<<' ';
//		cerr<<"\nC\n";
		for(int i=1;i<=sc;i++)ans+=c[i].c;//cerr<<c[i].i<<' ';
		cout<<ans<<'\n';
		memset(x,0,sizeof(x));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
	} 
//	cerr<<clock();
}
//你不过T1你过啥题啊（ 
//这倒是提醒我了，T1不开ll不会见祖宗，唐 
