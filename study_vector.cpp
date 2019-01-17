#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<set>
#include<map>
using namespace std;
int main() {
	vector<int> vec1;
	vec1.push_back(5);
	vec1.pop_back();
	printf("%d\n", vec1.size());
	vec1.resize(4);
	vec1.clear();
	vec1.begin();
	vec1.end();
	vec1.erase(vec1.begin(), vec1.end());


	set<int> s;
	//원소(5) 삽입
	s.insert(5);
	//6값을 가지는 원소를 찾음 있다면 해당 원소의 주소값,  없다면 s.end()리턴
	if (s.find(6) != s.end())
		printf("존재합니다.\n");
	else
		printf("없습니다.\n");
	//저장된 원소의 수를 리턴
	printf("%d\n", s.size());
	//모든 원소 삭제
	s.clear();

	//int 자료형을 key로 int 자료형을 데이터로 저장하는 딕셔너리 자료구조 생성
	map<int, int> m;
	//(4, 5)원소 삽입
	m.insert(make_pair(4, 5));
	//또는
	m[5] = 6;
	//key와 연관된 원소를 pair<키 자료형, 데이터 자료형> 형태로 리턴함
	printf("%d\n", m.find(4)->second);
	//key와 연관된 원소의 개수를 리턴함
	printf("%d\n", m.count(4));
	//저장된 원소의 수를 리턴함
	printf("%d\n", m.size());
	//해당 주소의 원소 삭제
	m.erase(++m.begin());
	//모든 원소 삭제
	m.clear();

	return 0;
}