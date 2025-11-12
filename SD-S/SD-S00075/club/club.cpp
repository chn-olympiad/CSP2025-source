#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,w=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')w=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return w*x;
}
int ostk[20],otop;
void print(int x){
	if(x==0){putchar('0');putchar(' ');return;}
	if(x<0){x=-x;putchar('-');}
	while(x){ostk[++otop]=x%10+48;x/=10;}
	while(otop){putchar(ostk[otop--]);}
	putchar(' ');
}
#define endline putchar('\n')
#define endl '\n'
const int N=1e5+5;
int T;
int n;
struct satistaction{
	int id;
	int d1,d2,d3;
	satistaction(int i=0,int a=0,int b=0,int c=0):id(i),d1(a),d2(b),d3(c){}
	void input(){
		d1=read(),d2=read(),d3=read();
	}
	int max(){
		return std::max({d1,d2,d3});
	}
	int min(){
		return std::min({d1,d2,d3});
	}
	int medium(){
		return d1+d2+d3-max()-min();
	}
	int maxid(){
		if(d1==max()) return 1;
		if(d2==max()) return 2;
		return 3;
	}
	int mediumid(){
		if(d1==medium()&&d1!=max()) return 1;
		if(d2==medium()&&d2!=max()) return 2;
		return 3;
	}
	int minid(){
		if(d1==min()&&d1!=medium()) return 1;
		if(d2==min()&&d2!=medium()) return 2;
		return 3;
	}
	int sum(){
		return d1+d2+d3;
	}
};
bool operator<(satistaction a,satistaction b){
//	if(a.max()>b.max()) return 1;
////	if(a.max()==b.max()&&a.sum()<b.sum()) return 1;
////	if(a.max()==b.max()&&a.sum()==b.sum()&&a.medium()>b.medium()) return 1;
////	if(a.max()==b.max()&&a.sum()==b.sum()&&a.medium()==b.medium()&&a.min()>b.min()) return 1;
//	if(a.max()==b.max()&&a.medium()<b.medium()) return 1;
//	if(a.max()==b.max()&&a.medium()==b.medium()&&a.min()<b.min()) return 1;
//	if(a.max()==b.max()&&a.medium()==b.medium()&&a.min()==b.min()&&a.id<b.id) return 1;
	if(a.d1<b.d1) return 1;
	if(a.d1==b.d1&&a.d2<b.d2) return 1;
	if(a.d1==b.d1&&a.d2==b.d2&&a.d3<b.d3) return 1;
	return 0;
}
satistaction a[N];
pair<int,array<int,5> > dp[N][5]; //dp[ i person ][ chose j club ] first:maxv, second:number_of_persons
void update(int i,int &maxi,int &medi,int &mini){
	if(dp[i][1].first>dp[i][2].first&&dp[i][2].first>dp[i][3].first){maxi=1,medi=2,mini=3;}
	else if(dp[i][1].first>dp[i][3].first&&dp[i][3].first>dp[i][2].first){maxi=1,medi=3,mini=2;}
	else if(dp[i][2].first>dp[i][1].first&&dp[i][1].first>dp[i][3].first){maxi=2,medi=1,mini=3;}
	else if(dp[i][2].first>dp[i][3].first&&dp[i][3].first>dp[i][1].first){maxi=2,medi=3,mini=1;}
	else if(dp[i][3].first>dp[i][1].first&&dp[i][1].first>dp[i][2].first){maxi=3,medi=1,mini=2;}
	else if(dp[i][3].first>dp[i][2].first&&dp[i][2].first>dp[i][1].first){maxi=3,medi=2,mini=1;}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
////	freopen("D:\\temp\\csps\\down\\club\\club1.in","r",stdin);
	T=read();
	while(T--){
		memset(dp,0,sizeof(dp));
		n=read();
		for(int i=1;i<=n;i++){
			a[i].input();
		}
		stable_sort(a+1,a+1+n);
		int dpmaxi=1,dpmedi=2,dpmini=3;
		for(int i=1;i<=n;i++){
			int maxi=a[i].maxid();
			int medi=a[i].mediumid();
			int mini=a[i].minid();
			if(dp[i-1][dpmaxi].second[maxi]==(n>>1)){
				dp[i][maxi]=make_pair(dp[i-1][dpmedi].first+a[i].max(),dp[i-1][dpmedi].second);
				dp[i][maxi].second[maxi]++;
			}else{
				dp[i][maxi]=make_pair(dp[i-1][dpmaxi].first+a[i].max(),dp[i-1][dpmaxi].second);
				dp[i][maxi].second[maxi]++;
			}
			if(dp[i-1][dpmaxi].second[medi]==(n>>1)){
				dp[i][medi]=make_pair(dp[i-1][dpmedi].first+a[i].medium(),dp[i-1][dpmedi].second);
				dp[i][medi].second[medi]++;
			}else{
				dp[i][medi]=make_pair(dp[i-1][dpmaxi].first+a[i].medium(),dp[i-1][dpmaxi].second);
				dp[i][medi].second[medi]++;
			}
			if(dp[i-1][dpmaxi].second[mini]==(n>>1)){
				dp[i][mini]=make_pair(dp[i-1][dpmedi].first+a[i].min(),dp[i-1][dpmedi].second);
				dp[i][mini].second[mini]++;
			}else{
				dp[i][mini]=make_pair(dp[i-1][dpmaxi].first+a[i].min(),dp[i-1][dpmaxi].second);
				dp[i][mini].second[mini]++;
			}
			update(i,dpmaxi,dpmedi,dpmini);
//			cout<<"a["<<i<<"].d1,d2,d3 = "<<a[i].d1<<" "<<a[i].d2<<" "<<a[i].d3;
//			endline;
//			print(dp[i][maxi].first);print(dp[i][maxi].second[1]);print(dp[i][maxi].second[2]);print(dp[i][maxi].second[3]);endline;
//			print(dp[i][medi].first);print(dp[i][medi].second[1]);print(dp[i][medi].second[2]);print(dp[i][medi].second[3]);endline;
//			print(dp[i][mini].first);print(dp[i][mini].second[1]);print(dp[i][mini].second[2]);print(dp[i][mini].second[3]);endline;
//			endline;
		}
		print(max({dp[n][1].first,dp[n][2].first,dp[n][3].first}));
		endline;
	}
	return 0;
}

