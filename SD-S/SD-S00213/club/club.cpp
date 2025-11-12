#include<bits/stdc++.h>
using namespace std;
#define go(i,l,r) for(int (i)=(l);(i)<=(r);++(i))

#define ll long long
//#define int ll

int read(){
	int w=1,x=0;
	char ch=getchar();
	while(ch<'0'||'9'<ch){
		if(ch=='-') w=-w;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=10*x+ch-'0';
		ch=getchar();
	}
	return w*x;
}

const int N=1e5+10;
const int M=1e4+10;
int t,n;
int cnt[4],de,ans;
struct lib{
	int id,x;
	bool operator <(const lib &alp)const{
		return x<alp.x;
	}
}b[4];
struct node{
	int fir,sec,thr;
	int idf,ids,idt;
	bool operator <(const node &x) const{
		if(fir==x.fir){
			if(sec==x.sec)
				return thr>x.thr;
			return sec>x.sec;
		}
		return fir>x.fir;
	}
}a[N];

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cnt[1]=cnt[2]=cnt[3]=0;
		ans=0;
		n=read();
		go(i,1,n){
			go(j,1,3){
				b[j].x=read();
				b[j].id=j;
			}
			sort(b+1,b+4);
			a[i].fir=b[3].x;
			a[i].idf=b[3].id;
			a[i].sec=b[2].x;
			a[i].ids=b[2].id;
			a[i].thr=b[1].x;
			a[i].idt=b[1].id;
		}
		sort(a+1,a+n+1);
		go(i,1,n){
			ans+=a[i].fir;
			cnt[a[i].idf]++;
		}
		priority_queue<int> pq;
		go(i,1,3){
			if(cnt[i]*2>n) de=i;
		}
		if(de==0){
			cout<<ans<<endl;
			continue;
		}
		go(i,1,n){
			if(a[i].idf==de) pq.push(a[i].sec-a[i].fir);
		}
		int sha=(2*cnt[de]-n)/2;
		go(i,1,sha){
			ans+=pq.top();
			pq.pop();
			cnt[de]--;
		}
		cout<<ans<<endl;
//		go(i,1,n){
//			cout<<a[i].fir<<' '<<a[i].sec<<' '<<a[i].thr<<endl;
//			cout<<a[i].idf<<' '<<a[i].ids<<' '<<a[i].idt<<endl;
//			cout<<endl;
//		}
//		cout<<"-----"<<endl;
	}
	return 0;
}
