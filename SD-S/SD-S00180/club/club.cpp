#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct pm{
	int a;
	int b;
	int c;
};

int T;

int n;
vector<pm> vec;
/*vector<int> A;
vector<int> B;
vector<int> C;*/
pm temp;
int ta,tb,tc;

/*bool cmp_A(int a,int b){
	return vec[a].a>vec[b].a;
}
bool cmp_B(int a,int b){
	return vec[a].b>vec[b].b;
}
bool cmp_C(int a,int b){
	return vec[a].c>vec[b].c;
}

void put(int i){
	int maxn=max(max(vec[i].a,vec[i].b),vec[i].c);
	if(maxn==vec[i].a){
		A.push_back(i);
	}
	else if(maxn==vec[i].b){
		B.push_back(i);
	}
	else{
		C.push_back(i);
	}
}*/
bool cmp(pm a,pm b){
	return a.a>b.a;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		
		cin>>n;
		
		temp.a=0;
	    temp.b=0;
	    temp.c=0;
		vec=vector<pm>(n+1,temp);
		/*A=vector<int>(1,0);
		B=vector<int>(1,0);
		C=vector<int>(1,0);*/
		for(int i=1;i<=n;i++){
			cin>>ta>>tb>>tc;
			temp.a=ta;
			temp.b=tb;
			temp.c=tc;
			vec[i]=temp;
		}
		
		if(n==2){
			int maxn=-1;
			maxn=max(vec[1].a+vec[2].b,maxn);
			maxn=max(vec[1].a+vec[2].c,maxn);
			maxn=max(vec[1].b+vec[2].a,maxn);
			maxn=max(vec[1].b+vec[2].c,maxn);
			maxn=max(vec[1].c+vec[2].a,maxn);
			maxn=max(vec[1].c+vec[2].b,maxn);
			cout<<maxn;
		}
		else{
			sort(vec.begin()+1,vec.end(),cmp);
			int sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=vec[i].a;
			}
			cout<<sum<<"\n";
		}
		
		
		/*for(int i=1;i<=n;i++){
			put(i);
		}
		//cout<<"//////////\n";
		if(A.size()-1>n/2){
			//cout<<"//////////\n";
			sort(A.begin()+1,A.end(),cmp_A);
			int cy=A.size()-1-n/2;
			for(int i=1;i<=cy;i++){
				int j=A.size()-i;
				if(vec[A[j]].b>=vec[j].c){
					B.push_back(A[j]);
					A.pop_back();
				}
				else{
					C.push_back(A[j]);
					A.pop_back();
				}
			}
		}
		else if(B.size()-1>n/2){
			//cout<<"//////////\n";
			sort(B.begin()+1,B.end(),cmp_B);
			int cy=B.size()-1-n/2;
			for(int i=1;i<=cy;i++){
				int j=B.size()-i;
				if(vec[B[j]].a>=vec[j].c){
					A.push_back(B[j]);
					B.pop_back();
				}
				else{
					C.push_back(B[j]);
					B.pop_back();
				}
			}
		}
		else if(C.size()-1>n/2){
			//cout<<"//////////\n";
			sort(C.begin()+1,C.end(),cmp_C);
			int cy=C.size()-1-n/2;
			for(int i=1;i<=cy;i++){
				int j=C.size()-i;
				if(vec[C[j]].a>=vec[j].b){
					A.push_back(C[j]);
					C.pop_back();
				}
				else{
					B.push_back(C[j]);
					C.pop_back();
				}
			}
		}
        
		int sum=0;
		for(int i=1;i<A.size();i++){
			sum+=vec[A[i]].a;
		}
		for(int i=1;i<B.size();i++){
			sum+=vec[B[i]].b;
		}
		//cout<<"//////////\n";
		for(int i=1;i<C.size();i++){
			sum+=vec[C[i]].c;
		}
		cout<<sum<<"\n";*/
		
	}
	return 0;
} 
