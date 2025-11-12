/*座位（seat）
【题目描述】
所有 n × m 名考生将按照 CSP-J 2025 第一轮的成绩，由. 高. 到. 低. 蛇. 形. 分. 配. 座位，
排列成 n 行. m 列. 。具体地，设小 R 所在的考场的所有考生的成绩从. 高. 到. 低. 
分别为 s1 > s2 > · · · > sn×m，则成绩为 s1 的考生的座位为第 1 列.第 1 行
成绩为 s2 的考生的座位为第 1 列. 第 2 行. ，……，
成绩为 sn 的考生的座位为第 1 列. 第 n 行. ，
成绩为 sn+1 的考生的座位为第 2 列. 第 n 行. ，……，
成绩为 s2n 的考生的座位为第 2 列. 第 1 行. ，
成绩为 s2n+1 的考生的座位为第 3 列. 第 1 行. ，以此类推
【输入格式】
输入的第一行包含两个正整数 n, m，分别表示小 R 所在的考场座位的行. 数. 与列. 数. 。
输入的第二行包含 n × m 个正整数 a1, a2, . . . , an×m，分别表示小 R 所在的考场的
所有考生 CSP-J 2025 第一轮的成绩，其中 a1 为小 R CSP-J 2025 第一轮的成绩。
*/
#include<bits/stdc++.h>
using namespace std;
int a[20],b[110][110],c[20]; 
int main(){
	int n,m,x=1;
	cin>>n>>m;
	int len=n*m;
	for(int i=1;i<=len;i++){
		cin>>c[i];
	}
	int a1=c[1];
	sort(c,c+len+1);
	for(int i=len;i>=1;i--){
		a[x]=c[i];
		x++;
	}
	for(int i=1;i<=len;i++){
		b[i][1]=a[i];

	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++) {
			b[i][j]=a[i+j];
		}	
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==a1){
				cout<<j<<" "<<i;
			}
		}
	}	
    return 0;
} 
