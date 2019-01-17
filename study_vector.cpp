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
	//����(5) ����
	s.insert(5);
	//6���� ������ ���Ҹ� ã�� �ִٸ� �ش� ������ �ּҰ�,  ���ٸ� s.end()����
	if (s.find(6) != s.end())
		printf("�����մϴ�.\n");
	else
		printf("�����ϴ�.\n");
	//����� ������ ���� ����
	printf("%d\n", s.size());
	//��� ���� ����
	s.clear();

	//int �ڷ����� key�� int �ڷ����� �����ͷ� �����ϴ� ��ųʸ� �ڷᱸ�� ����
	map<int, int> m;
	//(4, 5)���� ����
	m.insert(make_pair(4, 5));
	//�Ǵ�
	m[5] = 6;
	//key�� ������ ���Ҹ� pair<Ű �ڷ���, ������ �ڷ���> ���·� ������
	printf("%d\n", m.find(4)->second);
	//key�� ������ ������ ������ ������
	printf("%d\n", m.count(4));
	//����� ������ ���� ������
	printf("%d\n", m.size());
	//�ش� �ּ��� ���� ����
	m.erase(++m.begin());
	//��� ���� ����
	m.clear();

	return 0;
}