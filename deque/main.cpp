
#include <deque>
#include <iostream>
using namespace std;
int main(void)
{
	deque<int> d;
	d.push_back(6);
	d.push_back(7);
	//ͷ������
	d.push_front(5);
	for(int i=0; i<d.size(); i++)  //��ӡ6 7
		cout << d[i] << ' ';
	cout << endl;
	//�м�λ�ò���
	d.insert(d.begin() +1 ,9);     //�ڵڸ�Ԫ��ǰ����,��9 6 7
	for(int j=0; j<d.size(); j++)
		cout << d[j] << ' ';
	cout << endl;

	d.erase(d.begin());
    for(int j=0; j<d.size(); j++)
		cout << d[j] << ' ';
	cout << endl;

	d.pop_back();
    for(int j=0; j<d.size(); j++)
		cout << d[j] << ' ';
	cout << endl;

	d.pop_front();
	for(int j=0;j < d.size(); ++j)
        cout << d[j] << " ";
    cout << endl;

	return 0;
}
