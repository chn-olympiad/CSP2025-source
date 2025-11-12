//SN-S00717 guohaoxuan xianguojigangwuqutieyizhongluganggaojizhongxue
#include<bits/stdc++.h>
using namespace std;
const int ghxN = 1e5 + 10;
const int ghxN2 = (1e5 / 2) + 10;
int ghxt,ghxn;
struct ghxuse{
	int ghxmy1;
	int ghxmy2;
	int ghxmy3;
}ghxa[ghxN];
int ghxbm1[ghxN2];
int ghxbm2[ghxN2];
int ghxbm3[ghxN2];
int ghxbms;
int ghxrs1 = 0,ghxrs2 = 0,ghxrs3 = 0;
unsigned long long js(){
	unsigned long long ans = 0;
	for(int i = 1;i <= ghxrs1;i++){
		ans += ghxa[ghxbm1[i]].ghxmy1;
	}
	for(int i = 1;i <= ghxrs2;i++){
		ans += ghxa[ghxbm2[i]].ghxmy2;
	}
	for(int i = 1;i <= ghxrs3;i++){
		ans += ghxa[ghxbm3[i]].ghxmy3;
	}
	return ans;
}
bool cmp(int a,int b){
	return ghxa[a].ghxmy1 > ghxa[b].ghxmy1;
}
bool cmp2(int a,int b){
	return ghxa[a].ghxmy2 > ghxa[b].ghxmy2;
}
bool cmp3(int a,int b){
	return ghxa[a].ghxmy3 > ghxa[b].ghxmy3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> ghxt;
	while(ghxt--){
		cin >> ghxn;
		ghxbms = ghxn / 2;
		ghxrs1 = 0,ghxrs2 = 0,ghxrs3 = 0;
		for(int ghxi = 1;ghxi <= ghxn;ghxi++){
			cin >> ghxa[ghxi].ghxmy1 >> ghxa[ghxi].ghxmy2 >> ghxa[ghxi].ghxmy3;
			int maxn = max(ghxa[ghxi].ghxmy1,max(ghxa[ghxi].ghxmy2,ghxa[ghxi].ghxmy3));
			if(maxn == ghxa[ghxi].ghxmy1){
				ghxrs1++;
				ghxbm1[ghxrs1] = ghxi;
			}
			else if(maxn == ghxa[ghxi].ghxmy2){
				ghxrs2++;
				ghxbm2[ghxrs2] = ghxi;
			}
			else{
				ghxrs3++;
				ghxbm3[ghxrs3] = ghxi;
			}
		}
		sort(ghxbm1 + 1,ghxbm1 + ghxrs1 + 1,cmp);
		if(ghxrs1 > ghxbms){
			for(int j = ghxrs1;j > ghxbms;j--){
				ghxrs2++;
				ghxbm2[ghxrs2] = ghxbm1[j];
				ghxbm1[j] = 0;
			}
			ghxrs1 = ghxbms;
		}
		sort(ghxbm2 + 1,ghxbm2 + ghxrs2 + 1,cmp2);
		if(ghxrs2 > ghxbms){
			for(int j = ghxrs2;j > ghxbms;j--){
				ghxrs3++;
				ghxbm3[ghxrs3] = ghxbm2[j];
				ghxbm2[j] = 0;
			}
		}
		sort(ghxbm3 + 1,ghxbm3 + ghxrs3 + 1,cmp3);
		if(ghxrs3 > ghxbms){
			for(int j = ghxrs3;j > ghxbms;j--){
				if(ghxrs1 < ghxbms){
					ghxrs1++;
					ghxbm1[ghxrs1] = ghxbm3[j];
					ghxbm3[j] = 0;
				}
				if(ghxrs2 < ghxbms){
					ghxrs2++;
					ghxbm2[ghxrs2] = ghxbm3[j];
					ghxbm3[j] = 0;
				}
			}
		}
		cout << js() << "\n";
	}
	return 0;
}

