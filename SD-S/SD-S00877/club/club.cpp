#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long t,n;struct node{long long b,c,d;}a[100005];
bool cmp1(node e,node f){if(e.b==f.b){if(e.c==f.c){return e.d>f.d;}return e.c>f.c;}return e.b>f.b;}
bool cmp2(node e,node f){if(e.b==f.b){if(e.c==f.c){return e.d<f.d;}return e.c<f.c;}return e.b<f.b;}
bool cmp3(node e,node f){if(e.c==f.c){if(e.d==f.d){return e.b>f.b;}return e.d>f.d;}return e.c>f.c;}
bool cmp4(node e,node f){if(e.d==f.d){if(e.b==f.b){return e.c>f.c;}return e.b>f.b;}return e.d>f.d;}
bool cmp5(node e,node f){if(e.d==f.d){if(e.c==f.c){return e.b>f.b;}return e.c>f.c;}return e.d>f.d;}
bool cmp6(node e,node f){if(e.c==f.c){if(e.b==f.b){return e.d>f.d;}return e.b>f.b;}return e.c>f.c;}
bool cmp7(node e,node f){if(e.b==f.b){if(e.d==f.d){return e.c>f.c;}return e.d>f.d;}return e.b>f.b;}
bool cmp8(node e,node f){if(e.c==f.c){if(e.d==f.d){return e.b<f.b;}return e.d<f.d;}return e.c<f.c;}
bool cmp9(node e,node f){if(e.d==f.d){if(e.b==f.b){return e.c<f.c;}return e.b<f.b;}return e.d<f.d;}
bool cmp10(node e,node f){if(e.d==f.d){if(e.c==f.c){return e.b<f.b;}return e.c<f.c;}return e.d<f.d;}
bool cmp11(node e,node f){if(e.c==f.c){if(e.b==f.b){return e.d<f.d;}return e.b<f.b;}return e.c<f.c;}
bool cmp12(node e,node f){if(e.b==f.b){if(e.d==f.d){return e.c<f.c;}return e.d<f.d;}return e.b<f.b;}
long long so(){
	long long cnt=0,c1=0,c2=0,c3=0,m=n/2;
	for(long long i=1;i<=n;i++){
		if(a[i].b>=a[i].c&&a[i].b>=a[i].d){
			if(c1>=m){
				if(a[i].c>=a[i].d){
					if(c2>=m){
						cnt+=a[i].d;c3++;
					}else{
						cnt+=a[i].c;c2++;
					}
				}else{
					if(c3>=m){
						cnt+=a[i].c;c2++;
					}else{
						cnt+=a[i].d;c3++;
					}
				}
			}else{
				cnt+=a[i].b;c1++;
			}
		}else if(a[i].c>=a[i].b&&a[i].c>=a[i].d){
			if(c2>=m){
				if(a[i].b>=a[i].d){
					if(c1>=m){
						cnt+=a[i].d;c3++;
					}else{
						cnt+=a[i].b;c1++;
					}
				}else{
					if(c3>=m){
						cnt+=a[i].b;c1++;
					}else{
						cnt+=a[i].d;c3++;
					}
				}
			}else{
				cnt+=a[i].c;c2++;
			}
		}else if(a[i].d>=a[i].c&&a[i].d>=a[i].b){
			if(c3>=m){
				if(a[i].c>=a[i].b){
					if(c2>=m){
						cnt+=a[i].b;c1++;
					}else{
						cnt+=a[i].c;c2++;
					}
				}else{
					if(c1>=m){
						cnt+=a[i].c;c2++;
					}else{
						cnt+=a[i].b;c1++;
					}
				}
			}else{
				cnt+=a[i].d;c3++;
			}
		}
	}return cnt;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);cin>>t;
	while(t--){
		cin>>n;long long maxx=0;
		for(long long i=1;i<=n;i++){cin>>a[i].b>>a[i].c>>a[i].d;}
		sort(a+1,a+n+1,cmp1);maxx=max(maxx,so());
		sort(a+1,a+n+1,cmp2);maxx=max(maxx,so());
		sort(a+1,a+n+1,cmp3);maxx=max(maxx,so());
		sort(a+1,a+n+1,cmp4);maxx=max(maxx,so());
		sort(a+1,a+n+1,cmp5);maxx=max(maxx,so());
		sort(a+1,a+n+1,cmp6);maxx=max(maxx,so());
		sort(a+1,a+n+1,cmp7);maxx=max(maxx,so());
		sort(a+1,a+n+1,cmp8);maxx=max(maxx,so());
		sort(a+1,a+n+1,cmp9);maxx=max(maxx,so());
		sort(a+1,a+n+1,cmp10);maxx=max(maxx,so());
		sort(a+1,a+n+1,cmp11);maxx=max(maxx,so());
		sort(a+1,a+n+1,cmp12);maxx=max(maxx,so());
		cout<<maxx<<"\n";
	}
	return 0;
}
