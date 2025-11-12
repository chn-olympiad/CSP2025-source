#include<bits/stdc++.h>
#define froepen freopen
/*rp+++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++++
+++++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++++++++
+++++++++++++++++++++
++++++++++++++++++++++++
++++++++++++++++++++++
+++++++++++++++++
+++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++
++++++++++++++++++
+++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++++
+++++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++++++++
+++++++++++++++++++++
++++++++++++++++++++++++
++++++++++++++++++++++
+++++++++++++++++
+++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++
++++++++++++++++++*/
using namespace std;
const int ts=false;
int n;
struct stu{
	int d[3];
	int cur,i;
}a[100005];
int gemtax(const stu& x){
	int mx=-1;
	for(int i=0;i<3;++i){
		if(i!=x.cur){
			if(mx==-1)mx=i;
			else if(x.d[mx]<x.d[i])mx=i;
		}
	}
	return mx;
}
int gedt(const stu& x){
	int ret=x.d[x.cur];
	return ret-x.d[gemtax(x)];
}
bool cmpz(const stu& x,const stu& y){
		if(x.cur!=0&&y.cur!=0)return x.cur<y.cur;
		if(x.cur!=0&&y.cur==0)return false;
		if(x.cur==0&&y.cur!=0)return true;
		int ctx=gedt(x),cty=gedt(y);
		return ctx<cty;
	}
	bool cmpo(const stu& x,const stu& y){
		if(x.cur!=1&&y.cur!=1)return x.cur<y.cur;
		if(x.cur!=1&&y.cur==1)return false;
		if(x.cur==1&&y.cur!=1)return true;
		int ctx=gedt(x),cty=gedt(y);
		return ctx<cty;
	}
	bool cmpt(const stu& x,const stu& y){
		if(x.cur!=2&&y.cur!=2)return x.cur<y.cur;
		if(x.cur!=2&&y.cur==2)return false;
		if(x.cur==2&&y.cur!=2)return true;
		int ctx=gedt(x),cty=gedt(y);
		return ctx<cty;
	}
void enbalc(int i,int* cnt){
	sort(a,a+n,(i==0?cmpz:(i==1?cmpo:cmpt)));
	int j=0;
	while(cnt[i]>n/2){
		--cnt[i];
		a[j].d[a[j].cur]=-1;
		a[j].cur=gemtax(a[j]);
		++cnt[a[j].cur];
		++j;
	}
}
int main(){
	if(!ts){
		ios::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
		froepen("club.in","r",stdin);
		froepen("club.out","w",stdout);
	}
	unsigned long long rp=18446744073709551615ll;
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		assert(n%2==0);
		int cnt[3]={0,0,0};
		for(int i=0;i<n;++i){
			cin>>a[i].d[0]>>a[i].d[1]>>a[i].d[2];
			a[i].cur=-1;
			a[i].cur=gemtax(a[i]);
			a[i].i=i;
		//	cout<<gedt(a[i])<<" ";
			++cnt[a[i].cur];
		}//cout<<"\n";
		for(int i=0;i<3;++i){
			if(cnt[i]>n/2){
				enbalc(i,cnt);
				i=0;
			}
		}
		long long ans=0;
		for(int i=0;i<n;++i){
			ans+=a[i].d[a[i].cur];
		//	cout<<a[i].i<<" "<<a[i].cur<<"  ";
		}
		cout<<ans<<"\n";
	}
}