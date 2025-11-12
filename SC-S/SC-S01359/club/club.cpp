#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
struct club{
	int a,b,c,ch;
}a[N];

int find1(club a){
	int num=max({a.a,a.b,a.c});
	if(num==a.a) return 1;
	if(num==a.b) return 2;
	if(num==a.c) return 3;
}

int add1(club a){
	if(find1(a)==1) return a.a;
	if(find1(a)==2) return a.b;
	if(find1(a)==3) return a.c;
}

int add2(club a){
	if(find1(a)==1) return max(a.b,a.c);
	if(find1(a)==2) return max(a.a,a.c);
	if(find1(a)==3) return max(a.a,a.b);
}

int find2(club a){
	if(add2(a)==a.a) return 1;
	if(add2(a)==a.b) return 2;
	if(add2(a)==a.c) return 3;
}

bool cmp(club a,club b){
	if(a.ch==b.ch) return add1(a)>add1(b);
	return a.ch>b.ch;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int cnt[4]={0},ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].ch=add1(a[i])-add2(a[i]);
		}
		sort(a+1,a+n+1,cmp);
//		for(int i=1;i<=n;i++){
//			cout<<a[i].a<<" "<<a[i].b<<" "<<a[i].c<<" "<<a[i].ch<<endl;
//		}
		for(int i=1;i<=n;i++){
			if(cnt[find1(a[i])]<n/2){
				ans+=add1(a[i]);
				cnt[find1(a[i])]++;
			}else{
				ans+=add2(a[i]);
				cnt[find2(a[i])]++;
			}
		}
		
		cout<<ans<<endl;
	}
	
	
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/