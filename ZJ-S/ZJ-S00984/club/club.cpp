#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;
const int MAX=1e5;
int t, n, club[3];
LL ans, s[3];
bool vis[MAX+5];
struct Student{
	LL data, redata;
	int club, num;
}stu[3][MAX+5];
bool cmp(Student a, Student b){
	return a.data>b.data;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	for(int _=0; _<t; _++){
		ans=0;
		memset(stu, 0, sizeof(stu));
		memset(vis, 0, sizeof(vis));
		memset(club, 0, sizeof(club));
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%lld %lld %lld", &s[0], &s[1], &s[2]);
			int minflag=1e9, minflag_=-1, maxflag=-1e9, maxflag_=-1, midflag=0;
			for(int kk=0; kk<2; kk++)
			for(int j=0; j<3; j++){
				if(s[j]>maxflag){
					maxflag_=j;
					maxflag=s[j];
				}else if(s[j]<minflag){
					minflag_=j;
					minflag=s[j];
				}
			}midflag=s[0]+s[1]+s[2]-maxflag-minflag;
			stu[0][i]={maxflag-midflag, maxflag, maxflag_, i};
			stu[2][i]={0, minflag, minflag_, i};
			stu[1][i]={midflag-minflag, midflag, 3-maxflag_-minflag_, i};
		}sort(stu[0], stu[0]+n, cmp);
		sort(stu[1], stu[1]+n, cmp);
		sort(stu[2], stu[2]+n, cmp);
		for(int j=0; j<3; j++){
			for(int o=0; o<n; o++){
				if(club[stu[j][o].club]<n/2 && !vis[stu[j][o].num]){
					club[stu[j][o].club]++;
					ans+=stu[j][o].redata;
					vis[stu[j][o].num]=true;
				}
			}
		}printf("%d\n", ans);
	}
}