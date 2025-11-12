#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e5+10;
int t,n;
struct node{
	int a, b, c;

}s[N];
bool cmpa(node & x , node & y){
	return x.a > y.a;
}
bool cmpb(node & x , node & y){
	return x.b > y.b;
}
bool cmpmax(node & x , node & y){
	int t = x.a;
	t = max(t,x.b);
	t = max(t,x.c);
	
	int t1 = y.a;
	t1 = max(t1,y.b);
	t1 = max(t1,y.c);
	return t > t1;
}
int ans = 0;
bool fa,fb;
int f[105][105][105];

signed main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%lld",&t);
	while(t--){
		
				// ¶à×é
		fa =1,fb=1;// Ä¬ÈÏÂú×ã 
		ans = 0;
		//cin >> n; 
		scanf("%lld",&n);
		memset(f,0,sizeof f);
		for(int i = 1; i <= n; i++){
			//cin >> s[i].a >>s[i].b >>s[i].c;
			scanf("%lld%lld%lld",&s[i].a,&s[i].b,&s[i].c);
			if(s[i].b!=0) fa = 0;
			if(s[i].c!=0) fb = 0;
		}
		if(fa ==1 && fb == 1) fa = 1;
		if(n == 2){
			ans = s[1].a + s[2].b;
			ans = max(ans,s[1].a + s[2].c);
			ans = max(ans,s[1].b + s[2].a);
			ans = max(ans,s[1].b + s[2].c);
			ans = max(ans,s[1].c + s[2].a);
			ans = max(ans,s[1].c + s[2].b);
		}else if(n <= 30  || n <= 200 && fa ==0 && fb == 0 ){
	
			for(int i = 1; i <= n; i++){
				for(int x = n/2; x >= 0; x--){
					for(int y = n/2; y >=0 ;y--){
							for(int z = n/2; z >=0 ;z--){
							if(x >= 1)f[x][y][z] = max(f[x][y][z],f[x-1][y][z] + s[i].a);
						//	cout << f[x][y][z] << " ";
							if(y>=1) f[x][y][z] = max(f[x][y][z],f[x][y-1][z] + s[i].b);
							//	cout << f[x][y][z] << " ";
							if(z >=1) f[x][y][z] = max(f[x][y][z],f[x][y][z-1] + s[i].c);
							//	cout << f[x][y][z] << " ";
							ans = max(ans,f[x][y][z]);
						}
					}
				}
			}
			
		} else if(n <= 200 && fb == 1){
			int z = n/2;
			for(int i = 1; i <= n; i++){
				for(int x = n/2; x >= 0; x--){
					for(int y = n/2; y >=0 ;y--){
						
							if(x >= 1)f[x][y][z] = max(f[x][y][z],f[x-1][y][z] + s[i].a);
						//	cout << f[x][y][z] << " ";
							if(y>=1) f[x][y][z] = max(f[x][y][z],f[x][y-1][z] + s[i].b);
							//	cout << f[x][y][z] << " ";
							ans = max(ans,f[x][y][z]);
						
					}
				}
			}
		}else if(fa){
			
			sort(s + 1,s + 1 + n,cmpa);
			
			for(int i = 1; i <= n/2 ; i++) ans += s[i].a;
			
			
		}else if(fb){
			
			int suma = 0;
			int sumb = 0;
			
			sort(s + 1,s + 1 + n,cmpa);
			for(int i = 1; i <= n/2 ; i++) suma += s[i].a;
			for(int i = n/2 + 1; i <= n ; i++) suma += s[i].b;
		
			sort(s + 1,s + 1 + n,cmpb);
			for(int i = 1; i <= n/2 ; i++) sumb += s[i].b;
			for(int i = n/2 + 1; i <= n ; i++) sumb += s[i].a;
			ans = max(suma,sumb);
			
		}else{
			
			int suma = 0;
			int sumb = 0;
			
			sort(s + 1,s + 1 + n,cmpa);
			for(int i = 1; i <= n/2 ; i++) suma += s[i].a;
			for(int i = n/2 + 1; i <= n ; i++) suma += s[i].b;
		
			sort(s + 1,s + 1 + n,cmpb);
			for(int i = 1; i <= n/2 ; i++) sumb += s[i].b;
			for(int i = n/2 + 1; i <= n ; i++) sumb += s[i].a;
			ans = max(suma,sumb);
			
			int summax = 0;
			int c1 = 0;
			int c2 = 0;
			int c3 = 0;
			sort(s + 1,s + 1 + n,cmpmax);
			for(int i = 1; i <= n; i++){
				if(s[i].a >= s[i].b && s[i].a >= s[i].c && c1 < n/2){
					summax += s[i].a;
					c1++;
				} else 	if(s[i].b >= s[i].a && s[i].b >= s[i].c && c2 < n/2){
					summax += s[i].b;
					c2++;
				}else{
						summax += s[i].c;
					c3++;
				}
				
			}
			
			ans = max(ans,summax);
		}
		
		
	//	cout << ans << endl;
	printf("%lld\n",ans);
	}
	

	return 0;
}
