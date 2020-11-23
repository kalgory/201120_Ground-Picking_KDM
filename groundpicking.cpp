#include <iostream>
#include <map>
#include <vector>
using namespace std;

void input(vector<vector<int>> &v,int N){
    for(int temp=0; temp<N; temp++){
        for(int temp2=0; temp2<4; temp2++){
            cin>>v[temp][temp2];
        }
    }
}

void cal(multimap<int,int,greater<int>> &memo,vector<int> &v,int index){
    map<int,int>::iterator iter=memo.begin(); 
    map<int,int>::iterator it=memo.begin(); 
    it++;
    if(index==0) {
        cout<<iter->first;
        return;
    }
    for(int temp=0;temp<4;temp++) v[temp]+=iter->first;
    v[iter->second]=v[iter->second]-iter->first+it->first;
    
}

int main(){
    int N=0; //행의 크기
    multimap<int,int,greater<int>> memo; //memoization 저장소 multimap설정
    cin>>N;
    vector<vector <int>> input_vector(N, vector<int> (4,0)); //intput값을 저장하는 vector생성
    input(input_vector,N);//input값 vector에 저장
    for(int temp=N-1;temp>=0;temp--){
        for(int temp_index=0;temp_index<4;temp_index++){
            memo.insert(pair<int,int>(input_vector[temp][temp_index],temp_index));
        }
        cal(memo,input_vector[temp-1],temp);
        memo.clear();
    }
}