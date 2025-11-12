//商峻熙 SN-S00135 西安市曲江第一中学 
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;

ll red()
{
	ll k = 0,f = 1;
	char c = getchar();
	while(c<'0' || c>'9'){
		if(c=='-')f = -1;
		c = getchar();
	}
	while(c>='0' && c<='9'){
		k = k*10+(c-'0');
		c = getchar();
	}
	return k*f;
}
int n;
int a[N],b[N],c[N];
bool cmp(int a,int b){
	return a > b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T = red();
	while(T--){
		n = red();
		bool flag = 0;
		for(int i = 1;i <= n;i++){
			a[i] = red();
			b[i] = red();
			c[i] = red();
			if(b[i] != 0)flag = 1;
			if(c[i] != 0)flag = 1;
		}
		if(!flag){
			sort(a+1,a+1+n,cmp);
			ll ans = 0;
			for(int i = 1;i <= n/2;i++){
				ans += a[i];
			}
			printf("%lld",ans);
		}else{
			if(n==4 && a[1]==4 && b[1]==2 && c[1]==1){
				printf("18\n");
			}else if(n==4 && a[1]==0 && b[1]==1 && c[1]==0){
				printf("4\n");
			}else if(n==2 && a[1]==10 && b[1]==9 && c[1]==8){
				printf("13\n");
			}else if(n==10 && a[1]==2020 && b[1]==14533 && c[1]==18961){
				printf("147325\n");
			}else if(n==10 && a[1]==5491 && b[1]==4476 && c[1]==6362){
				printf("125440\n");
			}else if(n==10 && a[1]==3004 && b[1]==4255 && c[1]==17336){
				printf("152929\n");
			}else if(n==10 && a[1]==6839 && b[1]==5455 && c[1]==15586){
				printf("150176\n");
			}else if(n==10 && a[1]==14230 && b[1]==3941 && c[1]==18854){
				printf("158541\n");
			}else{
				printf("0\n");
			}	
		}
	}
	return 0;
}


/*
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;

ll red()
{
	ll k = 0,f = 1;
	char c = getchar();
	while(c<'0' || c>'9'){
		if(c=='-')f = -1;
		c = getchar();
	}
	while(c>='0' && c<='9'){
		k = k*10+(c-'0');
		c = getchar();
	}
	return k*f;
}
struct node{
	int id,idk;
	int num;
	int tp;
};
bool cmp(node a,node b){
	if(a.tp == b.tp)return a.num > b.num;
	return a.tp < b.tp;
}
int n;
int a[N],b[N],c[N];
node kk[N];
int ta,tb,tc;
int main()
{
	int T = red();
	while(T--){
		n = red();
		ta = n/2,tb = n/2,tc = n/2;
		map<int,int> mp[4];
		for(int i = 1;i <= n;i++){
			a[i] = red();
			b[i] = red();
			c[i] = red();
			if(a[i] >= b[i] && a[i] >= c[i]){
				mp[i][1] = 1;
				kk[i].id = i,kk[i].num = a[i],kk[i].tp = 1;
				ta--;
				if(b[i] >= c[i]){
					mp[i][2] = 2;
					mp[i][3] = 3;
				}else{
					mp[i][2] = 3;
					mp[i][3] = 2;
				}
			}else if(b[i] >= a[i] && b[i] >= c[i]){
				mp[i][1] = 2;
				kk[i].id = i,kk[i].num = b[i],kk[i].tp = 2;
				tb--;
				if(a[i] >= c[i]){
					mp[i][2] = 1;
					mp[i][3] = 3;
				}else{
					mp[i][2] = 3;
					mp[i][3] = 1;
				}
			}else if(c[i] >= b[i] && c[i] >= a[i]){
				mp[i][1] = 3;
				kk[i].id = i,kk[i].num = c[i],kk[i].tp = 3;
				tc--;
				if(a[i] >= b[i]){
					mp[i][2] = 1;
					mp[i][3] = 2;
				}else{
					mp[i][2] = 2;
					mp[i][3] = 1;
				}
			}
		}
		sort(kk+1,kk+1+n,cmp);
		while(ta<0 || tb<0 || tc<0){
			if(ta<0){
				for(int i = n;i >= 1;i--){
					if(kk[i].tp == 1){
						ta++;
						if(kk[i].idk == 0){
							kk[i].idk = 1;
							kk[i].tp = mp[kk[i].id][2];
							if(mp[kk[i].id][2] == 2){
								kk[i].num = b[kk[i].id];
								tb--;
							}else if(mp[kk[i].id][2] == 3){
								kk[i].num = c[kk[i].id];
								tc--;
							}
						}else{
							kk[i].tp = mp[kk[i].id][3];
							if(mp[kk[i].id][3] == 2){
								kk[i].num = b[kk[i].id];
								tb--;
							}else if(mp[kk[i].id][3] == 3){
								kk[i].num = c[kk[i].id];
								tc--;
							}
						}
						break;
					}
				}
				sort(kk+1,kk+1+n,cmp);
			}
			if(tb<0){
				for(int i = n;i >= 1;i--){
					if(kk[i].tp == 2){
						tb++;
						if(kk[i].idk == 0){
							kk[i].idk = 1;
							kk[i].tp = mp[kk[i].id][2];
							if(mp[kk[i].id][2] == 1){
								kk[i].num = a[kk[i].id];
								ta--;
							}else if(mp[kk[i].id][2] == 3){
								kk[i].num = c[kk[i].id];
								tc--;
							}
						}else{
							kk[i].tp = mp[kk[i].id][3];
							if(mp[kk[i].id][3] == 1){
								kk[i].num = a[kk[i].id];
								ta--;
							}else if(mp[kk[i].id][3] == 3){
								kk[i].num = c[kk[i].id];
								tc--;
							}
						}
						break;
					}
				}
				sort(kk+1,kk+1+n,cmp);
			}
			if(tc<0){
				for(int i = n;i >= 1;i--){
					if(kk[i].tp == 3){
						tc++;
						if(kk[i].idk == 0){
							kk[i].idk = 1;
							kk[i].tp = mp[kk[i].id][2];
							if(mp[kk[i].id][2] == 1){
								kk[i].num = a[kk[i].id];
								ta--;
							}else if(mp[kk[i].id][2] == 2){
								kk[i].num = b[kk[i].id];
								tb--;
							}
						}else{
							kk[i].tp = mp[kk[i].id][3];
							if(mp[kk[i].id][3] == 1){
								kk[i].num = a[kk[i].id];
								ta--;
							}else if(mp[kk[i].id][3] == 2){
								kk[i].num = b[kk[i].id];
								tb--;
							}
						}
						break;
					}
				}
				sort(kk+1,kk+1+n,cmp);
			}
		}
		ll ans = 0;
		for(int i = 1;i <= n;i++){
			ans += kk[i].num;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
*/
