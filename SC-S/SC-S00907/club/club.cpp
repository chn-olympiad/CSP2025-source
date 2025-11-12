#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,w=1;
	char ch=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*w;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	static int sta[35];
	int top=0;
	do{
		sta[++top]=x%10;
		x/=10;
	}while(x);
	while(top)putchar('0'+sta[top--]);
}
const int N=1e5+5;
int n;
struct node{
	int d1,d2,d3;
}a[N];
int cnt1,cnt2,cnt3;
vector<int>num[4];
bool cmp1(int x,int y){
	int val1=a[x].d1-max(a[x].d2,a[x].d3);
	int val2=a[y].d1-max(a[y].d2,a[y].d3);
	return val1<val2;
}
bool cmp2(int x,int y){
	int val1=a[x].d2-max(a[x].d1,a[x].d3);
	int val2=a[y].d2-max(a[y].d1,a[y].d3);
	return val1<val2;
}
bool cmp3(int x,int y){
	int val1=a[x].d3-max(a[x].d2,a[x].d1);
	int val2=a[y].d3-max(a[y].d2,a[y].d1);
	return val1<val2;
}
inline void work(){
	n=read();
	cnt1=cnt2=cnt3=0;
	for(int i=1;i<=3;i++)num[i].clear();
	for(int i=1;i<=n;i++){
		a[i].d1=read();
		a[i].d2=read();
		a[i].d3=read();
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		int mx=max({a[i].d1,a[i].d2,a[i].d3});
		if(mx==a[i].d1){
			ans+=a[i].d1;
			cnt1++;
			num[1].emplace_back(i);
			continue;
		}
		if(mx==a[i].d2){
			ans+=a[i].d2;
			cnt2++;
			num[2].emplace_back(i);
			continue;
		}
		if(mx==a[i].d3){
			ans+=a[i].d3;
			cnt3++;
			num[3].emplace_back(i);
			continue;
		}
	}
	sort(num[1].begin(),num[1].end(),cmp1);
	sort(num[2].begin(),num[2].end(),cmp2);
	sort(num[3].begin(),num[3].end(),cmp3);
	for(int i:num[1]){
		if(cnt1<=n/2)break;
		if(a[i].d2>a[i].d3){
			ans-=a[i].d1;
			cnt1--;
			if(cnt2<n/2){
				ans+=a[i].d2;
				cnt2++;
			}else{
				ans+=a[i].d3;
				cnt3++;
			}
		}else{
			ans-=a[i].d1;
			cnt1--;
			if(cnt3<n/2){
				ans+=a[i].d3;
				cnt3++;
			}else{
				ans+=a[i].d3;
				cnt2++;
			}
		}
	}
	for(int i:num[2]){
		if(cnt2<=n/2)break;
		if(a[i].d1>a[i].d3){
			ans-=a[i].d2;
			cnt2--;
			if(cnt1<n/2){
				ans+=a[i].d1;
				cnt1++;
			}else{
				ans+=a[i].d3;
				cnt3++;
			}
		}else{
			ans-=a[i].d2;
			cnt2--;
			if(cnt3<n/2){
				ans+=a[i].d3;
				cnt3++;
			}else{
				ans+=a[i].d1;
				cnt1++;
			}
		}
	}
	for(int i:num[3]){
		if(cnt3<=n/2)break;
		if(a[i].d2>a[i].d1){
			ans-=a[i].d3;
			cnt3--;
			if(cnt2<n/2){
				ans+=a[i].d2;
				cnt2++;
			}else{
				ans+=a[i].d1;
				cnt1++;
			}
		}else{
			ans-=a[i].d3;
			cnt3--;
			if(cnt1<n/2){
				ans+=a[i].d1;
				cnt1++;
			}else{
				ans+=a[i].d2;
				cnt2++;
			}
		}
	}
	write(ans);
	puts("");
}
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--)work();
	return 0;
}