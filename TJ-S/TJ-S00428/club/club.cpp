#include<bits/stdc++.h>	
std::vector<int> A;
std::vector<int> B;
std::vector<int> C;
std::vector<int> F;
int n;
int ANS=0;
void DFS(std::string a,int len){
	if(len==n){
		int ans=0;
		int A_cost=0;
		int B_cost=0;
		int C_cost=0;
		for(int i=0;i<len;i++){
			if(a[i]=='1'){
				ans+=A[i];
				A_cost++;
			}
			else if(a[i]=='2'){
				ans+=B[i];
				B_cost++;
			}else{
				ans+=C[i];
				C_cost++;
			}
			if(C_cost>n/2||B_cost>n/2||A_cost>n/2)return;
		}
	
		ANS=std::max(ANS,ans);
	}else{
		DFS(a+'1',len+1);
		DFS(a+'2',len+1);
		DFS(a+'3',len+1);
	}
	return;
}
void LiM(){
	ANS=0;
	A.clear();
	B.clear();
	C.clear();
	F.clear();
	F.clear();
	std::cin>>n;
	for(int i=0;i<n;i++){
		int a,b,c;
		std::cin>>a>>b>>c;
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
	}
	/*bool flag=1;
	for(int i=0;i<n;i++){
		if(B[i]!=0&&C[i]!=0){
			flag=false;
			break; 
		}
	}
	if(flag){
		std::sort(A.begin(),A.end(),std::greater<int>());
		for(int i=0;i<n/2;i++){
			ANS+=A[i];
		}
		std::cout<<ANS<<"\n";
		return;
	}*/
	DFS("",0);
	std::cout<<ANS<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	std::cin>>T;
	while(T--)LiM();
} 
