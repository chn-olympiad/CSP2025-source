//王乙丞 西安滨河学校 SN-J00708 
#include <bits/stdc++.h>
using namespace std;
int Wang1,Wang2;
int Wanga[1005],Wangb[1005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>Wang1>>Wang2;
	int Wang3=0;
	for(int i=1;i<=Wang1*Wang2;i++){
		cin>>Wanga[i];
		if(i==1)Wang3=Wanga[i];
	}
	sort(Wanga+1,Wanga+Wang1*Wang2+1);
	int Wang4=1;
	for(int i=Wang1*Wang2;i>=1;i--){
		Wangb[Wang4]=Wanga[i];
		Wang4++;
	}
    for (int i=1;i<=Wang1*Wang2;i++){
    	if(Wangb[i]==Wang3){
    		Wang4=i;
    		break;
		}
	}
	int Wang5=Wang4/Wang1;
	if (Wang4%Wang1!=0)Wang5++;
	if(Wang5%2==1){
		cout<<Wang5<<' '<<Wang4-(Wang5-1)*Wang1;
	}
	else cout<<Wang5<<' '<<Wang1-(Wang4-(Wang5-1)*Wang1)+1;
	return 0;
}
