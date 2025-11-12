#include<bits/stdc++.h>
using namespace std;
struct node{
	long long da,db,dc;
	long long maxone,maxtwo,cha;
}a[100001];
int n;
long long cnt1,cnt2,cnt3,ans;
vector<node> tmp;
bool cmp(node a,node b){
	return a.cha<b.cha;
}
void calc1(){
	for(int i=1;i<=n;i++){
		if(a[i].maxone==a[i].da){
			tmp.push_back(a[i]);
		}
	}
	sort(tmp.begin(),tmp.end(),cmp);
	for(int i=0;i<cnt1-n/2;i++){
		ans-=tmp[i].cha;
	}
}
void calc2(){
	for(int i=1;i<=n;i++){
		if(a[i].maxone==a[i].db){
			tmp.push_back(a[i]);
		}
	}
	sort(tmp.begin(),tmp.end(),cmp);
	for(int i=0;i<cnt2-n/2;i++){
		ans-=tmp[i].cha;
	}
}
void calc3(){
		for(int i=1;i<=n;i++){
		if(a[i].maxone==a[i].dc){
			tmp.push_back(a[i]);
		}
	}
	sort(tmp.begin(),tmp.end(),cmp);
	for(int i=0;i<cnt3-n/2;i++){
		ans-=tmp[i].cha;
	}
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].da,&a[i].db,&a[i].dc);
		a[i].maxone=max(a[i].da,max(a[i].db,a[i].dc));
		if(a[i].maxone==a[i].da) a[i].maxtwo=max(a[i].db,a[i].dc);
		else if(a[i].maxone==a[i].db) a[i].maxtwo=max(a[i].da,a[i].dc);
		else if(a[i].maxone==a[i].dc) a[i].maxtwo=max(a[i].da,a[i].db);
		a[i].cha=a[i].maxone-a[i].maxtwo;
	}
	tmp.clear();
	cnt1=cnt2=cnt3=0;
	ans=0;
	for(int i=1;i<=n;i++){
		if(a[i].maxone==a[i].da){
			ans+=a[i].maxone;
			cnt1++;
		}
		else if(a[i].maxone==a[i].db){
			ans+=a[i].maxone;
			cnt2++;
		}
		else if(a[i].maxone==a[i].dc){
			ans+=a[i].maxone;
			cnt3++;
		}
	}
	if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
		cout<<ans<<'\n';
//		cout<<114514<<'\n';
		return;
	}
	if(cnt1>n/2){
		calc1();
//		cout<<1<<" "<<cnt1<<'\n';
	}
	else if(cnt2>n/2){
		calc2();
//		cout<<2<<" "<<cnt2<<'\n';
	}
	else if(cnt3>n/2){
		calc3();
//		cout<<3<<" "<<cnt3<<'\n';
	}
	cout<<ans<<endl;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) solve();	
	return 0;
}