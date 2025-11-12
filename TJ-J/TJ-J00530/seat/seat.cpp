#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	int san3dai[1000],san3daj;
	int nm=m*n;
	cin>>san3dai[1];//小a的成绩 
	san3daj=san3dai[1];
	for(int i=2;i<=nm;i++){
		cin>>san3dai[i];//其他人的成绩 
	}
	sort(san3dai+1,san3dai+nm+1);
	int jishuqi;//保留san3dai的位置 
	for(int i=1;i<=nm;i++){
		if(san3dai[i]==san3daj){
			jishuqi=nm-i+1;
			break;
		}
	}
	if(jishuqi%n!=0){
		cout<<jishuqi/n+1<<" ";//除尽了到下一列 --有余数 
		if((jishuqi/n+1)%2==0){//如果是偶数列减到头 
			cout<<n-jishuqi%n+1;
		}else{//如果是奇数列那就加回来 
			cout<<jishuqi%n;
		}
	}else{//如果刚好除尽 那就定在最后或者最前 
		cout<<jishuqi/n<<" ";
		if(jishuqi/n%2==0){
			cout<<1;//偶数列最后一个就是最前面一个 
		}else{
			cout<<n;//奇数列就是最后一个 
		}
	}
	return 0;
} 
