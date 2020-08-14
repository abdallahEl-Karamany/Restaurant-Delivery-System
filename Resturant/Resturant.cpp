#include<iostream>
#include<windows.h>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>
using namespace std;

class Order
{
private:
	int id;
	int arrivalTime;
	int distance;
	int waitingTime, serviceTime, finishTime;
	double money;

public:
	Order(int arrivalTime, int id, int distance, double money)
	{
		this->id = id;
		this->arrivalTime = arrivalTime;
		this->distance = distance;
		this->money = money;
	}



	int get_id()
	{
		return id;
	}

	int get_arrivalTime()
	{
		return arrivalTime;
	}

	int get_distance()
	{
		return distance;
	}

	int get_Money()
	{
		return money;
	}

	void setServicetime(int serviceTime)
	{
		this->serviceTime = serviceTime;
	}

	int getServicetime()
	{
		return serviceTime;
	}

	void setFinishtime(int finishTime)
	{
		this->finishTime = finishTime;
	}

	int getFinishtime()
	{
		return finishTime;
	}

	void print()
	{
		cout << arrivalTime << "\t" << id << "\t" << distance << "\t" << money << endl;
	}

	void setwaitingTime(int timestep)
	{
		waitingTime = timestep - arrivalTime;
	}

	int getwaitingTime()
	{
		return waitingTime;
	}
};

class Motorcycle {
private:
	int id, speed;
	Order* order;

public:
	Motorcycle(int id, int speed)
	{
		this->id = id;
		this->speed = speed;
	}


	int get_id()
	{
		return id;
	}

	int get_speed()
	{
		return speed;
	}

	void setOrder(Order* order)
	{
		this->order = order;
	}

	Order* getOrder()
	{
		return order;
	}

	void calc_serviceTime()
	{
		order->setServicetime(order->get_distance() / speed);
	}


	void calc_OrderfinishTime()
	{
		order->setFinishtime(order->getServicetime() + order->get_arrivalTime() + order->getwaitingTime());
	}



	int getCyclefinishTime()
	{
		return (order->getFinishtime() + order->getServicetime());
	}


};

struct cancelOrder { int cancelTime; int id; };

class OrderNode
{
public:
	Order* Data;
	OrderNode* next;
};

class OrderslinkedList {

public:
	OrderNode* head;
	int size = 0;
	OrderslinkedList()
	{
		head = NULL;
	}



	OrderNode* deleteNode(OrderNode* Node)
	{
		OrderNode* search = head;
		OrderNode* temp = new OrderNode();
		if (Node == head)
		{
			temp = head;
			head = temp->next;
			delete temp;
			size--;
			return head;
		}

		while (search->next != Node)
		{
			if (search->next == NULL)
			{
				return head;
			}
			search = search->next;
		}
		temp = search->next;
		search->next = search->next->next;
		delete temp;
		size--;
		return head;
	}


	OrderNode* insertAt(Order* data, int index)
	{
		OrderNode* search = head;


		for (int i = 0; i < index - 1; i++)
		{
			search = search->next;
		}

		OrderNode* temp = new OrderNode();
		temp->Data = data;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
		}

		else
		{
			temp->next = search->next;
			search->next = temp;
		}

		return head;
	}


	OrderNode* insert(Order* data)
	{
		OrderNode* last = new OrderNode();
		last->Data = data;
		last->next = NULL;

		if (head == NULL)
		{
			head = last;
		}

		else
		{
			OrderNode* n = new OrderNode();
			n = head;

			while (n->next != NULL)
			{
				n = n->next;
			}

			n->next = last;
		}

		size++;
		return head;
	}

	void print()		// printing the linked list
	{
		OrderNode* n = head;
		while (n != NULL)
		{
			n->Data->print();
			n = n->next;
		}
	}

	void Push(Order* data)			//create new node in the linked list from the front
	{
		OrderNode* new_node = new OrderNode();
		new_node->Data = data;
		new_node->next = head;
		head = new_node;
	}
};

class MotorcyclesNode
{
public:
	Motorcycle* Data;
	MotorcyclesNode* next;
};

class MotorcycleslinkedList {

public:
	MotorcyclesNode* head;
	MotorcycleslinkedList()
	{
		head = NULL;
	}

	MotorcyclesNode* getHead() {
		return head;
	}

	MotorcyclesNode* deleteNode(MotorcyclesNode* Node)
	{
		MotorcyclesNode* search = head;
		MotorcyclesNode* temp = new MotorcyclesNode();
		if (Node == head)
		{
			temp = head;
			head = temp->next;
			delete temp;
			return head;
		}

		while (search->next != Node)
		{
			if (search->next == NULL)
			{
				return head;
			}
			search = search->next;
		}
		temp = search->next;
		search->next = search->next->next;
		delete temp;
		return head;
	}

	MotorcyclesNode* insertAt(Motorcycle* data, int index)
	{
		//create new pointer
		MotorcyclesNode* search = head;

		//ha search be al index
		for (int i = 0; i < index - 1; i++)
		{
			search = search->next;
		}

		MotorcyclesNode* temp = new MotorcyclesNode();
		temp->Data = data;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
		}

		else
		{
			temp->next = search->next;
			search->next = temp;
		}

		return head;
	}


	MotorcyclesNode* insert(Motorcycle* data)
	{
		MotorcyclesNode* last = new MotorcyclesNode();
		last->Data = data;
		last->next = NULL;
		if (head == NULL)
		{
			head = last;
		}

		else
		{
			MotorcyclesNode* n = new MotorcyclesNode();
			n = head;
			while (n->next != NULL)
			{
				n = n->next;
			}
			n->next = last;
		}
		return head;
	}

	void print()
	{
		MotorcyclesNode* n = head;
		while (n != NULL)
		{
			cout << n->Data->get_id() << "\t";
			n = n->next;
		}
		cout << endl;
	}

	void Push(Motorcycle* data)
	{
		MotorcyclesNode* new_node = new MotorcyclesNode();
		new_node->Data = data;
		new_node->next = head;
		head = new_node;
	}
};


int main()
{
	int motorcyclesNum, speed;

	queue <Motorcycle*> motorcycles;
	queue<cancelOrder> Cancel;
	queue<Order*> finishedOrders;
	OrderslinkedList OrderlinkedList;
	MotorcycleslinkedList motorcyclelinkedList;
	string inPuts;
	ifstream input1("input1.txt");
	ofstream OutPutFile("outputFile.txt");
	int totalMoney = 0;
	int ordersNum = 0;
	int CancelorderNum = 0;
	float totalWaitingTime = 0;
	float totalServiceTime = 0;
	float AvgWaitingTime = 0;
	float AvgServiceTime = 0;

	getline(input1, inPuts);
	motorcyclesNum = stoi(inPuts.substr(0, 1));

	getline(input1, inPuts);
	speed = stoi(inPuts.substr(0, 2));

	for (int i = 0; i < motorcyclesNum; i++)
	{
		motorcycles.push(new Motorcycle(i + 1, speed));
	}

	while (getline(input1, inPuts))
	{
		if (inPuts.substr(0, 1) == "R")
		{

			OrderlinkedList.insert(new Order(stoi(inPuts.substr(2, 2)),
				stoi(inPuts.substr(5, 3)),
				stoi(inPuts.substr(9, 2)),
				stoi(inPuts.substr(12, 3))));
		}

		else if (inPuts.substr(0, 1) == "X")
		{
			Cancel.push(cancelOrder{ stoi(inPuts.substr(2, 2)), stoi(inPuts.substr(5, 2)) });
		}
	}

	OrderNode* orderNode = OrderlinkedList.head;
	MotorcyclesNode* MotorcycleNode = motorcyclelinkedList.head;
	MotorcyclesNode* nextNode;
	cout << "ID\t" << "Arrival Time\t" << "Waiting Time\t" << "Service Time\t" << "delivered Time\t\t" << "Money\t\n\n";
	OutPutFile << "ID\t" << "Arrival Time\t" << "Waiting Time\t" << "Service Time\t" << "delivered Time\t\t" << "Money\t\n\n";

	for (int timeStep = 0; timeStep < 100; timeStep++)
	{
		while (orderNode != NULL && orderNode->Data->get_arrivalTime() <= timeStep && !motorcycles.empty())
		{

			Motorcycle* cycle;
			cycle = motorcycles.front();
			motorcyclelinkedList.insert(cycle);
			motorcycles.pop();
			cycle->setOrder(orderNode->Data);

			orderNode->Data->setwaitingTime(timeStep);
			cycle->calc_serviceTime();
			cycle->calc_OrderfinishTime();

			OrderlinkedList.deleteNode(orderNode);
			orderNode = OrderlinkedList.head;
			finishedOrders.push(cycle->getOrder());

			cout << finishedOrders.front()->get_id() << "\t\t" << finishedOrders.front()->get_arrivalTime() << "\t\t"
				<< finishedOrders.front()->getwaitingTime() << "\t\t" << finishedOrders.front()->getServicetime() << "\t\t"
				<< finishedOrders.front()->getFinishtime() << "\t\t" << finishedOrders.front()->get_Money() << endl << endl;
			OutPutFile << finishedOrders.front()->get_id() << "\t\t" << finishedOrders.front()->get_arrivalTime() << "\t\t"
				<< finishedOrders.front()->getwaitingTime() << "\t\t" << finishedOrders.front()->getServicetime() << "\t\t"
				<< finishedOrders.front()->getFinishtime() << "\t\t" << finishedOrders.front()->get_Money() << endl << endl;

			totalWaitingTime += finishedOrders.front()->getwaitingTime();
			totalServiceTime += finishedOrders.front()->getServicetime();
			totalMoney += finishedOrders.front()->get_Money();
			ordersNum++;

			finishedOrders.pop();
		}

		MotorcycleNode = motorcyclelinkedList.head;
		while (MotorcycleNode != NULL)
		{
			if (MotorcycleNode->Data->getCyclefinishTime() == timeStep)
			{
				motorcycles.push(MotorcycleNode->Data);
				nextNode = MotorcycleNode->next;
				motorcyclelinkedList.deleteNode(MotorcycleNode);
				MotorcycleNode = nextNode;
			}

			else
			{
				MotorcycleNode = MotorcycleNode->next;
			}
		}

		bool check = false;
		while (!Cancel.empty() && Cancel.front().cancelTime == timeStep)
		{
			orderNode = OrderlinkedList.head;
			while (orderNode != NULL)
			{
				if (orderNode->Data->get_id() == Cancel.front().id)
				{
					orderNode = OrderlinkedList.deleteNode(orderNode);
					CancelorderNum++;
					Cancel.pop();
					check = true;
					break;
				}

				else
				{
					orderNode = orderNode->next;
				}

			}

			if (check == false)
			{
				Cancel.pop();
			}
		}
		Sleep(500); 
	}

	AvgWaitingTime = totalWaitingTime / ordersNum;
	AvgServiceTime = totalServiceTime / ordersNum;
	//output on consoule.
	cout << "\t\t\t************************" << endl
		<< "\t\t\t************************" << endl << endl
		<< "number of orders= " << ordersNum << endl << "number of Cancelled Orders= " << CancelorderNum
		<< endl << "total money of orders= " << totalMoney << endl
		<< "Average Waiting Time= " << AvgWaitingTime << endl << "Average Service Time= " << AvgServiceTime;
	//output will be on externalfile called outputFile.txt
	OutPutFile << "\t\t\t************************" << endl
		<< "\t\t\t************************" << endl << endl
		<< "number of orders= " << ordersNum << endl << "number of Cancelled Orders= " << CancelorderNum
		<< endl << "total money of orders= " << totalMoney << endl
		<< "Average Waiting Time= " << AvgWaitingTime << endl << "Average Service Time= " << AvgServiceTime;
	cout << "output file has been saved" << endl;

	return 0;

}