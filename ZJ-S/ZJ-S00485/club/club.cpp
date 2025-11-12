#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;

struct Member{
	int max_part,second_max_part;
	long long score[5];
}member[MAXN];

int T;
int n;
long long f_dvd[5][MAXN];
int member_num[5];
int max_member;

bool cmp_member(int a,int b){
	return member[a].score[member[a].max_part] - member[a].score[member[a].second_max_part] < member[b].score[member[b].max_part] - member[b].score[member[b].second_max_part];
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&T);
	while(T--){
		member_num[1] = 0;member_num[2] = 0;member_num[3] = 0;
		scanf("%d",&n);
		max_member = n / 2;
		for(int i = 1;i <= n;i++){
			scanf("%lld%lld%lld",&member[i].score[1],&member[i].score[2],&member[i].score[3]);
			//fist_divide & mark the two max_sore_part
			if(member[i].score[1] >= member[i].score[2] && member[i].score[1] >= member[i].score[3]){ //max == 1
				member[i].max_part = 1;
				f_dvd[1][++member_num[1]] = i;
				if(member[i].score[2] >= member[i].score[3]){
					member[i].second_max_part = 2;
				}else{
					member[i].second_max_part = 3;
				}
			}else if(member[i].score[2] >= member[i].score[1] && member[i].score[2] >= member[i].score[3]){ //max == 2
				member[i].max_part = 2;
				f_dvd[2][++member_num[2]] = i;
				if(member[i].score[1] >= member[i].score[3]){
					member[i].second_max_part = 1;
				}else{
					member[i].second_max_part = 3;
				}
			}else if(member[i].score[3] >= member[i].score[2] && member[i].score[3] >= member[i].score[1]){ //max == 3
				member[i].max_part = 3;
				f_dvd[3][++member_num[3]] = i;
				if(member[i].score[1] >= member[i].score[2]){
					member[i].second_max_part = 1;
				}else{
					member[i].second_max_part = 2;
				}
			}
		}
		if(member_num[1] <= max_member && member_num[2] <= max_member && member_num[3] <= max_member){
			//print first_divide's result
			long long ans = 0;
			for(int i = 1;i <= 3;i++){
				for(int j = 1;j <= member_num[i];j++){
					ans += member[f_dvd[i][j]].score[i];
				}
			}
			printf("%d\n",ans);
			continue;
		}
		//test: print f_dvd
//		for(int i = 1;i <= 3;i++){
//			printf("part:%d,member_num = %d\n",i,member_num[i]);
//			for(int j = 1;j <= member_num[i];j++){
//				printf("%d ",f_dvd[i][j]);
//			}
//			printf("\n");
//		}
		
		int ex_part;
		for(int i = 1;i <= 3;i++){
			if(member_num[i] > max_member){
				ex_part = i;
				break;
			}
		}
		sort(f_dvd[ex_part] + 1,f_dvd[ex_part] + 1 + member_num[ex_part],cmp_member);
		int tsp = member_num[ex_part] - max_member;
		for(int i = 1;i <= tsp;i++){
			f_dvd[member[f_dvd[ex_part][i]].second_max_part][++member_num[member[f_dvd[ex_part][i]].second_max_part]] = f_dvd[ex_part][i]; // less value member transported to second max part
			f_dvd[ex_part][i] = -1;
		}
		//test: print f_dvd
//		for(int i = 1;i <= 3;i++){
//			printf("part:%d,member_num = %d\n",i,max(member_num[i],max_member));
//			for(int j = 1;j <= member_num[i];j++){
//				printf("%d ",f_dvd[i][j]);
//			}
//			printf("\n");
//		}
		
		// result print
		long long ans = 0;
		for(int i = 1;i <= 3;i++){
			for(int j = 1;j <= member_num[i];j++){
				if(f_dvd[i][j] == -1){
					continue;
				}
				ans += member[f_dvd[i][j]].score[i];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

