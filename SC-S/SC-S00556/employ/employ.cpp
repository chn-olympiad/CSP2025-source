#include <iostream>
#include <vector>

using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,num=0;
	cin>>n>>m;
	string s;
	cin>>s;
	vector<int> a(n);
	for(int i=0;i<n;++i){
		cin>>a[i];
		if(a[i]==0){
			num++;
		}
	}
	if(m==1){
		if(s=="1"){
			int jc=1;
			for(int i=1;i<=n-num;++i){
				jc*=i;
			}
			cout<<jc<<endl;
		}else{
			cout<<0<<endl;
		}
	}else if(m==n){
		int jc=1;
		for(int i=1;i<=n-num;++i){
			jc*=i;
		}
		cout<<jc<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}