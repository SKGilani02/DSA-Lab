#include <iostream>
#include <string>
using namespace std;

struct Applicant {
    int applicant_id;
    float height;
    float weight;
    float vision;
    string status;
    Applicant* next;

    Applicant(int id, float h, float w, float v, string s) {
        applicant_id = id;
        height = h;
        weight = w;
        vision = v;
        status = s;
        next = nullptr;
    }
};

class ApplicantQueue 
{
private:
    Applicant* front;
    Applicant* rear;

public:
    ApplicantQueue() 
	{
        front=rear=nullptr;
    }

    void enqueue(int id, float height, float weight, float vision, string status) 
	{
        Applicant* newApplicant=new Applicant(id, height, weight, vision, status);
        if(rear==nullptr)
		{
            front=rear=newApplicant;
        } 
		else
		{
            rear->next=newApplicant;
            rear=newApplicant;
        }
        cout<<"Applicant "<<id<<" has been added to the queue."<<endl;
    }

    void dequeue() 
	{
        if(front==nullptr) 
		{
            cout<<"Queue is empty!"<<endl;
            return;
        }
        Applicant*temp=front;
        front=front->next;
        cout<<"Applicant "<<temp->applicant_id<<" has completed the test and left the queue."<<endl;
        delete temp;

        if(front == nullptr)rear=nullptr;
    }

    void removeSecondApplicant() 
	{
        if(front==nullptr||front->next==nullptr)
		{
            cout<<"Not enough applicants in the queue to remove the second one."<<endl;
            return;
        }

        Applicant* second=front->next;
        front->next=second->next;
        cout<<"Applicant "<<second->applicant_id<<" had an urgency and left the queue."<<endl;
        delete second;

        if(front->next==nullptr)rear=front;
    }

    void display()
	{
        if(front==nullptr)
		{
            cout<<"Queue is empty!"<<endl;
            return;
        }

        Applicant* temp=front;
        cout<<"Current queue:\n";
        while(temp!=nullptr)
		{
            cout<<"ID: "<<temp->applicant_id<<", Height: "<<temp->height
                 <<", Weight: "<<temp->weight<<", Vision: "<<temp->vision
                 <<", Status: "<<temp->status<<endl;
            temp=temp->next;
        }
    }
};

int main() 
{
    ApplicantQueue q;

    q.enqueue(101, 5.8, 65, 1.2, "Pending");
    q.enqueue(102, 5.7, 70, 1.0, "Pending");
    q.enqueue(103, 5.9, 72, 0.8, "Pending");
    q.enqueue(104, 6.0, 68, 1.5, "Pending");
    q.enqueue(105, 5.6, 75, 0.9, "Pending");
    q.enqueue(106, 5.5, 69, 1.1, "Pending");
    q.enqueue(107, 5.4, 66, 1.3, "Pending");
    cout<<endl;
    q.display();
    cout<<endl;
    q.removeSecondApplicant();
    cout<<endl;
    q.display();
    cout<<endl;
    q.dequeue();
    cout<<endl;
    q.display();
	cout<<endl;

    return 0;
}

