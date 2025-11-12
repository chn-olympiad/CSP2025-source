#include <bits/stdc++.h> 
using namespace std;
struct m{
	long long a,b,c;
	char maxx;
} a[100005],cl;
bool amp(m a,m b){
	if(a.a != b.a) return a.a > b.a;
	return max(a.b,a.c) < max(b.b,b.c); 
}
bool bmp(m a,m b){
	if(a.b != b.b) return a.b > b.b;
	return max(a.a,a.c) < max(b.a,b.c); 
}
bool cmp(m a,m b){
	if(a.c != b.c) return a.c > b.c;
	return max(a.b,a.a) < max(b.b,b.a);
}
long long n,t,cnt,s,maxx;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		s = 0;
		cnt = 0;
		cl.a=0,cl.b=0,cl.c=0;
		cin >> n;
		for(long long i =1;i<=n;i++){
			cin >> a[i].a >> a[i].b >> a[i].c;
			maxx = max(a[i].a,max(a[i].b,a[i].c));
			if(maxx == a[i].a) a[i].maxx = 'a';
			else if(maxx == a[i].b) a[i].maxx = 'b';
			else if(maxx == a[i].c) a[i].maxx = 'c';
		}
		while(s < n){
			sort(a+1,a+n+1,amp);
			n -= s;
			for(int i =1;i<=n and cl.a < n/2;i++){
				if(a[i].maxx == 'b'){
					if(cl.b == n/2){
						if(a[i].a < a[i].c){
							a[i].maxx = 'c';
						}else a[i].maxx = 'a';
					}
					continue;
				}
				if(a[i].maxx == 'c'){
					if(cl.c == n/2){
						if(a[i].a < a[i].b){	
							a[i].maxx = 'b';
						}else a[i].maxx = 'a';
					}
					continue;
				}
				cnt += a[i].a;
				cl.a++;
				a[i].c = 0;
				a[i].b = 0;
				a[i].a = 0;
				s++;
			}
			sort(a+1,a+n+1,bmp);
			for(int i =1;i<=n and cl.b < n/2;i++){
				if(a[i].maxx == 'a'){
					if(cl.a == n/2){
						if(a[i].b < a[i].c){
							a[i].maxx = 'c';
						}else a[i].maxx = 'b';
					}
					continue;
				}
				if(a[i].maxx == 'c'){
					if(cl.c == n/2){
						if(a[i].b < a[i].a){
							a[i].maxx = 'a';
							
						}else a[i].maxx = 'b';
					}
					continue;
				}
				cnt += a[i].b;
				a[i].a = 0;
				a[i].b = 0;
				a[i].c = 0;
				cl.b++;
				s++;
			}
			sort(a+1,a+n+1,cmp);
			for(int i =1;i<=n and cl.c < n/2;i++){
				if(a[i].maxx == 'a'){
					if(cl.a == n/2){
						if(a[i].c < a[i].b){
							a[i].maxx = 'b';
						}else a[i].maxx = 'c';
					}
					continue;
				}
				if(a[i].maxx == 'b'){
					if(cl.b >= n/2){
						if(a[i].c < a[i].a){
							a[i].maxx = 'a';
							
						}else a[i].maxx = 'c';
					}
					continue;
				}
				cnt += a[i].c;
				a[i].a = 0;
				a[i].b = 0;
				a[i].c = 0;
				cl.c++;
				s++;
			}
			//cout << cl.a << ":" << cl.b << ":" << cl.c << endl;
		}
		cout << cnt<<endl;
	}
//147325
//125440
//152929
//150176
//158541

	return 0;
}
