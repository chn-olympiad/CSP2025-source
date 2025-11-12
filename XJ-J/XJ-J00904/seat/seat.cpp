#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r;
	cin>>n>>m;
	int grade[n*m];
	for(int q=0;q<n*m;q++){
		cin>>grade[q];
	}
	int count=grade[0];
	for(int q=0;q<n*m;q++){
		for(int w=q+1;w<n*m;w++){
			if(grade[w]>grade[q]){
				int zhou=grade[q];
				grade[q]=grade[w];
				grade[w]=zhou;
			}
		}
	}
	int paimin;
	for(int q=0;q<n*m;q++){
		if(grade[q]==count)
			paimin=q+1;
	}
	if(paimin%n>0){
		if((paimin/n+1)%2==0){
			cout<<paimin/n+1<<" "<<n-(paimin%n)+1;
		}
		else{
			cout<<paimin/n+1<<" "<<paimin%n;
		}
	}
	else{
		if((paimin/n)%2==0){
			cout<<paimin/n<<" "<<1;
		}
		else{
			cout<<paimin/n<<" "<<n;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
