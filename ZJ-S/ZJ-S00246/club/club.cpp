#include<bits/stdc++.h>
using namespace std;

struct node{
	int a,b,c;
//	bool used;
}a[100005];
int t;
int n;
int ans;
int cnta,cntb,cntc;

bool cmp(node a,node b){
	if(max(min(a.a - a.c,a.a - a.b),max(min(a.b - a.c,a.b - a.a),min(a.c - a.b,a.c - a.a))) == max(min(b.a - b.c,b.a - b.b),max(min(b.b - b.c,b.b - b.a),min(b.c - b.b,b.c - b.a)))){
		return max(a.a,max(a.b,a.c)) > max(b.a,max(b.b,b.c));
	}
	return max(min(a.a - a.c,a.a - a.b),max(min(a.b - a.c,a.b - a.a),min(a.c - a.b,a.c - a.a))) > max(min(b.a - b.c,b.a - b.b),max(min(b.b - b.c,b.b - b.a),min(b.c - b.b,b.c - b.a)));
}

int main(){
	ifstream cin("club.in");
	ofstream cout("club.out");
	cin>>t;
	while(t--){
		ans = 0;
		cin>>n;
		for(int i = 1;i <= n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		sort(a+1,a+n+1,cmp);
//		//////////////////
//		for(int i = 1;i <= n;i++){
//			cout<<a[i].a<<" "<<a[i].b<<" "<<a[i].c<<"\n";
//		}
//		//////////////////
		cnta = 0;
		cntb = 0;
		cntc = 0;
		for(int i = 1;i <= n;i++){
			if(a[i].a >= a[i].b && a[i].a >= a[i].c){
				if(cnta < n / 2){
					ans += a[i].a;
					cnta++;
				}else{
					if(a[i].b >= a[i].c){
						if(cntb < n / 2){
							ans += a[i].b;
							cntb++;
						}
					}else{
						if(cntc < n / 2){
							ans += a[i].c;
							cntc++;
						}
					}
				}
			}else if(a[i].b >= a[i].c){
				if(cntb < n / 2){
					ans += a[i].b;
					cntb++;
				}else{
					if(a[i].a >= a[i].c){
						if(cnta < n / 2){
							ans += a[i].a;
							cnta++;
						}
					}else{
						if(cntc < n / 2){
							ans += a[i].c;
							cntc++;
						}
					}
				}
			}else{
				if(cntc < n / 2){
					ans += a[i].c;
					cntc++;
				}else{
					if(a[i].a >= a[i].b){
						if(cnta < n / 2){
							ans += a[i].a;
							cnta++;
						}
					}else{
						if(cntb < n / 2){
							ans += a[i].b;
							cntb++;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
}
