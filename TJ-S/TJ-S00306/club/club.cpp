/*
总体思路：按每名学生的第一志愿和第二志愿差值从大到小排（使用贪心大法使损耗最低） 
如某学生第一志愿人数已满直接填报第二志愿，永远不需要考虑第三志愿 （2*n/2=n） 
long long:所有不关于满意度具体值的不用开 
*/
#include <bits/stdc++.h>
using namespace std;
long long ans;
int t,n,a2,b2,c2; 
struct student{
	long long a;
	long long b;
	long long c;
	long long fir;//第一志愿满意度 
	int fir2;//第一志愿种类 1a2b3c
	long long sec;//第二志愿满意度 
}l[100010];
bool cmp(student a,student b){
	return a.fir-a.sec>b.fir-b.sec;//志愿差值从大到小 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		ans=0;//初始化
		cin>>n;
		//人数限制（志愿剩余数量） 
		a2=n/2;
		b2=n/2;
		c2=n/2;
		
		//志愿选择 
		for(int j=1;j<=n;j++){
			scanf("%d %d %d",&l[j].a,&l[j].b,&l[j].c);
			if(l[j].a>=l[j].c&&l[j].a>=l[j].b){//第一志愿是a 
				l[j].fir=l[j].a;
				l[j].fir2=1;
				l[j].sec=max(l[j].b,l[j].c);//选第二志愿 
			}else if(l[j].b>=l[j].c&&l[j].b>=l[j].a){//第一志愿是b 
				l[j].fir=l[j].b;
				l[j].fir2=2;
				l[j].sec=max(l[j].a,l[j].c);//选第二志愿 
			}else{//剩下的第一志愿就是c了 
				l[j].fir=l[j].c;
				l[j].fir2=3;
				l[j].sec=max(l[j].b,l[j].a);//选第二志愿 
			}
		}
		sort(l+1,l+1+n,cmp);
		
		//按顺序填报志愿 
		for(int j=1;j<=n;j++){
			if(l[j].fir2==1){//第一志愿是a 
			    if(a2!=0){//志愿没有被抢光 
			    	ans+=l[j].fir;
			    	a2--;
				}else{
					ans+=l[j].sec;
				}
			}else if(l[j].fir2==2){//第一志愿是b
			    if(b2!=0){//志愿没有被抢光 
			    	ans+=l[j].fir;
			    	b2--;
				}else{
					ans+=l[j].sec;
				}
			}else{//第一志愿是c
			    if(c2!=0){//志愿没有被抢光 
			    	ans+=l[j].fir;
			    	c2--;
				}else{
					ans+=l[j].sec;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
