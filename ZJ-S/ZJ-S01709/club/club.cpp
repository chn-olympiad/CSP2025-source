#include"cstdio"
#include"queue"
#define ll long long
inline int min(int x,int y){return x<y?x:y;}
const int N=100010;
int n;
int a[N][5],mx[N],cnt[5];
ll sum;
std::priority_queue<int>pq;
void sol1(){
	for(int i=1;i<=n;i++){
		if(mx[i]==1)pq.push(-min(a[i][1]-a[i][2],a[i][1]-a[i][3]));
	}
	for(int i=1;i<=cnt[1]-n/2;i++){
		sum+=pq.top();pq.pop();
	}
	while(!pq.empty())pq.pop();
	printf("%lld\n",sum);
}
void sol2(){
	for(int i=1;i<=n;i++){
		if(mx[i]==2)pq.push(-min(a[i][2]-a[i][1],a[i][2]-a[i][3]));
	}
	for(int i=1;i<=cnt[2]-n/2;i++){
		sum+=pq.top();pq.pop();
	}
	while(!pq.empty())pq.pop();
	printf("%lld\n",sum);
}
void sol3(){
	for(int i=1;i<=n;i++){
		if(mx[i]==3)pq.push(-min(a[i][3]-a[i][1],a[i][3]-a[i][2]));
	}
	for(int i=1;i<=cnt[3]-n/2;i++){
		sum+=pq.top();pq.pop();
	}
	while(!pq.empty())pq.pop();
	printf("%lld\n",sum);
}
void sol(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
	sum=cnt[1]=cnt[2]=cnt[3]=0;
	for(int i=1;i<=n;i++){
		if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])mx[i]=1,cnt[1]++,sum+=a[i][1];
		else if(a[i][2]>a[i][3])mx[i]=2,cnt[2]++,sum+=a[i][2];
		else mx[i]=3,cnt[3]++,sum+=a[i][3];
	}
	if(cnt[1]>n/2)sol1();
	else if(cnt[2]>n/2)sol2();
	else if(cnt[3]>n/2)sol3();
	else {
		printf("%lld\n",sum);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)sol();
	return 0;
}
/*
//freopen("club.in","r",stdin);
//freopen("club.out","w",stdout);
上面是两行不明意义的代码，但我知道有人喜欢看。
在这里先说一件事：我是珊瑚宫心海的dog。
然后还有一件事：还有差不多2个月就要首考了，祝我认识的退役OIer首考顺利。
最后一件事：6.1下半卡池仆人别歪。
T1
14:48完成
*/
