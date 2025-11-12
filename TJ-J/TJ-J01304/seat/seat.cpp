#include<algorithm>
#include<iostream>
using namespace std;
struct seat{
	int score;
	int id;
}num[103]={0};
int main(){
	num[102].score=200;
	num[0].score=-1;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c;
	short b1,b2,a1;
	cin>>n;
	cin>>m;
	int j=0;
	for(int i=n*m;i>0;i--){
		j=i;
		cin>>num[i].score;
		b1=num[j-1].score;
		b2=num[j].score;
		while(b2<b1){
			num[j-1].score=b2;
			num[j].score=b1;
			j--;
			b1=num[j-1].score;
			b2=num[j].score;
		}
	}
	//for(int i=0;i<=n*m;i++)cout<<"#"<<num[i].score;
	cout<<1<<' '<<1<<endl;

}

