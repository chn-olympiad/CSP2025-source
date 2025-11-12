//#include<bits/stdc++.h> ZJ-J01102
//using namespace std;
//#define int64 long long
//int dal[500002];
//const int maxk=2<<20;
//vector<int> rd[maxk];
//struct nd{
//	int l,r;
//	bool operator <(const nd& b)const{
//		if(this->r==b.r)return this->l>b.l;
//		return this->r<b.r;
//	}
//};
//vector<nd> wp;
//int main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
//	int n,k;
//	scanf("%d %d",&n,&k);
//	dal[0]=0;
//	rd[0].push_back(0);
//	for(int i=1;i<=n;++i){
//		scanf("%d",dal+i);
//		dal[i]^=dal[i-1];
//		int nw=k^dal[i];
//		int siz=rd[nw].size();
//		for(int j=0;j<siz;++j){
//			wp.push_back({rd[nw][j]+1,i});
//		}
//		rd[k^nw].push_back(i);
//	}
//	sort(wp.begin(),wp.end());
//	int lastr=0;
//	int cnt=0;
//	int wps=wp.size();
//	for(int i=0;i<wps;++i){
//		if(wp[i].l>lastr){
//			++cnt;
//			lastr=wp[i].r;
//		}
//	}
//	printf("%d\n",cnt);
//	return 0;
//}
//// chaotic code -> UNchaotic code Pls!
//// No Cang Jie?
//
//
////1st:WA
////Debug 1
////2nd:AC
////3rd:AC
////4th:AC
////5th:AC
////6th:AC 0.07ms
////7th:TLE >10s
////Timing
////8th:???
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
int dal[500002];
const int maxk=2<<20;
vector<int> rd[maxk];
struct nd{
	int l,r;
	bool operator <(const nd& b)const{
		if(this->r==b.r)return this->l>b.l;
		return this->r<b.r;
	}
};
vector<nd> wp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d %d",&n,&k);
	dal[0]=0;
	rd[0].push_back(0);
	for(int i=1;i<=n;++i){
		scanf("%d",dal+i);
		dal[i]^=dal[i-1];
		int nw=k^dal[i];
		int siz=rd[nw].size();
		if(siz!=0)
		wp.push_back({rd[nw][siz-1]+1,i});
		rd[k^nw].push_back(i);
	}
	sort(wp.begin(),wp.end());
	int lastr=0;
	int cnt=0;
	int wps=wp.size();
	for(int i=0;i<wps;++i){
		if(wp[i].l>lastr){
			++cnt;
//			printf("l->%d r->%d lastr->%d\n",wp[i].l,wp[i].r,lastr);
			lastr=wp[i].r;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
// chaotic code -> UNchaotic code Pls!
// No Cang Jie?


//1st:WA
//Debug 1
//2nd:AC
//3rd:AC
//4th:AC
//5th:AC
//6th:AC 0.07ms
//7th:TLE >10s
//Timing
//8th:RE So????????????
//9th:AC xor6.in/ans!!!!!!!
//So 100pts