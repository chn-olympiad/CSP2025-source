#include<iostream>
#include<cstdlib>
#include<queue>
#include<string.h>
using namespace std;
const int M = 998244353;
const int MAXN = 5001;
int p2[MAXN],a[MAXN],n,ans = 0,m;//a[i]表示长度为i的小木棍数量; 

int pow2(int i){
	if(i<0) return 0;
	if(p2[i]==-1) p2[i] = (pow2(i-1)<<1)%M;
	return p2[i];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	memset(p2,-1,sizeof(p2));
	memset(a,0,sizeof(a));
	p2[0] = 1;p2[1] = 2;
	cin >> n;m = n;
	for(int i=0;i<n;i++){
		int j;
		cin >> j;
		a[j]++;
	}
	int l1 = -1,l2 = -1,l3 = -1;
	for(int i=MAXN-1;i>0;){//长度为i 
		if(m<3) break;
		if(!a[i]){
			i--;
			continue;
		}
		l1 = i;
		m--;
		a[i]--;
		//模拟选择最大的l2,l3
		if(a[i]>=2){
			l2 = i;
			l3 = i;
		}else if(a[i]){
			l2 = i;
			int j = i-1;
			while(!a[j]) j--;
			l3 = j;
		}else{
			int j = i-1;
			while(!a[j]) j--;
			if(a[j]>=2){
				l2 = j;
				l3 = j;
			}else{
				l2 = j;
				int k = j-1;
				while(!a[k]) k--;
				l3 = k;
			}
		}
		//选完了
		if(l2+l3<=l1){//不合法可以继续选择可能的多边形的(再加) 这样子架构有问题,来不及改了
			int l4;
			if(l3==l2){
				if(a[l3]>=3)
				l4 = l3;
			}else if(a[l3]>=2){
				l4 = l3;
			}else{
				l4 = l3-1;
				while(!a[l4]) l4--;
			}
			int sum = l3+l2+l4;
			while(l4>0&&sum<=l1){
			if(l3==l2){
				if(a[l3]>=3)
					l4 = l3;
				}else if(a[l3]>=2){
					l4 = l3;
				}else{
					l4 = l3-1;
					while(!a[l4]) l4--;
				}
				sum += l4;
			}
			if(sum>l1){
				ans++;//来不及了 
			}
			a[i] = 0;
			i--;
			continue;
		}else{//不妨设l2>=l3 中间跳过的不能再选了
			int q = 0,p = 0;//q:比l1小比l2大的数 p:比l2小比l3大的数 
			while(l2+l3>l1){
				bool b__ = 0;
				while(l2+l3>l1){
					if(l2!=l3){
						ans = (ans+(pow2(m-2-p-q)*a[l2]*a[l3])%M)%M;
						
						p += a[l3];
					}
					else{
						b__ = 1;
						ans = (ans+(pow2(m-2-p-q)*(a[l2]*(a[l2]-1)))%M)%M;
						
						p += a[l3]-1;//l2去已经在2里面体现了
					}
					l3--;
					while(!a[l3])l3--;
				}
				//l3到达最小 ,考虑下一个l2,并重选最大的l3 
				q += a[l2];
				p -= a[l2];
				//如果l2曾经与l3相等,那就多-了1
				p += b__; 
				l2--;
				while(!a[l2]) l2--;
				if(a[l2]>=2){
					l3 = l2;
				}else{
					l3 = l2-1;
					while(!a[l3]) l3--;
				}
				//选完了进入下一轮循环降l3 
			}
			//与l1组合形成三角形的l2、l3的个数有cntl2l3个,由于l1是最大的数,任选数进来都可以组成多边形
			//也可以不选,就是三角形 
		}
	}
	cout << ans;
	return 0;
} 
