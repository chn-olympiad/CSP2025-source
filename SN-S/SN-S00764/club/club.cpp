#include<bits/stdc++.h>
using namespace std;

/*首先保证20分的做法：暴力每个人可能去的社团（dfs），这是最次思路。 时间复杂度3^n 
但是如果一个人只有一个为0的话，这个0肯定不会去（条件b）。 
其次，我们注意到条件a：所有人只有a[i][0]有数字，其他都是0，那么排个序就好了。可以拿到5分。加个if判断 
测试的时候发现对于条件C，我之前的代码可以用，所以加个if判断就好，可以拿到5分。 
*/

int T;
int n,a[100010][3],cnt[3];//人数，满意度，目前社团报名人数 
int ans;

void dfs(int d,int sum) {//深度，总和。 
	if(d >= n) {
		ans = max(ans,sum);
		return;
	}
	
	int cnt0 = 0,ind0 = -1;//数0的个数 ，0的位置 
	for(int j = 0;j<3;j++)
		if(!a[d][j]) {
			cnt0++;
			ind0 = j;
		}
	for(int j = 0;j<3;j++) {//枚举报社团 
		if(cnt0 == 1 && ind0 == j)//如果一个为0，那么不可能走，减枝 
			continue;
		if(cnt[j] >= n/2)//如果一个社团爆满了，就不报了 
			continue;
	//如果报第j个社团：
		//这个社团报的人数+1
		cnt[j]++;
		//dfs下一层,sum增加
		dfs(d + 1,sum + a[d][j]);
		//如果不报第j社团，把空加的人数减回去
		cnt[j]--;
	}
}

//=================！！以上为dfs的内容，下面为错误的判断蒙答案内容，用于蒙更大检查点的分===========================
int choice[100010],sec_choice[100010],b[100010],len; 

void count(int i) {
	int maxi = 0,maxn = a[i][0];
	for(int j = 1;j<3;j++) {
		if(a[i][j] > maxn) {
			maxn = a[i][j];
			maxi = j;
		}
	}
	cnt[maxi]++;
	choice[i] = maxi;
}

void count2(int i) {
	int mini = 0,minn = a[i][0];
	for(int j = 1;j<3;j++) {
		if(a[i][j] < minn) {
			minn = a[i][j];
			mini = j;
		}
	}
	sec_choice[i] = (3 - choice[i] - mini);
}

int limit;//被限制的社团 

bool cmp(int x,int y) {
	int chax = a[x][choice[x]] - a[x][sec_choice[x]];
	int chay = a[y][choice[y]] - a[y][sec_choice[y]];
	return chax > chay;
}

void solve() {
	bool if_c[100010];//是否选择 
	len = 0;
	//先把所有choice为limit的人找出来放到一个数组里面
//	cout<<"limit:"<<limit<<"，maxcnt:"<<cnt[limit]<<endl;
	for(int i = 0;i<n;i++)
		if(choice[i] == limit)
			b[len++] = i;
			//然后对数组进行极端差排序，取前n/2个人
		sort(b,b + len,cmp);
		
//		cout<<"看一下b数组："<<endl;
//		for(int i = 0;i<len;i++)
//			cout<<b[i]<<" 极端差："<<a[b[i]][choice[b[i]]] - a[b[i]][sec_choice[b[i]]]<<endl;
			
		for(int i = 0;i<n/2;i++) {
			ans += a[b[i]][choice[b[i]]];
			if_c[b[i]] = 1;
//			cout<<"!,第"<<b[i]<<"个人选择第一志愿，极端差为"<<a[b[i]][choice[b[i]]] - a[b[i]][sec_choice[b[i]]]<<endl;
		}
		//剩下的人都拿第二选择
		for(int i = 0;i<n;i++)
			if(!if_c[i])
				ans += a[i][sec_choice[i]];
}

//==================结束，以下是满足A的解法======================= 
bool cmp2(int x,int y) {
	return x > y;
}

void solveA() {
	for(int i = 0;i<n;i++) {
		b[i] = a[i][0];
	}//b里面都是期待值，取前n/2个，其他都为0就好。
	sort(b,b + n,cmp2);
	for(int i = 0;i<n/2;i++)
		ans += b[i]; 
}

//==================结束======================================== 

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		ans = 0;
		for(int i = 0;i<3;i++)
			cnt[i] = 0;
		cin>>n;
		for(int i = 0;i<n;i++)
			for(int j = 0;j<3;j++)
				cin>>a[i][j];
		//如果n <= 10：dfs暴力一下
		if(n <= 10) {
			dfs(0,0);
		}
		else {//剩下的话：判断是否A
			bool ifisA = 1;
			for(int i = 0;i<n;i++) 
				if(a[i][1] != 0 || a[i][2] != 0) {
					ifisA = 0;
					break;
				}
			//如果是A：solveA，排序。
			if(ifisA) {
				solveA();
			} 
			else {//不是：动用蒙答案方法 
				for(int i = 0;i<n;i++) {
					count(i);//数一下最优选择、次选择。
					count2(i);
				}
				limit = 0;
				for(int i = 0;i<3;i++) 
					if(cnt[limit] < cnt[i]) 
						limit = i;
					
				//极端情况不存在： 
				if(cnt[limit] <= n/2) {
					for(int i = 0;i<n;i++) {
						ans += a[i][choice[i]];
					}
				}
				else {//极端情况存在：
//					cout<<endl<<"极端！"<<endl;
					solve();
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
} 
