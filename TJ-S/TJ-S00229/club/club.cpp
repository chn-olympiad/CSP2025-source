#include<bits/stdc++.h>
using namespace std;
struct club{int a,b,c;};
bool cmp(club a,club b){
	int maxa=max(a.a,max(a.b,a.c)),maxb=max(b.a,max(b.b,b.c));
	if(maxa==maxb){
		if(a.a==b.a){
			if(a.b==b.b){
				return a.c>b.c;
			}return a.b>b.b;
		}return a.a>b.a;
	}return maxa>maxb;
}int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=0;
	cin>>t;
	for(int iii=0;iii<t;iii++){
		club a[100005];
		int n,n2;
		cin>>n;
		n2=(n>>1);
		for(int i=0;i<n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}int c[3],cnt=0;
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++){
			int maxn=max(a[i].a,max(a[i].b,a[i].c));
			if(maxn==a[i].a){
				c[0]++;cnt+=a[i].a;
				if(c[0]>n2){
					c[0]--;
					cnt-=a[i].a;
					cnt+=max(a[i].b,a[i].c);
					c[max(a[i].b,a[i].c)==a[i].b?1:2]++;
				}
			}if(maxn==a[i].b){
				c[1]++;cnt+=a[i].b;
				if(c[1]>n2){
					c[1]--;
					cnt+=a[i].b;
					cnt+=max(a[i].a,a[i].c);
					c[max(a[i].a,a[i].c)==a[i].b?0:2]++;
				}
			}if(maxn==a[i].c){
				c[2]++;cnt+=a[i].c;
				if(c[2]>n2){
					c[2]--;
					cnt+=a[i].c;
					cnt+=max(a[i].b,a[i].a);
					c[max(a[i].b,a[i].a)==a[i].b?1:0]++;
				}
			}
		}cout<<cnt<<endl;
	}return 0;
}


