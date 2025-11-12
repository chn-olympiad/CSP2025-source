#include <bits/stdc++.h>
using namespace std;

int t,n,a[10],ans=0,p,x=0,y=0,z=0,jian=10000000000,jianz;//t次,n人 

struct node{
	int maxn=-1,suoyinzhi,zhongg,minnn,who,minn=1000000000000000000000,zhong=-1;
}T[100006];

bool cmp(int x,int y){
	return x>y;
} 

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	
	for (int i=1;i<=t;i++){
		ans=0;
		cin >> n;
		p=n/2;
		for (int i=1;i<=n;i++){
			T[i].who=i;
			for (int j=1;j<=3;j++){
				cin >> a[j];
			}
			for (int j=1;j<=3;j++){
				if (T[i].maxn<a[j]) {
					T[i].maxn=a[j];
					T[i].suoyinzhi=j;
				}
				if (T[i].minn>a[j]) {
					T[i].minn=a[j];
					T[i].minnn=j;
				}
				if (T[i].zhong<T[i].maxn && T[i].zhong>T[i].minn) {
					T[i].zhong=a[j];
					T[i].zhongg=j;
				}
			}
		}
		for (int i=1;i<=n;i++){
			ans+=T[i].maxn;
		}
		x=0,y=0,z=0;
		for (int i=1;i<=3;i++){
			if (T[i].suoyinzhi==1)x++;
			else if (T[i].suoyinzhi==2)y++;
			else if (T[i].suoyinzhi==3)z++;
		}
		if (x>p){
			for (int j;j<=x-p;j++){
				for (int j;j<=n;j++){
					if (T[i].maxn<jian) {
						jian=T[i].maxn;
						jianz=i;
					}
				}
				ans-=jian;
				T[jianz].maxn=1000000000000000000000000000000;
				ans+=T[jianz].zhong;//加上第jianz个人第二大的 
			}
			
		}
		if (y>p){
			for (int j;j<=y-p;j++){
				for (int j;j<=n;j++){
					if (T[i].maxn<jian) {
						jian=T[i].maxn;
						jianz=i;
					}
				}
				ans-=jian;
				T[jianz].maxn=1000000000000000000000000000000;
				ans+=T[jianz].zhong;//加上第jianz个人第二大的 
			}
			
		}
		if (z>p){
			for (int j;j<=z-p;j++){
				for (int j;j<=n;j++){
					if (T[i].maxn<jian) {
						jian=T[i].maxn;
						jianz=i;
					}
				}
				ans-=jian;
				T[jianz].maxn=1000000000000000000000000000000;
				ans+=T[jianz].zhong;//加上第jianz个人第二大的 
			}

		}
		x=0,y=0,z=0;
		for (int i=1;i<=3;i++){
			if (T[i].zhongg==1)x++;
			else if (T[i].zhongg==2)y++;
			else if (T[i].zhongg==3)z++;
		}
		if (x>p){
			for (int j;j<=x-p;j++){
				for (int j;j<=n;j++){
					if (T[i].zhong<jian) {
						jian=T[i].zhong;
						jianz=i;
					}
				}
				ans-=jian;
				T[jianz].zhong=1000000000000000000000000000000;
				ans+=T[jianz].minn;//加上第jianz个人最小的 
			}
			
		}
		if (y>p){
			for (int j;j<=y-p;j++){
				for (int j;j<=n;j++){
					if (T[i].zhong<jian) {
						jian=T[i].zhong;
						jianz=i;
					}
				}
				ans-=jian;
				T[jianz].zhong=1000000000000000000000000000000;
				ans+=T[jianz].minn;//加上第jianz个人最小的 
			}
			
		}
		if (z>p){
			for (int j;j<=z-p;j++){
				for (int j;j<=n;j++){
					if (T[i].zhong<jian) {
						jian=T[i].zhong;
						jianz=i;
					}
				}
				ans-=jian;
				T[jianz].zhong=1000000000000000000000000000000;
				ans+=T[jianz].minn;//加上第jianz个人最小的 
			}

		}
		cout << ans << endl;
	}
	

	return 0;
}
