#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct bond{
	int u;
	int v;
	int w;
	bool open;
};
struct contry_road{
	vector<int> bond_seat;
};
vector<bond> city_bond;
vector<bond> contry_bond;
vector<bool> contry_switch;
vector<int> city_father;
vector<int> contry_father;
vector<int> c;
int n,m,k;
long long ans=-1;
long long cur_ans_1=0;
bool bond_cmp(bond p,bond q){
	return p.w<q.w;
}
int find_root(int pos){
	if(pos<0){
		if(contry_father[-pos-1]!=-pos-1)contry_father[-pos-1]=find_root(contry_father[-pos-1]);
	}
	else{
		while(city_father[city_father[pos]]!=city_father[pos])city_father[pos]=city_father[city_father[pos]];
	}
}
void dfs(int pos,int point_cnt){
	if(pos<k){
		dfs(pos+1,point_cnt);
		contry_switch[pos]=true;
		for(size_t i=0;i<n;i++)
		    contry_bond[contry_road[pos].bond_seat[i]]=true;
		cur_ans_1+=1ll*c[pos];
		if(ans==-1 || cur_ans_1<ans)dfs(pos+1,point_cnt+1);
	}
	else{
		int city_bond_pos=0;
		int contry_bond_pos=0;
		int connect_remain=point_cnt-1;
		long long cur_ans_2=cur_ans_1;
		bond b1,b2;
		city_father.resize(n);
		for(int i=0;i<n;i++)
			city_father[i]=i;
		for(int j=0;j<k;j++)
			contry_father[j]=-j-1;
		while(connect_remain>0){
			b1=contry_bond[contry_bond_pos];
			b2=city_bond[city_bond_pos];
			while(contry_bond_pos!=-1 && (b1.open==false||find_root(b1.u)==find_root(b2.v))){
				if(contry_bond_pos<k*n)
					coutry_cond_pos++;
				else
					contry_bond_pos=-1;
			}
			while(city_bond_pos!=-1 && (contry_father[city_bond[city_bond_pos].u]==city_father[city_bond[city_bond_pos].v])){
				if(city_bond_pos<m)
					city_cond_pos++;
				else
					city_bond_pos=-1;
			}
			connect_remain_cnt--;
			if(bond_cmp(b1,b2)){
				cur_ans_2+=1ll*b1.w;
			}
			else{
				cur_ans_2+=1ll*b2.w;
			}
			if(ans!=-1&&cur_ans_2>=ans)break;
		}
		if(ans==-1||cur_ans_2<ans)ans=cur_ans_2;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int cur_ans;
	int u,v,w;
	bond temp_bond;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&w);
		temp_bond.u=u-1;
		temp_bond.v=v-1;
		temp_bond.w=w;
		temp_bond.open=true;
		city_bond.push_back(temp_bond);
	}
	contry_switch.resize(k,false);
	c.resize(k);
	for(int j=0;j<k;j++){
		u=-1-j;//xiang cun cong -1 kai shi bian hao
		scanf("%d",&c[j]);
		for(v=0;v<n;v++){
			scanf("%d",&w);
			temp_bond.u=u;
			temp_bond.v=v;
			temp_bond.w=w;
			temp_bond.open=false;
			contry_bond.push_back(temp_bond);
		}
	}
	sort(city_bond.begin(),city_bond.end(),bond_cmp);
	sort(contry_bond.begin(),contry_bond.end(),bond_cmp);
	contry.resize(k);
	for(size_t i=0;i<contry_bond.size();i++){
		temp_bond=contry_bond[i];
		contry_road[-temp_bond.u-1].bond_seat[temp_bond.v].push_back(i);
    }
	dfs(0,n);
	printf("%lld",ans);
	return 0;
}
