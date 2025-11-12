//I can have a score of 400.
#include<iostream>
using namespace std;
string a,ans;
int s[1000003];
long long js=0,snum=0;
struct Node{
	int m,myid;
};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>a;
	for(int n=0;n<=a.length();n++){
		if(a[n]>='0'&&a[n]<='9'){
			s[snum]=(int)(a[n]-'0');
			js++;
			snum++;
		}
	}
//	for(int w=0;w<js;w++){
//		cout<<s[w]<<' ';
//	}
//	printf("\n");
	int js2=js;
	while(js2--){
		Node mymax;
		mymax.m=-1;
		for(int j=0;j<js;j++){
			if(s[j]>mymax.m){
				mymax.m=s[j];
				mymax.myid=j;
			}
		}
		ans+=(char)mymax.m+'0';
		s[mymax.myid]=-1;
//		cout<<ans<<"\n";
	}
	cout<<ans;
	return 0;
}
