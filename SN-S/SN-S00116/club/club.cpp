#include <bits/stdc++.h>
using namespace std;
int a[200000][4],A[200000],B[200000],C[200000];
int cnt[4];
long long Summy=0;
int n;
bool cmpA(int s,int t){
	return a[s][1] >= a[t][1];
} 
bool cmpB(int s,int t){
	return a[s][2] >= a[t][2];
} 
bool cmpC(int s,int t){
	return a[s][3] >= a[t][3];
} 

void change(int t1,int t2,int t3){ 
	while(t1>n/2&&t2>n/2&&t3>n/2){
		int tmin = min(min(a[A[t1]][1],a[B[t2]][2]),a[C[t3]][3]);//优先处理三者末尾最小值 
		Summy -= tmin;
		if(tmin == a[A[t1]][1]) t1--;	
		else if(tmin == a[B[t2]][2]) t2--;
		else if(tmin == a[C[t3]][3]) t3--;
	}
	for(int i=t1;i>n/2;i--,t1--){
		if(a[A[i]][2]>a[A[i]][3]){
			t2++;
			B[t2] = i;
		}else{
			t3++;
			C[t3] = i;
		}
	}
	sort(B+1,B+1+t2,cmpB);
	sort(C+1,C+1+t3,cmpC);
	while(t2 > n/2){
		Summy -= a[B[t2]][2];
		t2--;
	}
	while(t3 > n/2){
		Summy -= a[C[t3]][3];
		t3--;
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	
	
	int sjzs;
	cin >> sjzs;
	
	for(int lll=1;lll<=sjzs;lll++){//此处为每组数据开始输入 
		Summy=0;
		
		memset(a,0,sizeof(a));
		//记得检查所有数组是否初始化 
		memset(cnt,0,sizeof(cnt));
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		memset(C,0,sizeof(C));
		n = 0;
		cin >> n;
		
		for(int i=1;i<=n;i++){
			int st=1,nd=1;
			for(int j=1;j<=3;j++){	
				cin >> a[i][j];
				st = (a[i][st] <= a[i][j]) ? j:st;//ai最满意的部门 
				//_nd = (a[i][_nd] >= a[i][j]) ? j:_nd;
			}
			//fstmy[i] = _st;
			Summy += a[i][st];
			cnt[st]++;//a[i]在部门中的位置 同时也是目前该部门分配到的人数 
			switch(st){//ai被分配到的部门及其位置 
			case 1:A[cnt[st]] = i;break;
			case 2:B[cnt[st]] = i;break;
			case 3:C[cnt[st]] = i;break;
			}
		}
		sort(A+1,A+1+cnt[1],cmpA);
		sort(B+1,B+1+cnt[2],cmpB);
		sort(C+1,C+1+cnt[3],cmpC);
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2){
			cout << Summy << endl;
		}else {
			
			change(cnt[1],cnt[2],cnt[3]);
			cout << Summy << endl;
		}
	} 
	return 0;
}
