#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const long long mod=998244353;
long long n,m,c[100050],sum,a[100050],flag[100050],s,s2,aflag,s0;
string str;

long long Read(){
	long long Ra=0,Rf=1;
	char Rc=getchar();
	while(Rc<'0'||Rc>'9'){
		if(Rc=='-') Rf=-1;
		Rc=getchar();
	}
	while(Rc>='0'&&Rc<='9'){
		Ra=(Ra<<1)+(Ra<<3)+(Rc&15);
		Rc=getchar();
	}
	return Ra*Rf;
}void check(){
	s=0,s2=0;
	for(int i=1;i<=n;i++){
		if(s2>=a[i]){
			s2++;
		}else if(str[i-1]=='0'){
			s2++;
		}else{
			s++;
		}
	}
	if(s>=m) sum=(sum+1)%mod;
}void p(long long now){
	if(now>n){
		check();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(flag[i]==0){
			flag[i]=1;
			a[now]=c[i];
			p(now+1);
			flag[i]=0;
		}
	}
}int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	//O(n!) 8
	n=Read(),m=Read();
	cin>>str;
	aflag=1;
	for(int i=0;i<str.size();i++){
		if(str[i]=='0'){
			aflag=0;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		c[i]=Read();
		if(c[i]==0) s0++;
	}
	p(1);
	cout<<sum;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
