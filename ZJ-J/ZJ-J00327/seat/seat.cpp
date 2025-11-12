/*
成绩全部不同
由高到低蛇形分配
共n*m个座位

找到座位

输入n,m
输入所有人的成绩1——n*m
第1个为小R的成绩
将成绩由低到高排序
看小R在第几名
并找到其位置
输出先列后行 
*/
#include<iostream>
#include<algorithm>
using namespace std;

int n,m;
int seat[15][15];
struct data{
	int number,a;
}s[105];

bool cmp(data l,data r)
{
	return l.a>r.a;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&s[i].a);
		s[i].number=i;
	}
	sort(s+1,s+n*m+1,cmp);
	int x;
	for(int i=1;i<=n*m;i++){
		if(s[i].number==1){
			x=i;
			break;
		}
	}
	int num=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				seat[j][i]=num;
				num++;
			}
		}else{
			for(int j=n;j>=1;j--){
				seat[j][i]=num;
				num++;
			}
		}
	}
	bool b=false;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(seat[i][j]==x){
				printf("%d %d",j,i);
				b=true;
				break;
			}
		}
		if(b){
			break;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	
	return 0;
}
