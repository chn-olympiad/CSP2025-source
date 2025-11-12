#include<iostream>
#define RELEASE 1
#define DEBUG 0
using std::cout;
using std::endl;
using std::cin;

//CSP-S 2025 T1 - □ ×
//Ren5Jie4Di4Ling5%

const int N=1e+5;
int n;
int a[N+10][4];
int party[4]={0};
int maxv=0;

void reset()
{
	maxv=0;
	for (int i=1;i<=4;i++){
		party[i] = 0;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=3;j++){
			a[i][j] = 0;
			
		}
	}
}
void search(int k,int now)
{
	if (k > n){
		maxv = std::max(maxv,now);
		return;
	}
	for(int i=1;i<=3;i++){
		party[i]++;
		if (party[i] <= n/2){
			now+=a[k][i];
			search(k+1,now);
			now-=a[k][i],party[i]--;
		}else{
			party[i]--;
		}
	}
}
void mian()
{
	cin>>n;
	reset();
	for (int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	
	search(1,maxv);
	cout<<maxv<<endl;
}


int main(){ // freopen only
	
	#if RELEASE
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
	#elif DEBUG
		freopen("club2.in","r",stdin);
	#else
		;
	#endif

	int t;
	cin>>t;
	for (int i=1;i<=t;i++){
		mian();
	}
	return 0;
}

/*
Fail Mountain

33:
printf("选择的人:%d\n",k);
34:
printf("此人不存在:%d\n",k);
38:
printf("此人去了:%d号部门工作\n",i);
41,43:
printf("当前满意度 :%d，%d 号部门现在有：%d人\n",now,i,party[i]);
44:
printf("%d部分超过一半，现有人数:%d\n",i,party[i]);
*/