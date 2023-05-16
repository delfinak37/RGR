#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int temp = 1;
class Point
{
	private:
		string name, locate;
		int a,b,c,num,salary;
	public:
		void put(Point p, vector<Point>& worker)
		{
			ifstream fin;
			fin.open("text32-1.txt");
			if (!fin)	cout << "File not founded!!";
			
			while(!fin.eof())
			{
				fin >> p.name >> p.locate >> p.a >> p.b >> p.c;
				p.salary = p.a*5 + p.b*15 + p.c*20;
				p.num = temp;
				temp++;
				worker.push_back(p);
			}
			fin.close();
		}
		
		void show(vector<Point>& worker)
		{
			int n = 0;
			cout << "\n	 |WORKERS DATA|\n"
				<< "********************************\n";
			while(n < worker.size())
			{
				cout << worker[n].name << " " << worker[n].locate 
					<< "  " << worker[n].a << " " << worker[n].b 
					<< " " << worker[n].c << "  " << worker[n].salary 
					<< "$" << endl;
				n++;
			}
			cout << "********************************\n\n\n";
		}	
		
		void push(Point p, vector<Point>& worker)
		{
			ofstream fout;
			fout.open("text32-2.txt");
			if (!fout) cout << "File not founded!!";
			
			int n,d1,d2,d3;
			double a1,a2,a3; 
			n = a1 = a2 = a3 = d1 = d2 = d3 = 0;
			
			while(n < worker.size())
			{	
				fout << worker[n].num << ") " <<worker[n].name << " " << worker[n].locate << " -- " 
					<< worker[n].a << " " << worker[n].b << " " 
					<< worker[n].c << " --  " << worker[n].salary << "$" << endl;
				
				if(worker[n].locate == "A1")
				{
					a1 = a1 + worker[n].salary;
					d1 += 1;
				}
					
				if(worker[n].locate == "A2")
					{
						a2 = a2 + worker[n].salary;
						d2 += 1;
					}
					
				if(worker[n].locate == "A3")
					{
						a3 = a3 + worker[n].salary;
						d3 += 1;
					}
				n++;
			}
			fout << endl << "Workshop salary:\nA1 -- " << a1/d1 
				<< "$\nA2 -- " << a2/d2 << "$\nA3 -- " << a3/d3 << "$";
			fout.close();
			cout << "Saved successfully!\n\n";
		}
		
		void del(vector<Point>& worker) 
		{
			cout << "Enter number of worker to delete: ";
			int n;	bool found = false;
			cin >> n;
			for(auto it = worker.begin(); it != worker.end();)
			{
				if(it->num == n)
				{
					it = worker.erase(it);
					found = true;
					break;
				}
				it++;
			}
			if(found == true)
				cout << "|Worker successfully deleted|\n\n";
			else
				cout << "|Worker not founded|\n\n";
		}
			
		void enter(vector<Point>& worker)
		{
			Point t;
			int num = temp;	temp++;
			string name,locate; name = locate = "";
			
			cout << "Enter candidate information:\nName: ";
				cin >> t.name;
				
				int k = 1;
				while(k != 0)
				{
					for(auto it = worker.begin(); it < worker.end();)
						{
							if(t.name == it->name)
							{
								cout << "Such worker already exists. Enter name again: ";
								cin >> t.name;
							}
							else ++it;
						}
					k = 0;
				}
				
			cout << "Number workshop: ";
				cin >> t.locate;
			cout << "Quantity products -A- : ";
				cin >> t.a;
			cout << "Quantity products -B- : ";
				cin >> t.b;
			cout << "Quantity products -C- : ";
				cin >> t.c;	cout << "\n";
				t.salary = t.salary = t.a*5 + t.b*15 + t.c*20;
			worker.push_back(t);
		}
		
		void sorting(vector<Point>& worker)
		{
			int n = -1;
			while(n)
			{
				switch(n)
				{
					case 1:
						sort(worker.begin(),worker.end(),[](Point n1, Point n2) {return n1.name < n2.name;});
						n = 0;
						break;
					case 2:
						sort(worker.begin(),worker.end(),[](Point n1, Point n2) {return n1.locate < n2.locate;});
						n = 0;
						break;
					case 3:
						sort(worker.begin(),worker.end(),[](Point n1, Point n2) {return n1.a < n2.a;});
						n = 0;
						break;
					case 4:
						sort(worker.begin(),worker.end(),[](Point n1, Point n2) {return n1.b < n2.b;});
						n = 0;
						break;
					case 5:
						sort(worker.begin(),worker.end(),[](Point n1, Point n2) {return n1.c < n2.a;});
						n = 0;
						break;		
					case 6:
						sort(worker.begin(),worker.end(),[](Point n1, Point n2) {return n1.salary < n2.salary;});
						n = 0;
						break;
					case 7:
						sort(worker.begin(),worker.end(),[](Point n1, Point n2) {return n1.num < n2.num;});
						n = 0;
						break;
					default:
						{
							cout << "Sort by:\n1 - Name\n2 - Workshop\n3 - Products -A- "
								<<"\n4 - Products -B- \n5 - Products -C- \n6 - Salary"
								<<"\n7 - Worker number\nChoosen: ";
							cin >> n; cout << "\n";
							if(n < 0 or n > 7)
							{
								cout << "\nDenied! Enter choosen again\n";
								cin >> n;
							}
							break;	
						}
				}
			}
		}
};



int main()
{
	Point p;
	vector<Point> worker;
	p.put(p,worker);
	
	int n = -1;
	while(n)
	{
		switch(n)
		{
			case 1:
				p.enter(worker);
				n = -1;
				break;
			case 2:
				p.del(worker);
				n = -1;
				break;
			case 3:
				p.push(p,worker);
				n = -1;
				break;
			case 4:
				p.show(worker);
				n = -1;
				break;
			case 5:
				p.sorting(worker);
				p.show(worker);
				n = -1;
				break;
			default:
				{
					cout << "	   |GENERAL|"
						<<"\n================================\n"
						<<"1 - Add worker\n2 - Delete worker\n3 " 
						<< "- Save data of workers\n4 - Show data of"
						<< " workers\n5 - Sorting data\n0 - Exit\n"
						<< "================================\nChosen: ";
					cin >> n; cout << "\n";
							if(n < 0 or n > 5)
							{
								cout << "\nDenied! Enter choosen again\n";
								cin >> n;
							}
							break;		
				}
				
		}
	}	
}

