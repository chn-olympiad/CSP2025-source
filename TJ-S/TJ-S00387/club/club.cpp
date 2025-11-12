#include<bits/stdc++.h>
using namespace std;
//我为什么要来S坐一下午
//QAQ QWQ qwq qaq (*_*) (^_^) ($_$) (#_#) (@_@) ("_")
//1+1=3 1+1=3 1+1=3
//能不能上迷惑行为大赏 
int n;
int a1[10005];
int a2[10005],t2;
int a3[10005],t3;
long long t;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);//不写零分
	freopen("club.out","w",stdout);//骗你的，其实写了也是零分 
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a3[i]!=0){
				t3=1;
			}
			if(a2[i]!=0){
				t2=1;
			}
		}
	}
	if(t3==0&&t2==0){
		sort(a1+1,a1+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			t+=a1[i];
		}
		cout<<t<<endl;
	}
	else{
		for(int i=1;i<=n;i++){
			t+=max(a1[i],a2[i]);
		}
		cout<<t<<endl; 
	}
	return 0;
}
