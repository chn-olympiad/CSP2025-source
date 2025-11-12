#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c,ab,bc,ca,id,f1,f2,f3,num;
}v[100005];
int n;
bool cmp(node x,node y){
	return x.num<y.num;
}
bool cmp1(node x,node y){
	return x.ab>y.ab;
}
bool cmp2(node x,node y){
	return x.bc>y.bc;
}
bool cmp3(node x,node y){
	return x.ca>y.ca;
}
void srt(int x){
	int l1=v[x].a,la=1;
	int l2=v[x].b,lb=2;
	int l3=v[x].c,lc=3;
	if(l3>l2){
		swap(l2,l3);
		swap(lb,lc);
	}
	if(l3>l1){
		swap(l3,l1);
		swap(lc,la);
	}
	if(l2>l1){
		swap(l2,l1);
		swap(lb,la);
	}
	v[x].f1=la;
	v[x].f2=lb;
	v[x].f3=lc;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>v[i].a>>v[i].b>>v[i].c;
		v[i].ab=abs(v[i].a-v[i].b);
		v[i].bc=abs(v[i].b-v[i].c);
		v[i].ca=abs(v[i].c-v[i].a);
		v[i].num=0;
		srt(i);
	}
	int last=1;
	sort(v+1,v+n+1,cmp1);
	for(int i=1;i<=n;i++){
		if(v[i].a!=v[i-1].a)last=i;
		v[i].num+=last;
	}
//	for(int i=1;i<=n;i++)cout<<v[i].a<<" "<<v[i].b<<" "<<v[i].c<<" "<<v[i].num<<endl;
//	cout<<endl;
	last=1;
	sort(v+1,v+n+1,cmp2);
	for(int i=1;i<=n;i++){
		if(v[i].b!=v[i-1].b)last=i;
		v[i].num+=last;
	}
//	for(int i=1;i<=n;i++)cout<<v[i].a<<" "<<v[i].b<<" "<<v[i].c<<" "<<v[i].num<<endl;
//	cout<<endl;
	last=1;
	sort(v+1,v+n+1,cmp3);
	for(int i=1;i<=n;i++){
		if(v[i].c!=v[i-1].c)last=i;
		v[i].num+=last;
	}
//	for(int i=1;i<=n;i++)cout<<v[i].a<<" "<<v[i].b<<" "<<v[i].c<<" "<<v[i].num<<endl;
//	cout<<endl;
	sort(v+1,v+n+1,cmp);
//	for(int i=1;i<=n;i++)cout<<v[i].a<<" "<<v[i].b<<" "<<v[i].c<<" "<<v[i].num<<endl;
	int fl[10]={0,0,0,0,0},ans=0;
	for(int i=1;i<=n;i++){
//		cout<<fl[1]<<" "<<fl[2]<<" "<<fl[3]<<"-/--<"<<n<<endl;
		int no=v[i].f1;
		if(fl[no]+1<=n/2){
			if(no==1)ans+=v[i].a;
			if(no==2)ans+=v[i].b;
			if(no==3)ans+=v[i].c;
			fl[no]++;
//		cout<<no<<"_"<<ans<<" ";
			continue;
		}
		no=v[i].f2;
		if(fl[no]+1<=n/2){
			if(no==1)ans+=v[i].a;
			if(no==2)ans+=v[i].b;
			if(no==3)ans+=v[i].c;
			fl[no]++;
//		cout<<no<<"_"<<ans<<" ";
			continue;
		}
		no=v[i].f3;
		if(fl[no]+1<=n/2){
			if(no==1)ans+=v[i].a;
			if(no==2)ans+=v[i].b;
			if(no==3)ans+=v[i].c;
			fl[no]++;
//		cout<<no<<"_"<<ans<<" ";
			continue;
		}
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

