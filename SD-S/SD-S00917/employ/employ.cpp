#include<iostream>
#include<string>
using namespace std;
string s;
long long n,m,flag = 0,A[510],sum1 = 1,sum2 = 1,sum3 = 1,book[510],ans = 0;
void dfs(long long step,long long x){
	long long i,lo = 0;
	if(step == n - lo){
		ans++;
		return;
	}
	for(i = 1;i <= n;i++){
		if(s[i - 1] == '0'){
			lo++;
//			cout<<lo<<','<<endl;
		}
		else if(book[i] == 0 && lo < A[i]){
			book[i] = 1;
//			cout<<i<<'.'<<step<<endl;
			dfs(step + 1,i);
			book[i] = 0;
		}
	}
}
int main(){
	freopen("employ.in","w",stdin);
	freopen("employ.out","r",stdout);
	long long i;
	cin>>n>>m;
	cin>>s;
	
	for(i = 0;i < s.size();i++){
		if(s[i] != '1'){
			flag = 1;
		}
	}
	for(i = 1;i <= n;i++){
		cin>>A[i];
	}
//	cout<<flag<<endl;
	if(flag == 0){
		for(i = 1;i <= n;i++){
			sum1 *= i;
			sum1 /= 998244353;
//			cout<<sum1<<endl;
			if(i == m){
				sum2 = sum1;
				sum2 = 998244353;
			}
			if(i == n - m){
				sum3 = sum1;
				sum3 %= 998244353;
			}
//			cout<<sum2<<" "<<sum3<<endl;
		}
		ans = (sum1 / (sum2 * sum3)) % 998244353;
		cout<<ans;
	}
	else{
		dfs(0,0);
		cout<<ans % 998244353;
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
