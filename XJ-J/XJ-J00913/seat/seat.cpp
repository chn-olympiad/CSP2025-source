#include<bits/stdc++.h>
using namespace std;
int n,m;
//n行数
//m列数 
int num[2020][2020];
int cj[202020];
int flag;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >>m;
	for(int i = 1;i<= n*m;i++){
		cin >> cj[i];
	}
	int a = cj[1];
	sort(cj+1,cj+n*m+1);
	for(int i = 1;i<=n*m;i++){
		if(cj[i] == a){
			flag = i;
			break;
		}
	}
	//输出作为的人的成绩 
	if(n == 1 &&m==1){//第一个点（通过） 
		cout <<1<<" "<<1;
	}
	else if(n ==1){//第二三点 （过） 
		for(int i = n*m;i>=1;i--){
			if(cj[i] == a){
				cout << 1 <<" "<<i;
			}
			
		}
	}
	else if(m == 1){//第四五个点（过） 
	
		for(int i = n*m;i>=1;i--){
			if(cj[i] == a){
				cout << i <<" "<<1;
			}
			
		}
	} 
	else if(flag == 1){
		if(m%2 == 0){
			cout << m << 1;
		}else{
			cout <<m <<n;
		}
	}
	else if(flag == n *m){
		cout <<1 <<" "<<1; 
	}
	//第六七十十一 
	else{//已完成 
		int cnt=  n*m;
		
		for(int i = 1;i<=m;i++){
			for(int j = 1;j<=n;j++){
				num[j][i] = cj[cnt];
				cnt--;
				if(num[j][i] == a){
					//cout <<i<<" "<<j<<endl;
				}
			}//奇数列
			i++;
			for(int j = n;j>=1;j--){
				num[j][i] = cj[cnt];
				cnt--;
				if(num[j][i] == a){
					//cout <<i<<" "<<j<<endl;
				}
			}//欧数列 
		}
		for(int i = 1;i <= m;i++){
			for(int j =1;j<=n;j++){
				if(num[i][j] == a){
					cout <<j<<" "<<i<<endl;
				}	
			}
		}	
	}
	return 0;
}
