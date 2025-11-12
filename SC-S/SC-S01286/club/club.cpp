
#include<bits/stdc++.h>
using namespace std;
long long t,n,cnt1,cnt2,cnt3;
long long a1[100010],a2[100010],a3[100010],mx=0; 
struct x{//结构体 应为分开的三个 
	int pos;//哪个人的
	int s;//里面的值 
}c1[100010],c2[100010],c3[100010]; 
int cmp(x a,x b){
	return a.s>b.s;
}
int cmp1(x a,x b){
	return abs(a.s-a1[a.pos])>abs(b.s-a1[b.pos]);
}
int cmp2(x a,x b){
	return abs(a.s-a2[a.pos])>abs(b.s-a2[b.pos]);
}
void dfs(int r,long long ans,long long ans1,long long ans2,long long ans3){//r表示第几个人sum表示第当前满意和 
	if(r==n+1){//走到底了 
		mx=max(mx,ans);
	//	cout<<mx<<endl;
		return;
	} 
	if(ans1<n/2){
		dfs(r+1,ans+a1[r],ans1+1,ans2,ans3);//选第1个 
	}
	if(ans2<n/2){
		dfs(r+1,ans+a2[r],ans1,ans2+1,ans3);//选第2个
	}
	if(ans3<n/2){
		dfs(r+1,ans+a3[r],ans1,ans2,ans3+1);//选第3个 
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){//多组数据 
		cin>>n;
		cnt1=0,cnt2=0,cnt3=0;
		bool a20=0,a30=0;
		for(int i=1;i<=n;i++){
			cin>>a1[i];
			cin>>a2[i];
			cin>>a3[i];
			if(a2[i]!=0){
				a20=1;
			}
			if(a3[i]!=0){
				a30=1;
			}
			if(a1[i]>max(a2[i],a3[i])){//第一个部门的满意度最高 
			    cnt1++; 
				c1[cnt1].s=a1[i];
				c1[cnt1].pos=i; 
			}
			if(a2[i]>max(a1[i],a3[i])){//第二个部门的满意度最高 
			    cnt2++; 
				c2[cnt2].s=a2[i];
				c2[cnt2].pos=i; 
			}
			if(a3[i]>max(a1[i],a2[i])){//第三个部门的满意度最高 
			    cnt3++; 
				c3[cnt3].s=a3[i];
				c3[cnt3].pos=i; 
			}
			//没有最大的 
			if(a1[i]==a2[i]||a1[i]==a3[i]){//相等先存到1里面，反正也要换回来的 
				if(a1[i]!=0){
					cnt1++; 
					c1[cnt1].s=a1[i];
					c1[cnt1].pos=i; 
				}
				
			}
			if(a2[i]==a3[i]){//存2里面 
				if(a2[i]!=0){
					cnt2++; 
					c2[cnt2].s=a2[i];
					c2[cnt2].pos=i; 
				}
				
			}
		} 
		
//			for(int i=1;i<=cnt1;i++){
//				cout<<c1[i].s<<" ";
//			}
//			cout<<endl;
//			for(int i=1;i<=cnt2;i++){
//				cout<<c2[i].s<<" ";
//			}
//			cout<<endl;
		if(a20==0&&a30==0){//性质A
		//cout<<1<<endl;
			long long sum=0; 
			sort(c1+1,c1+cnt1+1,cmp);
			for(int i=1;i<=n/2;i++){
				sum+=c1[i].s;
			}
			cout<<sum<<endl;
			 
		}else if(a20==1&&a30==0){//性质B 
			long long sum=0;
			
			sort(c1+1,c1+cnt1+1,cmp2);
			sort(c2+1,c2+cnt2+1,cmp1);
			for(int i=1;i<=min(n/2,cnt1);i++){
				sum+=c1[i].s;
				//cout<<sum<<" ";
			}
	//		cout<<endl;
			for(int i=1;i<=min(n/2,cnt2);i++){
				sum+=c2[i].s;
			//	cout<<sum<<" ";
			}
		//	cout<<endl;
			for(int i=n/2+1;i<=min(n,cnt1);i++){
				cnt2++;
				sum+=a2[c1[i].pos];
				if(cnt2==n/2){
					break;
				}
			//	cout<<sum<<" ";
			}
		//	cout<<endl;
			for(int i=n/2+1;i<=min(n,cnt2);i++){
				cnt1++;
				sum+=a1[c2[i].pos];
				if(cnt1==n/2){
					break;
				}
			//	cout<<sum<<" ";
			}
		//	cout<<endl;
		//	cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<endl; 
		//	cout<<min(n/2,cnt2)<<endl;
		//	cout<<2<<endl; 
			cout<<sum<<endl;
		}else{//暴力搜索 
		//cout<<3<<endl;
			mx=0;
			dfs(1,0,0,0,0);
			cout<<mx<<endl;
		}
		
	}
	return 0;
} 
/*
做性质AB
A非常简单
只需把所有点放个数组里面
求出最大的前n/2个加起来 
B 较为简单 
跟贪心思路差不多,但c为0，无需考虑到底是和哪个换 
但要虑损失
将损失最小的几个直接换就行 
最后使用暴力搜索枚举 
5+15+[20,40]=[40,60]
(ㄒoㄒ)/~~ 
事实证明只有 40分 
*/

/*
优先贪心后背包 
一、贪心思想+结构体  
1.将所有人每个部门的满意度存入数组之中
2.排序（从大到小）
例：
4
2 2 2 //部门最大人数 
4 2 1 //4为三个中最大存入1 
3 2 4 //4为三个中最大存入3 
5 3 4 //5为三个中最大存入1 
3 5 1 //5为三个中最大存入2 
均未超过
2 2 2 //部门最大人数 
4 2 1 //4为三个中最大存入1 
5 2 4 //4为三个中最大存入1 
5 3 4 //5为三个中最大存入1 
3 5 1 //5为三个中最大存入2 
1超过了算出将哪个换成哪个损失最小还不会超出 
4-2=2
5-4=1
5-4=1
2、3中任意一个都行 
空间复杂度： 6*100010 符合
时间复杂度： t*n*9(最大为50000000) 符合 
就算超时也不会错太多 
大概长度130行左右 
问题：是否放到损失最小的里面去了
后面的损失就会最小？ 
*/
