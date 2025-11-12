# include<bits/stdc++.h>
using namespace std;
int n,m,c[600],cnt=1;
string s;
int jc(int x){
	int sum=1;
	for(int i=1;i<=x;i++){
		sum*=i;
	}
	return sum;
}
int qm()
bool pd(){
	for(int i=1;i<=n;i++){
		
	}
}
int main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	//输入 
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	//排序 
	sort(c+1,c+n+1);
	//操作 
	for(int i=2;i<=n;i++){
		if(c[i]>c[i-1]){
			//重置 
			cnt=1;
			//交换 
			int zz=c[i];
			c[i]=c[i-1];
			c[i-1]=zz;
		}else{
			cnt++;
		}
	}
	return 0;
}
