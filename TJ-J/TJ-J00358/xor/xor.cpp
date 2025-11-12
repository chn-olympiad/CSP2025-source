#include<bits/stdc++.h>
using namespace std;
int a[10000];
string s[10000],m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,ans=0;
	cin >> n >> k;
	int kk=k;
	int qj[n];
	memset(qj,0,sizeof(qj));
	while(kk>0){
		m+=kk%2+'0';
		kk/=2;
	}
	for(int i=0;i<n;i++){ 
		cin >> a[i];
		if(a[i]==k){ 
			ans++;
			qj[i]=1; 
		}
		if(a[i]==0){
			s[i]+='0';
			continue;
		}
		int num=a[i];
		while(num>0){
			s[i]+=num%2+'0';
			num/=2;
		}
	}
	for(int i=0;i<n-1;i++){
		string t;
		for(int j=i+1;j<n;j++){//进行异或操作遍历 
			if(j==i+1){
				int len=max(s[i].size(),s[j].size());
				for(int k=0;k<len;k++){
					if(s[i][k]==s[j][k]){
						t+='0';
					}else{
						t+='1';
					}
				}
				//cout << s[i] << " " << s[j] << " ";
				//cout << t << endl;
			}else{
				int len=max(t.size(),s[j].size());
				string g;
				for(int k=0;k<len;k++){
					if(t[k]==s[j][k]){
						g+='0';
					}else{
						g+='1';
					}
				}
				t=g;
				//cout << t << " " << s[j] << " ";
				//cout << t << endl;
			}
			if(t==m){
				int bz=0;
				for(int k=i;k<=j;k++){
					if(qj[k]==1){
						bz=1;
						break;
					}
				}
				if(bz==0){
					ans++;
					for(int k=i;k<=j;k++){
						qj[k]=1;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}
