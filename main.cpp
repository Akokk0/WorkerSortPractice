#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

enum Department {

    programming,
    art,
    planning

};

class Worker {

private:

    string m_Name;
    int m_Salary;

public:

    Worker() {}
    Worker(string name, int salary) : m_Name(name), m_Salary(salary) {}

    /*Worker(const Worker & worker) {

        this->m_Name = worker.m_Name;
        this->m_Salary = worker.m_Salary;

    }*/

    const string &getMName() const {
        return m_Name;
    }

    void setMName(const string &mName) {
        m_Name = mName;
    }

    int getMSalary() const {
        return m_Salary;
    }

    void setMSalary(int mSalary) {
        m_Salary = mSalary;
    }

    friend ostream &operator<<(ostream &os, const Worker &worker) {
        os << "姓名🆔: " << worker.m_Name << " 薪水💰: " << worker.m_Salary;
        return os;
    }

};

//生成员工
void generateWorker(vector<Worker> & v) {

    string nameSeed = "ABCDEFGHIJ";

    for (int i = 0; i < 10; ++i) {

        int salary = rand() % 10000 + 10000;

        string name = "员工";
        name += nameSeed[i];

        Worker worker(name, salary);

        v.push_back(worker);

    }

}

void printWorker(vector<Worker> & v) {

    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {

        cout << *it << endl;

    }

}

void sortWorker(vector<Worker> & v, multimap<Department, Worker> & map) {

    int i = 0;

    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++, i++) {

        int randNum = rand() % 3;

        Department d;

        switch (randNum) {

            case 0:
                d = programming;
                map.insert(make_pair(d, v[i]));
                break;

            case 1:
                d = art;
                map.insert(make_pair(d, v[i]));
                break;

            case 2:
                d = planning;
                map.insert(make_pair(d, v[i]));
                break;

        }

    }

}

void printSortWorker(multimap<Department, Worker> m) {

    cout << "Programming" << endl;
    Department d = programming;
    multimap<Department, Worker>::iterator pos = m.find(d);
    int num = m.count(d);

    for(; pos != m.end(), num != 0; pos++, num--) {

        cout << pos->second << endl;

    }

    cout << endl;

    cout << "Art" << endl;
    d = art;
    pos = m.find(d);
    num = m.count(d);

    for(; pos != m.end(), num != 0; pos++, num--) {

        cout << pos->second << endl;

    }

    cout << endl;

    cout << "Planning" << endl;
    d = planning;
    pos = m.find(d);
    num = m.count(d);

    for(; pos != m.end(), num != 0; pos++, num--) {

        cout << pos->second << endl;

    }

    cout << endl;

}

int main() {

    //生成随机数
    srand((unsigned int) time(NULL));

    //创建员工列表
    vector<Worker> v;

    //生成员工
    generateWorker(v);

    //测试代码，输出打印所有员工
    //printWorker(v);

    //创建map集合
    multimap<Department, Worker> m;

    //将员工分类
    sortWorker(v, m);

    //测试代码
    //cout << typeid(rand() % 10000).name() << endl;

    //打印分类后的员工
    printSortWorker(m);

    return 0;

}
