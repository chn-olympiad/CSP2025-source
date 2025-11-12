#include<bits/stdc++.h>
using namespace std;
struct str{
	int a, b, c;
};
str k[100010];
long long ans;
int T, cnta, cntb, cntc;
struct st{
	int w;
	int p;
};
st a[100010], b[100010], c[100010];

int cmp(str x, str y){
	if( x.a == y.a){
		if(x.b == y.b){
			return x.c > y.c;
		}
		else return x.b > y.b;
	}
	else return x.a > y.a;
}
int cmq(st x, st y){
	return x.w <= y.w;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w", stdout);
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		if(n > 2500){
			for(int i = 1; i <= n; i++){
				cin >> k[i].a >> k[i].b >> k[i].c; 
			}
			
			sort(k+1, k+1+n, cmp);
			
			cnta = 0, cntb = 0, cntc = 0;
			for(int i = 1; i <= n; i++){
				if(k[i].a > k[i].b && k[i].a > k[i].c){
					if(cnta < n/2){
						cnta++;
						ans += k[i].a;
					}
					else if(k[i].b > k[i].c){
						cntb++;
						ans += k[i].b;
					}
					else{
						cntc++;
						ans += k[i].c;
					}
				}
				else if(k[i].b > k[i].a && k[i].b > k[i].c){
					if(cntb < n/2){
						cntb++;
						ans += k[i].b;
					}
					else if(k[i].a > k[i].c){
						cnta++;
						ans += k[i].a;
					}
					else{
						cntc++;
						ans += k[i].c;
					}
				}
				else{
					if(cntc < n/2){
						cntc++;
						ans += k[i].c;
					}
					else if(k[i].a > k[i].b){
						cnta++;
						ans += k[i].a;
					}
					else{
						cntb++;
						ans += k[i].b;
					}
				}
			}
			cout << ans << "\n";
			ans = 0;
		}
		else{
			for(int i = 1; i <= n; i++){
				cin >> k[i].a >> k[i].b >> k[i].c; 
			}
			for(int i = 1; i <= n; i++){
				if(k[i].a > k[i].b && k[i].a > k[i].c){
					if(cnta < n/2){
						cnta++;
						a[cnta].p = i;
						a[cnta].w = k[i].a;
					}
					else{
						sort(a+1,a+1+cnta,cmq);
						int sumy = a[1].w + max(k[i].b, k[i].c);
						int sumx = k[i].a + max(k[a[1].p].b, k[a[1].p].c);
						if(sumy > sumx){
							if(k[i].b > k[i].c){
								cntb++;
								b[cntb].p = i;
								b[cntb].w = k[i].b;
							}
							else{
								cntc++;
								c[cntc].p = i;
								c[cntc].w = k[i].c;	
							}
						}
						else{
							if(k[a[1].p].b > k[a[1].p].c){
								cntb++;
								b[cntb].p = a[1].p;
								b[cntb].w = k[a[1].p].b;
							}
							else{
								cntc++;
								c[cntc].p = a[1].p;
								c[cntc].w = k[a[1].p].c;
							}
							a[1].p = i;
							a[1].w = k[i].a;
						}
					}
				}
				else if(k[i].b > k[i].a && k[i].b > k[i].c){
					if(cntb < n/2){
						cntb++;
						b[cntb].p = i;
						b[cntb].w = k[i].b;
					}
					else{
						sort(b+1,b+1+cntb,cmq);
						int sumy = b[1].w + max(k[i].a, k[i].c);
						int sumx = k[i].b + max(k[b[1].p].a, k[b[1].p].c);
						if(sumy > sumx){
							if(k[i].a > k[i].c){
								cnta++;
								a[cnta].p = i;
								a[cnta].w = k[i].a;
							}
							else{
								cntc++;
								c[cntc].p = i;
								c[cntc].w = k[i].c;
							}
						}
						else{
							if(k[b[1].p].a > k[b[1].p].c){
								cnta++;
								a[cnta].p = b[i].p;
								a[cnta].w = k[b[i].p].a;
							}
							else{
								cntc++;
								c[cntc].p = b[i].p;
								c[cntc].w = k[b[1].p].c;
							}
							b[1].p = i;
							b[1].w = k[i].b;	
						}
					}
				}
				else{
					if(cntc < n/2){
						cntc++;
						c[cntc].p = i;
						c[cntc].w = k[i].c;
					}
					else{
						sort(c+1,c+1+cntc,cmq);
						int sumy = c[1].w + max(k[i].a, k[i].b);
						int sumx = k[i].c + max(k[c[1].p].a, k[c[1].p].b);
						if(sumy > sumx){
							if(k[i].a > k[i].b){
								cnta++;
								a[cnta].p = i;
								a[cnta].w = k[i].a;
							}
							else{
								cntb++;
								b[cntb].p = i;
								b[cntb].w = k[i].b;
							}
						}
						else{
							if(k[c[1].p].a > k[c[1].p].b){
								cnta++;
								a[cnta].p = c[i].p;
								a[cnta].w = k[c[i].p].a;
							}
							else{
								cntb++;
								b[cntb].p = c[i].p;
								b[cntb].w = k[c[1].p].b;
							}
							c[1].p = i;
							c[1].w = k[i].c;
						}
					}	
				}
			}
			for(int i = 1; i <= cnta; i++){
				ans += a[i].w;
			}
			for(int i = 1; i <= cntb; i++){
				ans += b[i].w;
			}
			for(int i = 1; i <= cntc; i++){
				ans += c[i].w;
			}
			cout << ans << "\n";
			ans = 0; cnta = 0; cntb = 0; cntc = 0;
		}
	}
	
	return 0;
}
