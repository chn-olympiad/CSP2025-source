#include<iostream> 
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	long long int b[1000010],c,num=1;
	cin>>a;
	for(int i=0;i<a.size();i++){
		c=int(a[i])-48;
		if(c>0&&c<9||c==0||c==9){
			b[num]=c;
			num++;
		}
	}
	if(num==2){
		cout<<b[1];
		return 0;
	}
	for(int i=1;i<num;i++){
		for(int j=1;j<num-1;j++){
			int h=0;
			if(b[j]<b[j+1]){
				h=b[j];
				b[j]=b[j+1];
				b[j+1]=h;
			}
		}
	}
	if(b[1]!=0){
		for(int i=1;i<num;i++){
		    cout<<b[i];
	    }
	}else{
		cout<<0;
	}
	return 0;
}
