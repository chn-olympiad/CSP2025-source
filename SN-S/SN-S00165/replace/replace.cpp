//安奭颉 SN-S00165 西安高新一中沣东中学初中校区
#include<bits/stdc++.h>
using namespace std;
struct panduan{
	int a1q,a1h,a2q,a2h;
}a[200001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m,sum;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		int x_len=x.length();
		int y_len=y.length();
		for(int j=0;j<=x_len;j++){
			if(x[j]=='b'){
				a[i].a1h=j;
				a[i].a1q=x_len-j-1;
				break;
			} 
		}
		for(int j=0;j<=y_len;j++){
			if(y[j]=='b'){
				a[i].a2h=j;
				a[i].a2q=y_len-j-1;
				break;
			} 
		}
	}
	for(int i=1;i<=m;i++){
		sum=0;
		string x,y;
		int s1,s2,s3,s4;
		cin>>x>>y;
		int x_len=x.length();
		int y_len=y.length();
		for(int j=0;j<=x_len;j++){
			if(x[j]=='b'){
				s1=j;
				s2=x_len-j-1;
				break;
			} 
		}
		for(int j=0;j<=y_len;j++){
			if(y[j]=='b'){
				s3=j;
				s4=y_len-j-1;
				break;
			} 
		}
		for(int i=1;i<=n;i++){
			if(s1+a[i].a2h-a[i].a1h==s3&&s2+a[i].a2q-a[i].a1q==s4) sum++;
		}
		cout<<sum<<endl;
	}
	return 0;
}
