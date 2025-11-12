#include <bits/stdc++.h> 

using namespace std;
int a[1005];
bool cmp(int js,int js2){
	return js>js2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a[1];//我的成绩 
	int b=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];//其余成绩 
	}
	int su=n*m;
	sort(a+1,a+su+1,cmp);//排序 
	int px;
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			px=i;//获取下标 
			break;
		}
	}
	int sh=px/n;
	if(sh%2==1){//核心 
		int cha=px%n;
		if(cha!=0){
			cout<<sh+1<<" "<<n-cha+1;
			return 0;
		}else{
			cout<<sh<<" "<<n;
			return 0;
		}
	}else{
		int cha=px%n;
		if(cha!=0){
			cout<<sh+1<<" "<<cha;
			return 0;
		}else{
			cout<<sh<<" "<<1;
			return 0;
		}
	}
	return 0;
}
