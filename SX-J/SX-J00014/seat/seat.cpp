#include<bits/stdc++.h>
using namespace std;
int n,m;
int num;
int ln,lm;
struct Node{
	int s;
	bool f;
}a[110];
bool cmp(Node s1,Node s2){
	if(s1.s>s2.s) return true;
	else return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1].s;
	a[1].f=true;
	for(int i=2;i<=n*m;i++){
		cin>>a[i].s;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].f){
			num=i;
			break;
		}
	}
	if(num==1){
		cout<<1<<' '<<1<<endl;
		return 0;
	}
	if(n==1){
		cout<<num<<' '<<1<<endl;
		return 0;
	}
	if(m==1){
		cout<<1<<' '<<num<<endl;
		return 0;
	}
	if(num%n==0){
		ln=(num+n-1)/n;
    	if(ln%2==1){
   			cout<<ln<<' '<<n<<endl;
   			return 0;
        }else{
			cout<<ln<<' '<<1<<endl;
			return 0;
		}
	}else{
		ln=(num+n-1)/n;
    	if(ln%2==1){

   			cout<<ln<<' '<<num%n<<endl;
   			return 0;
        }else{

			cout<<ln<<' '<<n+1-num%n<<endl;
			return 0;
		}
	}
	return 0;
}



