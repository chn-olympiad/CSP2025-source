#include<bits/stdc++.h>
using namespace std;
long long dor(int a,int b){
	return (a|b)-(a&b);
}
int n,k,a[1000005],f[1000005],dp[1000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.ans","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=dor(f[i-1],a[i]);
	}
//	for(int i=1;i<=n;i++){
//		cout<<f[i]<<' ';
//	}
//	cout<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<dor(f[i],k)<<' ';
//	}
//	cout<<endl;
/*
	for(int i=1;i<=n;i++){
		int x=dor(f[i],k),p=-1;
		for(int j=i;j>=0;j--){
			if(f[j]==x){
				p=j;
			}
		}
		if(p!=-1){
			dp[i]=max(dp[p]+1,dp[i-1]);
		}
		else{
			dp[i]=dp[i-1];
		}
	}
*/
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			dp[i]=dp[i-1]+1;
		}
		else{
			int x=dor(f[i],k),p=-1;
			for(int j=i-1;j>=0;j--){
				if(f[j]==x){
					p=j;
				}
			}
			if(p!=-1){
				dp[i]=max(dp[p]+1,dp[i-1]);
			}
			else{
				dp[i]=dp[i-1];
			}
		}
		
	}
//	for(int i=0;i<=n;i++){
//		cout<<dp[i]<<' ';
//	}
//	for(int i=1;i<=n;i++){
//		cout<<i<<';'<<a[i]<<';'<<f[i]<<';'<<dor(f[i],k)<<';'<<dp[i]<<endl;
//	}
	cout<<dp[n];
//	cout<<dp[n];
//I love you dp
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//CSP-J 2025 ZJ-J00017游记
//8:30开考 密码一不小心听对了
//8:40T1 经典难度
//9:00T2 怎么这么简单是不是哪错了比去年还水样例少万一没考虑特殊情况坠机怎么办
//看T3 ？？666直接傻掉了T3上动规也是阴到没边了去年还是数学题呢
//10：00想出来了 666 我^异或呢 其中看了T4感觉比T3好写
//10：20写出来了 哎呀下标一不小心搞对了 遂修改
//10:30哎呀一不小心改对了 遂重写
//10:40666动规不是正解吗怎么才25
//10:55不改了写T4去了
//看到数据范围非常高兴 暴力能拿40
//直接不想思考正解了（下午要考S）开始暴力
//11：15肥肠顺利地过了三个大样例 40应该有了
//随后开始写游记
//预估100+100+25+40=265 一？二？不知道 
//CCF orz
//CSP orz
//%%%%%%%%%%
//I love CCF
//I love CSP
//I stdstd
//#inlcude<bits/stdc++.h>
//#include<bits\stdc++.h>
//#include<bit/stdc++.h>
//#inclued<bits/stdc++.h>
//#inculde<bits/stdc++.h>
//#include<bist/stdc++.h>
//#include<bits/stcd++.h>
//freopen("xor.in","r",stdin);
//	froepen("xor.ans","w",stdout);
//freopen("xor.in","w",stdin);
//	freopen("xor.ans","r",stdout);
//freopen("xor.in","r",stdout);
//	freopen("xor.ans","w",stdin);
//freopen("orx.in","r",stdin);
//	freopen("orx.ans","w",stdout);
//freopen("xor.in","r",stdin);
//	freopen("xor.ans","w",stdout);
//frepen("xor.in","r",stdin);
//	frepen("xor.ans","w",stdout);
//fropen("xor.in","r",stdin);
//	fropen("xor.ans","w",stdout);
