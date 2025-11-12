#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
struct node{
	long long a,b,c,bi,id,mi,se;
	bool operator <(const node & a) const{
		return bi > a.bi;
	}
};
long long A[100100][3];
node cha[100100];
//a:0-1 b:1-2 c:0-2
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,n,i,j,ans = 0,cnt0=0,cnt1=0,cnt2=0,flag,flagb = 1,flagc = 1;
	cin>>t;
	while(t--){
		cin>>n;
		ans = 0;
		cnt0 = 0;
		cnt1 = 0;
		cnt2 = 0;
		for(i = 1;i <= n;i++){
			cin>>A[i][0]>>A[i][1]>>A[i][2];
			if(A[i][1] > 0 || A[i][2] > 0){
				flagc = 0;
			}
			if(A[i][2] > 0){
				flagc = 0;
			}
			cha[i].a = A[i][0] - A[i][1];
			cha[i].b = A[i][1] - A[i][2];
			cha[i].c = A[i][0] - A[i][2];
			cha[i].bi = max(abs(cha[i].a),max(abs(cha[i].b),abs(cha[i].c)));
			cha[i].id = i;
		}
		sort(cha+1,cha+1+n);
		if(flagb == 1){
			for(i = 0;i <= n;i++){
				cha[i].bi = A[cha[i].id][0];
			}
			sort(cha+1,cha+1+n);
			for(i = 0;i <= n/2;i++){
				ans += A[cha[i].id][0];
			}
			cout<<ans<<endl;
			continue;
		}
		if(flagc == 1){
			for(i = 0;i <= n;i++){
				cha[i].bi = cha[i].a;
			}
			sort(cha+1,cha+1+n);
			for(i = 0;i <= n/2;i++){
				ans += A[cha[i].id][0];
			}
			for(i = n/2+1;i <= n;i++){
				ans += A[cha[i].id][1];
			}
			cout<<ans<<endl;
			continue;
		}
		flag = 0;
		for(i = 1;i <= n;i++){
			if(cnt0 == n/2){
				if(flag == 0){
					for(j = i;j <= n;j++){
						cha[j].bi = abs(cha[j].b);
					}
					sort(cha+i,cha+n+1);
					flag = 1;
				}
				if(cha[i].b > 0){
					cnt1++;
					ans += A[cha[i].id][1];
					continue;
				}else{
					cnt2++;
					ans += A[cha[i].id][2];
					continue;
				}
			}else if(cnt1 == n/2){
				if(flag == 0){
					for(j = i;j <= n;j++){
						cha[j].bi = abs(cha[j].c);
					}
					sort(cha+i,cha+n+1);
					flag = 1;
				}
				if(cha[i].c > 0){
					cnt0++;
					ans += A[cha[i].id][0];
					continue;
				}else{
					cnt2++;
					ans += A[cha[i].id][2];
					continue;
				}
			}else if(cnt2 == n/2){
				if(flag == 0){
					for(j = i;j <= n;j++){
						cha[j].bi = abs(cha[j].a);
					}
					sort(cha+i,cha+n+1);
					flag = 1;
				}
				if(cha[i].a > 0){
					cnt0++;
					ans += A[cha[i].id][0];
					continue;
				}else{
					cnt1++;
					ans += A[cha[i].id][1];
					continue;
				}
			}
			if(abs(cha[i].a) == cha[i].bi){
				if(cha[i].a > 0){
					cnt0++;
					ans += A[cha[i].id][0];
					continue;
				}else{
					cnt1++;
					ans += A[cha[i].id][1];
					continue;
				}
			}else if(abs(cha[i].b) == cha[i].bi){
				if(cha[i].b > 0){
					cnt1++;
					ans += A[cha[i].id][1];
					continue;
				}else{
					cnt2++;
					ans += A[cha[i].id][2];
					continue;
				}
			}else{
				if(cha[i].c > 0){
					cnt0++;
					ans += A[cha[i].id][0];
					continue;
				}else{
					cnt2++;
					ans += A[cha[i].id][2];
					continue;
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}//30-50pts
