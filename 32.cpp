#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class Point
{
	private:
		string name;
		string locate;
		int a,b,c;
	public:
		void put(Point p, vector<Point>& worker)
		{
			ifstream fin;
			fin.open("text32-1.txt");
			if (!fin)	cout << "not OK!!!";
		
			while(fin)
			{
				fin >> p.name >> p.locate >> p.a >> p.b >> p.c;
				worker.push_back(p);
			}
			fin.close();
		}
		
		void show(vector<Point>& worker)
		{
			int n = 0;
			while(1)
			{
				cout << worker[n].name << " " << worker[n].locate << " " << worker[n].a
					<< " " << worker[n].b << " " << worker[n].c << endl;
				n++;
			}
		}	
}; 


int main()
{
	Point p;
	vector<Point> worker;
	p.put(p,worker);
	
	cout << worker.end();
	//p.show(worker);
		
}

