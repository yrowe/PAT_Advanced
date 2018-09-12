
#include <deque>
#include <iostream>
using namespace std;
int main(void)
{
	deque<int> d;
	d.push_back(6);
	d.push_back(7);
	//头部插入
	d.push_front(5);
	for(int i=0; i<d.size(); i++)  //打印6 7
		cout << d[i] << ' ';
	cout << endl;
	//中间位置插入
	d.insert(d.begin() +1 ,9);     //在第个元素前插入,即9 6 7
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
