#include<bits/stdc++.h>
using namespace std;
long long t,n,m,s,mx,cnt;
struct stu{
	int a,b,c;
} a[100010];
bool cmp1(stu a,stu b){
	if(a.a==b.a){
		if(a.b==a.b){
			return a.c>a.c;
		}
		return a.b>b.b;
	}
	return a.a>b.a;
}
bool cmp2(stu a,stu b){
	if(a.b==b.b){
		if(a.a==a.a){
			return a.c>a.c;
		}
		return a.a>b.a;
	}
	return a.b>b.b;
}
bool cmp3(stu a,stu b){
	if(a.c==b.c){
		if(a.a==a.a){
			return a.b>a.c;
		}
		return a.a>b.a;
	}
	return a.c>b.c;
}
int sort1(){
	sort(a+1,a+n+1,cmp1);
	m=0;
	for(int i=1;i<=n/2;i++){
		m+=a[i].a;
	}
	return m;
}
int sort2(){
	sort(a+1,a+n+1,cmp2);
	m=0;
	for(int i=1;i<=n/2;i++){
		m+=a[i].b;
	}
	return m;
}
int sort3(){
	sort(a+1,a+n+1,cmp3);
	m=0;
	for(int i=1;i<=n/2;i++){
		m+=a[i].c;
	}
	return m;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		mx=0;
		if(sort1()>sort2()&&sort1()>sort3()){
			s=sort1();
			for(int i=n/2+1;i<=n;i++){
				cnt=0;
				for(int j=n/2+1;j<=i;j++){
					cnt+=a[j].b;
				}
				for(int j=i+1;j<=n;j++){
					cnt+=a[j].c;
				}
				mx=max(mx,cnt);
			}
		}else if(sort2()>sort1()&&sort2()>sort1()){
			s=sort2();
			for(int i=n/2+1;i<=n-1;i++){
				cnt=0;
				for(int j=n/2+1;j<=i;j++){
					cnt+=a[j].a;
				}
				for(int j=i+1;j<=n;j++){
					cnt+=a[j].c;
				}
				mx=max(mx,cnt);
			}
		}else{
			s=sort3();
			for(int i=n/2+1;i<=n-1;i++){
				cnt=0;
				for(int j=n/2+1;j<=i;j++){
					cnt+=a[j].a;
				}
				for(int j=i+1;j<=n;j++){
					cnt+=a[j].c;
				}
				mx=max(mx,cnt);
			}
		}
		cout<<s+mx<<"\n";
	}
	return 0;
}