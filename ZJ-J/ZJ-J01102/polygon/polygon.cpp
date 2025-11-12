#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define ffk .first.first
#define fsk .first.second
#define s_k .second
int line[5002];
map<pair<int,int >,int > dp[5002];
void insr(pair<pair<int,int >,int > r,int i){
	auto k=dp[i].find(r.first);
	if(k!=dp[i].end()){
		(*k).second+=r.second;
	}else{
		dp[i].insert(r);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",line+i);
	}
	sort(line+1,line+n+1);
	dp[0].insert({{0,0},1});
	//Ren He Wei Da De CNT Dou Cong Xiao Xiao De 1 Kai Shi
	for(int i=1;i<=n;++i){
		for(int j=0;j<i;++j){
			for(auto k:dp[j]){
				pair<pair<int,int>,int> da=k;
				da ffk+=line[i];
				++da fsk;
				insr(da,i);
			}
		}
	}
	//Java == C++(Wo Yao Shang Mi Huo Xing Wei!!!4 Ti De Dai Ma Dou Yao!!!) 
	int64 cnt=0;
	for(int i=1;i<=n;++i){
		for(auto j:dp[i]){
			int ff=(j)ffk;
			int fs=(j)fsk;
			int s_=(j)s_k;
			if(fs>=3&&ff>line[i]<<1){
				cnt+=s_;
			}
		}
	}
	printf("%lld\n",cnt);
	return 0;
}
// chaotic code -> UNchaotic code Pls!
// No Cang Jie?
//1st:AC
//2nd:WA
//debug
//3rd AC
//4th WA
//debug
//4th Dangerous WA
// AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAaaaaaaaaaaaaaaaaaaaaaaaaaaaa!!!
// 5th Undangerous AC!!!!!!!!!!
//6th TLE........
//7th Po Fang Le
//8th TLE++
//So 48pts?
//100+100+100+48=348pts?????
//Yin Wei Qian San Dao Dou Hen Hao Zuo Dui,Suo Yi Xie Yi Ge Bu Zhi Suo Yun De FREOPEN Hen He Li
//Jing Ran Mei You Yi Ti Yao Yong Dao int64,Hen Jing Ya(Xian Zai Bu Shi Le)
//Zhu He *** Yu *** 99 Ke Yi Jia RP!!Dan Shi Bi Xu Shi Da Jia Gong Ren De
//Ji Rou Ji Yi(scanf,printf,freopen) Jing Ran Rang Wo Zai Da Chu Kuo Hao Hou Xia Yi Shi De Da Shuang Ying Hao







//Di Yi Ti De Zi Jie Shu Jing Ran Wei 520!
// Wo De Xin Qing(Zui Gao 1000) :80 100 200 500 700 600 800 1000 700 600 630 500 300 204 700 560 940 940 940 