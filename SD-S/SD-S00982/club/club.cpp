/*对于所有人来说优先选最大的，对于已经满了的（等于n/2的），优先选最大的前n/2个
统计一下每个人如果按自己最满意的选会不会有社团超人数，如果没有直接这种方案*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+10;
struct ad{
	int user;
	int n1;//首轮 
	int n2;//次 
	int n3;//末 
	int k1;//自己的首位比次位大了多少，衡量他如果选这个能多贡献多少,唯一爆掉需要用到的，因为如果有超过n/2的社团，其他两个一定不爆； 
	int f1;//首轮是哪个 
	int f2;//次 
	int f3; //末 
}a[N][6];
struct px{
	int user;
	int num;
}p[N],q[N];
bool cmp(px x,px y){
	return x.num>y.num;
}

/*
*/

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%lld",&t);
	while(t--){
//		int p[N],q[N];
		int n;
		scanf("%lld",&n);
		int s = n/2;
		int c1,c2,c3;
		for(int i = 1;i<=n;i++){
			a[i][t].user = i;
			scanf("%lld%lld%lld",&c1,&c2,&c3);
			if(c1>=c2){
				if(c1<=c3){
					a[i][t].f1 = 3; a[i][t].f2 = 1; a[i][t].f3 = 2;
					a[i][t].n1 = c3; a[i][t].n2 = c1; a[i][t].n3 = c2;		
				}
				else{
					if(c2>=c3){
						a[i][t].f1 = 1; a[i][t].f2 = 2; a[i][t].f3 = 3;
						a[i][t].n1 = c1; a[i][t].n2 = c2; a[i][t].n3 = c3;	
					} 
					else{
						a[i][t].f1 = 1; a[i][t].f2 = 3; a[i][t].f3 = 2;
						a[i][t].n1 = c1; a[i][t].n2 = c3; a[i][t].n3 = c2;	
					}
				}
			}
			else{
				if(c1<=c3){
					if(c3>=c2){
						a[i][t].f1 = 3; a[i][t].f2 = 2; a[i][t].f3 = 1;
						a[i][t].n1 = c3; a[i][t].n2 = c2; a[i][t].n3 = c1;						
					}
					else{
						a[i][t].f1 = 2; a[i][t].f2 = 3; a[i][t].f3 = 1;
						a[i][t].n1 = c2; a[i][t].n2 = c3; a[i][t].n3 = c1;
					}
				}
				else{
					a[i][t].f1 = 2; a[i][t].f2 = 1; a[i][t].f3 = 3;
					a[i][t].n1 = c2; a[i][t].n2 = c1; a[i][t].n3 = c3;
				}
			}
			a[i][t].k1 = a[i][t].n1-a[i][t].n2;
		}	
		int num1 = 0,num2 = 0,num3 = 0,sum = 0;
		for(int i = 1;i<=n;i++){
			if(a[i][t].f1==1){
				num1++;	
			}
			else if(a[i][t].f1==2){
				num2++;
			}
			else{
				num3++;
			}
			sum+=a[i][t].n1;
		}
		if(num1<=s&&num2<=s&&num3<=s){
//			cout<<num1<<" "<<num2<<" "<<num3<<endl;
			printf("%lld\n",sum);
//			return 0;
		}
		else{
			int ans = 0;
			bool flag[N] ={0};
			int tot = 0;
			int z;//接下来关注的社团，爆了的那个 
			int maxx;
			maxx = max(max(num1,num2),num3);
//			cout<<num1<<" "<<num2<<" "<<num3<<endl;
//			cout<<maxx<<endl;
			if(num1==maxx){
				z = 1;
			}
			if(num2==maxx){
				z = 2;
			}
			if(num3==maxx){
				z = 3;
			}
			for(int i = 1;i<=n;i++){
				if(a[i][t].f1 == z){
					q[++tot].num = a[i][t].k1;
					q[tot].user = i;
				}
			}
			sort(q+1,q+tot+1,cmp);
			
//			cout<<"!!!"<<endl;
////			cout<<z<<endl;
//			for(int i = 1;i<=tot;i++){
//				cout<<q[i].num<<" ";
//			}
//			for(int i = 1;i<=tot;i++){
//				cout<<q[i].user<<" ";
//			}
//			cout<<endl<<"!!!"<<endl;

			for(int i =1;i<=s;i++){
				ans+=a[q[i].user][t].n1;
				flag[q[i].user] = 1;
			}
			for(int i = 1;i<=n;i++){
				if(flag[i]){
					continue;
				}
				if(a[i][t].f1==z){
					ans+=a[i][t].n2;
				}
				else{
					ans+=a[i][t].n1;
				}
			}
			printf("%lld\n",ans);
		}
	}
		
	return 0;
} 
