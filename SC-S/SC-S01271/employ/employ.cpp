#include<iostream>
#include<string>
#define RELEASE 1
#define DEBUG 0
using std::cout;
using std::endl;
using std::cin;

int n,m;
int maxvp = 0;
std::string s;
int c[5];
bool blocked[5] = {false};
int before_fail = 0;

void search(int k,int now){
	if (k>n){
		if (now>=m){
			maxvp++;
			now=0;
		}
		return;
	}
	for (int i=1;i<=n;i++){ //第i天第k人參加
		if (i==1 || (!blocked[i] && blocked[i-1])){
			if (before_fail >= c[k]){
				before_fail++;
				continue;
			}
			int old = before_fail;
			if (s[i-1] == '0'){
				before_fail++;
			}else{
				before_fail = 0;
				now++;
			}
			blocked[i]=true;

			search(k+1,now);

			blocked[i]=false;
			if (s[i-1] == '1'){
				now--;
			}
			before_fail = old;
		}else if (k==1 || blocked[i-1]){
			search(k+1,now);
		}
	}

}
int main()
{
	#if RELEASE
		freopen("employ.in","r",stdin);
		freopen("employ.out","w",stdout);
	#elif DEBUG
		freopen("employ1.in","r",stdin);
	#else
		;
	#endif
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}

	search(1,0);
	cout<<maxvp-1;
	return 0;
}

/*
Fail Mountain
17:
printf("编号为%d的君来了\n",k);
18:
printf("此君无有矣:%d\n",k);
19:
printf("有超过m个人，现在有:%d被录取，有%d次测试均可以\n",now,maxvp);
25:
printf("在此之前，有%d个人失败。现在是第%d天，今天已经被%d了\n",before_fail,i,blocked[i]);
32:
printf("君失败也，今天题目难度%c\n",s[i-1]);
34:
printf("君成功也，今天题目难度%c\n",s[i-1]);
*/