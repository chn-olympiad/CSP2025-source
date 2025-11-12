#include<bits/stdc++.h>
using namespace std;

int n,m,value;

struct pos{
	int x,y;
};

vector<int> score;

pos find_seat(int n,int m,int s){
	pos p;
	if((s/n)%2==0){//ÆæÊýÅÅ 
		p.x=s%n;
	}else{//Å¼ÊýÅÅ 
		p.x=n-(s%n)+1;
	}
	float fn=n;
	p.y=ceil(s/fn);
	return p;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int i=n*m;
	while(i--){
		cin>>value;
		score.push_back(value);
	}
	int score_ming=score[0],s_ming;
	sort(score.begin(),score.end(),greater<int>());
	for(int i=0;i<=score.size();i++){
		if(score[i]==score_ming)s_ming=i+1;
	}
	pos ans=find_seat(n,m,s_ming);
    cout<<ans.y<<' '<<ans.x;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
