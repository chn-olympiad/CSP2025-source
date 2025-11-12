#include<bits/stdc++.h>
#define MAXN 10002
using namespace std;
long long results[MAXN];

//ai,2 = a且i,3 = 0的处理 
long long halfMax(vector<int> &nums){
//	cout << "[Debug]进入halfMax函数\n";
	sort(nums.begin(), nums.end());
	long long sum = 0;
	auto iter = nums.end() - 1;
//	cout << "---开始处理---\n";
	for(int t = 1;t <= nums.size() / 2;t++, iter--){
//		cout << *iter;
		sum += *iter;
	}
//	cout << "---END---\n";
//	cout << "累加: " << sum << endl;
	return sum;
}

// 搜索部分 
int group1sum, group2sum, group3sum;
long long result = 0; 
vector< vector<int> > inputs;
void dfs(int n, long long sum){
//	cout << "当前位于第" << n << "行, 计数: " << sum; 
	if(n == inputs.size()){
//		cout << ",达到最后";
		if(sum > result){
//			cout << ",刷新最大结果: " << sum << endl;
			result = sum;
		}
//		cout << endl;
		return;
	}
//	cout << endl;
	int maxSum = inputs.size() / 2;
	if(group1sum < maxSum){ 
		int nowValue = inputs[n][0];
//		cout << "位于0列的" << nowValue << "被选中\n";
		sum += nowValue;
		group1sum += 1;
		dfs(n + 1, sum);
		group1sum -= 1;
		sum -= nowValue;
	}
	if(group2sum < maxSum){
		int nowValue = inputs[n][1];
//		cout << "位于1列的" << nowValue << "被选中\n";
		sum += nowValue;
		group2sum += 1;
		dfs(n + 1, sum);
		group2sum -= 1;
		sum -= nowValue;
	}
	if(group3sum < maxSum){
		int nowValue = inputs[n][2];
//		cout << "位于2列的" << nowValue << "被选中\n";
		sum += nowValue;
		group3sum += 1;
		dfs(n + 1, sum);
		group3sum -= 1;
		sum -= nowValue;
	}
	return;
}

long long simpleSum(int n){
	// 处理剩余可选择
//	l1s -= inputs[n][0]; 
//	l2s -= inputs[n][1];
//	l3s -= inputs[n][2];
//	if(n == inputs.size() - 1){
//		if(sum > result){
//			result = sum;
//		}
//		return;
//	}
//	// 检测是否达到关键点
//	if(group1sum + 2 == inputs.size() / 2){
//		// 之后都不能再选择0列, 即0列以后不可能贡献任何值
//		long long temp12 = l2s + l3s; //以后最大的贡献值
//		long long temp02 = 0;
//		long long temp01 = 0;
//		if(group2sum + 2 == inputs.size() / 2){
//			// 第1列也到达临界
//			// 选择1列 
//			temp02 = l1s + l3s; //以后最大的贡献值
//		}else{
//			temp02 = l1s + l2s + l3s;
//		}
//		if(group3sum + 2 == inputs.size() / 2){
//			// 第2列也到达临界
//			// 选择2列 
//			temp01 = l1s + l2s; //以后最大的贡献值
//		}else{
//			temp01 = l1s + l2s + l3s;
//		}
//		if(temp12 >= temp02 && temp12 >= temp01){ //选择0列的时候, 可分配的贡献值最大
//			group1sum++; //选择0列
//			sum += inputs[n][0];
//			simpleSum(n + 1, l1s, l2s, l3s, sum); // 向下
//		}else if(temp02 == temp01){
//			// 选择剩下两列的可分配贡献相同
//			if(inputs[n][1] >= inputs[n][2]){
//				// 选择1列本次可最大化
//				group2sum++;
//				sum += inputs[n][1];
//				simpleSum(n + 1, l1s, l2s, l3s, sum) ;
//			}else{
//				group3sum++;
//				sum += inputs[n][2];
//				simpleSum(n + 1, l1s, l2s, l3s, sum); 
//			}
//		}else if(temp02 > temp01){
//			// 选择 
//			group2sum++;
//			sum += inputs[n][1];
//			simpleSum(n + 1, l1s, l2s, l3s, sum);
//		}else{
//			group3sum++;
//			sum += inputs[n][2];
//			simpleSum(n + 1, l1s, l2s, l3s, sum);
//		} 
//	}else if(group2sum + 2 == inputs.size() / 2){
//		// 之后都不能再选择1列, 即1列以后不可能贡献任何值
//		long long temp02 = l1s + l3s; //选择1列以后最大的贡献值
//		long long temp12 = l1s + l2s + l3s; // 选择0列的最大贡献值 
//		long long temp01 = l1s + l2s + (group3sum+2==inputs.size()/2?0:l3s); // 选择2列之后最大贡献 
//		if(temp12 >= temp02 && temp12 >= temp01){ //选择0列的时候, 可分配的贡献值最大
//			group1sum++; //选择0列
//			sum += inputs[n][0];
//			simpleSum(n + 1, l1s, l2s, l3s, sum); // 向下
//		}else if(temp02 == temp01){
//			// 选择剩下两列的可分配贡献相同
//			if(inputs[n][1] >= inputs[n][2]){
//				// 选择1列本次可最大化
//				sum += inputs[n][1];
//				group2sum++;
//				simpleSum(n + 1, l1s, l2s, l3s, sum) ;
//			}else{
//				group3sum++;
//				sum += inputs[n][2];
//				simpleSum(n + 1, l1s, l2s, l3s, sum); 
//			}
//		}else if(temp02 > temp01){
//			// 选择 
//			group2sum++;
//			sum += inputs[n][1];
//			simpleSum(n + 1, l1s, l2s, l3s, sum);
//		}else{
//			group3sum++;
//			sum += inputs[n][2];
//			simpleSum(n + 1, l1s, l2s, l3s, sum);
//		} 
//	}else if(group3sum + 2 == inputs.size() / 2){
//		// 之后都不能再选择2列, 即2列以后不可能贡献任何值
//		long long temp01 = l1s + l2s; //选择2列以后最大的贡献值
//		long long temp12 = l1s + l2s + l3s; // 选择0列的最大贡献值 
//		long long temp02 = l1s + l2s + l3s; // 选择1列之后最大贡献 
//		if(temp12 >= temp02 && temp12 >= temp01){ //选择0列的时候, 可分配的贡献值最大
//			group1sum++; //选择0列
//			sum += inputs[n][0];
//			simpleSum(n + 1, l1s, l2s, l3s, sum); // 向下
//		}else if(temp02 == temp01){
//			// 选择剩下两列的可分配贡献相同
//			if(inputs[n][1] >= inputs[n][2]){
//				// 选择1列本次可最大化
//				sum += inputs[n][1];
//				group2sum++;
//				simpleSum(n + 1, l1s, l2s, l3s, sum);
//			}else{
//				group3sum++;
//				sum += inputs[n][2];
//				simpleSum(n + 1, l1s, l2s, l3s, sum); 
//			}
//		}else if(temp02 > temp01){
//			// 选择 
//			group2sum++;
//			sum += inputs[n][1];
//			simpleSum(n + 1, l1s, l2s, l3s, sum);
//		}else{
//			group3sum++;
//			sum += inputs[n][2];
//			simpleSum(n + 1, l1s, l2s, l3s, sum);
//		} 
//	}else{ // 三者都没有到达临界点
////		group1sum++;
////		sum += inputs[n][0];
////		simpleSum(n + 1, l1s, l2s, l3s, sum);
////		sum -= inputs[n][0];
////		group1sum--;
////		// 尝试1列
////		group2sum++;
////		sum += inputs[n][1];
////		simpleSum(n + 1, l1s, l2s, l3s, sum);
////		sum -= inputs[n][1];
////		group2sum--;
////		// 尝试2列
////		group3sum++;
////		sum += inputs[n][2];
////		simpleSum(n + 1, l1s, l2s, l3s, sum);
////		sum -= inputs[n][2];
////		group3sum--;
//		if(l1s >= l2s && l1s >= l3s){ //0列最大
//			group1sum++;
//			sum += inputs[n][0];
//			simpleSum(n + 1, l1s, l2s, l3s, sum);
//		}else if(l2s >= l3s){
//			group2sum++;
//			sum += inputs[n][1];
//			simpleSum(n + 1, l1s, l2s, l3s, sum);
//		}else{
//			group3sum++;
//			sum += inputs[n][2];
//			simpleSum(n + 1, l1s, l2s, l3s, sum);
//		}
//	}
//	return;
	int ssize = inputs.size();
	int halfSize = ssize / 2;
	long long sum = 0;
	for(int t = 0;t < ssize;t++){
		if(inputs[t][0] >= inputs[t][1] && inputs[t][0] >= inputs[t][2] && group1sum < halfSize){
			sum += inputs[t][0];
			++group1sum; 
		}else if(inputs[t][1] > inputs[t][0] && inputs[t][1] >= inputs[t][2]&& group2sum < halfSize){
			sum += inputs[t][1];
			++group2sum;
		}else{
			sum += inputs[t][2];
			++group3sum;
		}
	}
	return sum;
}

// 单次问题入口 
void solve(int i) {
	inputs.clear();
	int n;
	scanf("%d", &n);
	bool empty1 = false, empty2 = false, empty3 = false, stop1 = false, stop2 = false, stop3 = false;
	for(int t = 0;t < n;t++){
		int a,b,c;
		scanf("%d%d%d", &a, &b, &c);
		vector<int> ktemp;
		ktemp.push_back(a);
		ktemp.push_back(b);
		ktemp.push_back(c);
//		lie1sum += a;
//		lie2sum += b;
//		lie3sum += c;
		inputs.push_back(ktemp);
		if(!empty1 && a != 0){
			empty1 = true;
		}
		if(!empty2 && b != 0){
			empty2 = true;
		}
		if(!empty3 && c != 0){
			empty3 = true;
		}
	}
	int re = int(empty1) + int(empty2) + int(empty3);
//	cout << "第" << i << "轮问题输入完毕,总个数为" << inputs.size() << ", 优化方向: " << re << endl;
//	printf("[Info]%d\n",inputs.size());
	if(re == 1){
//		printf("[]");
		int idT = empty1?0:(empty2?1:2); 
		vector<int> inTemp;
		for(int temp = 0;temp < inputs.size();temp++){
			inTemp.push_back(inputs[temp][idT]);
		}
		results[i] = halfMax(inTemp);
		return;
//	}else if(re == 2 || re == 3){
	}else{
		group1sum = 0;
		group2sum = 0;
		group3sum = 0;
		if(n > 10){
			result = 0;
			results[i] = simpleSum(0);
			return;
		}
		dfs(0, 0);
		results[i] = result;
		result = 0;
	}
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d", &t);
	for(int i = 0;i < t;i++){
		solve(i);
	}
	for(int i = 0;i < t;i++){
		cout << results[i] << "\n";
	}
	return 0;
}
